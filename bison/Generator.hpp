/**
 * @author Adrian Ulises Mercado Martínez
 * @version 1, 3/11/2021
 */
#ifndef __GENERATOR_HPP__
#define __GENERATOR_HPP__

#include <vector>
#include <fstream>
#include <string>
using namespace std;
#include "Quad.hpp"
#include "SymTab.hpp"

class Generator
{
private:
    ofstream file;
public:
    Generator();
    ~Generator();
    void translate(vector<Quad> icode, SymTab *ts);
    void translate(Quad q, int type);
    void translate(map<string, string> cf);
    void translate(SymTab *ts);
    void openFile(string name);
    bool isNumber(const string &str);
    void setFile(string name);
};

#endif // !__GENERATOR_HPP__
