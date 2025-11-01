#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 6
#define LARGE_STATE_COUNT 5
#define SYMBOL_COUNT 15
#define ALIAS_COUNT 0
#define TOKEN_COUNT 12
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 2
#define PRODUCTION_ID_COUNT 1

enum ts_symbol_identifiers {
  sym_package_line = 1,
  anon_sym_VARIABLES = 2,
  anon_sym_FUNCTIONS = 3,
  anon_sym_TYPES = 4,
  anon_sym_CONSTANTS = 5,
  anon_sym_DEPRECATED = 6,
  sym_func_line = 7,
  sym_type_line = 8,
  sym_var_line = 9,
  sym_const_line = 10,
  sym_text_line = 11,
  sym_document = 12,
  sym_section_header = 13,
  aux_sym_document_repeat1 = 14,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_package_line] = "package_line",
  [anon_sym_VARIABLES] = "VARIABLES",
  [anon_sym_FUNCTIONS] = "FUNCTIONS",
  [anon_sym_TYPES] = "TYPES",
  [anon_sym_CONSTANTS] = "CONSTANTS",
  [anon_sym_DEPRECATED] = "DEPRECATED",
  [sym_func_line] = "func_line",
  [sym_type_line] = "type_line",
  [sym_var_line] = "var_line",
  [sym_const_line] = "const_line",
  [sym_text_line] = "text_line",
  [sym_document] = "document",
  [sym_section_header] = "section_header",
  [aux_sym_document_repeat1] = "document_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_package_line] = sym_package_line,
  [anon_sym_VARIABLES] = anon_sym_VARIABLES,
  [anon_sym_FUNCTIONS] = anon_sym_FUNCTIONS,
  [anon_sym_TYPES] = anon_sym_TYPES,
  [anon_sym_CONSTANTS] = anon_sym_CONSTANTS,
  [anon_sym_DEPRECATED] = anon_sym_DEPRECATED,
  [sym_func_line] = sym_func_line,
  [sym_type_line] = sym_type_line,
  [sym_var_line] = sym_var_line,
  [sym_const_line] = sym_const_line,
  [sym_text_line] = sym_text_line,
  [sym_document] = sym_document,
  [sym_section_header] = sym_section_header,
  [aux_sym_document_repeat1] = aux_sym_document_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_package_line] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_VARIABLES] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_FUNCTIONS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_TYPES] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_CONSTANTS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DEPRECATED] = {
    .visible = true,
    .named = false,
  },
  [sym_func_line] = {
    .visible = true,
    .named = true,
  },
  [sym_type_line] = {
    .visible = true,
    .named = true,
  },
  [sym_var_line] = {
    .visible = true,
    .named = true,
  },
  [sym_const_line] = {
    .visible = true,
    .named = true,
  },
  [sym_text_line] = {
    .visible = true,
    .named = true,
  },
  [sym_document] = {
    .visible = true,
    .named = true,
  },
  [sym_section_header] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_document_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(1);
      if (lookahead == '\n') SKIP(0);
      if (lookahead == 'C') ADVANCE(33);
      if (lookahead == 'D') ADVANCE(21);
      if (lookahead == 'F') ADVANCE(48);
      if (lookahead == 'T') ADVANCE(49);
      if (lookahead == 'V') ADVANCE(12);
      if (lookahead == 'c') ADVANCE(61);
      if (lookahead == 'f') ADVANCE(66);
      if (lookahead == 'p') ADVANCE(50);
      if (lookahead == 't') ADVANCE(67);
      if (lookahead == 'v') ADVANCE(51);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(17);
      if (lookahead != 0) ADVANCE(68);
      END_STATE();
    case 1:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 2:
      ACCEPT_TOKEN(sym_package_line);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(2);
      END_STATE();
    case 3:
      ACCEPT_TOKEN(anon_sym_VARIABLES);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 4:
      ACCEPT_TOKEN(anon_sym_FUNCTIONS);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 5:
      ACCEPT_TOKEN(anon_sym_TYPES);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 6:
      ACCEPT_TOKEN(anon_sym_CONSTANTS);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(anon_sym_DEPRECATED);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(sym_func_line);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(8);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(sym_type_line);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(9);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(sym_var_line);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(10);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(sym_const_line);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(11);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'A') ADVANCE(37);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'A') ADVANCE(16);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'A') ADVANCE(31);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'A') ADVANCE(47);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'B') ADVANCE(28);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(sym_text_line);
      ADVANCE_MAP(
        'C', 33,
        'D', 21,
        'F', 48,
        'T', 49,
        'V', 12,
        'c', 61,
        'f', 66,
        'p', 50,
        't', 67,
        'v', 51,
      );
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(17);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(68);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'C') ADVANCE(44);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'C') ADVANCE(15);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'D') ADVANCE(7);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'E') ADVANCE(36);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'E') ADVANCE(20);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'E') ADVANCE(40);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'E') ADVANCE(19);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'E') ADVANCE(43);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'I') ADVANCE(13);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'I') ADVANCE(34);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'L') ADVANCE(25);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'N') ADVANCE(39);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'N') ADVANCE(18);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'N') ADVANCE(46);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'N') ADVANCE(42);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'O') ADVANCE(29);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'O') ADVANCE(32);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'P') ADVANCE(23);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'P') ADVANCE(38);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'R') ADVANCE(26);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'R') ADVANCE(24);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'S') ADVANCE(45);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'S') ADVANCE(5);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'S') ADVANCE(6);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'S') ADVANCE(4);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'S') ADVANCE(3);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'T') ADVANCE(27);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'T') ADVANCE(14);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'T') ADVANCE(41);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'T') ADVANCE(22);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'U') ADVANCE(30);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'Y') ADVANCE(35);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'a') ADVANCE(53);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'a') ADVANCE(63);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'a') ADVANCE(57);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'c') ADVANCE(58);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'c') ADVANCE(8);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'e') ADVANCE(9);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'e') ADVANCE(2);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'g') ADVANCE(56);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'k') ADVANCE(52);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'n') ADVANCE(64);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'n') ADVANCE(54);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'o') ADVANCE(59);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'p') ADVANCE(55);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'r') ADVANCE(10);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 's') ADVANCE(65);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 't') ADVANCE(11);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'u') ADVANCE(60);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'y') ADVANCE(62);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_package_line] = ACTIONS(1),
    [anon_sym_VARIABLES] = ACTIONS(1),
    [anon_sym_FUNCTIONS] = ACTIONS(1),
    [anon_sym_TYPES] = ACTIONS(1),
    [anon_sym_CONSTANTS] = ACTIONS(1),
    [anon_sym_DEPRECATED] = ACTIONS(1),
    [sym_func_line] = ACTIONS(1),
    [sym_type_line] = ACTIONS(1),
    [sym_var_line] = ACTIONS(1),
    [sym_const_line] = ACTIONS(1),
    [sym_text_line] = ACTIONS(1),
  },
  [1] = {
    [sym_document] = STATE(5),
    [sym_section_header] = STATE(2),
    [aux_sym_document_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym_package_line] = ACTIONS(5),
    [anon_sym_VARIABLES] = ACTIONS(7),
    [anon_sym_FUNCTIONS] = ACTIONS(7),
    [anon_sym_TYPES] = ACTIONS(7),
    [anon_sym_CONSTANTS] = ACTIONS(7),
    [anon_sym_DEPRECATED] = ACTIONS(7),
    [sym_func_line] = ACTIONS(5),
    [sym_type_line] = ACTIONS(5),
    [sym_var_line] = ACTIONS(5),
    [sym_const_line] = ACTIONS(5),
    [sym_text_line] = ACTIONS(5),
  },
  [2] = {
    [sym_section_header] = STATE(3),
    [aux_sym_document_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(9),
    [sym_package_line] = ACTIONS(11),
    [anon_sym_VARIABLES] = ACTIONS(7),
    [anon_sym_FUNCTIONS] = ACTIONS(7),
    [anon_sym_TYPES] = ACTIONS(7),
    [anon_sym_CONSTANTS] = ACTIONS(7),
    [anon_sym_DEPRECATED] = ACTIONS(7),
    [sym_func_line] = ACTIONS(11),
    [sym_type_line] = ACTIONS(11),
    [sym_var_line] = ACTIONS(11),
    [sym_const_line] = ACTIONS(11),
    [sym_text_line] = ACTIONS(11),
  },
  [3] = {
    [sym_section_header] = STATE(3),
    [aux_sym_document_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(13),
    [sym_package_line] = ACTIONS(15),
    [anon_sym_VARIABLES] = ACTIONS(18),
    [anon_sym_FUNCTIONS] = ACTIONS(18),
    [anon_sym_TYPES] = ACTIONS(18),
    [anon_sym_CONSTANTS] = ACTIONS(18),
    [anon_sym_DEPRECATED] = ACTIONS(18),
    [sym_func_line] = ACTIONS(15),
    [sym_type_line] = ACTIONS(15),
    [sym_var_line] = ACTIONS(15),
    [sym_const_line] = ACTIONS(15),
    [sym_text_line] = ACTIONS(15),
  },
  [4] = {
    [ts_builtin_sym_end] = ACTIONS(21),
    [sym_package_line] = ACTIONS(23),
    [anon_sym_VARIABLES] = ACTIONS(23),
    [anon_sym_FUNCTIONS] = ACTIONS(23),
    [anon_sym_TYPES] = ACTIONS(23),
    [anon_sym_CONSTANTS] = ACTIONS(23),
    [anon_sym_DEPRECATED] = ACTIONS(23),
    [sym_func_line] = ACTIONS(23),
    [sym_type_line] = ACTIONS(23),
    [sym_var_line] = ACTIONS(23),
    [sym_const_line] = ACTIONS(23),
    [sym_text_line] = ACTIONS(23),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 1,
    ACTIONS(25), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(5)] = 0,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [9] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 1, 0, 0),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [13] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0),
  [15] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(3),
  [18] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(4),
  [21] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_section_header, 1, 0, 0),
  [23] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_section_header, 1, 0, 0),
  [25] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_godoc(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
