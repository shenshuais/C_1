/**
 * @author Adrian Ulises Mercado Martínez
 * @version 1, 3/11/2021
 */
#ifndef __SYM_HPP__
#define __SYM_HPP__

#include <string>
#include <vector>
using namespace std;


class Sym
{
private:
    int dir;
    int type;
    string cat;
    vector<int> args;

public:
    Sym();
    Sym(int dir, int type, string cat);
    Sym(int dir, int type, string cat, vector<int> args);
    ~Sym();

    int getDir();
    int getType();
    string getCat();
    vector<int> getArgs();
    
};




#endif // !__SYM_HPP__
