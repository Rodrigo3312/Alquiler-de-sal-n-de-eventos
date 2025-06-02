#include <iostream>
#include "Servicio.h"


using namespace std;
void Servicios::cargarServicio()
{
    cout << "Ingrese ID SERVICIO: ";
    cin  >> _idServicio;
    cout << "Ingrese NOMBRE DE SERVICIO: ";
    cin  >> _nombreDeServicio;

    cout << "Ingrese PRECIO DE SERVICIO: ";
    cin  >> _precioDeServicio;

}

void Servicios::mostrarServicio()
{
    cout << "--SERVICIOS REGISTRADOS--"<<endl;

    cout <<"IDservicio: "<<_idServicio<<endl;
    cout <<"Nombre de Servicio: "<<_nombreDeServicio<<endl;
    cout <<"Precio de Servicio: "<<_precioDeServicio<<endl;

}
