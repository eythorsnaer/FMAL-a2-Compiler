#include "Parser.h"
#include <vector>
#include <algorithm>

Parser::Parser(Lexer lexer)
{
    this->lexer = lexer;
}

void Parser::parse()
{
    vector<string> temp;

    currentToken = lexer.nextToken();

    if (statements())
    {
        cin >> temp[1];
    }
    else
    {
        cin >> temp[1];
    }
}

bool Parser::statements()
{
    if (accept(END))
    {
        return true;
    }

    if (statement())
    {
        if(expect(SEMICOL))
        {
            if (statements())
            {
                return true;
            }
        }
    }

    return false;
}

bool Parser::statement()
{
    if (accept(ID))
    {
        if (expect(ASSIGN))
        {
            if (expr())
            {
                cout << "ASSIGN" << endl;
                return true;
            }
        }
    }
    else if (expect(PRINT))
    {
        if (expect(ID))
        {
            cout << "PRINT" << endl;
            return true;
        }
    }

    return false;
}

bool Parser::expr()
{
    if (term())
    {
        if (accept(ADD))
        {
            if (expr())
            {
                cout << "ADD" << endl;
                return true;
            }
            else
            {
                return false;
            }
        }
        else if (accept(SUB))
        {
            if (expr())
            {
                cout << "SUB" << endl;
                return true;
            }
            else
            {
                return false;
            }
        }

        return true;
    }

    return false;
}

bool Parser::term()
{
    if (factor())
    {
        if (accept(MULT))
        {
            if(term())
            {
                cout << "MULT" << endl;
                return true;
            }
        }
        else
        {
            return true;
        }
    }

    return false;
}

bool Parser::factor()
{
    if (accept(INT))
    {
        return true;
    }
    else if (accept(ID))
    {
        return true;
    }
    else if (expect(LPAREN))
    {
        if (expr())
        {
            if (expect(RPAREN))
            {
                return true;
            }
        }
    }

    return false;
}

void Parser::syntaxError()
{
    cout << "Syntax error!";
    return;
}

bool Parser::accept(int expectedToken)
{
    if (currentToken.tCode == expectedToken)
    {
        if (expectedToken == ID || expectedToken == INT)
        {
            cout << "PUSH " << currentToken.lexeme << endl;
        }

        if (currentToken.tCode != END)
        {
            currentToken = lexer.nextToken();
        }

        return 1;
    }

    return 0;
}

bool Parser::expect(int expectedToken)
{
    if (accept(expectedToken))
    {
        return 1;
    }

    syntaxError();
    return 0;
}
