;; Treesitter injection queries for godoc
;; These inject the Go parser into specific regions of godoc output

;; Inject Go syntax into function lines
((func_line) @injection.content
  (#set! injection.language "go"))

;; Inject Go syntax into type lines
((type_line) @injection.content
  (#set! injection.language "go"))

;; Inject Go syntax into variable lines
((var_line) @injection.content
  (#set! injection.language "go"))

;; Inject Go syntax into constant lines
((const_line) @injection.content
  (#set! injection.language "go"))
