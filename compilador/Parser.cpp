#include "parser.h"
#include "iostream"

namespace C_1
{
    Parser::Parser(){

    }
    Parser::Parser(Scanner *lexer){
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
    void Parser::declaracionesp(){
        if(token == INT || token == FLOAT){
            declaciones();
            declacionesP();
        }
    }
    void Parser::declaracion(){
        tipo();
        lista_var();
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
    void Parser::lista_Var(){
        eat(ID);
        lista_VarP(),

    }
    void Parser::lista_VarP(){
        if(token == ID){
            eat(ID);
            lista_VarP();
        }

    }
    void Parser::sentencias(){
        sentencia();
        sentenciasP();

    }
    void Parser::sentenciasP(){
        if(token)

    }
    void Parser::sentencia(){

    }
    void Parser::expresion(){

    }
    void Parser::expresionP(){

    }
    void Parser::termino(){

    }
    void Parser::terminoP(){

    }
    void Parser::factor(){

    }
    void Parser::eat(int t){

    }
    void Parser::error(string msg){

    }
}