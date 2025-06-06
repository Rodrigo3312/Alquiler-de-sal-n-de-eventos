#include <iostream>
#include "Fecha.h"
#include "Alquileres.h"
#include "Clientes.h"
#include "Servicio.h"
#include "ServiciosPorAlquiler.h"

using namespace std;

void ServiciosPorAlquiler::mostrar() const {
    cout << "ID Alquiler: " << _idAlquiler << endl;
    cout << "ID Servicio: " << _idServicio << endl;
    cout << "Precio del Servicio: $" << _precioDeServicio << endl;
}
