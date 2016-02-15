#ifndef PARSER_H
#define PARSER_H

#include "Lexer.h"

class Parser
{
private:
    Lexer lexer;
    Token currentToken;
    bool statements();
    bool statement();
    bool expr();
    bool term();
    bool factor();
    void syntaxError();
    bool accept(int expectedToken);
    bool expect(int expectedToken);

public:
    Parser(Lexer lexer);
    void parse();
};

#endif // PARSER_H
