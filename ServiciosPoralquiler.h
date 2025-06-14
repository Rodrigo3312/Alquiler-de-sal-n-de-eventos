#ifndef SERVICIOS_POR_ALQUILER_H_INCLUDED
#define SERVICIOS_POR_ALQUILER_H_INCLUDED


class ServiciosPorAlquiler {
private:
    int _idServicio;
    int _idAlquiler;
    float _precioDeServicio;

public:
    ServiciosPorAlquiler();
    ServiciosPorAlquiler(int idServicio, int idAlquiler, float precioDeServicio);

    int getIdServicio();
    int getIdAlquiler();
    float getPrecioDeServicio();

    void setIdServicio(int idServicio);
    void setIdAlquiler(int idAlquiler);
    void setPrecioDeServicios(float precioDeServicio);
    // Mostrar
    void cargarRelacion();
    void mostrar();
};

#endif // SERVICIOS_POR_ALQUILER_H_INCLUDED
