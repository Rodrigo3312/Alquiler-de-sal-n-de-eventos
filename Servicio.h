#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED
#include <string>
class Servicios
{
private:
    int _idServicio;
    char _nombreDeServicio[50];
    float _precioDeServicio;

public:
    void cargarServicio();
    void mostrarServicio();

    void mostrarCantidadRegistros();
    void listarTodosRegistros();


    Servicios();
    Servicios(int id, std::string nombreS, float precio);

    int getIdServicio();
    std::string getNombreDeServicio();
    float getPrecioDeServicio();


    void setIdServicio(int id);
    void setNombreDeServicio(std::string nombreS);
    void setPrecioDeServicio(float precio);


    ///std::string toCSV();

};

#endif // SERVICIO_H_INCLUDED
