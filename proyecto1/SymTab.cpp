/**
 * @author Adrian Ulises Mercado Martínez
 * @version 1, 3/11/2021
 */
#include "SymTab.hpp"

SymTab::SymTab()
{
}

SymTab::~SymTab()
{
}

/*
 * Agrega un símbolo a la tabla de símbolos
 */
void SymTab::addSym(string id, Sym s)
{
    syms[id] = s;
}

/*******************************************************************************/
/*    Funciones para acceder a la información en la tabla de símbolos **********/
/*******************************************************************************/

int SymTab::getDir(string id)
{
    return syms[id].getDir();
}

int SymTab::getType(string id)
{
    return syms[id].getType();
}

string SymTab::getCat(string id)
{
    return syms[id].getCat();
}

vector<int> SymTab::getArgs(string id)
{
    return syms[id].getArgs();
}

bool SymTab::is_in(string id)
{
    map<string,Sym>::iterator it;
    it = syms.find(id);
    return it != syms.end();
}

map<string,Sym> SymTab::getSyms()
{
    return syms;
}