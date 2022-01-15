#include "Pila.hpp"


Pila::~Pila(){
    data.clear();
}

void Pila::push(SymTab *ts)
{
    data.push_back(ts);
}

SymTab *Pila::pop(){
    int size = data.size()-1;
    SymTab *s = data[size];
    data.pop_back();
    return s;
}


SymTab *Pila::top()
{
    int size = data.size()-1;
    SymTab *s = data[size];
    data.pop_back();
    return s;
}


SymTab *Pila::bottom(){
    return data[0];
}