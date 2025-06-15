#include <iostream>
#include "../include/Lexer.hpp"
using namespace std;

#define path "C:\\Users\\avich\\Desktop\\AScript_compiler\\AScript_planning\\main.as"


int main() {
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

    DFA dfa;
    dfa.init_state_machine();
    dfa.init_state_token_map();
    cout<< "===========================================" << endl;
    cout << dfa.state_machine[0]['='] << endl;
    cout << dfa.state_machine[1][' '] << endl;
    cout<< "===========================================" << endl;
    Lexer lexer(path);
    Token token;
    token.type = START;
    while(token.type != ERROR && token.type != TOKEN_EOF) {
        token = lexer.get_next_token();
        cout << tokens[token.type] << ": " << token.value << endl;
    }
    return 0;
}