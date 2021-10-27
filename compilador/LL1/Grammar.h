#ifndef GRAMMAR_H
#define GRAMMAR_H

#include <string>
#include <vector>
#include <map>
using namespace std;

#include "Symbol.h"
#include "Production.h"

class Grammar
{
public:
    map<int, Symbol> syms;
    int term, noTerm; // numero terminales y no terminales
    int start;
    map<int, Production>  prods;

public:
    Grammar(/* args */);
    ~Grammar();
    void setNum(int term, int noTerm);
    void addSymbol(int i, Symbol s);
    void addProd(int i, Production p);
    Symbol getSym(int i);
    Production getProd(int i);
};




#endif // !GRAMMAR_H