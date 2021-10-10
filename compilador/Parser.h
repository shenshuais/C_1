#ifndef PARSER_H
#define PARSER_H
#include "Lexer.h"
#include <string>
#include "tokens.h"
using namespace std;

namespace C_1
{
    class Parser
    {
    private:
        Lexer *lexer;
        int token;
    public:
        Parser(/* args */);
        Parser(Lexer *lexer);
        ~Parser();
        void programa();
        void declaraciones();
        void declaracionesP();
        void declaracion();
        void tipo();
        void lista_var();
        void lista_varP();
        void sentencias();
        void sentenciasP();
        void sentencia();
        void expresion();
        void expresionP();
        void termino();
        void terminoP();
        void factor();
        void eat(int t);
        void error(string msg);
        void parse();
    };
    
}
#endif
