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
    Fecha _fechaDeEvento;           /// mecanismo composicion
    Fecha _fechaDeServicioContratado;   ///composicion
    int  _horaDeServicioContratado;
    int  _horaDeDuracionEvento;
    int  _cantidadMaxpersonas;
    float _importeTotal;
public:
    Alquileres();
    Alquileres(int idA,int dniC,std::string nombreEV,Fecha& fechaEV,Fecha& FechaSE, int hora, int duracion,int cantidad, float importe);

    void cargarAlquileres();
    void mostrarAlquileres();
    void calcularImporteTotal();

    int getIdAlquiler();
    int getDniCliente();
    std::string getNombreDeEvento();
    Fecha getFechaDeEvento();
    Fecha getFechaDeServicioContratado();
    int getHoraDeServicioContratado();
    int getHoraDeDuracionEvento();
    int getCantidadMaxPersonas();
    float getImporteTotal();

    ///Archivos
    void mostrarCantidadAlquileres();
    void listarTodosAlquileres();

    void setIdAlquiler(int idA);
    void setDniCliente(int dniC);
    void setNombreDeEvento(std::string nombreEV);
    void setFechaDeEvento(Fecha& fechaEV);
    void setFechaDeServicioContratado(Fecha& fechaSE);
    void setHoraDeServicioContratado(int hora);
    void setHoraDeDuracionEvento(int duracion);
    void setCantidadMaxPersonas(int cantidad);
    void setImporteTotal(float importe);


};

#endif // ALQUILERES_H_INCLUDED
