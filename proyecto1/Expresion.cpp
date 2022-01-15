#include "Expresion.hpp"

using namespace std;

Expresion::Expresion(int tipo, string dir){
            this->tipo = tipo;
            this->dir = dir;
}

Expresion::Expresion(int tipo){
            this->dir = dir;
}

Expresion::Expresion(string dir){
            this->dir = dir;
}

Expresion::Expresion(string ltrue, string lfalse)
        {
            this->ltrue = ltrue;
            this->lfalse = lfalse;
        }

Expresion::Expresion(int tipo, string dir,string ltrue, string lfalse){
            this->tipo = tipo;
            this->dir = dir;
            this->ltrue = ltrue;
            this->lfalse = false;
        }