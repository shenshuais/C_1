#include<stdlib.h>
#include<string.h>
#include <iostream>
#include<fstream>

using namespace std;

void lectura();
ifstream archivo;
int main(){
    
    char c;
    
    archivo.open("hola",ios::in);
    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }
    
        lectura();
         lectura();
          lectura();
           lectura();
            lectura();
             lectura();
    
    system("pause");
    return 0;

    archivo.close();
}

void lectura(){
    char letra;
    archivo.get(letra);
    cout<<letra<<endl;
    
    
}