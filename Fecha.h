#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

class Fecha
{
private:
    int dia, mes, anio;
public:
    Fecha(int d=0, int m=0, int a=0);                      ///constructor

    void cargarFecha();
    void mostrarFecha();             ///poner un void dentro solo es una manera de saber que no recibe objetos externos solo internos ,dia,mes y anio.

        // Setters
    void setDia(int d);
    void setMes(int m);
    void setAnio(int a);

    // Getters
    int getDia() ;
    int getMes() ;
    int getAnio() ;

};

#endif // FECHA_H_INCLUDED
