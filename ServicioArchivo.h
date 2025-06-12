#ifndef SERVICIOARCHIVO_H_INCLUDED
#define SERVICIOARCHIVO_H_INCLUDED
#include "Servicio.h"
#include <string>
class ServiciosArchivo{

private:
    std::string _nombreArchivo;
public:

ServiciosArchivo();
ServiciosArchivo(std::string nombreArchivo);

bool guardar(Servicios registro );
void listarServicios();
 int getCantidadRegistros();
 Servicios leerServicios(int pos);
};

#endif // SERVICIOARCHIVO_H_INCLUDED
