/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

/**
 * Tree-sitter grammar for godoc (Go documentation) output
 *
 * This grammar identifies structural regions in godoc output to enable
 * treesitter injections of the Go parser for syntax highlighting.
 * It does NOT parse Go syntax itself - that's delegated to the Go parser.
 */

module.exports = grammar({
	name: 'godoc',

	rules: {
		document: $ => repeat(
			choice(
				$.package_line,
				$.section_header,
				$.func_block,
				$.func_line,
				$.var_block,
				$.const_block,
				$.type_block,
				$.var_line,
				$.const_line,
				$.type_line,
				$.code_block_8plus,
				$.code_block_4,
				$.text_line,
			)
		),

		// Package declaration
		package_line: $ => token(seq('package', /.*/)),

		// Section headers
		section_header: $ => token(choice(
			'VARIABLES',
			'FUNCTIONS',
			'TYPES',
			'CONSTANTS',
			'DEPRECATED'
		)),

		// Function signature - capture whole line starting with "func" (but not ending with {)
		// Matches { within the line (like interface{}) but not { at end (which indicates func_block)
		// Strategy: { is only matched when followed immediately by a non-whitespace character
		func_line: $ => token(/func\s+(?:[^\{\n]|\{[^\s\n])+/),

		// Function block: func Name() {
		//   ...
		// }
		// Matches function implementations with bodies in curly braces
		// Only matches at start of line (no indentation) - indented examples are caught by code_block
		func_block: $ => seq(
			token(/func\s+.*\{/),  // func signature ending with { (no leading whitespace)
			/\s*\n/,           // Optional whitespace and newline after opening brace
			repeat(choice(
				/[^\}][^\n]*\n/, // Lines not starting with }
				/\n/             // Empty lines
			)),
			'}'
		),

		// Variable block: var (
		//   ...
		// )
		var_block: $ => seq(
			token(seq('var', /\s*\(/)),
			repeat(choice(
				/[^\)][^\n]*\n/,
				/\n/
			)),
			')'
		),

		// Single-line variable declaration (must NOT have opening paren)
		var_line: $ => token(seq('var', /\s+[^\(\n][^\n]*/)),

		// Constant block: const (
		//   ...
		// )
		const_block: $ => seq(
			token(seq('const', /\s*\(/)),
			repeat(choice(
				/[^\)][^\n]*\n/,
				/\n/
			)),
			')'
		),

		// Single-line constant declaration (must NOT have opening paren)
		const_line: $ => token(seq('const', /\s+[^\(\n][^\n]*/)),

		// Type block: type Name struct {
		//   ...
		// }
		// Only matches when there's content on subsequent lines (not single-line interface{})
		// Only matches at start of line (no indentation) - indented examples are caught by code_block
		type_block: $ => seq(
			token(/type\s+\w+\s+(struct|interface)\s*\{/),  // type definition (no leading whitespace)
			/\s*\n/,  // Require newline after opening brace to distinguish from single-line
			repeat(choice(
				/[^\}][^\n]*\n/,
				/\n/
			)),
			'}'
		),

		// Single-line type definition (everything else)
		type_line: $ => token(seq('type', /.*/)),

		// Indented code block with 8+ spaces - detects Go code examples through pattern matching
		// First line must start with Go code patterns at 8+ space indentation
		// Continuation lines must maintain 8+ space indentation (stops at dedent to fewer spaces)
		// This handles deeply nested examples and respects indentation scope
		code_block_8plus: $ => prec.dynamic(1, prec.left(-1, seq(
			choice(
				/[ ]{8,}\/\/[^\n]*\n/,                       // Comment
				/[ ]{8,}(var|const|type)\s[^\n]+\n/,         // Declaration keywords
				/[ ]{8,}func\s[^\n]+\{[^\n]*\n/,             // Function definition
				/[ ]{8,}[a-zA-Z_]\w*\s*:=[^\n]+\n/,          // Simple assignment (id := ...)
				/[ ]{8,}[a-zA-Z_]\w*,\s*[a-zA-Z_]\w*\s*:=[^\n]+\n/, // Multi-assignment (id1, id2 := ...)
				/[ ]{8,}(defer|go)\s+[^\n]+\n/,              // defer or go statement
				/[ ]{8,}[a-zA-Z_]\w*\([^\n]*\n/,             // Function call (no dots)
				/[ ]{8,}[a-zA-Z_][\w\[\]]*\{\s*\n/,          // Composite literal (TypeName{ or map[type]{)
			),
			repeat1(choice(
				/[ ]{8,}[^\n]+\n/,      // Additional indented lines at 8+ spaces (at least one required)
				/[ \t]*\n/              // Empty lines within the block
			))
		))),

		// Indented code block with 4-7 spaces - detects Go code examples through pattern matching
		// First line must start with Go code patterns at 4-7 space indentation
		// Continuation lines must maintain 4+ space indentation
		// This handles standard godoc examples with 4-space indentation
		code_block_4: $ => prec.dynamic(1, prec.left(-1, seq(
			choice(
				/[ ]{4,7}\/\/[^\n]*\n/,                       // Comment
				/[ ]{4,7}(var|const|type)\s[^\n]+\n/,         // Declaration keywords
				/[ ]{4,7}func\s[^\n]+\{[^\n]*\n/,             // Function definition
				/[ ]{4,7}[a-zA-Z_]\w*\s*:=[^\n]+\n/,          // Simple assignment (id := ...)
				/[ ]{4,7}[a-zA-Z_]\w*,\s*[a-zA-Z_]\w*\s*:=[^\n]+\n/, // Multi-assignment (id1, id2 := ...)
				/[ ]{4,7}(defer|go)\s+[^\n]+\n/,              // defer or go statement
				/[ ]{4,7}[a-zA-Z_]\w*\([^\n]*\n/,             // Function call (no dots)
				/[ ]{4,7}[a-zA-Z_][\w\[\]]*\{\s*\n/,          // Composite literal (TypeName{ or map[type]{)
			),
			repeat1(choice(
				/[ ]{4,}[^\n]+\n/,      // Additional indented lines at 4+ spaces (at least one required)
				/[ \t]*\n/              // Empty lines within the block
			))
		))),

		// Non-empty text line
		text_line: $ => /.+/,
	}
});
