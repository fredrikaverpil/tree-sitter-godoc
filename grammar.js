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
		// Supports any indentation level (including no indentation)
		func_line: $ => token(choice(
			/func\s+(?:[^\{\n]|\{[^\s\n])+/,  // No indentation
			/[ \t]+func\s+(?:[^\{\n]|\{[^\s\n])+/  // With indentation
		)),

		// Function block: func Name() {
		//   ...
		// }
		// Matches function implementations with bodies in curly braces
		// Supports any indentation level (including no indentation)
		func_block: $ => seq(
			token(choice(
				/func\s+.*\{/,  // No indentation
				/[ \t]+func\s+.*\{/  // With indentation
			)),
			/\s*\n/,           // Optional whitespace and newline after opening brace
			repeat(choice(
				/[ \t]*[^\}\s][^\n]*\n/, // Lines with content (not just whitespace and })
				/[ \t]*\n/             // Empty or whitespace-only lines
			)),
			/[ \t]*\}/  // Closing brace with optional leading whitespace
		),

		// Variable block: var (
		//   ...
		// )
		// Supports any indentation level (including no indentation)
		var_block: $ => seq(
			token(choice(
				seq('var', /\s*\(/),  // No indentation
				seq(/[ \t]+var/, /\s*\(/)  // With indentation
			)),
			repeat(choice(
				/[ \t]*[^\)\s][^\n]*\n/, // Lines with content (not just whitespace and ))
				/[ \t]*\n/             // Empty or whitespace-only lines
			)),
			/[ \t]*\)/  // Closing paren with optional leading whitespace
		),

		// Single-line variable declaration (must NOT have opening paren)
		// Supports any indentation level (including no indentation)
		var_line: $ => token(choice(
			seq('var', /\s+[^\(\n][^\n]*/),  // No indentation
			seq(/[ \t]+var/, /\s+[^\(\n][^\n]*/)  // With indentation
		)),

		// Constant block: const (
		//   ...
		// )
		// Supports any indentation level (including no indentation)
		const_block: $ => seq(
			token(choice(
				seq('const', /\s*\(/),  // No indentation
				seq(/[ \t]+const/, /\s*\(/)  // With indentation
			)),
			repeat(choice(
				/[ \t]*[^\)\s][^\n]*\n/, // Lines with content (not just whitespace and ))
				/[ \t]*\n/             // Empty or whitespace-only lines
			)),
			/[ \t]*\)/  // Closing paren with optional leading whitespace
		),

		// Single-line constant declaration (must NOT have opening paren)
		// Supports any indentation level (including no indentation)
		const_line: $ => token(choice(
			seq('const', /\s+[^\(\n][^\n]*/),  // No indentation
			seq(/[ \t]+const/, /\s+[^\(\n][^\n]*/)  // With indentation
		)),

		// Type block: type Name struct {
		//   ...
		// }
		// Only matches when there's content on subsequent lines (not single-line interface{})
		// Supports any indentation level (including no indentation)
		type_block: $ => seq(
			token(choice(
				/type\s+\w+\s+(struct|interface)\s*\{/,  // No indentation
				/[ \t]+type\s+\w+\s+(struct|interface)\s*\{/  // With indentation
			)),
			/\s*\n/,  // Require newline after opening brace to distinguish from single-line
			repeat(choice(
				/[ \t]*[^\}\s][^\n]*\n/, // Lines with content (not just whitespace and })
				/[ \t]*\n/             // Empty or whitespace-only lines
			)),
			/[ \t]*\}/  // Closing brace with optional leading whitespace
		),

		// Single-line type definition (everything else)
		// Supports any indentation level (including no indentation)
		type_line: $ => token(choice(
			seq('type', /.*/),  // No indentation
			seq(/[ \t]+type/, /.*/))  // With indentation
		),

		// Non-empty text line
		text_line: $ => /.+/,
	}
});
