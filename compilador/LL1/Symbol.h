#ifndef SYMBOL_H
#define SYMBOL_H

#include <string>
using namespace std;

enum TYPESYM {terminal, noterminal, cadenaVacia};
class Symbol
{
private:
    string name;
    TYPESYM type;
    int id;
    int idx;

public:
    Symbol(/* args */);
    Symbol(string name, TYPESYM type, int id, int idx);
    ~Symbol();

    void setName(string name);
    void setType(TYPESYM type);
    void setId(int id);
    void setIdx(int idx);

    string getName();
    TYPESYM getType();
    int getId();
    int getIdx();

};

#endif // SYMBOL_H