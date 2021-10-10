#include "Symbol.h"
#include<iostream>
using namespace std;

namespace C_1{

    Symbol::Symbol(string name,TYPESYM type,int id){
        this->name = name;
        this->type = type;
        this -> id = id;
    }

    int Symbol::getId(){   
        return this->id;
    }

    string Symbol::getName(){
        return this->name;
    }
    
    TYPESYM Symbol::getType(){
        return this->type;
    }

}