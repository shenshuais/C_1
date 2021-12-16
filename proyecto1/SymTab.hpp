/**
 * @author Adrian Ulises Mercado Martínez
 * @version 1, 3/11/2021
 */
#ifndef __SYMTAB_HPP__
#define __SYMTAB_HPP__

#include <string>
#include <vector>
#include <map>
using namespace std;

#include "Sym.hpp"

class SymTab
{
private:
    map<string, Sym> syms;
public:
    SymTab();
    ~SymTab();
    void addSym(string id, Sym s);
    int getDir(string id);
    int getType(string id);
    string getCat(string id);
    vector<int> getArgs(string id);
    bool is_in(string id);
    map<string,Sym> getSyms();
};

#endif // !__SYMTAB_HPP__