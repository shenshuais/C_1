
void Pila::push(SymTab *ts)
{
    data.push_back(ts);
}

SymTab Pila::top()
{
    int size = data.size()-1;
    return data[size];
}

SymTab Pila::pop(){
    int size = data.size()-1;
    T dato = data[size];
    data.pop_back();
    return dato;
}
