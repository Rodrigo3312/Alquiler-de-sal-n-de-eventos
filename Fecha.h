#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

class Fecha
{
private:
    int dia, mes, anio;
public:
    Fecha(int d=0, int m=0, int a=0); ///constructor

    void cargarFecha();
    void mostrarFecha(); ///poner un void dentro solo es una manera de saber que no recibe objetos externos solo internos ,dia,mes y anio.
    ///setter
    void setDia(int dia)
    {
        if(dia>=1 &&dia<=31)/// verifica que el valor este en un rango valido para un dia
            this->dia=dia; /// asigna el valor al atributo dia del objeto
                          ///this refiere al atributo

        else this->dia=0;  /// si el valor es invalido , guarda un 0 como señal de error.
    }

    void setMes(const int m)
    {
        mes=m;
    }

    void setAnio(int a)
    {
        anio=a;
    }
    ///getter
    int getDia()
    {
        return dia;
    }
    int getMes()
    {
        return mes;
    }
    int getAnio()
    {
        return anio;
    }
};

#endif // FECHA_H_INCLUDED
