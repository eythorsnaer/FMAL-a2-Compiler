#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
#include <string>

using namespace std;

enum TokenCode
{
    ID, ASSIGN, SEMICOL, INT, ADD, SUB, MULT, LPAREN, RPAREN, PRINT, END, ERROR
};

struct Token
{
    string lexeme;
    TokenCode tCode;
};

#endif // TOKEN_H
