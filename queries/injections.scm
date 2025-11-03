; Treesitter injection queries for godoc
; These inject the Go parser into specific regions of godoc output
; Inject Go syntax into function lines
((func_line) @injection.content
  (#set! injection.language "go"))

; Inject Go syntax into function blocks
((func_block) @injection.content
  (#set! injection.language "go"))

; Inject Go syntax into type lines
((type_line) @injection.content
  (#set! injection.language "go"))

; Inject Go syntax into type blocks (struct/interface definitions)
((type_block) @injection.content
  (#set! injection.language "go"))

; Inject Go syntax into variable lines
((var_line) @injection.content
  (#set! injection.language "go"))

; Inject Go syntax into variable blocks
((var_block) @injection.content
  (#set! injection.language "go"))

; Inject Go syntax into constant lines
((const_line) @injection.content
  (#set! injection.language "go"))

; Inject Go syntax into constant blocks
((const_block) @injection.content
  (#set! injection.language "go"))

; Inject Go syntax into indented code blocks (code examples in documentation)
; 8+ space indented code blocks
((code_block_8plus) @injection.content
  (#set! injection.language "go"))

; 4-7 space indented code blocks
((code_block_4) @injection.content
  (#set! injection.language "go"))
