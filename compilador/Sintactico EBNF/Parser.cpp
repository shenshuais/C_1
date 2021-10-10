#include "parser.h"
#include "iostream"

namespace C_1
{
    Parser::Parser(){

    }
    Parser::Parser(Lexer *lexer){
        this->lexer=lexer;
    }
    Parser::~Parser(){
        
    }
    void Parser::programa(){
        declaraciones();
        sentencias();
    }
    void Parser::declaraciones(){
        declaracion();
        declaracionesP();
    }
    void Parser::declaracionesP(){
        while(token == INT || token ==FLOAT){
            declaracion();
        }
    }
    void Parser::declaracion(){
        tipo();
        lista_var();
        eat(PYC);
    }
    void Parser::tipo(){
        switch(token){
            case INT:
                eat(INT);
                break;
            case FLOAT:
                eat(FLOAT);
                break;
            default:
                error("El token debe ser int o float");
                break;
        }
    }
    void Parser::lista_var(){
        eat(ID);
        lista_varP();

    }
    void Parser::lista_varP(){ //preguntar 
        while(token == COMA ){
            eat(COMA);
            eat(ID);
        }

    }
    void Parser::sentencias(){
        sentencia();
        sentenciasP();

    }
    void Parser::sentenciasP(){
        while(token == ID || token ==WHILE || token ==IF){
            sentencia();
        }

    }
    void Parser::sentencia(){
        switch(token){
            case ID:
                eat(ID);
                eat(IGUAL);
                expresion();
                eat(PYC);
                break;
            case IF:
                eat(IF);
                eat(PARI);
                expresion();
                eat(PARD);
                sentencias();
                eat(ELSE);
                sentencias();
                break;
            case WHILE:
                eat(WHILE);
                eat(PARI);
                expresion();
                eat(PARD);
                sentencias();
                break;
            default:
                error("El token debe ser ID o IF o WHILE");
                break;
        }

    }
    void Parser::expresion(){
        termino();
        expresionP();

    }
    void Parser::expresionP(){
        while(token == MAS || token == MEN){
            if(token == MAS ){
                eat(MAS);
                termino();
            }
            else{
                eat(MEN);
                termino();
            }
        }

    }
    void Parser::termino(){
        factor();
        terminoP();

    }
    void Parser::terminoP(){
        while(token == MULT || token == DIV){
            if(token == MULT ){
                eat(MULT);
                factor();
            }
            else{
                eat(DIV);
                factor();
            }
        }

    }
    void Parser::factor(){
        switch(token){
            case PARI:
                eat(PARI);
                expresion();
                eat(PARD);
                break;
            case ID:
                eat(ID);
                break;
            case NUMERO:
                eat(NUMERO);
                break;
            default:
                error("El token debe ser PARI o ID o numero");
                break;
        }

    }
    void Parser::eat(int t){
        if(token == t){
            token = lexer->yylex();
        }else
            error("El token es incorrecto");

    }
    void Parser::error(string msg){
        cout<<"ERROR DE SINTAXIS"<<msg<<endl;
        exit(-1);

    }

    void Parser::parse(){
        token= lexer->yylex(); // cambio
        programa();
        if(token==0){
            cout<<"La cadena es aceptada"<<endl;
        }else{
            cout<<"La cadena no pertenece al lenguaje generado por la gramatica"<<endl;
        }
    }
}