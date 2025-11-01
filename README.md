# tree-sitter-godoc

This parser...

- identifies structural regions in `godoc` output so to efficiently delegate Go
  syntax highlighting to the
  [tree-sitter-go](https://github.com/tree-sitter/tree-sitter-go) parser via
  tree-sitter query injections.
- is designed to work with
  [godoc.nvim](https://github.com/fredrikaverpil/godoc.nvim).

## Quickstart for Neovim users

### Using nvim-treesitter (`main` branch)

1. **Configure how to install the `godoc` parser**:

```lua
require('nvim-treesitter.parsers').godoc = {
  install_info = {
    url = "https://github.com/fredrikaverpil/tree-sitter-godoc",
    files = {"src/parser.c"},
    branch = "main",
  },
  filetype = "godoc",
}
```

2. **Install parsers via TSInstall**:

```vim
:TSInstall godoc go
```

3. **Copy queries into Neovim configuration**:

```sh
cp queries/*.csm ~/.config/nvim/after/queries/godoc/
```

## Development

### Prerequisites

- [tree-sitter CLI](https://github.com/tree-sitter/tree-sitter)
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

## Contributing

Contributions welcome! Please open an issue or PR.
