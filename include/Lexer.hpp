#ifndef LEXER
#define LEXER

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept> // For runtime_error



// Enum for Token Types
enum TokenType
{
    TOKEN_EOF,
    ERROR,
    START,

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

    //===== MISC =====
    RETURN,
    IDENTIFIER
};

#define STATES 79
#define ASCII 128

// DFA structure declaration
struct DFA {
    int state_machine[STATES][ASCII];
    TokenType state_token_map[STATES];

    void init_state_token_map();
    void init_state_machine();
    int get_next_state(int current_state, char c);
    TokenType get_token_type(int state);
    void print_state_machine();
};

// Token structure declaration
struct Token {
    TokenType type;
    std::string value;
    int line;
    int column;

    Token(TokenType t, std::string v, int l, int c);
    Token(); // Default constructor
};

// Lexer class declaration
class Lexer {
    private:
        std::ifstream inFile;
        DFA *dfa;

    public:
        Lexer(std::string fName);
        ~Lexer();

        Token get_next_token();
        std::vector<Token> get_tokens_list();
};

#endif