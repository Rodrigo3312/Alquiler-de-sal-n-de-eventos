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
    cout<<"INGRESE DIA: ";
    cin>>d;


    cout<<"INGRESE MES: ";
    cin>>m;

    cout<<"INGRESE ANIO: ";
    cin>>a;

    setDia(d);
    setMes(m);
    setAnio(a);
    /// Verificación final de que no se haya cargado ningún campo inválido
    if (dia == 0 || mes == 0 || anio == 0)
    {
        cout << "FECHA INVALIDA, ALGUNO DE LOS CAMPOS NO ES VALIDO." << endl;
    }


}

void Fecha::mostrarFecha()
{
    cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
}



///setter
void Fecha::setDia(int dia)
{
    if(dia>=1 &&dia<=31)          /// verifica que el valor este en un rango valido para un dia
        this->dia=dia;           /// asigna el valor al atributo dia del objeto
    ///this refiere al atributo
    else this->dia=0;             /// si el valor es invalido , guarda un 0 como señal de error.
}

void Fecha::setMes(const int m)
{
    if (m >= 1 && m <= 12)         /// El mes debe estar entre 1 y 12
    {
        mes = m;
    }
    else
    {
        mes = 0;                   /// Si es inválido, lo marca con 0
    }
}

void Fecha::setAnio(int a)                  ///validar aun
{
    if (a >= 1900 && a <= 2100)    // Año razonable
    {
        anio = a;
    }
    else
    {
        anio = 0;                  // Año inválido, se pone en 0
    }
}



///getters
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
