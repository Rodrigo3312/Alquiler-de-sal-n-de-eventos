#include <iostream>
#include "Fecha.h"
using namespace std;

void Fecha::cargarFecha(){
            int d;
            cout<<"DIA ";
            cin>>d;
            setDia(d);
            cout<<"MES ";
            cin>>mes;
            cout<<"ANIO ";
            cin>>anio;
}

void Fecha::mostrarFecha(){
             cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
}

Fecha::Fecha(const int d,const int m,const int a){
            dia=d;
            mes=m;
            anio=a;
}
