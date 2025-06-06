#include <iostream>
#include <cstring>
#include "Servicio.h"


using namespace std;

void Servicios::cargarServicio()
{
    int id;
    do  /// para que no guarde el erroneo
    {
        cout << "INGRESE ID SERVICIO: ";
        cin  >> id;
        setIdServicio(id); /// uso la validacion
    }
    while (id<0||id >999); ///vuelve a pedir ID


    cout << "INGRESE NOMBRE DE SERVICIO: ";
    cin.ignore();
    cin.getline(_nombreDeServicio,50);

    cout << "INGRESE PRECIO DE SERVICIO: ";
    cin  >> _precioDeServicio;

}

void Servicios::mostrarServicio()
{
    cout << "--SERVICIOS REGISTRADOS--"<<endl;

    cout <<"EL ID DEL SERVICIO ES: "<<_idServicio<<endl;
    cout <<"NOMBRE DEL SERVICIO CONTRATADO: "<<_nombreDeServicio<<endl;
    cout <<"PRECIO DE SERVICIO: "<<_precioDeServicio<<endl;

}

int Servicios::getIdServicio() const
{
    return _idServicio;
}

void Servicios::setIdServicio(int id)
{

    if (id < 0)
    {
        cout << "ERROR!: El ID del servicio no puede ser negativo." << endl;
        return;
    }
    if (id > 999)
    {
        cout << "ERROR!: El ID del servicio es demasiado grande (maximo 3 numeros)" << endl;
        return;
    }

    _idServicio = id;
}

