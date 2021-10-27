#ifndef PARSER_H
#define PARSER_H

#include <map>
#include <stack>
#include <vector>
using namespace std;

#include "Grammar.h"
#include "Lexer.h"



class Parser
{
private:
    map<int, map<int, int>> table;
    Grammar grammar;    
    Lexer *lexer;
    int token;
public:
    Parser(Lexer *lexer);
    ~Parser();
    void loadSymbols();
    void loadProds();
    void loadTable();
    int parse();
    void error(string  msg);
};

#endif // PARSER_H