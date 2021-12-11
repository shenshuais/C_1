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


        // TODO(1) Completar las constantes que faltan de los tokens
    };

}

#endif /* END __SCANNER_H__ */