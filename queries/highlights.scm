;; Treesitter highlight queries for godoc
;; These highlight structural elements (non-Go code regions)

;; Section headers (VARIABLES, FUNCTIONS, TYPES, CONSTANTS, etc.)
(section_header) @text.title

;; Package declaration line
(package_line) @keyword.import

;; Text lines remain unhighlighted for readability
(text_line) @none
