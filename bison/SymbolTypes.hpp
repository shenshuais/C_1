/**
 * @author Adrian Ulises Mercado Martínez
 * @version 1, 3/11/2021
 */
#ifndef __SYMBOLTYPES_HPP__
#define __SYMBOLTYPES_HPP__
#include <string>
using namespace std;

//Nuevos tipos que pueden devolver las funciones

struct Expresion{
    int type;
    string dir;
    Expresion(string dir, int type=0){
        this->type = type;
        this->dir = dir;
    };

    Expresion(int type=0){
        this->type = type;
        this->dir = "";
    };

};



#endif // !__SYMBOLTYPES_HPP__