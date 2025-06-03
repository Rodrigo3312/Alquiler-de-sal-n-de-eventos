#include <iostream>
#include "Alquileres.h"
#include "Fecha.h"
using namespace std;
void Alquileres::cargarAlquileres()
{

    cout <<"INGRESE NOMBRE DE EVENTO: ";
    cin >>_nombreDeEvento;
        cout <<"FECHA DE EVENTO: "<<endl;
     _fechaDeEvento.cargarFecha();
     cout <<"FECHA DE SERVICIO CONTRATADO: ";
     _fechaDeServicioContratado.cargarFecha();
    cout <<"INGRESE HORA DE CONTRATACION: ";
    cin >> _horaDeServicioContratado;
    cout <<"INGRESE DURACION DE EVENTO: ";
    cin >> _horaDeduracionEvento;
    cout <<"INGRESE CANTIDAD DE PERSONAS: ";
    cin >> _cantidadMaxpersonas;



}
void Alquileres::mostrarAlquileres()
{
    cout << "--ALQUILERES--"<<endl;
    cout <<"NOMBRE DE SALON: "<<_nombreDeEvento<<endl;
    cout <<"FECHA DE EVENTO: "<<endl;
    _fechaDeEvento.mostrarFecha();
    cout << "FECHA DE SERVICIO CONTRATADO: "<<endl;
    _fechaDeServicioContratado.mostrarFecha();
    cout <<"HORA DE CONTRATACION: "<<_horaDeServicioContratado<<endl;
    cout <<"DURACION DE EVENTO: "<<_horaDeduracionEvento<<endl;
    cout <<"CANTIDAD DE PERSONAS PARA ESTE EVENTO: "<<_cantidadMaxpersonas<<endl;
}
