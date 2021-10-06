#ifndef PARSER_H
#define PARSER_H
#include "Scanner.h"
#include <string>
#include "tokens.h"
usa namespace std;

namespace C_1
{
    class Parser
    {
    private:
        Scanner *lexer;
        int token;
    public:
        Parser(/* args */);
        Parser(Scanner *lexer);
        ~Parser();
        void programa();
        void declaraciones();
        void declaracionesp();
        void declaracion();
        void tipo();
        void lista_var();
        void lista_VarP();
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
    };
    
}
#endif
