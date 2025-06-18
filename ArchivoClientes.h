#ifndef ARCHIVOCLIENTES_H_INCLUDED
#define ARCHIVOCLIENTES_H_INCLUDED
#include "Clientes.h"
#include <cstring>

class ArchivoClientes{

private:
    char nombre[30];


public:
    ArchivoClientes(const char *n="Clientes.dat"){
        strcpy(nombre, n);
    }

    int contarRegistros();

    int agregarCliente();

    bool listarClientes();

    bool modificarRegistro(int posicion, const Clientes& nuevoReg);

    bool verificarDni(int dni);

    int buscarClientePorDni(int dni);

};

#endif // ARCHIVOCLIENTES_H_INCLUDED
