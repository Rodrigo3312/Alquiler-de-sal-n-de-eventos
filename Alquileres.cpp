#include <iostream>
#include "Alquileres.h"
using namespace std;
void Alquileres::cargarAlquileres()
{
    cout <<"INGRESE NOMBRE DE EVENTO: "<<;
    cin >> _nombreDeEvento;
    cout <<"INGRESE HORA DE CONTRATACION: "<< endl;
    cin >> _horaDeServicioContratado;
    cout <<"INGRESE DURACION DE EVENTO: "<< endl;
    cin >> _horaDeduracionEvento;
    cout <<"INGRESE CANTIDAD DE PERSONAS: "<< endl;
    cin >> _cantidadMaxpersonas;



}
void Alquileres::mostrarAlquileres()
{
    cout << "--ALQUILERES--"<<endl;
    cout <<"NOMBRE DE SALON: "<<_nombreDeEvento<<endl;
    cout <<"HORA DE CONTRATACION: "<<_horaDeServicioContratado<<endl;
    cout <<"DURACION DE EVENTO: "<<_horaDeduracionEvento<<endl;
    cout <<"CANTIDAD DE PERSONAS PARA ESTE EVENTO: "<<_cantidadMaxpersonas<<endl;
}
