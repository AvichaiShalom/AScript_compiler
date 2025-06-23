#include <iostream>
#include "../include/Lexer.hpp"
#include "../include/error_handler.hpp"
using namespace std;

#define path "C:\\Users\\avich\\Desktop\\AScript_compiler\\AScript_planning\\main.as"

string tokens[] = {
    "EOF",
    "ERROR",
    "START",

    //===== DATA TYPES =====
    "INT",
    "CHAR",
    "VOID",

    //===== LITERALS =====
    "INT_LITERAL",
    "CHAR_LITERAL",
    "STRING_LITERAL",

    //===== OPERATIONS =====
    "EQUAL",
    "PLUS",
    "SUBTRACTION",
    "DIVISION",
    "STAR",
    "MOD",
    "INCREMENT",
    "DECREMENT",

    "PLUS_EQUAL",
    "SUBTRACTION_EQUAL",
    "DIVISION_EQUAL",
    "STAR_EQUAL",
    "MOD_EQUAL",

    //===== SIGNS =====
    "SEMICOLON",
    "AMPERSAND",
    "OPEN_PARENTHESES",
    "CLOSE_PARENTHESES",
    "OPEN_SQUARE_BRACKETS",
    "CLOSE_SQUARE_BRACKETS",
    "OPEN_CURLY_BRACKETS",
    "CLOSE_CURLY_BRACKETS",
    "PIPE",
    "QUESTION_MARK",
    "COLON",
    "COMMA",

    //===== LOOPS / CONDITIONS =====
    "FOR",
    "WHILE",
    "IF",
    "ELSE",

    //===== COMPARISONS =====
    "AND",
    "OR",
    "IS_EQUAL",
    "NOT_EQUAL",
    "GREATER",
    "LESS",
    "GREATER_EQUAL",
    "LESS_EQUAL",
    "NOT",

    //===== BITWISE =====
    "XOR",
    "BITWISE_NOT",
    "XOR_EQUAL",
    "BITWISE_NOT_EQUAL",
    "PIPE_EQUAL",
    "AMPERSAND_EQUAL",

    //===== MISC =====
    "RETURN",
    "IDENTIFIER"
};

void test_lexer_output(const vector<Token>& actual_tokens, const TokenType* expected_tokens, int expected_count) {
    if ((int)actual_tokens.size() != expected_count) {
        cout << "Number of tokens mismatch. Got " << actual_tokens.size() << ", expected " << expected_count << endl;
        return;
    }

    for (int i = 0; i < expected_count; ++i) {
        if (actual_tokens[i].type != expected_tokens[i]) {
            cout << "Mismatch at token #" << i << endl;
            cout << "Expected: " << tokens[expected_tokens[i]]
                 << ", Got: " << tokens[actual_tokens[i].type]
                 << ", Value: '" << actual_tokens[i].value << "'"
                 << ", Line: " << actual_tokens[i].line
                 << ", Column: " << actual_tokens[i].column
                 << endl;
        }
    }

    cout << "Test finished. If no mismatch above, everything is correct." << endl;
}

int main() {
    TokenType expected_tokens[] = {
    //===== DATA TYPES =====
    INT,
    CHAR,
    VOID,

    //===== LITERALS =====
    INT_LITERAL,
    CHAR_LITERAL,
    STRING_LITERAL,

    //===== OPERATIONS =====
    EQUAL,
    PLUS,
    SUBTRACTION,
    DIVISION,
    STAR,
    MOD,
    INCREMENT,
    DECREMENT,

    PLUS_EQUAL,
    SUBTRACTION_EQUAL,
    DIVISION_EQUAL,
    STAR_EQUAL,
    MOD_EQUAL,

    //===== SIGNS =====
    SEMICOLON,
    AMPERSAND,
    OPEN_PARENTHESES,
    CLOSE_PARENTHESES,
    OPEN_SQUARE_BRACKETS,
    CLOSE_SQUARE_BRACKETS,
    OPEN_CURLY_BRACKETS,
    CLOSE_CURLY_BRACKETS,
    PIPE,
    QUESTION_MARK,
    COLON,
    COMMA,

    //===== LOOPS / CONDITIONS =====
    FOR,
    ERROR,
    WHILE,
    IF,
    ELSE,

    //===== COMPARISONS =====
    AND,
    OR,
    IS_EQUAL,
    NOT_EQUAL,
    GREATER,
    LESS,
    GREATER_EQUAL,
    LESS_EQUAL,
    NOT,

    //===== BITWISE =====
    XOR,
    BITWISE_NOT,
    XOR_EQUAL,
    BITWISE_NOT_EQUAL,
    PIPE_EQUAL,
    AMPERSAND_EQUAL,

    ERROR,
    ERROR,

    //===== MISC =====
    RETURN,
    IDENTIFIER,
    TOKEN_EOF
};

    
    Lexer lexer(path);
    vector<Token> tokens_lst = lexer.get_tokens_list();

    int expected_count = sizeof(expected_tokens) / sizeof(expected_tokens[0]);
    test_lexer_output(tokens_lst, expected_tokens, expected_count);
    for (const auto& t : tokens_lst) {
        cout << "Got token: Type = " << tokens[t.type] << ", Value = '" << t.value << "' at Line " << t.line << ", Column " << t.column << endl;
    }

    lexer_error_handler(tokens_lst);

    delete &lexer;
    return 0;
}