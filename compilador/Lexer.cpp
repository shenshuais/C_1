#include "Lexer.h"
#include "tokens.h"
#include <iostream>

namespace C_1{
    Lexer :: Lexer(){

    }
    Lexer :: Lexer(string file)
    {
        transiciones =  new int*[36];
        for(int i=0; i<36; i++) 
            transiciones[i] = new int[26];

        // leer el archivo de AFD
        ifstream archivo;
        int i=0;
        int j=0;
        archivo.open(file.c_str(),ios::in);

        if(archivo.fail()){
            cout<<"No se pudo abrir el archivo";
            exit(1);
        }

        for(i=0; i<36; i++){
            while(!archivo.eof() && j<26){
                archivo >> transiciones[i][j];
                j=j+1;
            }
            j=0;
        }

        archivo.close();

        //arreglo de aceptaciones 
        acc = new bool[36];
        acc[0] = false;
        acc[1] = true;
        acc[2] = true;
        acc[3] = true;
        acc[4] = true;
        acc[5] = true;
        acc[6] = true;
        acc[7] = true;
        acc[8] = true;
        acc[9] = true;
        acc[10] = true;
        acc[11] = false;
        acc[12] = true;
        acc[13] = true;
        acc[14] = true;
        acc[15] = true;
        acc[16] = true;
        acc[17] = true;
        acc[18] = true;
        acc[19] = true;
        acc[20] = true;
        acc[21] = true;
        acc[22] = true;
        acc[23] = true;
        acc[24] = false;
        acc[25] = true;
        acc[26] = true;
        acc[27] = true;
        acc[28] = true;
        acc[29] = false;
        acc[30] = true;
        acc[31] = true;
        acc[32] = true;
        acc[33] = true;
        acc[34] = true;
        acc[35] = true;


        // Map 
        simbolos['+'] = 0;
        simbolos['-'] = 1;
        simbolos['*'] = 2;
        simbolos['/'] = 3;
        simbolos['='] = 4;
        simbolos['('] = 5;
        simbolos[')'] = 6;
        simbolos[';'] = 7;
        simbolos[','] = 8;
        simbolos['0'] = 9;
        simbolos['1'] = 9;
        simbolos['2'] = 9;
        simbolos['3'] = 9;
        simbolos['4'] = 9;
        simbolos['5'] = 9;
        simbolos['6'] = 9;
        simbolos['7'] = 9;
        simbolos['8'] = 9;
        simbolos['9'] = 9;
        simbolos['.'] = 10;
        simbolos['i'] = 11;
        simbolos['n'] = 12;
        simbolos['t'] = 13;
        simbolos['f'] = 14;
        simbolos['l'] = 15;
        simbolos['o'] = 16;
        simbolos['a'] = 17;
        simbolos['e'] = 18;
        simbolos['s'] = 19;
        simbolos['w'] = 20;
        simbolos['h'] = 21;
        simbolos['A'] = 22;
        simbolos['B'] = 22;
        simbolos['C'] = 22;
        simbolos['D'] = 22;
        simbolos['F'] = 22;
        simbolos['G'] = 22;
        simbolos['H'] = 22;
        simbolos['I'] = 22;
        simbolos['J'] = 22;
        simbolos['K'] = 22;
        simbolos['L'] = 22;
        simbolos['M'] = 22;
        simbolos['N'] = 22;
        simbolos['O'] = 22;
        simbolos['P'] = 22;
        simbolos['Q'] = 22;
        simbolos['R'] = 22;
        simbolos['S'] = 22;
        simbolos['T'] = 22;
        simbolos['U'] = 22;
        simbolos['V'] = 22;
        simbolos['W'] = 22;
        simbolos['X'] = 22;
        simbolos['Y'] = 22;
        simbolos['Z'] = 22;
        simbolos['b'] = 22;
        simbolos['c'] = 22;
        simbolos['d'] = 22;
        simbolos['g'] = 22;
        simbolos['j'] = 22;
        simbolos['k'] = 22;
        simbolos['m'] = 22;
        simbolos['p'] = 22;
        simbolos['q'] = 22;
        simbolos['u'] = 22;
        simbolos['v'] = 22;
        simbolos['x'] = 22;
        simbolos['y'] = 22;
        simbolos['z'] = 22;
        simbolos[' '] = 23;
        simbolos['\t'] = 23;
        simbolos['\n'] = 23;
        simbolos['\r'] = 23;
        simbolos['E'] = 24;
        simbolos['_'] = 25;

    }
    
    Lexer::~Lexer()
    {
        // el destructor libera la memoria
        for(int i=0; i<36; i++){
            delete transiciones[i];
        }
        // emilinar la tabla 
        delete transiciones; 
        delete acc; 
    }

    void Lexer::getChar(){
            yyin.get(c);
    }

    bool Lexer::openFile(string file){
        yyin.open(file.c_str(),ios::in);
        if(yyin.fail()){
        cout<<"No se pudo abrir el archivo";
        exit(1); //return EXIT_FAILURE
        }
        getChar();
    }

    bool Lexer::closeFile(){
        yyin.close();

    }

    int Lexer::yylex(){
        int q=0;
        int cc;
        yytext = "";        
        if(yyin.eof()) return 0;
        while(true){
            cc =  simbolos[c];
            if(transiciones[q][cc]!=-1){
                q=transiciones[q][cc];
                yytext+=c;
                getChar();
                if(yyin.eof()) return token(q);
            }else{
                if(acc[q]){
                    if(q==17){
                        q = 0;
                        yytext="";
                    }
                    else return token(q);
                }else{
                    return ERROR;
                }
            }
        }
    }


    int Lexer::token(int q){
        switch(q){
            case 1:
                return MAS;
            case 2:
                return MEN;
            case 3:
                return MULT;
            case 4:
                return DIV;
            case 5:
                return IGUAL;
            case 6:
                return PARI;
            case 7:
                return PARD;
            case 8:
                return PYC;
            case 9: 
                return COMA;
            case 10: case 19: case 30: 
                return NUMERO;
            case 12: case 13: case 14: case 15: case 16: case 20: case 21: case 22: 
            case 23: case 26: case 27: case 28: case 31: case 33:
                return ID;
            case 17:
                return ESPACE;
            case 18: 
                return IF;
            case 25:
                return INT;
            case 32:
                return ELSE;
            case 34: 
                return FLOAT;
            case 35:
                return WHILE;
            default:
                return ERROR;
        }
    }

    string Lexer::getYytext(){
        return yytext;
    }

    void Lexer::printTable(){
        for (int i=0; i<36; i++){
            for(int j=0; j<26; j++){
                cout<<transiciones[i][j]<<" "; 
            }
            cout<<""<<endl;
        }
    }


}