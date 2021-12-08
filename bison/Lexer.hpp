#ifndef __LEXER_HPP__
/**
 * @author Adrian Ulises Mercado Martínez
 * @version 1, 3/11/2021
 */
#define __LEXER_HPP__
#include "parser.tab.hh"
#include "location.hh"

#if !defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif

#include <string>
using namespace std;

class Lexer : public yyFlexLexer
{
public:
    Lexer(std::istream *in) : yyFlexLexer(in){
        loc = new yy::Parser::location_type();
    };

    using FlexLexer::yylex;
    virtual int yylex(yy::Parser::semantic_type *const lval, yy::Parser::location_type *location);
    //virtual int Lexeclear::yylex(yy::Parser::semantic_type *const lval, yy::Parser::location_type *location);
    virtual int getLine();
    virtual int getType();
    virtual string getVal();

private:
    yy::Parser::semantic_type *yylval = nullptr;
    yy::Parser::location_type *loc = nullptr;
};

#endif /* __LEXER_HPP__ */