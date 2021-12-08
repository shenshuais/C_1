#include "Driver.hpp"
#include <sstream>
#include <string>

Expresion Driver::disyunción(Expresion e1, Expresion e2){
    Expresion e;
    e.tipo = 2; // Depende de la tabla de tipos
    e.dir = nuevaTemporal();
    if(compatibles(e1.tipo, e2.tipo)){
        Cuadrupla c;
        c.arg1 = e1.dir;
        c.arg2 = e2.dir;nuevaTemporal()
        c.resultado = e.dir;
        c.operador = "||";
        codigo_intermedio.push_back(c);
    }else{
        error_semantico("Los tipos de los operandos son incompatibles");
    }
}

Expresion Driver::conjuncion(Expresion e1, Expresion e2){
    Expresion e;
    e.tipo = 2; // Depende de la tabla de tipos
    e.dir = nuevaTemporal();
    if(compatibles(e1.tipo, e2.tipo)){
        Cuadrupla c;
        c.arg1 = e1.dir;
        c.arg2 = e2.dir;
        c.resultado = e.dir;
        c.operador = "&&";
        codigo_intermedio.push_back(c);
    }else{
        error_semantico("Los tipos de los operandos son incompatibles");
    }
}

Expresion Driver::igual(Expresion e1, Expresion e2){
    Expresion e;
    e.tipo = 2; // Depende de la tabla de tipos
    e.dir = nuevaTemporal();
    if(compatibles(e1.tipo, e2.tipo)){
        Cuadrupla c;
        c.arg1 = e1.dir;
        c.arg2 = e2.dir;
        c.resultado = e.dir;
        c.operador = "==";
        codigo_intermedio.push_back(c);
    }else{
        error_semantico("Los tipos de los operandos son incompatibles");
    }
}

Expresion Driver::distinto(Expresion e1, Expresion e2){
    Expresion e;
    e.tipo = 2; // Depende de la tabla de tipos
    e.dir = nuevaTemporal();
    if(compatibles(e1.tipo, e2.tipo)){
        Cuadrupla c;
        c.arg1 = e1.dir;
        c.arg2 = e2.dir;
        c.resultado = e.dir;
        c.operador = "!=";
        codigo_intermedio.push_back(c);
    }else{
        error_semantico("Los tipos de los operandos son incompatibles");
    }
}

Expresion Driver::mayor_que(Expresion e1, Expresion e2){
    Expresion e;
    e.tipo = 2; // Depende de la tabla de tipos
    e.dir = nuevaTemporal();
    if(compatibles(e1.tipo, e2.tipo)){
        Cuadrupla c;
        c.arg1 = e1.dir;
        c.arg2 = e2.dir;
        c.resultado = e.dir;
        c.operador = ">";
        codigo_intermedio.push_back(c);
    }else{
        error_semantico("Los tipos de los operandos son incompatibles");
    }
}

Expresion Driver::menor_que(Expresion e1, Expresion e2){
    Expresion e;
    e.tipo = 2; // Depende de la tabla de tipos
    e.dir = nuevaTemporal();
    if(compatibles(e1.tipo, e2.tipo)){
        Cuadrupla c;
        c.arg1 = e1.dir;
        c.arg2 = e2.dir;
        c.resultado = e.dir;
        c.operador = "<";
        codigo_intermedio.push_back(c);
    }else{
        error_semantico("Los tipos de los operandos son incompatibles");
    }
}

Expresion Driver::mayor_o_igual(Expresion e1, Expresion e2){
    Expresion e;
    e.tipo = 2; // Depende de la tabla de tipos
    e.dir = nuevaTemporal();
    if(compatibles(e1.tipo, e2.tipo)){
        Cuadrupla c;
        c.arg1 = e1.dir;
        c.arg2 = e2.dir;
        c.resultado = e.dir;
        c.operador = ">=";
        codigo_intermedio.push_back(c);
    }else{
        error_semantico("Los tipos de los operandos son incompatibles");
    }
}

Expresion Driver::menor_o_igual(Expresion e1, Expresion e2){
    Expresion e;
    e.tipo = 2; // Depende de la tabla de tipos
    e.dir = nuevaTemporal();
    if(compatibles(e1.tipo, e2.tipo)){
        Cuadrupla c;
        c.arg1 = e1.dir;
        c.arg2 = e2.dir;
        c.resultado = e.dir;
        c.operador = "<=";
        codigo_intermedio.push_back(c);
    }else{
        error_semantico("Los tipos de los operandos son incompatibles");
    }
}

Expresion Driver::suma(Expresion e1, Expresion e2){
    Expresion e;
    e.tipo = max(e1.type, e2.type); // Depende de la tabla de tipos
    e.dir = nuevaTemporal();
    if(e.tipo!=-1){
        string alfa1 = ampliar(e1.dir, e1.type, e.type);
        string alfa2 = ampliar(e2.dir, e2.type, e.type);
        genCode(e.dir, alfa1, "+", alfa2);
    }else{
        error_semantico("Los tipos de los operandos son incompatibles");
    }
}

Expresion Driver::resta(Expresion e1, Expresion e2){
    Expresion e;
    e.tipo = max(e1.type, e2.type); // Depende de la tabla de tipos
    e.dir = nuevaTemporal();
    if(e.tipo!=-1){
        string alfa1 = ampliar(e1.dir, e1.type, e.type);
        string alfa2 = ampliar(e2.dir, e2.type, e.type);
        genCode(e.dir, alfa1, "-", alfa2);
    }else{
        error_semantico("Los tipos de los operandos son incompatibles");
    }
}

Expresion Driver::division(Expresion e1, Expresion e2){
    Expresion e;
    e.tipo = max(e1.type, e2.type); // Depende de la tabla de tipos
    e.dir = nuevaTemporal();
    if(e.tipo!=-1){
        string alfa1 = ampliar(e1.dir, e1.type, e.type);
        string alfa2 = ampliar(e2.dir, e2.type, e.type);
        genCode(e.dir, alfa1, "/", alfa2);
    }else{
        error_semantico("Los tipos de los operandos son incompatibles");
    }
}

Expresion Driver::multiplicacion(Expresion e1, Expresion e2){
    Expresion e;
    e.tipo = max(e1.type, e2.type); // Depende de la tabla de tipos
    e.dir = nuevaTemporal();
    if(e.tipo!=-1){
        string alfa1 = ampliar(e1.dir, e1.type, e.type);
        string alfa2 = ampliar(e2.dir, e2.type, e.type);
        genCode(e.dir, alfa1, "*", alfa2);
    }else{
        error_semantico("Los tipos de los operandos son incompatibles");
    }
}

Expresion Driver::negacion(Expresion e1){
    Expresion e;
    e.tipo = 2; // Depende de la tabla de tipos
    e.dir = nuevaTemporal();
    genCode(e.dir, "", "*", e1.dir);
}

bool Driver::compatibles(int t1, int t2){
    std::string nombre = tt.getNombre(t1);
    std::string nombre2 = tt.getNombre(t2);
    if(nombre =="struct" && nombre2=="struct"){
        //Validar la equivalencia de los campos de los tipos
        //estructurados
    }
    if(t1==t2) return true;
    if(t1 ==1 || t2 == 2) return true;
    if(t1 ==2 || t2 == 3) return true;
    if(t1 ==3 || t2 == 4) return true;
    return false;
    
}

string Driver::ampliar(string dir, int t1, int t2)
{
    string temp;
    if(t1==t2) return dir;
    else if((t1==1 && t2==2)){
        temp = newTemp();

        Cuadrupla c;
        c.arg1 = dir;
        c.arg2 = "";
        c.resultado = temp;
        c.operador = "(int)";
        codigo_intermedio.push_back(c);
        //¿Como agregar los temporales?
        //pilaTemporal.push(1); 
        return temp;
    }else if(t1==2 && t2==3){
        temp = newTemp();

        Cuadrupla c;
        c.arg1 = dir;
        c.arg2 = "";
        c.resultado = temp;
        c.operador = "(float)";
        codigo_intermedio.push_back(c);
        //¿Como agregar los temporales?
        //pilaTemporal.push(1); 
    }else if(t1==3 && t2==4){
        temp = newTemp();

        Cuadrupla c;
        c.arg1 = dir;
        c.arg2 = "";
        c.resultado = temp;
        c.operador = "(double)";
        codigo_intermedio.push_back(c);
        //¿Como agregar los temporales?
        //pilaTemporal.push(1); 
    } else return "";
}

string Driver::reducir(string dir, int t1, int t2)
{
    string temp;
    if(t1==t2) return dir;
    else if((t1==2 && t2==1)){
        temp = newTemp();

        Cuadrupla c;
        c.arg1 = dir;
        c.arg2 = "";
        c.resultado = temp;
        c.operador = "(char)";
        codigo_intermedio.push_back(c);
        //¿Como agregar los temporales?
        //pilaTemporal.push(1); 
        return temp;
    }else if(t1==3 && t2==2){
        temp = newTemp();

        Cuadrupla c;
        c.arg1 = dir;
        c.arg2 = "";
        c.resultado = temp;
        c.operador = "(int)";
        codigo_intermedio.push_back(c);
        //¿Como agregar los temporales?
        //pilaTemporal.push(1); 
    }else if(t1==4 && t2==3){
        temp = newTemp();

        Cuadrupla c;
        c.arg1 = dir;
        c.arg2 = "";
        c.resultado = temp;
        c.operador = "(float)";
        codigo_intermedio.push_back(c);
        //¿Como agregar los temporales?
        //pilaTemporal.push(1); 
    } else return "";
}

int Driver::max(int t1, int t2)
{
    if(t1==t2) return t1;
    else if(t1==1 && t2==2) return 2;
    else if(t1==2 && t2==1) return 2;
    else if(t1==2 && t2==3) return 3;
    else if(t1==3 && t2==2) return 3;
    else if(t1==3 && t2==4) return 4;
    else if(t1==4 && t2==3) return 4;
    else return -1;
}

int Driver::min(int t1, int t2)
{
    if(t1==t2) return t1;
    else if(t1==1 && t2==2) return 1;
    else if(t1==2 && t2==1) return 1;
    else if(t1==2 && t2==3) return 2;
    else if(t1==3 && t2==2) return 2;
    else if(t1==3 && t2==4) return 3;
    else if(t1==4 && t2==3) return 3;
    else return -1;
}


Expresion Driver::identificador(std::string id){
    Expresion e;
    if(ts.is_in(id)){ //Se válida que exista el id
        e.dir = id;
        e.tipo = ts.getType(id); // Se obtiene el tipo del id
    }else{
        error_semantico("El identificador "+ id + " no fue declarado");
    }
    return e;  
}


Expresion Expresion::numero(std::string val, int tipo){
    if( tipo == 2 || tipo == 3){
        stringstream cte;
        cte<<"cteFloat"<<cteFloat++;
        Numero num;
        num.val = val;
        num.tipo = tipo;
        contantes[cte.str()] = num;
    }
}


void error_semantico(std::string mensaje){
    cout<<"Error semántico "<<mensaje<<endl;
    exit(EXIT_FAILURE);
}

int Driver::nuevaEtiqueta()
{
    return ++numEtiquetas;
}

Expresion Driver::asignacion(string id, Expresion e)
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

int Driver::agregar_tipo(string name, SymTab *tab)
{
    tt.addType(numType++,name, tab);
    return numType-1;
}

void Driver::agregar_simbolo(string id, int dir, int type, string cat, vector<int> args)
{
    ts.addSym(id, Sym(dir,gType, cat, args));
}

void Driver::agregar_simbolo(string id, int dir, int type, string cat)
{
    if(!ts.is_in(id))
        ts.addSym(id, Sym(dir,type, cat));
    else
        error("La variable "+id+" ya fue declarada");
}

/*
 * Función para agregar un símbolo a la tabla de símbolos e incrementar dir
 */
void Driver::agregar_simbolo(string id, int type, string cat)
{
    agregar_simbolo(id, dir, type, cat);
    dir += tt.getTam(type);
}

void Driver::gen_if(string var, string label)
{
    codigo_intermedio.push_back(Cuadrupla( var,"goto","if",label));    
}

void Driver::genCode(string res, string arg1, string op, string arg2)
{
    codigo_intermedio.push_back(Cuadrupla( arg1, arg2, op, res));
}

void Driver::gen_goto(string label)
{
    codigo_intermedio.push_back(Cuadrupla("","","goto",label ));
}

void Driver::gen_label(string label)
{
    codigo_intermedio.push_back(Cuadrupla("","","label",label ));
}

string Driver::nuevaTemporal()
{
    stringstream temp;
    temp<<"t"<<numTemporales++;
    return temp.str();
}

string Driver::nuevaEtiqueta(int lab)
{
    stringstream label;
    label<< "L"<<lab;
    return label.str();
}

string Driver::nuevaEtiqueta()
{
    stringstream label;
    label<< "L"<<numEtiquetas++;
    return label.str();
}