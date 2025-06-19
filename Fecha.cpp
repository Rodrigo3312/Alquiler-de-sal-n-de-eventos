#include <iostream>
#include "Fecha.h"
using namespace std;
Fecha::Fecha(int d,int m,int a)
{

    setAnio(a);
    setMes(m);
    setDia(d);

}

void Fecha::cargarFecha()
{

    int d,m,a;
    do
    {
        cout<<"INGRESE DIA: ";
        cin>>d;
        setDia(d);
        if(dia == 0)
        {
            cout << "ERROR: DIA INVALIDO DEBE ESTAR ENTRE 1 y 31."<< endl;
        }
    }
    while (dia==0);


    do
    {
        cout<<"INGRESE MES: ";
        cin>>m;
        setMes (m);
        if (mes == 0)
        {
            cout << "ERROR: MES INVALIDO DEBE ESTAR ENTRE 1 y 12."<< endl;

        }
    }
    while (mes==0);

    do
    {
        cout<<"INGRESE ANIO: ";
        cin>>a;
        setAnio(a);
        if (anio == 0)
        {
            cout <<"ERROR : ANIO INVALIDO DEBE ESTAR ENTRE 1900 y 2100."<<endl;
        }
    }
    while (anio==0);

}

void Fecha::mostrarFecha()
{
    cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
}


bool Fecha::esIgual(const Fecha& otra)const{

return dia==otra.dia && mes==otra.mes && anio == otra.anio;

}


void Fecha::setDia(int dia)
{
    if(dia>=1 &&dia<=31)
        this->dia=dia;
    else this->dia=0;
}

void Fecha::setMes(const int m)
{
    if (m >= 1 && m <= 12)
    {
        mes = m;
    }
    else
    {
        mes = 0;
    }
}

void Fecha::setAnio(int a)
{
    if (a >= 1900 && a <= 2100)
    {
        anio = a;
    }
    else
    {
        anio = 0;
    }
}

int Fecha::getDia()
{
    return dia;
}
int Fecha::getMes()
{
    return mes;
}
int Fecha::getAnio()
{
    return anio;
}
