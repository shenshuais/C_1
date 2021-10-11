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
    //Lexer *lexer;
    int token;

public:
    Parser(/* args */);
    ~Parser();
    void loadTable();
    void loadSymbols();
    void loadProds();
    int parse();
};

Parser::Parser(/* args */)
{
}

Parser::~Parser()
{
}
