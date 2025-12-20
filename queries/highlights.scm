; Treesitter highlight queries for godoc
; These highlight structural elements (non-Go code regions)
; Section headers (VARIABLES, FUNCTIONS, TYPES, CONSTANTS, etc.)
(section_header) @label

; Headings (# Heading)
(heading) @markup.heading

; List items
(list_item) @markup.list

; Text lines remain unhighlighted (no capture = no highlighting)
