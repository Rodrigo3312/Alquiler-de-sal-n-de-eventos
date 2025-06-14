#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
#include "Fecha.h"

class Clientes
{
private:
    int dniCliente;
    int telefono;
    bool eliminado;
    char nombre[30];
    char apellido[30];
    char email[30];
    Fecha fechaDeNacimiento; ///composicion

public:
    Cliente();
    Cliente(int _dniCliente, int _telefono,const char *_nombre,const char *_apellido, const char *_email);

    int getDniCliente();
    int getTelefono();
    const char *getNombre();
    const char *getApellido();
    const char *getEmail();

    void setNombre(const char *nombre);
    void setApellido(const char *apellido);
    void setEmail(const char *email);

    bool setDni(int _dni);

   ///metodos
    void cargarClientes();
    void mostrarClientes();


};

#endif // CLIENTES_H_INCLUDED
