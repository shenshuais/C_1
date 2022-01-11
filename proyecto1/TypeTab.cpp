/**
 * @author Adrian Ulises Mercado Martínez
 * @version 1, 3/11/2021
 */
#include "TypeTab.hpp"

TypeTab::TypeTab(/* args */)
{
}

TypeTab::~TypeTab()
{
}

/*
 * Función para agregar un tipo nativo en la tabla de tipos
 */
void TypeTab::addType(int id, string name, int tam)
{
    types[id] = Type(name, tam);
}

/*
 * Función para agregar un tipo de array en la tabla de tipos
 */
void TypeTab::addType(int id, string name, int items,  int base)
{
    int tam = types[base].getTam()*items;
    types[id] = Type(name, items, base, tam);
}

/*
 * Función para agregar un tipo struct en la tabla de tipos
 */
void TypeTab::addType(int id, string name, SymTab *tab)
{
    int tam = 100;
    types[id] = Type(name, tab, tam);
}

/****************************************************************************************/
/* Funciones para devolver las características de un tipo de acuerdo a su identificador */
/****************************************************************************************/

int TypeTab::getTam(int id)
{
    return types[id].getTam();
}

int TypeTab::getItems(int id)
{
    return types[id].getItems();
}

SymTab *TypeTab::getTab(int id)
{
    return types[id].getTab();
}

int TypeTab::getBase(int id)
{
    return types[id].getBase();
}

string TypeTab::getName(int id)
{
    return types[id].getName();
}