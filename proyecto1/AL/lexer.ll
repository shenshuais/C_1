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
CHAR ['][a-zA-Z0-9][']
CADENA ([']([ \t\n\r]?[a-zA-Z0-9]?)+['])
ESP [ \t\n\r]

%%

"int"   { return INT;}
"float" { return FLOAT;}
"char"  { return CHAR;}
"struct"  { return STRUCT;}
"else"  { return ELSE;}
"if"    { return IF;}
"do"    { return DO;}
"while" { return WHILE;}
"break" { return BREAK;}
"print" { return PRINT;}
"scan" { return SCAN;}
"return" { return RETURNN;}
"."     { return PUNTO;}
"+"     { return MAS;}
"-"     { return MEN;}
"*"     { return MULT;}
"/"     { return DIV;}
"="     { return IGUAL;}
"||"    { return OR;}
"&&"    { return AND;}
"<"     { return MENOSK;}
">"     { return MAYORK;}
"=="    { return EQUAL;}
"!="    { return DIFF;}
">="    { return MAYORY;}
"<="    { return MENORY;}
"!"    { return NOT;}
"("     { return PARI;}
")"     { return PARD;}
"{"     { return LLABI;}
"}"     { return LLABD;}
";"     { return PYC;}
","     { return COMA;}


{ENTERO}   {return NUMERO;}
{FLOTANTE} {return NUMERO;}
{ID} {return ID;}
{CHAR}     {return CHAR;}
{CADENA}    {return CADENA;}
{ESP} {}


.    { cout<<"ERROR LEXICO "<<yytext<<endl;}   

%%


