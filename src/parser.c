#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 21
#define LARGE_STATE_COUNT 11
#define SYMBOL_COUNT 29
#define ALIAS_COUNT 0
#define TOKEN_COUNT 21
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 4
#define PRODUCTION_ID_COUNT 1

enum ts_symbol_identifiers {
  sym_package_line = 1,
  anon_sym_VARIABLES = 2,
  anon_sym_FUNCTIONS = 3,
  anon_sym_TYPES = 4,
  anon_sym_CONSTANTS = 5,
  anon_sym_DEPRECATED = 6,
  sym_func_line = 7,
  aux_sym_var_block_token1 = 8,
  aux_sym_var_block_token2 = 9,
  aux_sym_var_block_token3 = 10,
  anon_sym_RPAREN = 11,
  sym_var_line = 12,
  aux_sym_const_block_token1 = 13,
  sym_const_line = 14,
  aux_sym_type_block_token1 = 15,
  aux_sym_type_block_token2 = 16,
  aux_sym_type_block_token3 = 17,
  anon_sym_RBRACE = 18,
  sym_type_line = 19,
  sym_text_line = 20,
  sym_document = 21,
  sym_section_header = 22,
  sym_var_block = 23,
  sym_const_block = 24,
  sym_type_block = 25,
  aux_sym_document_repeat1 = 26,
  aux_sym_var_block_repeat1 = 27,
  aux_sym_type_block_repeat1 = 28,
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
  [aux_sym_var_block_token1] = "var_block_token1",
  [aux_sym_var_block_token2] = "var_block_token2",
  [aux_sym_var_block_token3] = "var_block_token3",
  [anon_sym_RPAREN] = ")",
  [sym_var_line] = "var_line",
  [aux_sym_const_block_token1] = "const_block_token1",
  [sym_const_line] = "const_line",
  [aux_sym_type_block_token1] = "type_block_token1",
  [aux_sym_type_block_token2] = "type_block_token2",
  [aux_sym_type_block_token3] = "type_block_token3",
  [anon_sym_RBRACE] = "}",
  [sym_type_line] = "type_line",
  [sym_text_line] = "text_line",
  [sym_document] = "document",
  [sym_section_header] = "section_header",
  [sym_var_block] = "var_block",
  [sym_const_block] = "const_block",
  [sym_type_block] = "type_block",
  [aux_sym_document_repeat1] = "document_repeat1",
  [aux_sym_var_block_repeat1] = "var_block_repeat1",
  [aux_sym_type_block_repeat1] = "type_block_repeat1",
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
  [aux_sym_var_block_token1] = aux_sym_var_block_token1,
  [aux_sym_var_block_token2] = aux_sym_var_block_token2,
  [aux_sym_var_block_token3] = aux_sym_var_block_token3,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [sym_var_line] = sym_var_line,
  [aux_sym_const_block_token1] = aux_sym_const_block_token1,
  [sym_const_line] = sym_const_line,
  [aux_sym_type_block_token1] = aux_sym_type_block_token1,
  [aux_sym_type_block_token2] = aux_sym_type_block_token2,
  [aux_sym_type_block_token3] = aux_sym_type_block_token3,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [sym_type_line] = sym_type_line,
  [sym_text_line] = sym_text_line,
  [sym_document] = sym_document,
  [sym_section_header] = sym_section_header,
  [sym_var_block] = sym_var_block,
  [sym_const_block] = sym_const_block,
  [sym_type_block] = sym_type_block,
  [aux_sym_document_repeat1] = aux_sym_document_repeat1,
  [aux_sym_var_block_repeat1] = aux_sym_var_block_repeat1,
  [aux_sym_type_block_repeat1] = aux_sym_type_block_repeat1,
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
  [aux_sym_var_block_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_var_block_token2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_var_block_token3] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [sym_var_line] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_const_block_token1] = {
    .visible = false,
    .named = false,
  },
  [sym_const_line] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_type_block_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_type_block_token2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_type_block_token3] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [sym_type_line] = {
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
  [sym_var_block] = {
    .visible = true,
    .named = true,
  },
  [sym_const_block] = {
    .visible = true,
    .named = true,
  },
  [sym_type_block] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_document_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_var_block_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_type_block_repeat1] = {
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
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(85);
      ADVANCE_MAP(
        ')', 105,
        'C', 32,
        'D', 20,
        'F', 47,
        'T', 48,
        'V', 12,
        'c', 68,
        'f', 78,
        'p', 49,
        't', 80,
        'v', 50,
        '}', 118,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(1);
      if (lookahead == '(') ADVANCE(98);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(107);
      if (lookahead != 0) ADVANCE(108);
      END_STATE();
    case 2:
      if (lookahead == '\n') ADVANCE(103);
      if (lookahead == ')') ADVANCE(105);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(3);
      if (lookahead != 0) ADVANCE(4);
      END_STATE();
    case 3:
      if (lookahead == '\n') ADVANCE(102);
      if (lookahead == ')') ADVANCE(106);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(3);
      if (lookahead != 0) ADVANCE(4);
      END_STATE();
    case 4:
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead != 0) ADVANCE(4);
      END_STATE();
    case 5:
      if (lookahead == '\n') ADVANCE(117);
      if (lookahead != 0) ADVANCE(5);
      END_STATE();
    case 6:
      if (lookahead == '\n') ADVANCE(116);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(6);
      END_STATE();
    case 7:
      if (lookahead == '\n') ADVANCE(7);
      if (lookahead == '(') ADVANCE(109);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(112);
      if (lookahead != 0) ADVANCE(113);
      END_STATE();
    case 8:
      if (lookahead == '\n') ADVANCE(104);
      if (lookahead == '}') ADVANCE(118);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(9);
      if (lookahead != 0) ADVANCE(5);
      END_STATE();
    case 9:
      if (lookahead == '\n') ADVANCE(104);
      if (lookahead == '}') ADVANCE(119);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(9);
      if (lookahead != 0) ADVANCE(5);
      END_STATE();
    case 10:
      if (lookahead == '(') ADVANCE(98);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(1);
      END_STATE();
    case 11:
      if (lookahead == '(') ADVANCE(109);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(7);
      END_STATE();
    case 12:
      if (lookahead == 'A') ADVANCE(36);
      END_STATE();
    case 13:
      if (lookahead == 'A') ADVANCE(16);
      END_STATE();
    case 14:
      if (lookahead == 'A') ADVANCE(30);
      END_STATE();
    case 15:
      if (lookahead == 'A') ADVANCE(46);
      END_STATE();
    case 16:
      if (lookahead == 'B') ADVANCE(27);
      END_STATE();
    case 17:
      if (lookahead == 'C') ADVANCE(43);
      END_STATE();
    case 18:
      if (lookahead == 'C') ADVANCE(15);
      END_STATE();
    case 19:
      if (lookahead == 'D') ADVANCE(95);
      END_STATE();
    case 20:
      if (lookahead == 'E') ADVANCE(35);
      END_STATE();
    case 21:
      if (lookahead == 'E') ADVANCE(19);
      END_STATE();
    case 22:
      if (lookahead == 'E') ADVANCE(39);
      END_STATE();
    case 23:
      if (lookahead == 'E') ADVANCE(18);
      END_STATE();
    case 24:
      if (lookahead == 'E') ADVANCE(42);
      END_STATE();
    case 25:
      if (lookahead == 'I') ADVANCE(13);
      END_STATE();
    case 26:
      if (lookahead == 'I') ADVANCE(33);
      END_STATE();
    case 27:
      if (lookahead == 'L') ADVANCE(24);
      END_STATE();
    case 28:
      if (lookahead == 'N') ADVANCE(38);
      END_STATE();
    case 29:
      if (lookahead == 'N') ADVANCE(17);
      END_STATE();
    case 30:
      if (lookahead == 'N') ADVANCE(45);
      END_STATE();
    case 31:
      if (lookahead == 'N') ADVANCE(41);
      END_STATE();
    case 32:
      if (lookahead == 'O') ADVANCE(28);
      END_STATE();
    case 33:
      if (lookahead == 'O') ADVANCE(31);
      END_STATE();
    case 34:
      if (lookahead == 'P') ADVANCE(22);
      END_STATE();
    case 35:
      if (lookahead == 'P') ADVANCE(37);
      END_STATE();
    case 36:
      if (lookahead == 'R') ADVANCE(25);
      END_STATE();
    case 37:
      if (lookahead == 'R') ADVANCE(23);
      END_STATE();
    case 38:
      if (lookahead == 'S') ADVANCE(44);
      END_STATE();
    case 39:
      if (lookahead == 'S') ADVANCE(91);
      END_STATE();
    case 40:
      if (lookahead == 'S') ADVANCE(93);
      END_STATE();
    case 41:
      if (lookahead == 'S') ADVANCE(89);
      END_STATE();
    case 42:
      if (lookahead == 'S') ADVANCE(87);
      END_STATE();
    case 43:
      if (lookahead == 'T') ADVANCE(26);
      END_STATE();
    case 44:
      if (lookahead == 'T') ADVANCE(14);
      END_STATE();
    case 45:
      if (lookahead == 'T') ADVANCE(40);
      END_STATE();
    case 46:
      if (lookahead == 'T') ADVANCE(21);
      END_STATE();
    case 47:
      if (lookahead == 'U') ADVANCE(29);
      END_STATE();
    case 48:
      if (lookahead == 'Y') ADVANCE(34);
      END_STATE();
    case 49:
      if (lookahead == 'a') ADVANCE(53);
      END_STATE();
    case 50:
      if (lookahead == 'a') ADVANCE(70);
      END_STATE();
    case 51:
      if (lookahead == 'a') ADVANCE(62);
      END_STATE();
    case 52:
      if (lookahead == 'a') ADVANCE(55);
      END_STATE();
    case 53:
      if (lookahead == 'c') ADVANCE(64);
      END_STATE();
    case 54:
      if (lookahead == 'c') ADVANCE(97);
      END_STATE();
    case 55:
      if (lookahead == 'c') ADVANCE(59);
      END_STATE();
    case 56:
      if (lookahead == 'c') ADVANCE(74);
      END_STATE();
    case 57:
      if (lookahead == 'e') ADVANCE(121);
      END_STATE();
    case 58:
      if (lookahead == 'e') ADVANCE(86);
      END_STATE();
    case 59:
      if (lookahead == 'e') ADVANCE(81);
      END_STATE();
    case 60:
      if (lookahead == 'e') ADVANCE(71);
      END_STATE();
    case 61:
      if (lookahead == 'f') ADVANCE(52);
      END_STATE();
    case 62:
      if (lookahead == 'g') ADVANCE(58);
      END_STATE();
    case 63:
      if (lookahead == 'i') ADVANCE(67);
      if (lookahead == 's') ADVANCE(75);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(63);
      END_STATE();
    case 64:
      if (lookahead == 'k') ADVANCE(51);
      END_STATE();
    case 65:
      if (lookahead == 'n') ADVANCE(73);
      END_STATE();
    case 66:
      if (lookahead == 'n') ADVANCE(54);
      END_STATE();
    case 67:
      if (lookahead == 'n') ADVANCE(77);
      END_STATE();
    case 68:
      if (lookahead == 'o') ADVANCE(65);
      END_STATE();
    case 69:
      if (lookahead == 'p') ADVANCE(57);
      END_STATE();
    case 70:
      if (lookahead == 'r') ADVANCE(10);
      END_STATE();
    case 71:
      if (lookahead == 'r') ADVANCE(61);
      END_STATE();
    case 72:
      if (lookahead == 'r') ADVANCE(79);
      END_STATE();
    case 73:
      if (lookahead == 's') ADVANCE(76);
      END_STATE();
    case 74:
      if (lookahead == 't') ADVANCE(81);
      END_STATE();
    case 75:
      if (lookahead == 't') ADVANCE(72);
      END_STATE();
    case 76:
      if (lookahead == 't') ADVANCE(11);
      END_STATE();
    case 77:
      if (lookahead == 't') ADVANCE(60);
      END_STATE();
    case 78:
      if (lookahead == 'u') ADVANCE(66);
      END_STATE();
    case 79:
      if (lookahead == 'u') ADVANCE(56);
      END_STATE();
    case 80:
      if (lookahead == 'y') ADVANCE(69);
      END_STATE();
    case 81:
      if (lookahead == '{') ADVANCE(114);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(81);
      END_STATE();
    case 82:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(82);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 83:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(63);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(83);
      END_STATE();
    case 84:
      if (eof) ADVANCE(85);
      if (lookahead == '\n') SKIP(84);
      if (lookahead == 'C') ADVANCE(164);
      if (lookahead == 'D') ADVANCE(152);
      if (lookahead == 'F') ADVANCE(179);
      if (lookahead == 'T') ADVANCE(180);
      if (lookahead == 'V') ADVANCE(143);
      if (lookahead == 'c') ADVANCE(192);
      if (lookahead == 'f') ADVANCE(197);
      if (lookahead == 'p') ADVANCE(181);
      if (lookahead == 't') ADVANCE(198);
      if (lookahead == 'v') ADVANCE(182);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(148);
      if (lookahead != 0) ADVANCE(199);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(sym_package_line);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(86);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(anon_sym_VARIABLES);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(anon_sym_VARIABLES);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(anon_sym_FUNCTIONS);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(anon_sym_FUNCTIONS);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(anon_sym_TYPES);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(anon_sym_TYPES);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(anon_sym_CONSTANTS);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(anon_sym_CONSTANTS);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(anon_sym_DEPRECATED);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(anon_sym_DEPRECATED);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(sym_func_line);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(97);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(aux_sym_var_block_token1);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(aux_sym_var_block_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(108);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(aux_sym_var_block_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(aux_sym_var_block_token2);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(aux_sym_var_block_token2);
      if (lookahead == '\n') ADVANCE(102);
      if (lookahead == ')') ADVANCE(106);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(3);
      if (lookahead != 0) ADVANCE(4);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(aux_sym_var_block_token3);
      if (lookahead == '\n') ADVANCE(102);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(3);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(aux_sym_var_block_token3);
      if (lookahead == '\n') ADVANCE(104);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(9);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead != 0) ADVANCE(4);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(sym_var_line);
      if (lookahead == '\n') ADVANCE(1);
      if (lookahead == '(') ADVANCE(99);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(107);
      if (lookahead != 0) ADVANCE(108);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(sym_var_line);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(108);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(aux_sym_const_block_token1);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(aux_sym_const_block_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(113);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(aux_sym_const_block_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(sym_const_line);
      if (lookahead == '\n') ADVANCE(7);
      if (lookahead == '(') ADVANCE(110);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(112);
      if (lookahead != 0) ADVANCE(113);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(sym_const_line);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(113);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(aux_sym_type_block_token1);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(aux_sym_type_block_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(138);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(aux_sym_type_block_token2);
      if (lookahead == '\n') ADVANCE(116);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(6);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(aux_sym_type_block_token3);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      if (lookahead == '\n') ADVANCE(117);
      if (lookahead != 0) ADVANCE(5);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(sym_type_line);
      if (lookahead == '\n') ADVANCE(82);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(120);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(123);
      if (lookahead != 0) ADVANCE(138);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(sym_type_line);
      if (lookahead == '\n') ADVANCE(82);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(120);
      if (lookahead != 0) ADVANCE(138);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(sym_type_line);
      if (lookahead == '\n') ADVANCE(63);
      if (lookahead == 'i') ADVANCE(131);
      if (lookahead == 's') ADVANCE(134);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(122);
      if (lookahead != 0) ADVANCE(138);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(sym_type_line);
      if (lookahead == '\n') ADVANCE(63);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(122);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(123);
      if (lookahead != 0) ADVANCE(138);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(sym_type_line);
      if (lookahead == '\n') ADVANCE(81);
      if (lookahead == '{') ADVANCE(115);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(124);
      if (lookahead != 0) ADVANCE(138);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(sym_type_line);
      if (lookahead == 'a') ADVANCE(126);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(138);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(sym_type_line);
      if (lookahead == 'c') ADVANCE(128);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(138);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(sym_type_line);
      if (lookahead == 'c') ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(138);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(sym_type_line);
      if (lookahead == 'e') ADVANCE(124);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(138);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(sym_type_line);
      if (lookahead == 'e') ADVANCE(133);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(138);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(sym_type_line);
      if (lookahead == 'f') ADVANCE(125);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(138);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(sym_type_line);
      if (lookahead == 'n') ADVANCE(135);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(138);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(sym_type_line);
      if (lookahead == 'r') ADVANCE(137);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(138);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(sym_type_line);
      if (lookahead == 'r') ADVANCE(130);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(138);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(sym_type_line);
      if (lookahead == 't') ADVANCE(132);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(138);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(sym_type_line);
      if (lookahead == 't') ADVANCE(129);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(138);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(sym_type_line);
      if (lookahead == 't') ADVANCE(124);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(138);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(sym_type_line);
      if (lookahead == 'u') ADVANCE(127);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(138);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(sym_type_line);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(138);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == '\n') ADVANCE(1);
      if (lookahead == '(') ADVANCE(100);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(107);
      if (lookahead != 0) ADVANCE(108);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == '\n') ADVANCE(1);
      if (lookahead == '(') ADVANCE(100);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(139);
      if (lookahead != 0) ADVANCE(199);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == '\n') ADVANCE(7);
      if (lookahead == '(') ADVANCE(111);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(112);
      if (lookahead != 0) ADVANCE(113);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == '\n') ADVANCE(7);
      if (lookahead == '(') ADVANCE(111);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(141);
      if (lookahead != 0) ADVANCE(199);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'A') ADVANCE(168);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'A') ADVANCE(147);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'A') ADVANCE(162);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'A') ADVANCE(178);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'B') ADVANCE(159);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(sym_text_line);
      ADVANCE_MAP(
        'C', 164,
        'D', 152,
        'F', 179,
        'T', 180,
        'V', 143,
        'c', 192,
        'f', 197,
        'p', 181,
        't', 198,
        'v', 182,
      );
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(148);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(199);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'C') ADVANCE(175);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'C') ADVANCE(146);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'D') ADVANCE(96);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'E') ADVANCE(167);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'E') ADVANCE(151);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'E') ADVANCE(171);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'E') ADVANCE(150);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'E') ADVANCE(174);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'I') ADVANCE(144);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'I') ADVANCE(165);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'L') ADVANCE(156);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'N') ADVANCE(170);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'N') ADVANCE(149);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'N') ADVANCE(177);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'N') ADVANCE(173);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'O') ADVANCE(160);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'O') ADVANCE(163);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'P') ADVANCE(154);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'P') ADVANCE(169);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'R') ADVANCE(157);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'R') ADVANCE(155);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'S') ADVANCE(176);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'S') ADVANCE(92);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'S') ADVANCE(94);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'S') ADVANCE(90);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'S') ADVANCE(88);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'T') ADVANCE(158);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'T') ADVANCE(145);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'T') ADVANCE(172);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'T') ADVANCE(153);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'U') ADVANCE(161);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'Y') ADVANCE(166);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'a') ADVANCE(185);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'a') ADVANCE(194);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'a') ADVANCE(188);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'c') ADVANCE(97);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'c') ADVANCE(189);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'e') ADVANCE(121);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'e') ADVANCE(86);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'g') ADVANCE(187);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'k') ADVANCE(183);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'n') ADVANCE(195);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'n') ADVANCE(184);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'o') ADVANCE(190);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'p') ADVANCE(186);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'r') ADVANCE(140);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 's') ADVANCE(196);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 't') ADVANCE(142);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'u') ADVANCE(191);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead == 'y') ADVANCE(193);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(sym_text_line);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 84},
  [2] = {.lex_state = 84},
  [3] = {.lex_state = 84},
  [4] = {.lex_state = 84},
  [5] = {.lex_state = 84},
  [6] = {.lex_state = 84},
  [7] = {.lex_state = 84},
  [8] = {.lex_state = 84},
  [9] = {.lex_state = 84},
  [10] = {.lex_state = 84},
  [11] = {.lex_state = 2},
  [12] = {.lex_state = 8},
  [13] = {.lex_state = 2},
  [14] = {.lex_state = 2},
  [15] = {.lex_state = 2},
  [16] = {.lex_state = 8},
  [17] = {.lex_state = 2},
  [18] = {.lex_state = 8},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 6},
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
    [aux_sym_var_block_token1] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [sym_var_line] = ACTIONS(1),
    [aux_sym_const_block_token1] = ACTIONS(1),
    [sym_const_line] = ACTIONS(1),
    [aux_sym_type_block_token1] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [sym_type_line] = ACTIONS(1),
  },
  [1] = {
    [sym_document] = STATE(19),
    [sym_section_header] = STATE(3),
    [sym_var_block] = STATE(3),
    [sym_const_block] = STATE(3),
    [sym_type_block] = STATE(3),
    [aux_sym_document_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym_package_line] = ACTIONS(5),
    [anon_sym_VARIABLES] = ACTIONS(7),
    [anon_sym_FUNCTIONS] = ACTIONS(7),
    [anon_sym_TYPES] = ACTIONS(7),
    [anon_sym_CONSTANTS] = ACTIONS(7),
    [anon_sym_DEPRECATED] = ACTIONS(7),
    [sym_func_line] = ACTIONS(5),
    [aux_sym_var_block_token1] = ACTIONS(9),
    [sym_var_line] = ACTIONS(5),
    [aux_sym_const_block_token1] = ACTIONS(11),
    [sym_const_line] = ACTIONS(5),
    [aux_sym_type_block_token1] = ACTIONS(13),
    [sym_type_line] = ACTIONS(5),
    [sym_text_line] = ACTIONS(5),
  },
  [2] = {
    [sym_section_header] = STATE(2),
    [sym_var_block] = STATE(2),
    [sym_const_block] = STATE(2),
    [sym_type_block] = STATE(2),
    [aux_sym_document_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(15),
    [sym_package_line] = ACTIONS(17),
    [anon_sym_VARIABLES] = ACTIONS(20),
    [anon_sym_FUNCTIONS] = ACTIONS(20),
    [anon_sym_TYPES] = ACTIONS(20),
    [anon_sym_CONSTANTS] = ACTIONS(20),
    [anon_sym_DEPRECATED] = ACTIONS(20),
    [sym_func_line] = ACTIONS(17),
    [aux_sym_var_block_token1] = ACTIONS(23),
    [sym_var_line] = ACTIONS(17),
    [aux_sym_const_block_token1] = ACTIONS(26),
    [sym_const_line] = ACTIONS(17),
    [aux_sym_type_block_token1] = ACTIONS(29),
    [sym_type_line] = ACTIONS(17),
    [sym_text_line] = ACTIONS(17),
  },
  [3] = {
    [sym_section_header] = STATE(2),
    [sym_var_block] = STATE(2),
    [sym_const_block] = STATE(2),
    [sym_type_block] = STATE(2),
    [aux_sym_document_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(32),
    [sym_package_line] = ACTIONS(34),
    [anon_sym_VARIABLES] = ACTIONS(7),
    [anon_sym_FUNCTIONS] = ACTIONS(7),
    [anon_sym_TYPES] = ACTIONS(7),
    [anon_sym_CONSTANTS] = ACTIONS(7),
    [anon_sym_DEPRECATED] = ACTIONS(7),
    [sym_func_line] = ACTIONS(34),
    [aux_sym_var_block_token1] = ACTIONS(9),
    [sym_var_line] = ACTIONS(34),
    [aux_sym_const_block_token1] = ACTIONS(11),
    [sym_const_line] = ACTIONS(34),
    [aux_sym_type_block_token1] = ACTIONS(13),
    [sym_type_line] = ACTIONS(34),
    [sym_text_line] = ACTIONS(34),
  },
  [4] = {
    [ts_builtin_sym_end] = ACTIONS(36),
    [sym_package_line] = ACTIONS(38),
    [anon_sym_VARIABLES] = ACTIONS(38),
    [anon_sym_FUNCTIONS] = ACTIONS(38),
    [anon_sym_TYPES] = ACTIONS(38),
    [anon_sym_CONSTANTS] = ACTIONS(38),
    [anon_sym_DEPRECATED] = ACTIONS(38),
    [sym_func_line] = ACTIONS(38),
    [aux_sym_var_block_token1] = ACTIONS(38),
    [sym_var_line] = ACTIONS(38),
    [aux_sym_const_block_token1] = ACTIONS(38),
    [sym_const_line] = ACTIONS(38),
    [aux_sym_type_block_token1] = ACTIONS(38),
    [sym_type_line] = ACTIONS(38),
    [sym_text_line] = ACTIONS(38),
  },
  [5] = {
    [ts_builtin_sym_end] = ACTIONS(40),
    [sym_package_line] = ACTIONS(42),
    [anon_sym_VARIABLES] = ACTIONS(42),
    [anon_sym_FUNCTIONS] = ACTIONS(42),
    [anon_sym_TYPES] = ACTIONS(42),
    [anon_sym_CONSTANTS] = ACTIONS(42),
    [anon_sym_DEPRECATED] = ACTIONS(42),
    [sym_func_line] = ACTIONS(42),
    [aux_sym_var_block_token1] = ACTIONS(42),
    [sym_var_line] = ACTIONS(42),
    [aux_sym_const_block_token1] = ACTIONS(42),
    [sym_const_line] = ACTIONS(42),
    [aux_sym_type_block_token1] = ACTIONS(42),
    [sym_type_line] = ACTIONS(42),
    [sym_text_line] = ACTIONS(42),
  },
  [6] = {
    [ts_builtin_sym_end] = ACTIONS(44),
    [sym_package_line] = ACTIONS(46),
    [anon_sym_VARIABLES] = ACTIONS(46),
    [anon_sym_FUNCTIONS] = ACTIONS(46),
    [anon_sym_TYPES] = ACTIONS(46),
    [anon_sym_CONSTANTS] = ACTIONS(46),
    [anon_sym_DEPRECATED] = ACTIONS(46),
    [sym_func_line] = ACTIONS(46),
    [aux_sym_var_block_token1] = ACTIONS(46),
    [sym_var_line] = ACTIONS(46),
    [aux_sym_const_block_token1] = ACTIONS(46),
    [sym_const_line] = ACTIONS(46),
    [aux_sym_type_block_token1] = ACTIONS(46),
    [sym_type_line] = ACTIONS(46),
    [sym_text_line] = ACTIONS(46),
  },
  [7] = {
    [ts_builtin_sym_end] = ACTIONS(48),
    [sym_package_line] = ACTIONS(50),
    [anon_sym_VARIABLES] = ACTIONS(50),
    [anon_sym_FUNCTIONS] = ACTIONS(50),
    [anon_sym_TYPES] = ACTIONS(50),
    [anon_sym_CONSTANTS] = ACTIONS(50),
    [anon_sym_DEPRECATED] = ACTIONS(50),
    [sym_func_line] = ACTIONS(50),
    [aux_sym_var_block_token1] = ACTIONS(50),
    [sym_var_line] = ACTIONS(50),
    [aux_sym_const_block_token1] = ACTIONS(50),
    [sym_const_line] = ACTIONS(50),
    [aux_sym_type_block_token1] = ACTIONS(50),
    [sym_type_line] = ACTIONS(50),
    [sym_text_line] = ACTIONS(50),
  },
  [8] = {
    [ts_builtin_sym_end] = ACTIONS(52),
    [sym_package_line] = ACTIONS(54),
    [anon_sym_VARIABLES] = ACTIONS(54),
    [anon_sym_FUNCTIONS] = ACTIONS(54),
    [anon_sym_TYPES] = ACTIONS(54),
    [anon_sym_CONSTANTS] = ACTIONS(54),
    [anon_sym_DEPRECATED] = ACTIONS(54),
    [sym_func_line] = ACTIONS(54),
    [aux_sym_var_block_token1] = ACTIONS(54),
    [sym_var_line] = ACTIONS(54),
    [aux_sym_const_block_token1] = ACTIONS(54),
    [sym_const_line] = ACTIONS(54),
    [aux_sym_type_block_token1] = ACTIONS(54),
    [sym_type_line] = ACTIONS(54),
    [sym_text_line] = ACTIONS(54),
  },
  [9] = {
    [ts_builtin_sym_end] = ACTIONS(56),
    [sym_package_line] = ACTIONS(58),
    [anon_sym_VARIABLES] = ACTIONS(58),
    [anon_sym_FUNCTIONS] = ACTIONS(58),
    [anon_sym_TYPES] = ACTIONS(58),
    [anon_sym_CONSTANTS] = ACTIONS(58),
    [anon_sym_DEPRECATED] = ACTIONS(58),
    [sym_func_line] = ACTIONS(58),
    [aux_sym_var_block_token1] = ACTIONS(58),
    [sym_var_line] = ACTIONS(58),
    [aux_sym_const_block_token1] = ACTIONS(58),
    [sym_const_line] = ACTIONS(58),
    [aux_sym_type_block_token1] = ACTIONS(58),
    [sym_type_line] = ACTIONS(58),
    [sym_text_line] = ACTIONS(58),
  },
  [10] = {
    [ts_builtin_sym_end] = ACTIONS(60),
    [sym_package_line] = ACTIONS(62),
    [anon_sym_VARIABLES] = ACTIONS(62),
    [anon_sym_FUNCTIONS] = ACTIONS(62),
    [anon_sym_TYPES] = ACTIONS(62),
    [anon_sym_CONSTANTS] = ACTIONS(62),
    [anon_sym_DEPRECATED] = ACTIONS(62),
    [sym_func_line] = ACTIONS(62),
    [aux_sym_var_block_token1] = ACTIONS(62),
    [sym_var_line] = ACTIONS(62),
    [aux_sym_const_block_token1] = ACTIONS(62),
    [sym_const_line] = ACTIONS(62),
    [aux_sym_type_block_token1] = ACTIONS(62),
    [sym_type_line] = ACTIONS(62),
    [sym_text_line] = ACTIONS(62),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 3,
    ACTIONS(67), 1,
      anon_sym_RPAREN,
    STATE(11), 1,
      aux_sym_var_block_repeat1,
    ACTIONS(64), 2,
      aux_sym_var_block_token2,
      aux_sym_var_block_token3,
  [11] = 3,
    ACTIONS(71), 1,
      anon_sym_RBRACE,
    STATE(16), 1,
      aux_sym_type_block_repeat1,
    ACTIONS(69), 2,
      aux_sym_var_block_token3,
      aux_sym_type_block_token3,
  [22] = 3,
    ACTIONS(75), 1,
      anon_sym_RPAREN,
    STATE(11), 1,
      aux_sym_var_block_repeat1,
    ACTIONS(73), 2,
      aux_sym_var_block_token2,
      aux_sym_var_block_token3,
  [33] = 3,
    ACTIONS(79), 1,
      anon_sym_RPAREN,
    STATE(15), 1,
      aux_sym_var_block_repeat1,
    ACTIONS(77), 2,
      aux_sym_var_block_token2,
      aux_sym_var_block_token3,
  [44] = 3,
    ACTIONS(81), 1,
      anon_sym_RPAREN,
    STATE(11), 1,
      aux_sym_var_block_repeat1,
    ACTIONS(73), 2,
      aux_sym_var_block_token2,
      aux_sym_var_block_token3,
  [55] = 3,
    ACTIONS(85), 1,
      anon_sym_RBRACE,
    STATE(18), 1,
      aux_sym_type_block_repeat1,
    ACTIONS(83), 2,
      aux_sym_var_block_token3,
      aux_sym_type_block_token3,
  [66] = 3,
    ACTIONS(89), 1,
      anon_sym_RPAREN,
    STATE(13), 1,
      aux_sym_var_block_repeat1,
    ACTIONS(87), 2,
      aux_sym_var_block_token2,
      aux_sym_var_block_token3,
  [77] = 3,
    ACTIONS(94), 1,
      anon_sym_RBRACE,
    STATE(18), 1,
      aux_sym_type_block_repeat1,
    ACTIONS(91), 2,
      aux_sym_var_block_token3,
      aux_sym_type_block_token3,
  [88] = 1,
    ACTIONS(96), 1,
      ts_builtin_sym_end,
  [92] = 1,
    ACTIONS(98), 1,
      aux_sym_type_block_token2,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(11)] = 0,
  [SMALL_STATE(12)] = 11,
  [SMALL_STATE(13)] = 22,
  [SMALL_STATE(14)] = 33,
  [SMALL_STATE(15)] = 44,
  [SMALL_STATE(16)] = 55,
  [SMALL_STATE(17)] = 66,
  [SMALL_STATE(18)] = 77,
  [SMALL_STATE(19)] = 88,
  [SMALL_STATE(20)] = 92,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(17),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(20),
  [15] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0),
  [17] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(2),
  [20] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(4),
  [23] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(14),
  [26] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(17),
  [29] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(20),
  [32] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 1, 0, 0),
  [34] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [36] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_section_header, 1, 0, 0),
  [38] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_section_header, 1, 0, 0),
  [40] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_block, 4, 0, 0),
  [42] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_type_block, 4, 0, 0),
  [44] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_block, 3, 0, 0),
  [46] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_type_block, 3, 0, 0),
  [48] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_const_block, 3, 0, 0),
  [50] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_const_block, 3, 0, 0),
  [52] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_var_block, 2, 0, 0),
  [54] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_var_block, 2, 0, 0),
  [56] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_var_block, 3, 0, 0),
  [58] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_var_block, 3, 0, 0),
  [60] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_const_block, 2, 0, 0),
  [62] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_const_block, 2, 0, 0),
  [64] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_var_block_repeat1, 2, 0, 0), SHIFT_REPEAT(11),
  [67] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_var_block_repeat1, 2, 0, 0),
  [69] = {.entry = {.count = 1, .reusable = false}}, SHIFT(16),
  [71] = {.entry = {.count = 1, .reusable = false}}, SHIFT(6),
  [73] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [75] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [77] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [79] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [81] = {.entry = {.count = 1, .reusable = false}}, SHIFT(9),
  [83] = {.entry = {.count = 1, .reusable = false}}, SHIFT(18),
  [85] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [87] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [89] = {.entry = {.count = 1, .reusable = false}}, SHIFT(10),
  [91] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_type_block_repeat1, 2, 0, 0), SHIFT_REPEAT(18),
  [94] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_type_block_repeat1, 2, 0, 0),
  [96] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [98] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
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
