#include "Parser.h"

Parser::Parser(Lexer *lexer)
{
    this->lexer = lexer;
}

Parser::~Parser()
{

}

void Parser::loadSymbols(){
    grammar.addSymbol(0, Symbol("programa", noterminal, 0, 0));
    grammar.addSymbol(1, Symbol("declaraciones", noterminal, 1, 1));
    grammar.addSymbol(2, Symbol("declaraciones_", noterminal, 2, 2));
    grammar.addSymbol(3, Symbol("declaracion", noterminal, 3, 3));
    grammar.addSymbol(4, Symbol("tipo", noterminal, 4, 4));
    grammar.addSymbol(5, Symbol("listaVar", noterminal, 5, 5));
    grammar.addSymbol(6, Symbol("listaVar_", noterminal, 6, 6));
    grammar.addSymbol(7, Symbol("sentencias", noterminal, 7, 7));
    grammar.addSymbol(8, Symbol("sentencias_", noterminal, 8, 8));
    grammar.addSymbol(9, Symbol("sentencia", noterminal, 9, 9));
    grammar.addSymbol(10, Symbol("expresion", noterminal, 10, 10));
    grammar.addSymbol(11, Symbol("expresion_", noterminal, 11, 11));
    grammar.addSymbol(12, Symbol("termino", noterminal, 12, 12));
    grammar.addSymbol(13, Symbol("termino_", noterminal, 13, 13));
    grammar.addSymbol(14, Symbol("factor", noterminal, 14, 14));
    grammar.noTerm = 15;
    grammar.addSymbol(15, Symbol("$", terminal, 15, 0));
    grammar.addSymbol(16, Symbol("MAS", terminal, 16, 1));
    grammar.addSymbol(17, Symbol("MENOS", terminal, 17, 2));
    grammar.addSymbol(18, Symbol("MUL", terminal, 18, 3));
    grammar.addSymbol(19, Symbol("DIV", terminal, 19, 4));
    grammar.addSymbol(20, Symbol("ASIG", terminal, 20, 5));
    grammar.addSymbol(21, Symbol("LPAR", terminal, 21, 6));
    grammar.addSymbol(22, Symbol("RPAR", terminal, 22, 7));
    grammar.addSymbol(23, Symbol("COMA", terminal, 23, 8));
    grammar.addSymbol(24, Symbol("PYC", terminal, 24, 9));
    grammar.addSymbol(25, Symbol("ID", terminal, 25, 10));
    grammar.addSymbol(26, Symbol("IF", terminal, 26, 11));
    grammar.addSymbol(27, Symbol("INT", terminal, 27, 12));
    grammar.addSymbol(28, Symbol("WHILE", terminal, 28, 13));
    grammar.addSymbol(29, Symbol("ELSE", terminal, 29, 14));
    grammar.addSymbol(30, Symbol("FLOAT", terminal, 30, 15));
    grammar.addSymbol(31, Symbol("NUMERO", terminal, 31, 16));
    grammar.addSymbol(32, Symbol("LKEY", terminal, 32, 17));
    grammar.addSymbol(33, Symbol("RKEY", terminal, 33, 18));
    grammar.term= 19;
    grammar.addSymbol(34, Symbol("EPS", cadenaVacia, 34, 1000));
    grammar.start = 0;

}

void Parser::loadProds()
{
    grammar.addProd(0, Production(0, {1, 7}));
    grammar.addProd(1, Production(1, {3, 2}));
    grammar.addProd(2, Production(2, {3, 2}));
    grammar.addProd(3, Production(2, {34}));
    grammar.addProd(4, Production(3, {4, 5, 24}));
    grammar.addProd(5, Production(4, {27}));
    grammar.addProd(6, Production(4, {30}));
    grammar.addProd(7, Production(5, {25, 6}));
    grammar.addProd(8, Production(6, {23, 25, 6}));
    grammar.addProd(9, Production(6, {34}));
    grammar.addProd(10, Production(7, {9, 8}));
    
    grammar.addProd(11, Production(8, {9, 8}));
    grammar.addProd(12, Production(8, {34}));
    grammar.addProd(13, Production(9, {25, 20, 10, 24}));
    grammar.addProd(14, Production(9, {26, 21, 10, 22, 32, 7, 33, 29, 32, 7, 33}));
    grammar.addProd(15, Production(9, {28, 21, 10, 22, 32, 7, 33}));
    grammar.addProd(16, Production(10, {12, 11}));
    grammar.addProd(17, Production(11, {16, 12, 11}));
    grammar.addProd(18, Production(11, {17, 12, 11}));
    grammar.addProd(19, Production(11, {34}));
    grammar.addProd(20, Production(12, {14, 13}));
    
    grammar.addProd(21, Production(13, {18, 14, 13}));
    grammar.addProd(22, Production(13, {19, 14, 13}));
    grammar.addProd(23, Production(13, {34}));
    grammar.addProd(24, Production(14, {21, 10, 22}));
    grammar.addProd(25, Production(14, {25}));
    grammar.addProd(26, Production(14, {31}));
    
}

void Parser::loadTable()
{
    table[0][12] = 0;
    table[0][15] = 0;
    
    table[1][12] = 1;
    table[1][15] = 1;
    
    table[2][12] = 2;
    table[2][15] = 2;
    table[2][10] = 3;
    table[2][11] = 3;
    table[2][13] = 3;
    
    table[3][12] = 4;
    table[3][15] = 4;    

    table[4][12] = 5;
    table[4][15] = 6;

    table[5][10] = 7;

    table[6][8] = 8;
    table[6][9] = 9;

    table[7][10] = 10;
    table[7][ 11] = 10;
    table[7][13] = 10;

    table[8][10] = 11;
    table[8][11] = 11;
    table[8][13] = 11;
    table[8][0] = 12;
    table[8][18] = 12;

    table[9][10] = 13 ;
    table[9][11] = 14;
    table[9][13] = 15;

    table[10][6] = 16;
    table[10][10] = 16;
    table[10][16] = 16;

    table[11][1] = 17;
    table[11][2] = 18;
    table[11][9] = 19;
    table[11][7] = 19;

    table[12][6] = 20;
    table[12][10] = 20;
    table[12][16] = 20;

    table[13][3] = 21;
    table[13][4] = 22;
    table[13][1] = 23;
    table[13][2] = 23;
    table[13][9] = 23;
    table[13][7] = 23;

    table[14][6] = 24;
    table[14][10] = 25;
    table[14][16] = 26;

}

int Parser::parse()
{    
    stack<Symbol>  pila;
    map<int,int>::iterator prod; //para consultar la producción  
    map<int, int> row;  
    vector<int> syms;
    loadSymbols();
    loadProds();
    loadTable();
    
    token = lexer->yylex();
    pila.push(grammar.getSym(15));
    pila.push(grammar.getSym(grammar.start));
    
    while(pila.top().getName()!="$")
    {
        if(pila.top().getType()==noterminal)
        {
            row = table[pila.top().getIdx()];
            prod = row.find(token);
            if(prod!= row.end()){
                syms = grammar.getProd(prod->second).getBody();
                pila.pop();
                if(syms[0]==34) continue;
                for(vector<int>::reverse_iterator it = syms.rbegin(); it != syms.rend(); it++)
                {
                    pila.push(grammar.getSym(*it));
                }
            }else{
                error("No existe ninguna acción sintáctica con el token actual");
            }
        }else if(pila.top().getType() == terminal){
            if(pila.top().getIdx() == token){
                pila.pop();
                token = lexer->yylex();
            }else{
                error("El token esperado no coincide con el actual");
            }
        }
    }
    if( pila.top().getName()=="$" && token ==0)
    {
        cout<<"La cadena es aceptada" <<endl;
        return 1;
    }else{
        cout<<"La cadena no es aceptada"<<endl;
        return -1;
    }
    
}


void Parser::error(string msg)
{
    cout<<"ERROR SINTACTICO: "<<msg<<endl;
    exit(EXIT_FAILURE);
}