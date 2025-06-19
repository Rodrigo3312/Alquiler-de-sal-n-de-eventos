#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

class Fecha
{
private:
    int dia, mes, anio;
public:
    Fecha(int d=0, int m=0, int a=0);

    void cargarFecha();
    void mostrarFecha();
        // Setters
    void setDia(int d);
    void setMes(int m);
    void setAnio(int a);

    // Getters
    int getDia() ;
    int getMes() ;
    int getAnio() ;

    bool esIgual(const Fecha& otra) const;
};

#endif // FECHA_H_INCLUDED
