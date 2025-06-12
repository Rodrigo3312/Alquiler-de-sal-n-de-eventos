#ifndef SERVICIOS_POR_ALQUILER_H_INCLUDED
#define SERVICIOS_POR_ALQUILER_H_INCLUDED

class ServiciosPorAlquiler {
private:
    int _idServicio;
    int _idAlquiler;
    float _precioDeServicio;

public:

    void cargarRelacion();
    // Mostrar
    void mostrar() const;
};

#endif // SERVICIOS_POR_ALQUILER_H_INCLUDED
