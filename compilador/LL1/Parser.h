#include "Symbol.h"
#include "Production.h"

#include <map>
#include <vector>
using namespace std;
class Parser
{
private:
    map< int, map<int, int> > table;
    map<int, Symbol> syms;
    vector<Production> prod;

public:
    Parser(/* args */);
    ~Parser();
    void loadTable();
    void loadSymbols();
    void loadProds();
};

Parser::Parser(/* args */)
{
}

Parser::~Parser()
{
}
