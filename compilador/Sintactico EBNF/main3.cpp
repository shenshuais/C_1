#include  <iostream>
#include "Lexer.h"
#include "Parser.h"
#include "tokens.h"

using namespace std;
using namespace C_1;


int main(int argc, char *argv[]){
    

    if(argc <2){
        cout<<"Faltan argumentos"<<endl;
        return -1;
    }
    
    Lexer lexer("Tabla.txt");
    lexer.openFile(string(argv[1]));
    Parser parser(&lexer);
    parser.parse();    
    lexer.closeFile();
    //lexer.printTable();
    return 0;
}
