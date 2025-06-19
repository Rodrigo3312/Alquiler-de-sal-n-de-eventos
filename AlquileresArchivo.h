#ifndef ALQUILERESARCHIVO_H_INCLUDED
#define ALQUILERESARCHIVO_H_INCLUDED


class AlquileresArchivo{

private:
    std::string _nombreArchivoAlquiler;
public:
    AlquileresArchivo();
    AlquileresArchivo(std::string nombreArchivoAlquiler);

    bool guardarA(Alquileres registroA);

    void listaralquileres();
    int getCantidadRegistrosAlquileres();
    Alquileres leerAlquileres(int pos);
    bool verificarIdAlquiler(int id);
    bool existeFechaReservada(const Fecha& fecha);
bool sumarImporteAlquiler(int idAlq, float monto);


};


#endif // ALQUILERESARCHIVO_H_INCLUDED
