#ifndef __EXPRESION_HPP__
#define __EXPRESION_HPP__

#include <string>
using namespace std;

class Expresion{

    public:
        int tipo;
        string ltrue;
        string lfalse;
        string dir;
        Expresion() = default;
        Expresion(int tipo, string dir);
        Expresion(int tipo);
        Expresion(string dir);
        Expresion(string ltrue, string lfalse);
        Expresion(int tipo, string dir,string ltrue, string lfalse);

};

#endif