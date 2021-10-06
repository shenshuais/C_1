#include <iostream>
#include "Lexer.h"
using namespace std;
using namespace C_1;

int main(int argc, char *argv[]){
    // si el argumento es menor a dps entonces manda error
    if(argc <2){
        return -1;
    }

    Lexer lexer("Tabla.txt");
    lexer.printTable();
    lexer.openFile(string(argv[1]));
    int token = lexer.yylex(); 

    

    while(token != 0){
        cout<<token<<", "<<lexer.getYytext()<<endl;
        token=lexer.yylex();
    }

    lexer.closeFile();
    return 0; 

}