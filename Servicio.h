#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

class Servicios
{
private:
    int _idServicio;
    char _nombreDeServicio[50];
    float _precioDeServicio;

public:
    void cargarServicio();
    void mostrarServicio();

};

#endif // SERVICIO_H_INCLUDED
