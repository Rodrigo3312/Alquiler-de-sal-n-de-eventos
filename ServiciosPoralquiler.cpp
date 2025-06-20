#include <iostream>
#include "Fecha.h"
#include "Alquileres.h"
#include "Clientes.h"
#include "Servicio.h"
#include "ServiciosPorAlquiler.h"
#include "ArchivoServiciosPorAlquiler.h"

using namespace std;

ServiciosPorAlquiler::ServiciosPorAlquiler(){
  _idAlquiler = 0;
 _idServicio = 0;

    _precioDeServicio = 0;
}

ServiciosPorAlquiler::ServiciosPorAlquiler( int idAlquiler,int idServicio, float precioDeServicios) {

    setIdAlquiler (idAlquiler);
     setIdServicio (idServicio);
    setPrecioDeServicios(precioDeServicios);
}



void ServiciosPorAlquiler::cargarRelacion(){

    cout << "===== ASIGNAR SERVICIO A UN ALQUILER ======" << endl;

     cout << "INGRESE ID DEL SERVICIO: ";
    cin >> _idAlquiler;

      cout << "INGRESE ID DEL ALQUILER: ";
    cin >> _idServicio;

    cout << "INGRESE PRECIO DEL SERVICIO: ";
    cin >> _precioDeServicio;

}


void ServiciosPorAlquiler::mostrar(){
    cout << " --SERVICIOS POR ALQUILER-- "<< endl;
    cout << "ID Alquiler: " << _idAlquiler << endl;
    cout << "ID Servicio: " << _idServicio << endl;
    cout << "Precio del Servicio: $" << _precioDeServicio << endl;
}





int ServiciosPorAlquiler::getIdAlquiler(){
    return _idAlquiler;
   }

int ServiciosPorAlquiler::getIdServicio(){
    return _idServicio;
}



float ServiciosPorAlquiler::getPrecioDeServicio(){
    return _precioDeServicio;
}


void ServiciosPorAlquiler::setIdAlquiler(int idAlquiler){

    _idAlquiler = idAlquiler;

}

void ServiciosPorAlquiler::setIdServicio(int idServicio){

    _idServicio = idServicio;

}

void ServiciosPorAlquiler::setPrecioDeServicios(float precioDeServicios){

    _precioDeServicio=precioDeServicios;

}



