/**
 * @author Adrian Ulises Mercado Martínez
 * @version 1, 3/11/2021
 */
#ifndef __TYPE_HPP__
#define __TYPE_HPP__
#include <string>
using namespace std;

#include "SymTab.hpp"

union TypeBase{
    SymTab *tab;
    int base;
};

class Type
{
private:
    string name;
    int tam;
    int items;
    bool  isTable;
    TypeBase base;
public:
    Type();
    Type(string name, int tam);
    Type(string name, SymTab *tab, int tam);
    Type(string name, int items, int base, int tam);
    ~Type();
    int getTam();
    SymTab *getTab();
    int getItems();
    int getBase();
    string getName();
};

#endif // !__TYPE_HPP__