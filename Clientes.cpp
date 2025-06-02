#include <iostream>
#include "Clientes.h"

using namespace std;

void Clientes::cargarClientes()
{
    cout << "Ingrese DNI CLIENTES: ";
    cin >> dniCliente;

    cout << "Ingrese TELEFONO: ";
    cin >> telefono;

    cout << "Eliminado - esto no se muestra"<<endl;

}

void Clientes::mostrarClientes(){

cout << "--CLIENTES REGISTRADOS--"<<endl;

cout << "TELEFONO: "<<telefono<<endl;
cout << "DNI CLIENTE: "<<dniCliente<<endl;

}
