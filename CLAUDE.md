# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

This is a Tree-sitter grammar parser for Go documentation (`go doc`) output format. The parser identifies WHERE Go code appears in godoc output and delegates actual Go syntax highlighting to the existing Go tree-sitter parser via injections.

**Key Design Principle**: This parser does NOT parse Go syntax itself. It only recognizes the structure of godoc output and marks code regions for injection.

## Development Commands

```bash
# Regenerate parser from grammar.js (required after any grammar changes)
tree-sitter generate

# Run test suite
tree-sitter test

# Build the parser
tree-sitter build

# Interactive testing and debugging
tree-sitter playground
```

**Prerequisites**: tree-sitter CLI (`cargo install tree-sitter-cli`), C compiler

## High-Level Architecture

### Core Files

**grammar.js** - Grammar definition
- Defines parsing rules for godoc output format
- Key rules: `package_line`, `section_header`, `func_line`, `func_block`, `type_line`, `type_block`, `var_line`, `var_block`, `const_line`, `const_block`, `code_block`, `text_line`
- Uses `token()` for atomic matching (performance optimization)
- Distinguishes single-line vs multi-line constructs by checking for newlines after opening braces
- Uses negative lookahead to prevent mismatches (e.g., `var_line` must NOT have opening paren)
- **Code block detection**:
  - `code_block`: Smart detection of indented Go code examples using pattern matching
    - Matches **4+ space indented** lines where the first line contains Go code patterns
    - **First line patterns** (restrictive to prevent mid-block splitting):
      - Comments: `//`
      - Declaration keywords: `var`, `const`, `type`
      - Short variable declarations: `x := ...` or `x, y := ...`
      - Keywords: `defer`, `go`
      - Function calls: `fmt.Println()` (excludes method calls like `obj.Method()` to prevent splitting)
      - Composite literals: `map[string]int{`, `Person{`
    - Requires **at least 2 indented lines** to form a block (prevents single-line false matches)
    - Pattern matching distinguishes code from prose (documentation prose won't match Go patterns)
    - Works for both 4-space and 8+ space indented examples

**queries/injections.scm** - Injection queries
- Injects Go parser into code regions: `func_line`, `func_block`, `type_line`, `type_block`, `var_line`, `var_block`, `const_line`, `const_block`, `code_block`
- This is how Go syntax highlighting is achieved for both declarations and code examples

**queries/highlights.scm** - Highlight queries
- Highlights structural elements only:
  - `section_header` → @label (FUNCTIONS, TYPES, etc.)
  - `package_line` → @keyword.import
  - `text_line` → @none (keeps prose unhighlighted for readability)

**test/corpus/godoc.txt** - Test cases
- Uses tree-sitter test format with input/expected parse tree pairs

**src/** - Auto-generated parser files
- `parser.c`, `grammar.json`, `node-types.json`
- Do NOT edit these files manually - regenerate via `tree-sitter generate`

### Two-Stage Highlighting Strategy

1. **This parser** creates a parse tree with nodes like `func_line`, `type_block`, etc.
2. **injections.scm** tells tree-sitter to run the Go parser on the content of these nodes
3. Result: Full Go syntax highlighting within code regions, while keeping the godoc grammar simple

## Development Workflow

1. Edit `grammar.js` to modify grammar rules
2. Run `tree-sitter generate` to regenerate the parser
3. Run `tree-sitter test` to verify changes
4. Use `tree-sitter playground` for interactive debugging

**Note**: Query files (`injections.scm`, `highlights.scm`) can be edited without regenerating the parser. Changes take effect when the parser is reloaded.

## Local Testing in Neovim

To test the parser locally in Neovim (especially the nvim-fredrik config):

```bash
# Build the parser
tree-sitter build

# Copy parser and queries to Neovim config
mkdir -p ~/.local/share/nvim-fredrik/site/parser
mkdir -p ~/.local/share/nvim-fredrik/site/queries/godoc

# On macOS, tree-sitter build creates .dylib but Neovim expects .so
cp godoc.dylib ~/.local/share/nvim-fredrik/site/parser/godoc.so   # macOS
# OR
cp godoc.so ~/.local/share/nvim-fredrik/site/parser/              # Linux

cp queries/*.scm ~/.local/share/nvim-fredrik/site/queries/godoc/
```

After copying, restart Neovim or reload the parser. Open a `.godoc` file to test syntax highlighting.

**Quick test script (macOS):**
```bash
tree-sitter build && \
  cp godoc.dylib ~/.local/share/nvim-fredrik/site/parser/godoc.so && \
  cp queries/*.scm ~/.local/share/nvim-fredrik/site/queries/godoc/ && \
  echo "Parser updated! Restart Neovim to see changes."
```

## Context

This parser is designed for use with **godoc.nvim**, a Neovim plugin for viewing Go documentation with proper syntax highlighting. The parser enables tree-sitter features like text objects, folding, and selective syntax highlighting in documentation buffers.
