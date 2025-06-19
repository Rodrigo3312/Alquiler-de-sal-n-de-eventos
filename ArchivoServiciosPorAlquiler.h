#ifndef ARCHIVOSERVICIOSPORALQUILER_H_INCLUDED
#define ARCHIVOSERVICIOSPORALQUILER_H_INCLUDED
#include "ServiciosPoralquiler.h"

#include <string>
#include <cstring>

class ArchivoServiciosPorAlquiler{

private:
    char nombreArchivo[50];

public:

    ArchivoServiciosPorAlquiler(const char *a = "ServiciosPorAlquiler.dat"){
        strcpy(nombreArchivo,a );
    }

    int contarRegistrosServiciosPorAlquiler();
    int agregarServicioPorAlquiler();
    bool listarServiciosPorAlquileres();

};



#endif // ARCHIVOSERVICIOSPORALQUILER_H_INCLUDED
