# tree-sitter-godoc

Tree-sitter grammar for Go documentation (`go doc`) output format.

## Purpose

This parser identifies structural regions in `godoc` output to enable:

1. **Treesitter injections** - Injects the Go parser for syntax highlighting of code regions only
2. **Selective highlighting** - Section headers highlighted, prose kept clean and readable
3. **Treesitter features** - Enables text objects, better folding, and other treesitter-based functionality

**Key design principle**: This parser identifies WHERE Go code appears (functions, types, variables, code blocks) but doesn't parse Go syntax itself. Go syntax highlighting is delegated to the Go treesitter parser via injections.

## What it parses

The godoc output format includes:

- **Package headers**: `package foo // import "path/to/package"`
- **Section headers**: `VARIABLES`, `FUNCTIONS`, `TYPES`, `CONSTANTS`
- **Function signatures**: Lines starting with `func `
- **Type definitions**: Lines starting with `type ` (including multi-line structs/interfaces)
- **Variable/constant declarations**: Lines starting with `var`/`const`
- **Code blocks**: Indented content (4+ spaces) - common in examples
- **Prose**: Regular description text (kept unhighlighted)
- **URLs**: HTTP/HTTPS links

## Quick Start for Users

### Using nvim-treesitter

1. **Install the parser**:

```lua
require('nvim-treesitter.parsers').get_parser_configs().godoc = {
  install_info = {
    url = "https://github.com/fredrikaverpil/tree-sitter-godoc",
    files = {"src/parser.c"},
    branch = "main",
  },
  filetype = "godoc",
}
```

2. **Install via TSInstall**:

```vim
:TSInstall godoc
```

### Manual installation

```bash
git clone https://github.com/fredrikaverpil/tree-sitter-godoc
cd tree-sitter-godoc
tree-sitter generate
tree-sitter build
```

Copy the compiled parser to your Neovim parser directory:

```bash
# macOS/Linux
cp build/godoc.so ~/.local/share/nvim/site/parser/

# Windows
cp build/godoc.dll %LOCALAPPDATA%\nvim-data\site\parser\
```

## Usage with godoc.nvim

This parser is designed to work with [godoc.nvim](https://github.com/fredrikaverpil/godoc.nvim). The plugin automatically uses treesitter if the parser is installed, otherwise falls back to Vim syntax highlighting.

**Example**: With tree-sitter-godoc installed:

- Section headers (`FUNCTIONS`, `TYPES`) are highlighted
- Go function signatures get full Go syntax highlighting (keywords, types, punctuation)
- Type definitions with structs get proper Go syntax highlighting
- Code examples (indented blocks) get Go syntax highlighting
- Prose descriptions remain clean and unhighlighted for readability

## Queries

### Injection queries (injections.scm)

Injects Go parser into code regions:

```scheme
;; Function signatures
((function_signature) @injection.content
  (#set! injection.language "go"))

;; Type definitions
((type_definition) @injection.content
  (#set! injection.language "go"))

;; Variable/constant declarations
((variable_declaration) @injection.content
  (#set! injection.language "go"))

((const_declaration) @injection.content
  (#set! injection.language "go"))

;; Code blocks
((code_block) @injection.content
  (#set! injection.language "go"))
```

### Highlight queries (highlights.scm)

Highlights structural elements:

```scheme
;; Section headers
(section_header) @text.title

;; Package header
(package_header) @keyword.import

;; URLs
(url_line) @text.uri
```

## Development

### Prerequisites

- [tree-sitter CLI](https://github.com/tree-sitter/tree-sitter/blob/master/cli/README.md)
- Node.js (for testing)
- A C compiler

### Building

```bash
# Generate the parser from grammar.js
tree-sitter generate

# Test the grammar
tree-sitter test

# Build the parser
tree-sitter build
```

### Testing with playground

```bash
tree-sitter playground
```

Then paste some `go doc` output to see how it's parsed.

## Example

Given this godoc output:

```
package proto // import "google.golang.org/protobuf/proto"

Package proto provides functions operating on protocol buffers.

FUNCTIONS

func Bool(v bool) *bool
    Bool stores v in a new bool value and returns a pointer to it.

func Marshal(m Message) ([]byte, error)
    Marshal returns the wire-format encoding of m.

TYPES

type Message = protoreflect.ProtoMessage
    Message is the top-level interface that all messages must implement.

type MarshalOptions struct {
    AllowPartial  bool
    Deterministic bool
}
    MarshalOptions configures the marshaler.
```

The parser creates this structure:

- `package proto...` → `package_header` (highlighted as keyword)
- `Package proto provides...` → `prose_line` (unhighlighted)
- `FUNCTIONS` → `section_header` (highlighted as title)
- `func Bool(v bool) *bool` → `function_signature` → **Go parser injected**
- `Bool stores v...` → `prose_line` (unhighlighted)
- `func Marshal...` → `function_signature` → **Go parser injected**
- `TYPES` → `section_header` (highlighted as title)
- `type Message...` → `type_definition` → **Go parser injected**
- `type MarshalOptions struct { ... }` → `type_definition` → **Go parser injected**

## Contributing

Contributions welcome! Please open an issue or PR.

## License

MIT

## Credits

Created for use with [godoc.nvim](https://github.com/fredrikaverpil/godoc.nvim).
