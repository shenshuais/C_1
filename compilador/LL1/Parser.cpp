#include "Parser.h"

#include<vector>

void Parser::loadSymbols(){
    syms[0] = Symbol("programa", noterminal, 0);
    syms[1] = Symbol("declaraciones", noterminal, 1);
    syms[2] = Symbol("declaracionesP", noterminal, 2);
    syms[3] = Symbol("declaracion", noterminal, 3);
    syms[4] = Symbol("tipo", noterminal, 4);
    syms[5] = Symbol("lista_var", noterminal, 5);
    syms[6] = Symbol("lista_varP", noterminal, 6);
    syms[7] = Symbol("sentencias", noterminal, 7);
    syms[8] = Symbol("sentenciasP", noterminal, 8);
    syms[9] = Symbol("sentencia", noterminal, 9);
    syms[10] = Symbol("expresion", noterminal, 10);
    syms[11] = Symbol("expresionP", noterminal, 11);
    syms[12] = Symbol("termino", noterminal, 12);
    syms[13] = Symbol("terminoP", noterminal, 13);
    syms[14] = Symbol("factor", noterminal, 14);
    syms[15] = Symbol("$", terminal, 0);
    syms[16] = Symbol("MAS", terminal, 1);
    syms[17] = Symbol("MEN", terminal, 2);
    syms[18] = Symbol("MULT", terminal, 3);
    syms[19] = Symbol("DIV", terminal, 4);
    syms[20] = Symbol("IGUAL", terminal, 5);
    syms[21] = Symbol("PARI", terminal, 6);
    syms[22] = Symbol("PARD", terminal, 7);
    syms[23] = Symbol("PYC", terminal, 8);
    syms[24] = Symbol("COMA", terminal, 9);
    syms[25] = Symbol("NUMERO", terminal, 10); 
    syms[26] = Symbol("ID", terminal, 11);
    syms[27] = Symbol("INT", terminal, 12);
    syms[28] = Symbol("FLOAT", terminal, 13);
    syms[29] = Symbol("ELSE", terminal, 14);
    syms[30] = Symbol("IF", terminal, 15);
    syms[31] = Symbol("WHILE", terminal, 16);
    syms[32] = Symbol("ESPACE", terminal, 17); //ESPACE?
    syms[33] = Symbol("EPS", cadena, 0);
}

void Parser::loadProds()
{
    vector<int> s ={1,7};
    prod[0]=Production( 0 , s);
    s.clear();
    s = { 3 , 2 };
    prod[1]=Production( 1 , s);
    s.clear();
    s = { 3 , 2 };
    prod[2]=Production( 2 , s);
    s.clear();
    s = { 33 };
    prod[3]=Production( 2 , s);
    s.clear();
    s = { 4 , 5 ,23 };
    prod[4]=Production( 3 , s);
    s.clear();
    s = { 27 };
    prod[5]=Production( 4 , s);
    s.clear();
    s = { 28 };
    prod[6]=Production( 4 , s);
    s.clear();
    s = { 26, 6 };
    prod[7]=Production( 5 , s);
    s.clear();
    s = { 24, 26 , 6 };
    prod[8]=Production( 6 , s);
    s.clear();
    s = { 33 };
    prod[9]=Production( 6 , s);
    s.clear();
    s = { 9,8 };
    prod[10]=Production( 7 , s);
    s.clear();
    s = { 9,8 };
    prod[11]=Production( 8 , s);
    s.clear();
    s = { 33 };
    prod[12]=Production( 8 , s);
    s.clear();
    s = { 26, 20, 10 , 23 };
    prod[13]=Production( 9 , s);
    s.clear();
    s = { 30, 21, 10,22, 7 , 29, 7 };
    prod[14]=Production( 9 , s);
    s.clear();
    s = { 31, 21, 10,22, 7 };
    prod[15]=Production( 9 , s);
    s.clear();
    s = { 12,11 };
    prod[16]=Production( 10 , s);
    s.clear();
    s = { 16, 12, 11 };
    prod[17]=Production( 11 , s);
    s.clear();
    s = { 17, 12, 11};
    prod[18]=Production( 11 , s);
    s.clear();
    s = {33 };
    prod[19]=Production( 11 , s);
    s.clear();
    s = { 14,13 };
    prod[20]=Production( 12 , s);
    s.clear();
    s = { 18, 14, 13 };
    prod[21]=Production( 13 , s);
    s.clear();
    s = { 19,14,13 };
    prod[22]=Production( 13 , s);
    s.clear();
    s = { 33 };
    prod[23]=Production( 13 , s);
    s.clear();
    s = { 21,10,22 };
    prod[24]=Production( 14 , s);
    s.clear();
    s = { 26 };
    prod[25]=Production( 14 , s);
    s.clear();
    s = { 25 };
    prod[26]=Production( 14 , s);
    s.clear();
    
}

void Parser::loadTable(){

    table[0][12]= 0;
    table[0][13]= 0;

    table[1][12]= 1;
    table[1][13]= 1;

    table[2][15] =  3;
    table[2][16] = 3 ;
    table[2][11] =  3;
    table[2][12] = 2 ;
    table[2][13] = 2 ;

    table[3][12] = 4;
    table[3][13]= 4;

    table[4][12] = 5  ;
    table[4][13] =  6 ;

    table[5][11] = 7 ;

    table[6][9] = 8 ;
    table[6][8] =9;
    
    table[7][15] =  10;
    table[7][16] =  10;
    table[7][11] =  10;

    table[8][15] =  11;
    table[8][16] =  11;
    table[8][11] =  11;
    table[8][14] =  12;
    table[9][0] = 12 ;

    table[9][15] =  14;
    table[9][16] =  15;
    table[9][11] =  13;
    

    table[10][6] = 16  ;
    table[10][11] =  16;
    table[10][10] =  16;

    table[11][1] = 17 ;
    table[11][2] =  18;
    table[11][7] =  19;
    table[11][8] =  19;

    table[12][6] = 20 ;
    table[12][11] = 20;
    table[12][10] = 20;

    table[13][1] = 23 ;
    table[13][2] = 23;
    table[13][3] = 21 ;
    table[13][4] =  22;
    table[13][7] = 23;
    table[13][8] = 23;

    table[14][6] = 24 ;
    table[14][11] = 25 ;
    table[14][10] =  26;




    }

