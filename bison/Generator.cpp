/**
 * @author Adrian Ulises Mercado Martínez
 * @version 1, 3/11/2021
 */
#include "Generator.hpp"

Generator::Generator()
{ 
}

void Generator::setFile(string name)
{
    name += ".mips";
    openFile(name);
}




Generator::~Generator()
{
}

/* 
 * Función para escribir la tabla de símbolos como variales globales en MIPS
 * @param ts tabla de símbolos a convertir
 */
void Generator::translate(SymTab *ts)
{
    
    file<<".data"<<endl;
    map<string,Sym> syms = ts->getSyms();
    for(map<string,Sym>::iterator sym=syms.begin();sym!=syms.end(); sym++ )
    {
        if(sym->second.getType()==0){
            file<<"\t"<<sym->first<<": .word 0"<<endl;
        }else{
            file<<"\t"<<sym->first<<": .float 0.0"<<endl;            
        }
    }

}

/*
 * Función para traducir las cuadruplas de acuerdo al tipo de resultados
 * @param icode código intermedio
 * @param ts tabla de símbolos para obtener el tipo del resultado
 */
void Generator::translate(vector<Quad> icode, SymTab *ts)
{
    
    file<<".text"<<endl;
    for(vector<Quad>::iterator q = icode.begin(); q!=icode.end(); q++){
        translate(*q, ts->getType(q->getRes()));
    }
    // Código final para terminar  la ejecución del programa en ensamblador
    file<<"\tli $v0, 10"<<endl;
    file<<"\tsyscall"<<endl;
    file.close();
}

/*
 * Función para traducir un cuadrupla de acuerto al tipo su tipo usa la tabla del documento
 * de código intermedio
 * @param q cuadrupla a traducir
 * @param type tipo para usar en la traducción
 */
void Generator::translate(Quad q, int type){
    switch (q.resolveQuad())
    {
        case QMAS: 
            if(type ==0){
                isNumber(q.getArg1())?
                file<<"\tli $t0,"<<q.getArg1()<<endl //Aqui ademas se debe comparar si es un entero o una variable
                :file<<"\tlw $t0,"<<q.getArg1()<<endl;
                //file<<"\tli $t0,"<<q.getArg1()<<endl; //En caso de ser un número
                isNumber(q.getArg2())?
                file<<"\tli $t0,"<<q.getArg2()<<endl //Aqui ademas se debe comparar si es un entero o una variable
                :file<<"\tlw $t0,"<<q.getArg2()<<endl;
                file<<"\tadd $t2, $t0, $t1"<<endl;
                file<<"\tsw $t2, "<<q.getRes()<<endl;
            }else{
                file<<"\tla $t0,"<<q.getArg1()<<endl;
                file<<"\tl.s $f0, ($t0)"<<endl;
                file<<"\tla $t1,"<<q.getArg2()<<endl;
                file<<"\tl.s $f1, ($t1)"<<endl;
                file<<"\tadd.s $f2, $f0, $f1"<<endl;
                file<<"\ts.s $f2, "<<q.getRes()<<endl;
            }
            break;
        case QMENOS:
            if(type ==0){ //Hacer la mismas comprobaciones que para la suma
                if(isNumber(q.getArg1()))
                    file<<"\tli $t0,"<<q.getArg1()<<endl;
                else
                    file<<"\tlw $t0,"<<q.getArg1()<<endl;
                if(isNumber(q.getArg2()))
                    file<<"\tli $t0,"<<q.getArg2()<<endl;
                else
                    file<<"\tlw $t0,"<<q.getArg2()<<endl;
                file<<"\tsub $t2, $t0, $t1"<<endl;
                file<<"\tsw $t2, "<<q.getRes()<<endl;
            }else{
                file<<"\tla $t0,"<<q.getArg1()<<endl;
                file<<"\tl.s $f0, ($t0)"<<endl;
                file<<"\tla $t1,"<<q.getArg2()<<endl;
                file<<"\tl.s $f1, ($t1)"<<endl;
                file<<"\tsub.s $f2, $f0, $f1"<<endl;
                file<<"\ts.s $f2, "<<q.getRes()<<endl;
            }
            break;
        case QMUL:
            if(type ==0){//Hacer la mismas comprobaciones que para la suma
                if(isNumber(q.getArg1()))
                    file<<"\tli $t0,"<<q.getArg1()<<endl;
                else
                    file<<"\tlw $t0,"<<q.getArg1()<<endl;
                if(isNumber(q.getArg2()))
                    file<<"\tli $t0,"<<q.getArg2()<<endl;
                else
                    file<<"\tlw $t0,"<<q.getArg2()<<endl;
                file<<"\tmul $t2, $t0, $t1"<<endl;
                file<<"\tsw $t2, "<<q.getRes()<<endl;
            }else{
                file<<"\tla $t0,"<<q.getArg1()<<endl;
                file<<"\tl.s $f0, ($t0)"<<endl;
                file<<"\tla $t1,"<<q.getArg2()<<endl;
                file<<"\tl.s $f1, ($t1)"<<endl;
                file<<"\tmul.s $f2, $f0, $f1"<<endl;
                file<<"\ts.s $f2, "<<q.getRes()<<endl;
            }
            break;
        case QDIV:
            if(type ==0){//Hacer la mismas comprobaciones que para la suma
                file<<"\tli $t0,"<<q.getArg1()<<endl;
                file<<"\tli $t1,"<<q.getArg2()<<endl;
                file<<"\tdiv.s $t2, $t0, $t1"<<endl;
                file<<"\tsw $t2, "<<q.getRes()<<endl;
            }else{
                file<<"\tla $t0,"<<q.getArg1()<<endl;
                file<<"\tl.s $f0, ($t0)"<<endl;
                file<<"\tla $t1,"<<q.getArg2()<<endl;
                file<<"\tl.s $f1, ($t1)"<<endl;
                file<<"\tdiv.s $f2, $f0, $f1"<<endl;
                file<<"\ts.s $f2, "<<q.getRes()<<endl;
            }
            break;
            
        case QIF:            
            file<<"\tlw $t0,"<<q.getArg1()<<endl;
            file<<"\tbne $t0, $zero, "<<q.getRes()<<endl;                
            break;

        case QGOTO:
            file<<"\tb "<<q.getRes()<<endl;
            break;
        case QCOPY:
            if(type == 0){
                if(isNumber(q.getArg1()))
                    file<<"\tli $t0,"<<q.getArg1()<<endl;
                else
                    file<<"\tlw $t0,"<<q.getArg1()<<endl;                
                file<<"\tsw $t0,  "<<q.getRes()<<endl;
            }else{
                file<<"\tla $t0,"<<q.getArg1()<<endl;
                file<<"\tl.s $f0, ($t0)"<<endl;
                file<<"\ts.s $f0,  "<<q.getRes()<<endl;
            }
            break;
        case QLABEL:
            file<<q.getRes()<<":";
            break;
        case QCASTFLOAT:
            file<<"\tlw $t0,"<<q.getArg1()<<endl;            
            file<<"\tmtc1 $t0,$f0"<<endl;
            file<<"\tcvt.s.w $f0,$f0"<<endl;
            file<<"\ts.s $f0, "<<q.getRes()<<endl;
            break;

        case QCASTINT:            
            file<<"\tla $t0,"<<q.getArg1()<<endl;
            file<<"\tl.s $f0, ($t0)"<<endl;
            file<<"\tcvt.w.s $f0,$f0"<<endl;
            file<<"\tmfc1 $t0,$f0"<<endl;            
            file<<"\tlw $t0, "<<q.getRes()<<endl;
            break;
        default:
            break;
    }
}

void Generator::openFile(string name){
    file.open(name, ios::out);
}

void Generator::translate(map<string, string> cf){
    for(map<string,string>::iterator c = cf.begin(); c != cf.end(); c++){
        file<<"\t"<<c->first<<": .float "<<c->second<<endl;
    }
}

bool Generator::isNumber(const string &str)
{
    return str.find_first_not_of("0123456789") == string::npos;
}