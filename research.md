# Go documentation generation and rendering architecture

## Background and motivation

This research was conducted to support building a tree-sitter parser for
`go doc` output (tree-sitter-godoc). The goal is to enable reliable syntax
highlighting of Go documentation in terminal environments and editors.

The challenge is that `go doc` output contains multiple types of Go code that
need highlighting:

- **Declarations**: `func`, `type`, `var`, and `const` signatures at the top
  level
- **Code examples**: Indented code blocks within documentation prose
- **Inline types**: Type definitions within struct/interface blocks

Unlike simple code block detection, these elements appear in different
structural contexts throughout the output (see the `examples/` folder for real
`go doc` output samples).

The strategy is to build tree-sitter-godoc as a **structural parser only**—its
job is to identify regions containing Go code, not to parse Go syntax itself.
Once regions are identified, tree-sitter's injection system delegates to the
existing [tree-sitter-go][tree-sitter-go] parser for actual syntax highlighting.
This two-layer approach keeps tree-sitter-godoc simple while leveraging the full
power of tree-sitter-go.

---

## Overview

Go's documentation system uses a **two-stage pipeline**: extraction from source
code via [`go/doc`][go-doc], followed by rendering via
[`go/doc/comment`][go-doc-comment]. A critical insight for parsing Go
documentation is that **code blocks require only one space of indentation**, not
four like Markdown, and they're detected by a simple rule: any span of indented
or blank lines that doesn't start with a list marker becomes a code block.

The extraction layer (`go/doc`) parses source files and associates doc comments
with declarations, while the rendering layer (`go/doc/comment`, introduced in
[Go 1.19][go1.19]) parses the doc comment text itself, identifying structural
elements including code blocks, lists, headings, and links. Both `go doc` and
pkg.go.dev use the same underlying parsing logic but differ in output
formatting—plain text versus rich HTML.

## Package architecture and responsibilities

The Go documentation system divides responsibilities across several packages in
the standard library and extended tooling.

**Generation packages** handle extracting documentation from Go source code. The
[`go/parser`][go-parser] package parses source files into an Abstract Syntax
Tree (AST) when called with the `parser.ParseComments` flag. The AST includes
`CommentGroup` nodes attached to declarations via `Doc` fields. The `go/doc`
package (specifically [`src/go/doc/reader.go`][reader.go]) walks this AST to
extract documentation, implemented primarily through the `NewFromFiles()`
function. This function returns a `Package` struct containing extracted
documentation for all package-level declarations—functions, types, constants,
variables, and examples from test files.

**Rendering packages** transform extracted documentation into display formats.
The modern approach uses `go/doc/comment` (Go 1.19+), located at
[`src/go/doc/comment/parse.go`][parse.go], which provides a `Parser` type that
converts doc comment text into a structured AST of blocks (paragraphs, headings,
lists, code blocks). The `Printer` type in the same package renders this AST to
multiple formats: plain text for `go doc`, HTML for pkg.go.dev, or Markdown. The
`go doc` command uses `Printer.Text()` directly for terminal output, while
pkg.go.dev uses [`golang.org/x/pkgsite/internal/godoc/dochtml`][dochtml] which
wraps `Printer.HTML()` with additional features like identifier cross-linking
and syntax highlighting.

The key difference between rendering paths is presentation richness, not parsing
logic. Both `go doc` and pkg.go.dev parse comments identically using
`go/doc/comment.Parser`, but terminal rendering produces wrapped plain text
while web rendering generates HTML with clickable links, syntax highlighting,
and interactive examples. The underlying comment syntax rules remain consistent
across both outputs.

## Documentation generation logic and data flow

Go identifies doc comments through a simple proximity rule: **any comment
appearing immediately before a top-level declaration with no intervening blank
lines** becomes that declaration's documentation. This applies to package,
const, func, type, and var declarations.

The extraction process follows this sequence. First, `parser.ParseFile()`
tokenizes source code and builds an AST while collecting comments into
`CommentGroup` nodes. The parser automatically associates these comment groups
with declarations by placing them in `Doc` fields of AST nodes like `FuncDecl`,
`GenDecl`, and `TypeSpec`. For example, a `FuncDecl` struct contains a
`Doc *CommentGroup` field that holds the function's documentation comment.

The `go/doc` package then processes this annotated AST. The `reader` type in
[`src/go/doc/reader.go`][reader.go] walks the AST and extracts documentation
into structured forms. For each declaration type, dedicated methods extract the
relevant information: `readFunc()` processes functions, `readType()` handles
types and their methods, and `readValue()` extracts constants and variables. The
reader also handles grouping—multiple const declarations in a single block share
a common doc comment, and type methods are collected under their receiver type.

The resulting data structure is a `go/doc.Package` containing:

- `Doc string`: Package-level documentation from comments before the package
  clause
- `Funcs []*Func`: Standalone functions with their documentation
- `Types []*Type`: Types with associated methods, constants, variables, and
  examples
- `Consts []*Value` and `Vars []*Value`: Package-level declarations
- `Examples []*Example`: Extracted from `_test.go` files matching `Example*`
  naming

Each `Func`, `Type`, and `Value` struct contains a `Doc string` field with the
raw comment text (comment markers removed), plus a `Decl` field maintaining a
reference to the original AST node. This structure preserves both human-readable
documentation and the original source representation for rendering tools.

## Code block detection rules: the critical algorithm

The **single most important rule** for any tree-sitter parser targeting this
format is Go's code block detection algorithm in [`parseSpans()`][parseSpans] at
lines 360-494 of `src/go/doc/comment/parse.go`. A code block is formed from
**any sequence of indented or blank lines that doesn't begin with a list
marker**.

**Indentation detection** is deliberately minimal. The [`indented()`][indented]
function at line 498 returns true if a line is non-empty and starts with a
single space (U+0020) or tab (U+0009). This differs fundamentally from Markdown,
which requires four spaces. In Go doc comments, even one space creates
indentation. This design choice prioritizes source code readability—code blocks
require less ceremony and nest naturally within comment columns.

**Span classification** proceeds sequentially through lines. When the parser
encounters an indented line, it collects all following indented or blank lines
into a span, then removes trailing blank lines. The span becomes either a list
or a code block based on its first indented line. If that line matches a list
marker pattern (via [`listMarker()`][listMarker] at lines 737-764), the entire
span becomes a list. Otherwise, it becomes a code block.

**List markers** that prevent code block interpretation include:

- Bullet markers: `* `, `+ `, `- `, `• ` (asterisk, plus, dash, or bullet point)
- Numbered markers: digits followed by `. ` or `) `

The critical requirement is that **text must follow the marker on the same
line**, and that text must also be indented. A line like `- item` (with space
after dash) starts a list, but `-item` (no space) or just `- ` (no text) doesn't
match the pattern and becomes part of a code block instead.

**Special heuristics** handle edge cases common in Go documentation:

The **closing brace heuristic** ([line 425][brace-heuristic]) includes an
unindented `}` line following indented lines in the code block. This prevents
JSON examples from breaking:

```
    {
        "key": "value"
    }
```

Without this rule, the `}` would start a new paragraph.

The **force-indent mechanism** ([lines 453-470][force-indent]) handles
continuation patterns. When an unindented line ends with a list marker, `{`, or
`\` character, the next span is forced to be treated as indented even if it
isn't. This fixes common cases like shell commands using line continuation:

```
go run generate.go \
    --flag value
```

The second line, though unindented in the comment, continues the code block.

**Processing** of identified code blocks occurs in the [`code()`][code-fn]
function at line 636. The implementation removes common leading whitespace via
[`unindent()`][unindent], strips leading and trailing blank lines, adds a single
trailing newline, and joins lines with newline separators. The resulting `Code`
struct contains a single `Text string` field with the processed code.

A tree-sitter implementation should detect code blocks by:

1. Identifying lines with any leading space or tab
2. Collecting consecutive indented/blank lines until an unindented non-blank
   line
3. Checking if the first indented line matches list marker regex:
   `^\s*([*+\-•]|[0-9]+[.)])(\s+\S)`
4. If no list match, treat the span as code requiring tree-sitter-go parsing
5. Apply closing brace and force-indent heuristics for edge cases

## Other syntax elements in doc comments

**Headings** use two syntaxes. The modern form (Go 1.19+) requires lines
starting with `# ` followed by heading text, detected by
[`isHeading()`][isHeading] at line 623. The legacy form identifies single-line
paragraphs that start with uppercase, contain no terminal punctuation, and are
surrounded by blank lines—detected by [`isOldHeading()`][isOldHeading] at
line 568. Both forms produce `Heading` blocks in the parsed AST.

**Lists** are restricted to flat structures—no nesting allowed. Each `ListItem`
in a `List` block contains a `Number` field (for numbered items) and `Content`
slice limited to paragraphs only. Continuation lines within an item remain part
of that item as long as they maintain indentation. A blank line between items
sets the `ForceBlankBetween` flag, affecting rendering with extra spacing.

**Links** come in two varieties. URL links use reference syntax `[text]: URL`
where the URL must have a valid scheme like `http://` or `https://`. Doc links
use inline syntax `[Name]`, `[pkg.Name]`, or `[Recv.Method]` to reference Go
identifiers. The parser validates these links through callback functions
`LookupPackage` and `LookupSym` in the `Parser` config. Doc links must be
surrounded by punctuation, whitespace, or line boundaries to prevent false
positives like `map[string]int`.

**Paragraphs** are spans of unindented non-blank lines that don't match other
patterns. Within paragraphs, text processing converts typography: double
backtick (\`\`) becomes left quote ", double apostrophe ('') becomes right quote
", and URLs matching `scheme://...` are auto-linked. The parser also supports
inline formatting through an optional `Words` map that italicizes specified
identifiers.

## Rendering differences across output formats

Terminal rendering via `Printer.Text()` in
[`src/go/doc/comment/print.go`][print.go] produces wrapped plain text. Code
blocks are indented by `TextCodePrefix` (default: base prefix plus tab) with
line wrapping at `TextWidth` (default: 80 characters minus prefix length). Lists
use ` -` for bullets and ` N.` for numbered items. No syntax highlighting
occurs—code appears as plain monospace text. Doc links render as plain text
references like "Name" without any special formatting.

HTML rendering for pkg.go.dev flows through
[`golang.org/x/pkgsite/internal/godoc/dochtml/internal/render`][render]. The
pipeline calls `Parser.Parse()` to create the AST, then `Printer.HTML()` to
generate HTML, which `dochtml` templates wrap with site structure. Code blocks
render as `<pre>code content</pre>` with preserved whitespace and syntax
highlighting applied client-side. Headings receive IDs like `hdr-HeadingText`
with non-alphanumeric characters converted to underscores for anchor linking.
Doc links become actual hyperlinks resolving to package documentation URLs, and
identifiers throughout the documentation gain hover tooltips and clickable
navigation.

The key distinction is that both paths parse identically but render differently.
A tree-sitter parser should focus on the parsing layer (`go/doc/comment.Parser`
behavior), not the rendering layer, since code block _detection_ occurs during
parsing while syntax highlighting occurs during rendering.

## Implementation roadmap

A tree-sitter-godoc parser should implement a two-phase strategy. **Phase one**
parses doc comment structure following `parseSpans()` logic: classify lines as
indented or not, group consecutive indented/blank lines into spans, determine if
spans are lists or code blocks based on first line pattern matching, and handle
special heuristics for braces and continuation.

**Phase two** delegates to specialized parsers: when a code block is identified,
hand off its content to tree-sitter-go for syntax highlighting. For lists, parse
marker syntax and item continuation. For headings, distinguish `#` prefix from
legacy heuristics. For doc links and URLs, tokenize link syntax for highlighting
or validation.

Critical edge cases to handle include:

- Single-space indentation (not four spaces)
- List markers requiring both marker pattern and following text
- Closing braces after indented code extending the block
- Lines ending with `\`, `{`, or list markers forcing next span to continue
- Blank lines within code blocks remaining part of the block
- Comment markers (`//` or `/* */`) already stripped by the time comment text
  reaches the parser

The source code at [`src/go/doc/comment/parse.go`][parse.go] lines 360-494
contains the authoritative algorithm. Study `parseSpans()`, `indented()`,
`listMarker()`, and the special-case handling for a complete understanding. The
parser builds a simple AST: `Doc` contains `[]Block`, where `Block` is an
interface implemented by `Paragraph`, `Heading`, `List`, and `Code`. Within
blocks, `Text` elements represent inline content with `Plain`, `Italic`, `Link`,
and `DocLink` types.

For testing an implementation, use `go doc` on standard library packages to see
expected output, run the local `pkgsite` server
(`go install golang.org/x/pkgsite/cmd/pkgsite@latest`) to preview HTML
rendering, and compare against the official `go/doc/comment` package behavior by
parsing sample comments and inspecting the resulting AST structure. The [Go 1.19
release notes][go1.19] and [proposal #48305][proposal-48305] provide additional
design rationale and examples of edge cases the parser must handle.

## Considerations

Building a tree-sitter parser for `go doc` output differs significantly from
Go's internal documentation parsing. This section documents key considerations
that informed the implementation approach.

### Source comments vs. rendered output

Go's `go/doc/comment` package parses **source code comments** where indentation
is minimal (1 space) and context is clear. However, `go doc` **terminal output**
has already been rendered with standardized formatting:

- Code examples: 4-space (or tab) indentation
- Documentation prose after declarations: also 4-space indentation
- Continuation lines: same indentation as their parent

This means the 1-space indentation rule from the source algorithm cannot
directly distinguish code from prose in rendered output—both use identical
indentation.

### Why not detect code in prose blocks?

A pattern-based approach that detects Go keywords (`if`, `for`, `switch`,
`return`, `go`, `case`, `range`, `select`, `default`) in indented prose will
produce false positives when these words appear naturally in English:

```
    switch to a new underlying Reader    ← "switch to" (English)
    if this is a server, received)       ← "if this is" (English)
    if they are not equal               ← "if they are" (English)
    for example, to write data          ← "for example" (English)
    return the result to the caller     ← "return the" (English)
    go to the next section              ← "go to" (English)
```

Attempting to distinguish Go code from English prose is inherently unreliable.
Rather than risking false positives that produce garbled highlighting, the
parser focuses on **structural elements** that are unambiguously Go code:

- Top-level declarations: `func`, `type`, `var`, `const` signatures
- Declaration blocks: `type ... struct {`, `var (`, `const (`
- Package lines: `package foo // import "..."`

Indented prose blocks (documentation text after declarations) are left
unhighlighted. This trade-off prioritizes correctness over completeness—it's
better to leave prose unstyled than to incorrectly apply Go syntax highlighting
to English text.

### Composite literals and data structures

JSON, YAML, and other data literals in documentation examples don't match Go
declaration patterns:

```
    {
        "key": "value"
    }
```

An opening `{` alone doesn't indicate Go code. These remain unhighlighted, which
is acceptable since they aren't Go syntax anyway.

---

The fundamental insight: Go chose readability over power, using minimal syntax
(one-space indentation, flat lists, simple heading markers) to keep
documentation readable in source while still supporting structured rendering. A
parser should embrace this philosophy—detect structure simply and delegate
complexity to downstream tools like tree-sitter-go for syntax highlighting
within detected code blocks.

<!-- Reference links -->

<!-- External tools -->

[tree-sitter-go]: https://github.com/tree-sitter/tree-sitter-go

<!-- Standard library documentation -->

[go-doc]: https://pkg.go.dev/go/doc
[go-doc-comment]: https://pkg.go.dev/go/doc/comment
[go-parser]: https://pkg.go.dev/go/parser

<!-- Go source code (pinned to commit 8c28ab936a10) -->

[reader.go]: https://github.com/golang/go/blob/8c28ab936a10/src/go/doc/reader.go
[parse.go]:
  https://github.com/golang/go/blob/8c28ab936a10/src/go/doc/comment/parse.go
[print.go]:
  https://github.com/golang/go/blob/8c28ab936a10/src/go/doc/comment/print.go

<!-- Specific functions in parse.go -->

[parseSpans]:
  https://github.com/golang/go/blob/8c28ab936a10/src/go/doc/comment/parse.go#L360
[indented]:
  https://github.com/golang/go/blob/8c28ab936a10/src/go/doc/comment/parse.go#L498
[listMarker]:
  https://github.com/golang/go/blob/8c28ab936a10/src/go/doc/comment/parse.go#L737
[isHeading]:
  https://github.com/golang/go/blob/8c28ab936a10/src/go/doc/comment/parse.go#L623
[isOldHeading]:
  https://github.com/golang/go/blob/8c28ab936a10/src/go/doc/comment/parse.go#L568
[code-fn]:
  https://github.com/golang/go/blob/8c28ab936a10/src/go/doc/comment/parse.go#L636
[unindent]:
  https://github.com/golang/go/blob/8c28ab936a10/src/go/doc/comment/parse.go#L656
[brace-heuristic]:
  https://github.com/golang/go/blob/8c28ab936a10/src/go/doc/comment/parse.go#L425
[force-indent]:
  https://github.com/golang/go/blob/8c28ab936a10/src/go/doc/comment/parse.go#L453

<!-- pkgsite source (pinned to commit 4eb0af2c34bf) -->

[dochtml]:
  https://github.com/golang/pkgsite/tree/4eb0af2c34bf/internal/godoc/dochtml
[render]:
  https://github.com/golang/pkgsite/tree/4eb0af2c34bf/internal/godoc/dochtml/internal/render

<!-- Release notes and proposals -->

[go1.19]: https://go.dev/doc/go1.19#go-doc
[proposal-48305]: https://github.com/golang/go/issues/48305
