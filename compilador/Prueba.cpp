#include<stdlib.h>
#include<string.h>
#include <iostream>
#include<fstream>

using namespace std;

void lectura();

int main(){
    lectura();
    system("pause");
    return 0;
}

void lectura(){
    ifstream archivo;
    int letra;
    int transiciones [36][25];
    int i=0;
    int j=0;

    archivo.open("Tabla.txt",ios::in);

    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }

    for(i=0; i<36; i++){
        while(!archivo.eof() && j<25){
            archivo >> transiciones[i][j];
            j=j+1;
        }
        j=0;
    }
    
    archivo.close();

    for (i=0; i<36; i++){
            for(j=0; j<25; j++){
                cout<<transiciones[i][j]<<" "; 
            }
            cout<<""<<endl;
        }
}