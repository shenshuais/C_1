/**
 * @author Adrian Ulises Mercado Martínez
 * @version 1, 3/11/2021
 */
#include "Type.hpp"

Type::Type()
{
}

Type::~Type()
{
}

/*
 * Crea un tipo a partir de su nombre y tamaño
 * sirve para los tipos nativos
 * @param name nombre del tipo
 * @param tam tamaño del tipo nativo
 */
Type::Type(string name, int tam)
{
    this->name = name;
    this->isTable=false;
    this->base.base = -1;
    this->items= -1;
    this->tam = tam;
}

/*
 * Crea un tipo para las estructuras
 * @param name nombre del tipo (struct)
 * @param tab tabla de símbolos para la estructura
 * @param tam tamaño en bytes de la tabla de símbolos
 */
Type::Type(string name, SymTab *tab, int tam)
{
    this->name = name;
    this->isTable=true;
    this->base.tab = tab;
    this->items= -1;
    this->tam = tam;
}

/*
 * Crea un tipo para los arreglos
 * @param name nombre del tipo (array)
 * @param items número de elementos del arreglo
 * @param tam tamaño en bytes
 */
Type::Type(string name, int items, int base, int tam)
{
    this->name = name;
    this->isTable=false;
    this->base.base = base;
    this->items= items;
    this->tam = tam;
}

int Type::getTam()
{
    return tam;
}

SymTab *Type::getTab()
{
    if(isTable) return base.tab;
    return nullptr;
}   

int Type::getItems()
{
    return items;
}

int Type::getBase()
{
    if(!isTable) return base.base;
    return -1;
}

string Type::getName()
{
    return  name;
}