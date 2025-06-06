#ifndef ALQUILERES_H_INCLUDED
#define ALQUILERES_H_INCLUDED
#include "Fecha.h"
#include "Clientes.h"

class Alquileres
{
private:
    int _idAlquiler;
    int _dniCliente;
    char _nombreDeEvento[50];
    Fecha _fechaDeEvento;
    Fecha _fechaDeServicioContratado;
    int  _horaDeServicioContratado;
    int  _horaDeduracionEvento;
    int  _cantidadMaxpersonas;
    float _importeTotal;
public:
    void cargarAlquileres();
    void mostrarAlquileres();

};

#endif // ALQUILERES_H_INCLUDED
