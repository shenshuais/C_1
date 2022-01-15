#ifndef __PILA_HPP__
#define __PILA_HPP__
#include <vector>
#include "SymTab.hpp"
using namespace std;

class Pila{
private:
    vector<SymTab*> data;
public:
    Pila() = default;
    ~Pila();
    void push(SymTab *);
    SymTab *top();
    SymTab *pop();
    SymTab *bottom();
};

#endif // !__PILA_HPP__