#ifndef LEXER_H
#define LEXER_H
#include <fstream>
#include <string>
#include <iostream>
#include <map>
using namespace std;

namespace C_1{    

    class Lexer
    {
    private:        
        static const int ERROR = -1; // estado error
        ifstream yyin;        // para leer el archivo de codigo
        int **transiciones;   // la matriz de AFD
        bool *acc;            // areeglo de estados de acetacion 
        string yytext;        // buffer de mensaje que entra           
        char c;               // caracter actual
        int edos, sims;
        map<char, int> simbolos;  //simbolos y su numero de columna 

    public:
        Lexer();
        Lexer(string file);
        ~Lexer();

        bool readAFD(string file);
        void getChar();
        bool openFile(string file);
        bool closeFile();
        int yylex();
        void printTable();   // es para ver la tabla de transiciones, hay que quitarla despues
        int token(int q); 
        string getYytext();    
    };  
    
    
}

#endif