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
    section_header: $ => choice(
      'VARIABLES',
      'FUNCTIONS',
      'TYPES',
      'CONSTANTS',
      'DEPRECATED'
    ),

    // Function signature - capture whole line starting with "func" (but not ending with {)
    func_line: $ => token(/func\s+[^{\n]+/),

    // Function block: func Name() {
    //   ...
    // }
    // Matches function implementations with bodies in curly braces
    func_block: $ => seq(
      /func\s+.*\{/,     // func signature ending with {
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
    type_block: $ => seq(
      /type\s+\w+\s+(struct|interface)\s*\{/,
      /\s*\n/,  // Require newline after opening brace to distinguish from single-line
      repeat(choice(
        /[^\}][^\n]*\n/,
        /\n/
      )),
      '}'
    ),

    // Single-line type definition (everything else)
    type_line: $ => token(seq('type', /.*/)),

    // Non-empty text line
    text_line: $ => /.+/,
  }
});
