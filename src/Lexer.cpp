#include <iostream>
#include <fstream>
using namespace std;
#define STATES 78
#define ASCII 128

enum TokenType
{
    ERROR,

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


//ליצור בהיפ ולשמור פיינטר
struct DFA {
    int state_machine[STATES][ASCII];
    TokenType state_token_map[STATES];

    void init_state_token_map() {
        state_token_map[0] = ERROR;
        state_token_map[1] = EQUAL;
        state_token_map[2] = IS_EQUAL;
        state_token_map[3] = PLUS;
        state_token_map[4] = PLUS_EQUAL;
        state_token_map[5] = INCREMENT;
        state_token_map[6] = SUBTRACTION;
        state_token_map[7] = DECREMENT;
        state_token_map[8] = SUBTRACTION_EQUAL;
        state_token_map[9] = DIVISION;
        state_token_map[10] = DIVISION_EQUAL;
        state_token_map[11] = MOD;
        state_token_map[12] = MOD_EQUAL;
        state_token_map[13] = STAR;
        state_token_map[14] = STAR_EQUAL;
        state_token_map[15] = SEMICOLON;
        state_token_map[16] = AMPERSAND;
        state_token_map[17] = AMPERSAND_EQUAL;
        state_token_map[18] = OPEN_PARENTHESES;
        state_token_map[19] = CLOSE_PARENTHESES;
        state_token_map[20] = OPEN_SQUARE_BRACKETS;
        state_token_map[21] = CLOSE_SQUARE_BRACKETS;
        state_token_map[22] = OPEN_CURLY_BRACKETS;
        state_token_map[23] = CLOSE_CURLY_BRACKETS;
        state_token_map[24] = PIPE;
        state_token_map[25] = PIPE_EQUAL;
        state_token_map[26] = QUESTION_MARK;
        state_token_map[27] = COLON;
        state_token_map[28] = AND;
        state_token_map[29] = OR;
        state_token_map[30] = XOR;
        state_token_map[31] = XOR_EQUAL;
        state_token_map[32] = NOT;
        state_token_map[33] = NOT_EQUAL;
        state_token_map[34] = GREATER;
        state_token_map[35] = GREATER_EQUAL;
        state_token_map[36] = LESS;
        state_token_map[37] = LESS_EQUAL;
        state_token_map[38] = BITWISE_NOT;
        state_token_map[39] = BITWISE_NOT_EQUAL;
        state_token_map[40] = IDENTIFIER;
        state_token_map[41] = IDENTIFIER;
        state_token_map[42] = INT;
        state_token_map[43] = IDENTIFIER;
        state_token_map[44] = IF;
        state_token_map[45] = IDENTIFIER;
        state_token_map[46] = IDENTIFIER;
        state_token_map[47] = IDENTIFIER;
        state_token_map[48] = CHAR;
        state_token_map[49] = IDENTIFIER;
        state_token_map[50] = IDENTIFIER;
        state_token_map[51] = IDENTIFIER;
        state_token_map[52] = VOID;
        state_token_map[53] = IDENTIFIER;
        state_token_map[54] = IDENTIFIER;
        state_token_map[55] = FOR;
        state_token_map[56] = IDENTIFIER;
        state_token_map[57] = IDENTIFIER;
        state_token_map[58] = IDENTIFIER;
        state_token_map[59] = ELSE;
        state_token_map[60] = IDENTIFIER;
        state_token_map[61] = IDENTIFIER;
        state_token_map[62] = IDENTIFIER;
        state_token_map[63] = IDENTIFIER;
        state_token_map[64] = WHILE;
        state_token_map[65] = IDENTIFIER;
        state_token_map[66] = IDENTIFIER;
        state_token_map[67] = IDENTIFIER;
        state_token_map[68] = IDENTIFIER;
        state_token_map[69] = IDENTIFIER;
        state_token_map[70] = RETURN;
        state_token_map[71] = ERROR;
        state_token_map[72] = STRING_LITERAL;
        state_token_map[73] = ERROR;
        state_token_map[74] = ERROR;
        state_token_map[75] = CHAR_LITERAL;
        state_token_map[76] = INT_LITERAL;
        state_token_map[77] = INT_LITERAL;
    }

    void init_state_machine() {
        for (int s = 0; s < STATES; s++) {
            for (int c = 0; c < ASCII; c++) {
                state_machine[s][c] = -1; //init to error state
            }
        }

        for (int c = 'a'; c <= 'z'; c++){
            state_machine[0][c] = 43;
            state_machine[0][c-('a'-'A')] = 43;
        }
        state_machine[0]['\n'] = 0;
        state_machine[0][' '] = 0;
        state_machine[0]['='] = 1;
        state_machine[0]['+'] = 3;
        state_machine[0]['-'] = 6;
        state_machine[0]['*'] = 13;
        state_machine[0][';'] = 15;
        state_machine[0]['&'] = 16;
        state_machine[0]['('] = 18;
        state_machine[0][')'] = 19;
        state_machine[0]['['] = 20;
        state_machine[0][']'] = 21;
        state_machine[0]['{'] = 22;
        state_machine[0]['}'] = 23;
        state_machine[0]['|'] = 24;
        state_machine[0]['?'] = 26;
        state_machine[0][':'] = 27;
        state_machine[0]['^'] = 30;
        state_machine[0]['%'] = 11;
        state_machine[0]['/'] = 9;
        state_machine[0]['~'] = 38;
        state_machine[0]['<'] = 36;
        state_machine[0]['>'] = 34;
        state_machine[0]['!'] = 32;
        state_machine[0]['i'] = 40;
        state_machine[0]['c'] = 45;
        state_machine[0]['v'] = 49;
        state_machine[0]['f'] = 53;
        state_machine[0]['e'] = 56;
        state_machine[0]['w'] = 60;
        state_machine[0]['r'] = 65;
        for (int c = '1'; c <= '9'; c++){
            state_machine[0][c] = 76;
        }
        state_machine[0]['0'] = 77;
        state_machine[0]['\''] = 73;
        state_machine[0]['\"'] = 72;

        state_machine[1]['='] = 2;

        state_machine[3]['='] = 4;
        state_machine[3]['+'] = 5;

        state_machine[6]['-'] = 7;
        state_machine[6]['='] = 8;

        state_machine[9]['='] = 10;

        state_machine[11]['='] = 12;

        state_machine[13]['='] = 14;

        state_machine[16]['='] = 17;
        state_machine[16]['&'] = 28;

        state_machine[24]['='] = 25;
        state_machine[24]['|'] = 29;

        state_machine[30]['='] = 31;

        state_machine[32]['='] = 33;

        state_machine[34]['='] = 35;

        state_machine[36]['='] = 37;

        state_machine[38]['='] = 39;

        for (int c = '0'; c <= '9'; c++) {
            state_machine[40][c] = 43;
        }
        for (int c = 'a'; c <= 'z'; c++) {
            state_machine[40][c] = 43;
            state_machine[40][c - ('a' - 'A')] = 43;
        }
        state_machine[40]['n'] = 41;
        state_machine[40]['f'] = 44;

        for (int c = '0'; c <= '9'; c++) {
            state_machine[41][c] = 43;
        }
        for (int c = 'a'; c <= 'z'; c++) {
            state_machine[41][c] = 43;
            state_machine[41][c - ('a' - 'A')] = 43;
        }
        state_machine[41]['t'] = 42;

        for (int c = '0'; c <= '9'; c++) {
            state_machine[42][c] = 43;
        }
        for (int c = 'a'; c <= 'z'; c++) {
            state_machine[42][c] = 43;
            state_machine[42][c - ('a' - 'A')] = 43;
        }

        for (int c = '0'; c <= '9'; c++) {
            state_machine[43][c] = 43;
        }
        for (int c = 'a'; c <= 'z'; c++) {
            state_machine[43][c] = 43;
            state_machine[43][c - ('a' - 'A')] = 43;
        }

        for (int c = '0'; c <= '9'; c++) {
            state_machine[44][c] = 43;
        }
        for (int c = 'a'; c <= 'z'; c++) {
            state_machine[44][c] = 43;
            state_machine[44][c - ('a' - 'A')] = 43;
        }

        for (int c = '0'; c <= '9'; c++) {
            state_machine[45][c] = 43;
        }
        for (int c = 'a'; c <= 'z'; c++) {
            state_machine[45][c] = 43;
            state_machine[45][c - ('a' - 'A')] = 43;
        }
        state_machine[45]['h'] = 46;

        for (int c = '0'; c <= '9'; c++) {
            state_machine[46][c] = 43;
        }
        for (int c = 'a'; c <= 'z'; c++) {
            state_machine[46][c] = 43;
            state_machine[46][c - ('a' - 'A')] = 43;
        }
        state_machine[46]['a'] = 47;

        for (int c = '0'; c <= '9'; c++) {
            state_machine[47][c] = 43;
        }
        for (int c = 'a'; c <= 'z'; c++) {
            state_machine[47][c] = 43;
            state_machine[47][c - ('a' - 'A')] = 43;
        }
        state_machine[47]['r'] = 48;

        for (int c = '0'; c <= '9'; c++) {
            state_machine[48][c] = 43;
        }
        for (int c = 'a'; c <= 'z'; c++) {
            state_machine[48][c] = 43;
            state_machine[48][c - ('a' - 'A')] = 43;
        }

        for (int c = '0'; c <= '9'; c++) {
            state_machine[49][c] = 43;
        }
        for (int c = 'a'; c <= 'z'; c++) {
            state_machine[49][c] = 43;
            state_machine[49][c - ('a' - 'A')] = 43;
        }
        state_machine[49]['o'] = 50;

        for (int c = '0'; c <= '9'; c++) {
            state_machine[50][c] = 43;
        }
        for (int c = 'a'; c <= 'z'; c++) {
            state_machine[50][c] = 43;
            state_machine[50][c - ('a' - 'A')] = 43;
        }
        state_machine[50]['i'] = 51;

        for (int c = '0'; c <= '9'; c++) {
            state_machine[51][c] = 43;
        }
        for (int c = 'a'; c <= 'z'; c++) {
            state_machine[51][c] = 43;
            state_machine[51][c - ('a' - 'A')] = 43;
        }
        state_machine[51]['d'] = 52;

        for (int c = '0'; c <= '9'; c++) {
            state_machine[52][c] = 43;
        }
        for (int c = 'a'; c <= 'z'; c++) {
            state_machine[52][c] = 43;
            state_machine[52][c - ('a' - 'A')] = 43;
        }

        for (int c = '0'; c <= '9'; c++) {
            state_machine[53][c] = 43;
        }
        for (int c = 'a'; c <= 'z'; c++) {
            state_machine[53][c] = 43;
            state_machine[53][c - ('a' - 'A')] = 43;
        }
        state_machine[53]['o'] = 54;

        for (int c = '0'; c <= '9'; c++) {
            state_machine[54][c] = 43;
        }
        for (int c = 'a'; c <= 'z'; c++) {
            state_machine[54][c] = 43;
            state_machine[54][c - ('a' - 'A')] = 43;
        }
        state_machine[54]['r'] = 55;

        for (int c = '0'; c <= '9'; c++) {
            state_machine[55][c] = 43;
        }
        for (int c = 'a'; c <= 'z'; c++) {
            state_machine[55][c] = 43;
            state_machine[55][c - ('a' - 'A')] = 43;
        }

        for (int c = '0'; c <= '9'; c++) {
            state_machine[56][c] = 43;
        }
        for (int c = 'a'; c <= 'z'; c++) {
            state_machine[56][c] = 43;
            state_machine[56][c - ('a' - 'A')] = 43;
        }
        state_machine[56]['l'] = 54;

        for (int c = '0'; c <= '9'; c++) {
            state_machine[57][c] = 43;
        }
        for (int c = 'a'; c <= 'z'; c++) {
            state_machine[57][c] = 43;
            state_machine[57][c - ('a' - 'A')] = 43;
        }
        state_machine[57]['s'] = 58;

        for (int c = '0'; c <= '9'; c++) {
            state_machine[58][c] = 43;
        }
        for (int c = 'a'; c <= 'z'; c++) {
            state_machine[58][c] = 43;
            state_machine[58][c - ('a' - 'A')] = 43;
        }
        state_machine[58]['e'] = 59;

        for (int c = '0'; c <= '9'; c++) {
            state_machine[59][c] = 43;
        }
        for (int c = 'a'; c <= 'z'; c++) {
            state_machine[59][c] = 43;
            state_machine[59][c - ('a' - 'A')] = 43;
        }

        for (int c = '0'; c <= '9'; c++) {
            state_machine[60][c] = 43;
        }
        for (int c = 'a'; c <= 'z'; c++) {
            state_machine[60][c] = 43;
            state_machine[60][c - ('a' - 'A')] = 43;
        }
        state_machine[60]['h'] = 61;

        for (int c = '0'; c <= '9'; c++) {
            state_machine[61][c] = 43;
        }
        for (int c = 'a'; c <= 'z'; c++) {
            state_machine[61][c] = 43;
            state_machine[61][c - ('a' - 'A')] = 43;
        }
        state_machine[61]['i'] = 62;

        for (int c = '0'; c <= '9'; c++) {
            state_machine[62][c] = 43;
        }
        for (int c = 'a'; c <= 'z'; c++) {
            state_machine[62][c] = 43;
            state_machine[62][c - ('a' - 'A')] = 43;
        }
        state_machine[62]['l'] = 63;

        for (int c = '0'; c <= '9'; c++) {
            state_machine[63][c] = 43;
        }
        for (int c = 'a'; c <= 'z'; c++) {
            state_machine[63][c] = 43;
            state_machine[63][c - ('a' - 'A')] = 43;
        }
        state_machine[63]['e'] = 64;

        for (int c = '0'; c <= '9'; c++) {
            state_machine[64][c] = 43;
        }
        for (int c = 'a'; c <= 'z'; c++) {
            state_machine[64][c] = 43;
            state_machine[64][c - ('a' - 'A')] = 43;
        }

        for (int c = '0'; c <= '9'; c++) {
            state_machine[65][c] = 43;
        }
        for (int c = 'a'; c <= 'z'; c++) {
            state_machine[65][c] = 43;
            state_machine[65][c - ('a' - 'A')] = 43;
        }
        state_machine[65]['e'] = 66;

        for (int c = '0'; c <= '9'; c++) {
            state_machine[66][c] = 43;
        }
        for (int c = 'a'; c <= 'z'; c++) {
            state_machine[66][c] = 43;
            state_machine[66][c - ('a' - 'A')] = 43;
        }
        state_machine[66]['l'] = 67;

        for (int c = '0'; c <= '9'; c++) {
            state_machine[67][c] = 43;
        }
        for (int c = 'a'; c <= 'z'; c++) {
            state_machine[67][c] = 43;
            state_machine[67][c - ('a' - 'A')] = 43;
        }
        state_machine[67]['u'] = 68;

        for (int c = '0'; c <= '9'; c++) {
            state_machine[68][c] = 43;
        }
        for (int c = 'a'; c <= 'z'; c++) {
            state_machine[68][c] = 43;
            state_machine[68][c - ('a' - 'A')] = 43;
        }
        state_machine[68]['r'] = 69;

        for (int c = '0'; c <= '9'; c++) {
            state_machine[69][c] = 43;
        }
        for (int c = 'a'; c <= 'z'; c++) {
            state_machine[69][c] = 43;
            state_machine[69][c - ('a' - 'A')] = 43;
        }
        state_machine[69]['n'] = 70;

        for (int c = '0'; c <= '9'; c++) {
            state_machine[70][c] = 43;
        }
        for (int c = 'a'; c <= 'z'; c++) {
            state_machine[70][c] = 43;
            state_machine[70][c - ('a' - 'A')] = 43;
        }

        for (int c = 0; c < ASCII; c++) {
            state_machine[71][c] = 71;
        }
        state_machine[71]['\n'] = -1;
        state_machine[71]['\"'] = 72;

        for (int c = 0; c < ASCII; c++) {
            state_machine[73][c] = 74;
        }
        state_machine[73]['\n'] = -1;
        state_machine[73]['\''] = -1;

        state_machine[74]['\''] = 75;

        for (int c = '0'; c <= '9'; c++) {
            state_machine[76][c] = 76;
        }
    }

    int get_next_state(int current_state, char c) {
        if (current_state < 0 || current_state >= STATES || c < 0 || c >= ASCII) {
            return -1;
        }
        return state_machine[current_state][c];
    }
};

struct Token {
    TokenType type;
    std::string value;
    int line;
    int column;

    Token(TokenType t, std::string v, int l, int c) : type(t), value(v), line(l), column(c) {}
    Token() : type(ERROR), value(""), line(-1), column(-1) {}
};

class Lexer {
    private:
        ifstream inFile;

    public:
        Lexer(string fName):inFile(fName) {
            if (!inFile.is_open()) {
                throw runtime_error("Failed to open file: " + fName);
            }
        }
        ~Lexer() {
            if (inFile.is_open()) {
                inFile.close();
            }
        }

        Token get_next_token() {
        }
};