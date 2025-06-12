#include <iostream>
#include "Fecha.h"
#include "Alquileres.h"
#include "Clientes.h"
#include "Servicio.h"
#include "ServiciosPorAlquiler.h"

using namespace std;
void ServiciosPorAlquiler::cargarRelacion(){

    cout << "ASIGNAR SERVICIO A UN ALQUILER" << endl;

    cout << "INGRESE ID DEL ALQUILER: ";
    cin >> _idAlquiler;

    cout << "INGRESE ID DEL SERVICIO: ";
    cin >> _idServicio;

    cout << "INGRESE PRECIO DEL SERVICIO: ";
    cin >> _precioDeServicio;

}


void ServiciosPorAlquiler::mostrar() const {
    cout << "ID Alquiler: " << _idAlquiler << endl;
    cout << "ID Servicio: " << _idServicio << endl;
    cout << "Precio del Servicio: $" << _precioDeServicio << endl;
}
