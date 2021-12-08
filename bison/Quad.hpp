/**
 * @author Adrian Ulises Mercado Martínez
 * @version 1, 3/11/2021
 */
#ifndef __QUAD_HPP__
#define __QUAD_HPP__

#include <string>
using namespace std;
/*
 * Una cuadrupla es una tupla para representar una instrucción de tres direcciones
 * Si la instruccion de tres direcciones se escribe de la siguiente forma
 * x = y op z la cuadrupla para representarla instruccion será
 * op, y, z, x, donde 
 * op es el operador
 * y es el argumento 1
 * z es el argumento2
 * x es la dirección de resultado
 */

//Tipos de operaciones de tres direcciones en cuadruplas
enum QuadType {QIF, QGOTO, QMAS, QMENOS, QMUL, QDIV, QCOPY, QLABEL, QCASTINT, QCASTFLOAT, QSIN};


class Quad
{
private:
    string op;
    string arg1;
    string arg2;
    string res;
public:
    Quad();
    Quad(string op, string arg1, string arg2, string res);    
    ~Quad();

    void print();
    //Funcion para representar un op de tipo string en un op de tipo enum
    QuadType resolveQuad(string op);
    QuadType resolveQuad();
    
    string getRes();
    string getArg1();
    string getArg2();
    string getOp();
};

#endif // !__QUAD_HPP__