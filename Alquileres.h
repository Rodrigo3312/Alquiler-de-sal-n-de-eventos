#ifndef ALQUILERES_H_INCLUDED
#define ALQUILERES_H_INCLUDED

class Alquileres
{
private:
    char _nombreDeEvento[50];
    int  _horaDeServicioContratado;
    int  _horaDeduracionEvento;
    int  _cantidadMaxpersonas;
    float _importeTotal;
public:
    void cargarAlquileres();
    void mostrarAlquileres();

};

#endif // ALQUILERES_H_INCLUDED
