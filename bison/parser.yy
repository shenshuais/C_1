/**
 * @author Adrian Ulises Mercado Martínez
 * @version 1, 3/11/2021
 */
%skeleton "lalr1.cc"
%require  "3.8"
%debug 
%defines 
%define api.parser.class {Parser}

%code requires{
#include "SymbolTypes.hpp"

    class Driver;
    class Lexer;

// The following definitions is missing when %locations isn't used
# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

}

%parse-param { Lexer  &lexer  }
%parse-param { Driver  &driver  }

%code{
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;
#include "Driver.hpp"
#include "Lexer.hpp"

#undef yylex
#define yylex lexer.yylex
}

%define api.value.type variant
%define parse.assert

%token <std::string>     ID
%token <std::string>     NUMERO
%token              IF ELSE WHILE 
%token              INT FLOAT
%token              LKEY RKEY PYC COMA

%left               ASIG
%left               MAS MENOS
%left               MUL DIV
%nonassoc           LPAR RPAR

%type<int>  tipo
%type <Expresion> expresion

%locations

%start programa

%%
programa : 
    declaraciones sentencias
    {
        driver.print();
        driver.translate();
    }
    ;

declaraciones:
    declaraciones declaracion
    | declaracion
    ;

declaracion:
    tipo {driver.setType($1);} lista_var PYC
    ;

tipo:
    INT { $$= 0;}
    |
    FLOAT {$$=1;}
    ;

lista_var: 
    lista_var COMA ID{
        driver.addSym($3, driver.getType(), "variable");
    }
    |
    ID{
        driver.addSym($1, driver.getType(), "variable");
    }
    ;

sentencias:
    sentencias sentencia
    | sentencia
    ;

sentencia:
    IF LPAR expresion 
    {
        driver.pushLabel(driver.newLab());// next
        driver.pushLabel(driver.newLab());// label true
        driver.pushLabel(driver.newLab());// label false
        driver._if($3.dir, driver.newLabel(driver.element(1)));        
        driver._goto(driver.newLabel(driver.element(0)));
        driver._label(driver.newLabel(driver.element(1)));
    } 
    RPAR LKEY sentencias
    {
        driver._goto(driver.newLabel(driver.element(2)));
        driver._label(driver.newLabel(driver.element(0)));
    }
    RKEY ELSE LKEY sentencias RKEY
    {
        driver._label(driver.newLabel(driver.element(2)));
        driver.popLabel();
        driver.popLabel();
        driver.popLabel();
    }
    |
    WHILE
    {
        driver.pushLabel(driver.newLab()); // begin
        driver.pushLabel(driver.newLab()); // true
        driver.pushLabel(driver.newLab()); // false
    }
    LPAR expresion 
    {
        driver._label(driver.newLabel(driver.element(2)));
        driver._if($4.dir, driver.newLabel(driver.element(1)));
        driver._goto(driver.newLabel(driver.element(0)));
        driver._label(driver.newLabel(driver.element(1)));        
    }
    RPAR LKEY sentencias RKEY
    {
        driver._goto(driver.newLabel(driver.element(2)));
        driver.popLabel();
        driver.popLabel();
        driver.popLabel();
    }
    |
    ID ASIG expresion PYC
    {
        driver.asig($1, $3);
    }
    ;

expresion:
    expresion MAS expresion {$$=driver.mas($1, $3);}
    | 
    expresion MENOS expresion{$$=driver.menos($1, $3);}
    | 
    expresion MUL expresion{$$=driver.mul($1, $3);}
    | 
    expresion DIV expresion{$$=driver.div($1, $3);}
    | 
    LPAR expresion RPAR{$$=$2;}
    | 
    NUMERO{$$=driver.numero($1, lexer.getType());}
    | 
    ID{$$=driver.ident($1);}
    ;



%%


void yy::Parser::error( const location_type &l, const std::string &err_message )
{
    cerr << "Error: " << err_message << " at " << l <<" whith token "<<lexer.getVal()<< endl;
}