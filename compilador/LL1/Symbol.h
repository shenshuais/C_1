#ifndef SYMBOL_H
#define SYMBOL_H

#include<string>
using namespace std;

enum TYPESYM {terminal, noterminal, cadena};

class Symbol
{

    private:
        string name;
        TYPESYM type;
        int id;

    public:
        Symbol(/* args*/);
        Symbol(string name, TYPESYM type, int id);
        ~Symbol();

        void setName(string name);
        void setType(TYPESYM type);
        void setId(TYPESYM type);

        string getName();
        TYPESYM getType();
        int getId();


};

#endif