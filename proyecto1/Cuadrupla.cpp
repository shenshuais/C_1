#include "Cuadrupla.hpp"
#include <iostream>
Cuadrupla::Cuadrupla(/* args */)
{
}

Cuadrupla::Cuadrupla( string arg1, string arg2, string op, string res)
{
    this->arg1 = arg1;
    this->arg2 = arg2;
    this->op = op;
    this->res = res;
}

Cuadrupla::~Cuadrupla()
{
}

QuadType Cuadrupla::resolveQuad(){
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
    //Agregar más operadores
    return QSIN;
}

void Cuadrupla::print()
{
    switch(resolveQuad()){
        //Faltan más casos :)
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


string Cuadrupla::getRes()
{
    return res;
}

string Cuadrupla::getArg1()
{
    return arg1;
}

string Cuadrupla::getArg2()
{
    return arg2;
}

string Cuadrupla::getOp()
{
    return op;
}