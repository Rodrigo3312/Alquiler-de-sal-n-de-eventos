#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

class Clientes
{
private:
    int dniCliente;
    int telefono;
    bool eliminado;

public:
    void cargarClientes();
    void mostrarClientes();
};

#endif // CLIENTES_H_INCLUDED
