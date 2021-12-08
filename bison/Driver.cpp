/**
 * @author Adrian Ulises Mercado Martínez
 * @version 1, 3/11/2021
 */

#include "Driver.hpp"
#include <iostream>
#include <sstream>
string Driver::newLabel()
{
    stringstream label;
    label<< "L"<<numLabel++;
    return label.str();
}
Driver::Driver()
{
    numType = 0;
    numLabel = 0;
    numTemp = 0;
    dir= 0;
    cteF = 0;
}


void Driver::setType(int type){
    gType = type;
}


void Driver::setFile(string name){
    gen.setFile(name);
}

Driver::~Driver()
{
    delete (lexer);
    lexer = nullptr;
    delete (parser);
    parser = nullptr;
}

/*
 * Función para generar etiquetas con la siguiente forma
 * L0, L1, L2, L3, ..., Ln
 */
string Driver::newLabel()
{
    stringstream label;
    label<< "L"<<numLabel++;
    return label.str();
}

string Driver::newLabel(int lab)
{
    stringstream label;
    label<< "L"<<lab;
    return label.str();
}

/*
 * Función para generar variables temporales con la siguiente forma
 * t0, t1, t2, t3, ..., tn
 */
string Driver::newTemp()
{
    stringstream temp;
    temp<<"t"<<numTemp++;
    return temp.str();
}

/*
 * Función para agregar una cuadrupla al código intermedio
 * @param res representa la dirección del resultado
 * @param arg1 representa la dirección del primer operando
 * @param arg2 representa la dirección del segundo operando
 * @param op representa el operador
 */
void Driver::genCode(string res, string arg1, string op, string arg2)
{
    icode.push_back(Quad(op, arg1, arg2, res));
}

/*
 * Función que agrega una etiqueta al código intermedio
 * @param label etiqueta para colocar en el código intermedio
 */
void Driver::_label(string label)
{
    icode.push_back(Quad("label","","",label ));
}

/*
 * Función para agregar un salto incondicional al código intermedio
 * @param label etiqueta destino del salto incondicional
 */
void Driver::_goto(string label)
{
    icode.push_back(Quad("goto","","",label ));
}


/*
 * Función para generar el código para un condición en código intemerdio
 * genera el salto condicional y el incondicional
 * @param var variable a evaluar en la condición
 * @param ltrue etiqueta para saltar en caso de verdadero
 */
void Driver::_if(string var, string label)
{
    icode.push_back(Quad("if", var,"goto",label));    
}

/*
 * Función para hacer un cast en caso de requerirse convertir de int a float
 * se pueden agregar mas tipos
 * @param dir dirección de la variable original
 * @param t1 tipo de la variable
 * @param t2 tipo deseado para la variable
 * @return devuelve el valor de la nueva dirección en caso de un cast o la original en caso de no hacerlo
 */
string Driver::ampliar(string dir, int t1, int t2)
{
    string temp;
    if(t1==t2) return dir;
    else if(t1==0 && t2==1){
        temp = newTemp();
        icode.push_back(Quad("(float)",dir, "", temp));
        addSym(temp, 1, "temporal");
        return temp;
    }else return "";
}

/*
 * Función para hacer un cast en caso de requerirse convertir de float a int
 * se pueden agregar mas tipos
 * @param dir dirección de la variable original
 * @param t1 tipo de la variable
 * @param t2 tipo deseado para la variable
 * @return devuelve el valor de la nueva dirección en caso de un cast o la original en caso de no hacerlo
 */
string Driver::reducir(string dir, int t1, int t2)
{
    string temp;
    if(t1==t2) return dir;
    else if(t1==1 && t2==0){
        temp = newTemp();
        icode.push_back(Quad("(int)",dir, "", temp));
        addSym(temp, 0, "temporal");        
        return temp;
    }else return "";
}

/*
 * Calcula el máximo entre dos tipos
 * @param t1 primer tipo 
 * @param t2 segundo tipo
 * @return el valor de tipo mayor entre t1 y t2
 */
int Driver::max(int t1, int t2)
{
    if(t1==t2) return t1;
    else if(t1==0 && t2==1) return 1;
    else if(t1==1 && t2==0) return 1;
    else return -1;
}

/*
 * Calcula el mínimo entre dos tipos
 * @param t1 primer tipo 
 * @param t2 segundo tipo
 * @return el valor de tipo mayor entre t1 y t2
 */
int Driver::min(int t1, int t2)
{
    if(t1==t2) return t1;
    else if(t1==0 && t2==1) return 0;
    else if(t1==1 && t2==0) return 0;
    else return -1;
}

/*
 * Función para agregar un símbolo a la tabla de símbolos e incrementar dir
 */
void Driver::addSym(string id, int type, string cat)
{
    addSym(id, dir, type, cat);
    dir += tt.getTam(type);
}

/*
 * Función para agregar un símbolo a la tabla de símbolos validando
 * que el id no se encuentra en la tabla en caso de que sí 
 * marca un error
 */
void Driver::addSym(string id, int dir, int type, string cat)
{
    if(!ts.is_in(id))
        ts.addSym(id, Sym(dir,type, cat));
    else
        error("La variable "+id+" ya fue declarada");
}

/*
 * Función para agregar un símbolo a la tabla de símbolos (del tipo función)
 * validando que el id no se encuentra en la tabla en caso de que sí 
 * marca un error (No se usa para este lenguaje)
 */
void Driver::addSym(string id, int dir, int type, string cat, vector<int> args)
{
    ts.addSym(id, Sym(dir,gType, cat, args));
}


/*
 * Función para agregar un tipo nuevo, se usa en caso de los arreglos
 * (no usado para este lenguaje)
 * @param name nombre del tipo por lo general array
 * @param items número de elementos del array
 * @param base tipo base del arreglo
 * @return indice del tipo dentro de la tabla de tipos
 */
int Driver::addType(string name, int items, int base)
{
    tt.addType(numType++,name,items, base);
    return numType-1;
}

/*
 * Función para agregar un tipo nuevo, se usa en caso de las estructuras
 * (no usado para este lenguaje)
 * @param name nombre del tipo por lo general struct 
 * @param tab tabla de símbolos que representa a la estructura
 * @return indice del tipo dentro de la tabla de tipos
 */
int Driver::addType(string name, SymTab *tab)
{
    tt.addType(numType++,name, tab);
    return numType-1;
}

/*
 * Función para realizar las comprobaciones semánticas para la operación de suma
 * @param e1 expresión para el primer operando
 * @param e2 expresión para el segundo operando
 * @return expresión que representa la variable temporal de resultado
 */
Expresion Driver::mas(Expresion e1, Expresion e2)
{
    Expresion e;
    //Obtiene el máximo de los dos tipos
    e.type = max(e1.type, e2.type);
    if(e.type != -1){
        // Se genera la dirección temporal para el resultado parcial
        e.dir = newTemp();
        addSym(e.dir, e.type, "temporal");
        //Se intenta hacer el cast el alguno de los operandos
        string alfa1 = ampliar(e1.dir, e1.type, e.type);
        string alfa2 = ampliar(e2.dir, e2.type, e.type);
        genCode(e.dir, alfa1, "+", alfa2);
    }else{
        error("Los tipos son incompatibles");
    }
    return e;
}

/*
 * Acciones semánticas para la resta similares  a la suma
 */
Expresion Driver::menos(Expresion e1, Expresion e2)
{
    Expresion e;
    e.type = max(e1.type, e2.type);
    if(e.type!=-1){
        string alfa1 = ampliar(e1.dir, e1.type, e.type);
        string alfa2 = ampliar(e2.dir, e2.type, e.type);
        genCode(e.dir, alfa1, "-", alfa2);
    }else{
        error("Los tipos son incompatibles");
    }
    return e;
}

/*
 * Acciones semánticas para la multiplicación similares  a la suma
 */
Expresion Driver::mul(Expresion e1, Expresion e2)
{
    Expresion e;
    e.type = max(e1.type, e2.type);
    if(e.type!=-1){
        string alfa1 = ampliar(e1.dir, e1.type, e.type);
        string alfa2 = ampliar(e2.dir, e2.type, e.type);
        genCode(e.dir, alfa1, "*", alfa2);
    }else{
        error("Los tipos son incompatibles");
    }
    return e;
}

/*
 * Acciones semánticas para la división similares  a la suma
 */
Expresion Driver::div(Expresion e1, Expresion e2)
{
    Expresion e;
    e.type = max(e1.type, e2.type);
    if(e.type!=-1){
        string alfa1 = ampliar(e1.dir, e1.type, e.type);
        string alfa2 = ampliar(e2.dir, e2.type, e.type);
        genCode(e.dir, alfa1, "/", alfa2);
    }else{
        error("Los tipos son incompatibles");
    }
    return e;
}

/*
 * Función para las acciones semánticas de asignación
 * prueba la compatibilidad de tipos entre el id y la expresión que se le quiere asignar
 * @param id el identificador al que se le va asignar un valor
 * @param expresión la expresión de donde se obtiene el valor para el id
 * @return la expresión resultado
 */
Expresion Driver::asig(string id, Expresion e)
{
    Expresion e1;
    string alfa;
    //Validar que el id fue declarado
    if(!ts.is_in(id)) error("La variable "+id+" no fue declarada");
    int typeId = ts.getType(id);
    e1.type = typeId; //La expresión de salida siempre tendrá el tipo del id
    if(typeId == e.type){
        alfa = e.dir;
    }
    else if(typeId>e.type)
    {
        alfa = ampliar(e.dir, e.type, e1.type);
    }
    else if(min(typeId, e.type)!=1)
    {    
        alfa = reducir(e.dir, e.type, e1.type);        
    }
    else
    {
        error("Los tipos son incompatibles");
    }
    genCode(id, alfa, "=", "");
    e.dir = id;        
    return e1;
}

/*
 * Función para generar un tipo expresión a partir de un identificador
 * válida que el identificador haya sido declarado
 * @param id el identificador a ser validado
 * @return la expresión formada por id como dir y el tipo obtenido de la Tabla de símbolos
 */
Expresion Driver::ident(string id)
{
    Expresion e;
    if(ts.is_in(id)){ //Se válida que exista el id
        e.dir = id;
        e.type = ts.getType(id); // Se obtiene el tipo del id
    }else{
        error("El identificador "+ id + " no fue declarado");
    }
    return e;    
}

/*
 * Función para generar una expresión de un número 
 * Si el número es de tipo flotante genera una constante para agregarla al ensamblador
 * @param val el valor de yytext del número actual
 * @param type el tipo retornado por el lexer
 * @return la expresión formada por la tupla<val, type>
 */
Expresion Driver::numero(string val, int type)
{
    Expresion e;
    if(type ==1){
        stringstream nombre;
        nombre<<"cteFloat"<<cteF++; //Genera una nueva constante flotante
        constantes[nombre.str()] = val; //Agrega la constante al mapa de constantes flotantes
        e.dir= nombre.str();
    }else{
        e.dir =val;
    }
    e.type = type;
    return e;
}

void Driver::error(string msg)
{
    cout<<"Error semántico "<<msg<<endl;
    exit(EXIT_FAILURE);
}


/*
 * Función para imprimir el código intermedio al finalizar el análisis semántico
 * y la generación de código intermedio
 */
void Driver::print()
{
    for(vector<Quad>::iterator q = icode.begin(); q != icode.end(); q++)
    {
        q->print();
    }
    cout<<endl;
}


/*
 * Función para traducir el código intermedio en el código destino final
 */
void Driver::translate()
{
    gen.translate(&ts); // Traduce la tabla de símbolos en variables globales
    gen.translate(constantes); // Traduce las constantes como variables globales
    gen.translate(icode, &ts);   // Traduce las instrucciones a código MIPS
}


void Driver::pushLabel(int label)
{
    labelStack.push(label);
}

void Driver::popLabel(){
    labelStack.pop();
}

int Driver::topLabel()
{
    return labelStack.top();
}

int Driver::newLab()
{
    return ++numLabel;
}

int Driver::element(int i)
{    
    return labelStack[i];
}


void Driver::parse(const string& filename)
{
    filebuf fb;    
    fb.open(filename, ios::in);
    std::istream in_file(&fb);
    string output;
    size_t found = filename.find(".");
    if(found!=string::npos){
        output = filename.substr(0,found);
    }else
        output = filename;
    setFile(output);
    
    if (!in_file.good())
    {
        exit(EXIT_FAILURE);
    }
    parse_helper(in_file);
    return;
}

void Driver::parse_helper(std::istream &stream)
{
    
    delete (lexer);
    try
    {
        lexer = new Lexer(&stream);
        
    }
    catch (std::bad_alloc &ba)
    {
        std::cerr << "Error al crear lexer: (" << ba.what() << "), exiting!!\n";
        exit(EXIT_FAILURE);
    }

    delete (parser);
    try
    {
        parser = new yy::Parser((*lexer) /* lexer */,
                                   (*this) /* driver */);
    }
    catch (std::bad_alloc &ba)
    {
        std::cerr << "Error al crear parser: (" << ba.what() << "), exiting!!\n";
        exit(EXIT_FAILURE);
    }
    const int accept(0);
    if (parser->parse() != accept)
    {
        std::cerr << "¡Error de sintaxis!\n";
    }
    return;
}

int Driver::getType()
{
    return gType;
}