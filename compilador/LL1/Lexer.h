#ifndef LEXER_H
#define LEXER_H

#if !defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif

class Lexer : public yyFlexLexer
{
public:
    Lexer(std::istream *in) : yyFlexLexer(in){};

    using FlexLexer::yylex;
    virtual int yylex();

private:
    
};

#endif