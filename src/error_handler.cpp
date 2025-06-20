#include <iostream>
#include "../include/Lexer.hpp"
using namespace std;



void lexer_error_handler(const vector<Token>& tokens_lst) {
    for(Token token : tokens_lst) {
        if(token.type == ERROR) {
            cout << "\033[31m" << "Invalid character: '" + token.value + "' at line " << token.line << " column " << token.column << "\033[0m" << endl;
        }
    }
}

//להוסיף מחיקת טוקנים של שגיאה