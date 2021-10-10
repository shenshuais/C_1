%{
#include <iostream>
#include <string>
using namespace std;

#include "tokens.h"
#include "Scanner.h"
%}

%option c++ 
%option outfile="Scanner.cpp"
%option yyclass="C_1::Scanner"
%option case-insensitive
%option noyywrap

ENTERO [0-9]+
FLOTANTE [0-9]*\.[0-9]+([Ee][+-]?[0-9]+)?
ID [A-Za-z_][A-Za-z0-9_]*
ESP [ \t\n\r]

%%

"int"   { return INT;}
"float" { return FLOAT;}
"else"  { return ELSE;}
"if"    { return IF;}
"while" { return WHILE;}
"+"     { return MAS;}
"-"     { return MEN;}
"*"     { return MULT;}
"/"     { return DIV;}
"="     { return IGUAL;}
"("     { return PARI;}
")"     { return PARD;}
";"     { return PYC;}
","     { return COMA;}

{ENTERO}   { return NUMERO;}
{FLOTANTE} { return NUMERO;}
{ID} {return ID;}
{ESP} {return ESPACE}


.    { cout<<"ERROR LEXICO "<<yytext<<endl;}   

%%


