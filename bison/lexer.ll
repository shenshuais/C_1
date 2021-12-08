%{
#include <iostream>
#include <string>
using namespace std;

#include "Lexer.hpp"

#undef YY_DECL
#define YY_DECL int Lexer::yylex(yy::Parser::semantic_type *const lval, yy::Parser::location_type *location)
using token = yy::Parser::token;

#define YY_USER_ACTION loc->step(); loc->columns(yyleng);

int line=1;
int numType;

%}

%option c++
%option outfile="Lexer.cpp"
%option yyclass="Lexer"

id [a-zA-Z_][a-zA-Z0-9_]*
ent [0-9]+
notacion [eE][+-]?[0-9]+
real ([0-9]+"."[0-9]*|"."[0-9]+){notacion}?|[0-9]+{notacion}

%%
%{  /** Code executed at the beginning of yylex **/
    yylval = lval;
%}
"=" { return token::ASIG; }
"+" { return token::MAS; }
"*" { return token::MUL; }
"-" { return token::MENOS; }
"/" { return token::DIV; }
"(" { return token::LPAR; }
")" { return token::RPAR; }
"{" { return token::LKEY; }
"}" { return token::RKEY; }
"," { return token::COMA; }
";" { return token::PYC; }

"if"    { return token::IF; }
"else"    { return token::ELSE; }
"int"    { return token::INT; }
"float"    { return token::FLOAT; }
{id}    { 
            yylval->build<std::string>(yytext);
            return token::ID; 
        }
{ent}   { 
            numType = 0;
            yylval->build<std::string>(yytext);
            return token::NUMERO;
        }
{real}   { 
            numType = 1;
            yylval->build<std::string>(yytext);
            return token::NUMERO;
        }

[ \t\r]+   {}
"\n"    {line++;}
.   { cout<<"ERROR LEXICO "<<yytext<<endl;}
%%
int yyFlexLexer::yywrap(){
    return 1;
}

int Lexer::getLine()
{
    return line;
}


int Lexer::getType()
{
    return numType;
}

string Lexer::getVal(){
    return yytext;
}