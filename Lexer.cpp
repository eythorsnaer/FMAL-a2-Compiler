#include "Lexer.h"

Token Lexer::nextToken()
{
    Token token;
    char thisChar;
    char nextChar;
    string input = "";
    string nextCharType;
    string thisCharType;

    do
    {
        cin >> thisChar;
        input += thisChar;
        nextChar = cin.peek();

        if (isLetter(nextChar))
        {
            nextCharType = "Letter";
        }
        else if (isDigit(nextChar))
        {
            nextCharType = "Digit";
        }
        else if (nextChar == '+')
        {
            nextCharType = "+";
        }
        else if (nextChar == '-')
        {
            nextCharType = "-";
        }
        else if (nextChar == '*')
        {
            nextCharType = "*";
        }
        else if (nextChar == '=')
        {
            nextCharType = "=";
        }
        else if (nextChar == '(')
        {
            nextCharType = "(";
        }
        else if (nextChar == ')')
        {
            nextCharType = ")";
        }
        else if (nextChar == ';')
        {
            nextCharType = ";";
        }
        else
        {
            nextCharType = "???";
        }

        if (isLetter(thisChar))
        {
            thisCharType = "Letter";
        }
        else if (isDigit(thisChar))
        {
            thisCharType = "Digit";
        }
        else
        {
            thisCharType = "???";
        }
    }
    while(nextCharType == thisCharType && thisCharType != "???");

    token.lexeme = input;
    if (input == "+")
    {
        token.tCode = ADD;
    }
    else if (input == "-")
    {
        token.tCode = SUB;
    }
    else if (input == "*")
    {
        token.tCode = MULT;
    }
    else if (input == "(")
    {
        token.tCode = LPAREN;
    }
    else if (input == ")")
    {
        token.tCode = RPAREN;
    }
    else if (input == "=")
    {
        token.tCode = ASSIGN;
    }
    else if (input == ";")
    {
        token.tCode = SEMICOL;
    }
    else if (input == "end")
    {
        token.tCode = END;
    }
    else if (input == "print")
    {
        token.tCode = PRINT;
    }
    else if (isInt(input))
    {
        token.tCode = INT;
    }
    else if (isId(input))
    {
        token.tCode = ID;
    }
    else
    {
        token.tCode = ERROR;
    }

    return token;
}

bool Lexer::isInt(string input)
{
    for (unsigned int i = 0; i < input.length(); i++)
    {
        if (!isDigit(input[i]))
        {
            return false;
        }
    }

    return true;
}

bool Lexer::isId(string input)
{
    for (unsigned int i = 0; i < input.length(); i++)
    {
        if (!isLetter(input[i]))
        {
            return false;
        }
    }

    return true;
}

bool Lexer::isDigit(char c)
{
    switch (c)
    {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            return true;
        default:
            return false;
    }
}

bool Lexer::isLetter(char c)
{
    switch (c)
    {
        case 'a':
        case 'b':
        case 'c':
        case 'd':
        case 'e':
        case 'f':
        case 'g':
        case 'h':
        case 'i':
        case 'j':
        case 'k':
        case 'l':
        case 'm':
        case 'n':
        case 'o':
        case 'p':
        case 'q':
        case 'r':
        case 's':
        case 't':
        case 'u':
        case 'v':
        case 'x':
        case 'y':
        case 'z':
        case 'A':
        case 'B':
        case 'C':
        case 'D':
        case 'E':
        case 'F':
        case 'G':
        case 'H':
        case 'I':
        case 'J':
        case 'K':
        case 'L':
        case 'M':
        case 'N':
        case 'O':
        case 'P':
        case 'Q':
        case 'R':
        case 'S':
        case 'T':
        case 'U':
        case 'V':
        case 'X':
        case 'Y':
        case 'Z':
            return true;
        default:
            return false;
    }
}
