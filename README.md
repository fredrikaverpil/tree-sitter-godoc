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
- **Section headers**: `VARIABLES`, `FUNCTIONS`, `TYPES`, `CONSTANTS`, `DEPRECATED`
- **Function signatures**: Lines starting with `func ` (without body)
- **Function blocks**: Function implementations with bodies in `{ ... }`
- **Type definitions**:
  - Single-line: `type Message interface{}`
  - Multi-line structs/interfaces: `type Config struct { ... }`
- **Variable declarations**:
  - Single-line: `var MaxRetries int`
  - Multi-line blocks: `var ( ... )`
- **Constant declarations**:
  - Single-line: `const MaxInt = 123`
  - Multi-line blocks: `const ( ... )`
- **Prose**: Regular description text (kept unhighlighted)

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

This parser is designed to work with [godoc.nvim](https://github.com/fredrikaverpil/godoc.nvim). The plugin automatically uses treesitter injections when this parser is installed.

**What you get**:

- Section headers (`FUNCTIONS`, `TYPES`, etc.) are highlighted
- Function signatures get full Go syntax highlighting
- **Function blocks** (`func Name() { ... }`) have Go syntax highlighting applied to their bodies
- Type definitions (including struct/interface bodies) get Go syntax highlighting
- Variable and constant declarations get Go syntax highlighting
- **Multi-line blocks** (`const ( ... )`, `var ( ... )`, `type Name struct { ... }`) have Go syntax highlighting applied to their contents
- Prose descriptions remain clean and unhighlighted for readability

## Queries

### Injection queries (injections.scm)

Injects Go parser into code regions:

```scheme
;; Function signatures
((func_line) @injection.content
  (#set! injection.language "go"))

;; Function blocks
((func_block) @injection.content
  (#set! injection.language "go"))

;; Type lines (single-line type definitions)
((type_line) @injection.content
  (#set! injection.language "go"))

;; Type blocks (multi-line struct/interface definitions)
((type_block) @injection.content
  (#set! injection.language "go"))

;; Variable lines (single-line declarations)
((var_line) @injection.content
  (#set! injection.language "go"))

;; Variable blocks (multi-line var blocks)
((var_block) @injection.content
  (#set! injection.language "go"))

;; Constant lines (single-line declarations)
((const_line) @injection.content
  (#set! injection.language "go"))

;; Constant blocks (multi-line const blocks)
((const_block) @injection.content
  (#set! injection.language "go"))
```

### Highlight queries (highlights.scm)

Highlights structural elements:

```scheme
;; Section headers (VARIABLES, FUNCTIONS, TYPES, etc.)
(section_header) @text.title

;; Package declaration line
(package_line) @keyword.import

;; Text lines remain unhighlighted for readability
(text_line) @none
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

- `package proto...` → `package_line` (highlighted as keyword)
- `Package proto provides...` → `text_line` (unhighlighted)
- `FUNCTIONS` → `section_header` (highlighted as title)
- `func Bool(v bool) *bool` → `func_line` → **Go parser injected**
- `Bool stores v...` → `text_line` (unhighlighted)
- `func Marshal...` → `func_line` → **Go parser injected**
- `TYPES` → `section_header` (highlighted as title)
- `type Message...` → `type_line` → **Go parser injected**
- `type MarshalOptions struct { ... }` → `type_block` → **Go parser injected** (including struct fields)

For function implementations with bodies:

```go
func Example() {
    fmt.Println("hello")
}
```

Would be parsed as:
- Entire function → `func_block` → **Go parser injected** (including signature and body)

## Contributing

Contributions welcome! Please open an issue or PR.

## License

MIT

## Credits

Created for use with [godoc.nvim](https://github.com/fredrikaverpil/godoc.nvim).
