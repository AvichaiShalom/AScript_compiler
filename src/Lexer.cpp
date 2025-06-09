#include <iostream>
#include <fstream>
using namespace std;
#define STATES 76
#define ASCII 128

enum TokenType
{
    ERROR,

    //===== data type =====
    INT,
    CHAR,
    VOID,

    //===== literal =====
    int_literal,
    char_literal,
    string_literal,

    //===== operations =====
    equal,
    plus,
    subtraction,
    division,
    star,
    mod,
    increment,
    decrement,

    plus_equal,
    subtraction_equal,
    division_equal,
    star_equal,
    mod_equal,

    //===== signs =====
    semicolon,
    ampersand,
    open_parentheses,
    close_parentheses,
    open_square_brackets,
    close_square_brackets,
    open_curly_brackets,
    close_curly_brackets,
    pipe,
    question_mark,
    colon,

    //===== loops =====
    FOR,
    WHILE,
    IF,
    ELSE,

    //===== conditions =====
    AND,
    OR,
    is_equal,
    not_equal,
    greater,
    less,
    greater_equal,
    less_equal,
    NOT,

    //===== bitwise =====
    xor,
    bitwise_not,
    xor_equal,
    bitwise_not_equal,
    pipe_equal,
    ampersand_equal,

    //===== more =====
    RETURN,
    identifier
};

//ליצור בהיפ ולשמור פיינטר
struct DFA {
    int state_machine[STATES][ASCII];

    void init_state_machine() {
        for (int s = 0; s < STATES; s++) {
            for (int c = 0; c < ASCII; c++){
                state_machine[s][c] = ERROR;
            }
        }

    }
};

class Lexer {
    private:
        ifstream inFile;

    public:
        Lexer(string fNmae):inFile(fNmae){
        }
};