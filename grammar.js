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
        $.func_line,
        $.type_line,
        $.var_line,
        $.const_line,
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

    // Function signature - capture whole line starting with "func"
    func_line: $ => token(seq('func', /.*/)),

    // Type definition - capture whole line starting with "type"
    type_line: $ => token(seq('type', /.*/)),

    // Variable declaration - capture whole line starting with "var"
    var_line: $ => token(seq('var', /.*/)),

    // Constant declaration - capture whole line starting with "const"
    const_line: $ => token(seq('const', /.*/)),

    // Non-empty text line
    text_line: $ => /.+/,
  }
});
