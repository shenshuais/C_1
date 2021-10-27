#include "Symbol.h"

Symbol::Symbol(/* args */)
{
}

Symbol::Symbol(string name, TYPESYM type, int id, int idx)
{
    this->name = name;
    this->type = type;
    this->id = id;
    this->idx = idx;
}

Symbol::~Symbol()
{
}

void Symbol::setName(string name)
{
    this->name = name;
}

void Symbol::setType(TYPESYM type)
{
    this->type = type;
}

void Symbol::setId(int id)
{
    this->id = id;
}

void Symbol::setIdx(int idx)
{
    this->idx = idx;
}

string Symbol::getName()
{
    return name;
}

TYPESYM Symbol::getType()
{
    return type;
}

int Symbol::getId()
{
    return id;
}

int Symbol::getIdx()
{
    return idx;
}