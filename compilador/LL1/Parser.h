#include "Symbol.h"
#include "Production.h"

#include <map>
#include <vector>
using namespace std;
class Parser
{
private:
    map< int, map<int, int> > table;
    map<int, Symbol> Syms;
    vector<Production> prod;

public:
    Parser(/* args */);
    ~Parser();
    void loadSymbols();
    void loadProds();
};

Parser::Parser(/* args */)
{
}

Parser::~Parser()
{
}
