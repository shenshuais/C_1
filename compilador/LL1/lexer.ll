%{
#include <iostream>
#include <string>
using namespace std;

#include "tokens.h"
#include "Lexer.h"

%}

%option c++
%option outfile="Lexer.cpp"
%option yyclass="Lexer"
%option case-insensitive


DIG [0-9]
ID [A-Za-z_][A-Za-z0-9_]*
ESP [ \t\n\r]
ENT {DIG}+
FLTT {ENT}?"."{ENT}([eE][+-]?{ENT})?

%%

"+" { return MAS; }
"-" { return MENOS;}
"*" { return MUL;}
"/" { return DIV;}
"=" { return ASIG;}
"(" { return LPAR;}
")" { return RPAR;}
"," { return COMA;}
";" { return PYC;}
"{" { return LKEY;}
"}" { return RKEY; }

"if"    { return IF;}
"int"    { return INT;}
"float"    { return FLOAT;}
"else"  { return ELSE;}
"while"    { return WHILE;}
{ID}    { return ID;}
{ENT}   { return NUMERO; }
{FLTT}  { return NUMERO; }
{ESP}   {}
.   { cout<<"ERROR LEXICO "<<yytext<<endl;}
%%
int yyFlexLexer::yywrap(){
    return 1;
}