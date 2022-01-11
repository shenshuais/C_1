/**
 * @author Adrian Ulises Mercado Martínez
 * @version 1, 3/11/2021
 */
#include "Sym.hpp"

Sym::Sym()
{
}

/*
 * Crea un símbolo para una variable
 */
Sym::Sym(int dir, int type, string cat)
{
    this->dir = dir;
    this->type = type;
    this->cat = cat;
}

/*
 * Crea un símbolo para una función
 */
Sym::Sym(int dir, int type, string cat, vector<int> args)
{
    this->dir = dir;
    this->type = type;
    this->cat = cat;
    this->args = args;
}


Sym::~Sym()
{
}

int Sym::getDir()
{
    return dir;
}

int Sym::getType()
{
    return type;
}

string Sym::getCat()
{
    return cat;
}

vector<int> Sym::getArgs()
{
    return args;
}
