#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
#include "Fecha.h"

class Clientes
{
private:
    int dniCliente;
    char nombre[30];
    char apellido[30];
    int telefono;
    char email[30];
    Fecha fechaDeNacimiento;
    bool eliminado;

public:
    Cliente();
    Cliente(int _dniCliente, int _telefono,const char *_nombre,const char *_apellido, const char *_email);

    int getDniCliente();
    const char *getNombre();
    const char *getApellido();
    int getTelefono();
    const char *getEmail();


    bool setDni(int _dni);
    void setNombre(const char *_nombre);
    void setApellido(const char *_apellido);
    bool setTelefono(int _telefono);
    void setEmail(const char *_email);



    void cargarClientes();
    void mostrarClientes();


};

#endif // CLIENTES_H_INCLUDED
