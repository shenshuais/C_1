%{
#include <iostream>
#include <string>
using namespace std;

#include "tokens.hpp"
#include "Scanner.hpp"
%}

%option c++ 
%option outfile="Scanner.cpp"
%option yyclass="C_1::Scanner"
%option case-insensitive
%option noyywrap

ENTERO [0-9]+
DOUBLE [0-9]*\.[0-9]+([Ee][+-]?[0-9]+)?(d|D)?
FLOTANTE [0-9]*\.[0-9]+([Ee][+-]?[0-9]+)?(f|F)
CHAR ['][\x20-\x7E][']
ID [A-Za-z_][A-Za-z0-9_]*
CADENA (["][\x20-\x7E]+["])
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
"-"     { return MENOS;}
"*"     { return MUL;}
"/"     { return DIV;}
"="     { return ASIG;}
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
{DOUBLE} {return NUMERO;}
{FLOTANTE} {return NUMERO;}
{CHAR}     {return CHAR;}
{ID} {return ID;}
{CADENA}    {return CADENA;}
{ESP} {}


.    { cout<<"ERROR LEXICO "<<yytext<<endl;}   

%%


