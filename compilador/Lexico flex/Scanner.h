#ifndef __SCANNER_HPP__
#define __SCANNER_HPP__ 1

#if !defined(yyFlexLexerOnce)
#include <FlexLexer.h> 
#endif

namespace C_1
{

    class Scanner : public yyFlexLexer
    {
    public:
        Scanner(std::istream *in) : yyFlexLexer(in)
        {
        };

        using FlexLexer::yylex;
        virtual int yylex();

    private:
        const int ERROR = -1;
        const int ACEPTAR = 0;
        const int MAS = 1;
        const int MEN = 2;
        const int MULT= 3;
        const int DIV = 4;
        const int IGUAL = 5;
        const int PARI = 6;
        const int PARD = 7;
        const int PYC = 8;
        const int COMA = 9;
        const int NUMERO = 10;
        const int ID = 11;
        const int INT = 12;
        const int FLOAT = 13;
        const int ELSE = 14;
        const int IF = 15;
        const int WHILE = 16;
        const int ESPACE = 17;

        // TODO(1) Completar las constantes que faltan de los tokens
    };

}

#endif /* END __SCANNER_H__ */