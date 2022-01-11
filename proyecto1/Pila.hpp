/**
 * @author Adrian Ulises Mercado Martínez
 * @version 1, 3/11/2021
 */
#ifndef __PILA_HPP__
#define __PILA_HPP__
#include <vector>
#include "SymTab.hpp"
using namespace std;

template <class T>
class Pila{
private:
    vector<SymTab*> data;
public:
    Pila() = default;
    ~Pila() {};
    void push(SymTab *);
    SymTab top();
    SymTab &operator[](int i);
    SymTab pop();
};

template<class T>
void Pila<T>::push(T dat)
{
    data.push_back(dat);
}

template<class T>
T Pila<T>::top()
{
    int size = data.size()-1;
    return data[size];
}

template<class T>
T &Pila<T>::operator[](int i)
{
    int size = data.size()-1;
    return data[size-i];
}

template<class T>
T Pila<T>::pop(){
    int size = data.size()-1;
    T dato = data[size];
    data.pop_back();
    return dato;
}

#endif // !__PILA_HPP__