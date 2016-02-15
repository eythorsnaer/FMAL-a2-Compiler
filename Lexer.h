#ifndef LEXER_H
#define LEXER_H

#include "Token.h"

class Lexer
{
private:
    bool isInt(string input);
    bool isId(string input);
    bool isDigit(char c);
    bool isLetter(char c);
public:
    Token nextToken();
};

#endif // LEXER_H
