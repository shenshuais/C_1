/**
 * @author Adrian Ulises Mercado Martínez
 * @version 1, 3/11/2021
 */
#include "Quad.hpp"
#include <iostream>
Quad::Quad(/* args */)
{
}

Quad::Quad(string op, string arg1, string arg2, string res)
{
    this->op = op;
    this->arg1 = arg1;
    this->arg2 = arg2;
    this->res = res;
}

Quad::~Quad()
{
}

QuadType Quad::resolveQuad(){
    if(op == "+") return QMAS;
    if(op == "-") return QMENOS;
    if(op == "*") return QMUL;
    if(op == "/") return QDIV;
    if(op == "=") return QCOPY;
    if(op == "if") return QIF;
    if(op == "goto") return QGOTO;
    if(op == "label") return QLABEL;
    if(op=="(float)") return QCASTFLOAT;
    if(op=="(int)") return QCASTINT;
    return QSIN;
}

void Quad::print()
{
    switch(resolveQuad()){
        case QMAS: 
        case QMENOS:
        case QMUL:
        case QDIV:
            cout<<res<<"="<<arg1<<op<<arg2<<endl;
            break;
        case QIF:
            cout<<op<<" "<<arg1<<" goto "<<res<<endl;
            break;
        case QGOTO:
            cout<<op<<" "<<res<<endl;
            break;
        case QCOPY:
            cout<<res<<op<<arg1<<endl;
            break;
        case QLABEL:
            cout<<res<<":";
            break;
        case QCASTFLOAT:
        case QCASTINT:
            cout<<res<<"="<<op<<arg1<<endl;
            break;
        default:
            break;
    }
}


string Quad::getRes()
{
    return res;
}

string Quad::getArg1()
{
    return arg1;
}

string Quad::getArg2()
{
    return arg2;
}

string Quad::getOp()
{
    return op;
}