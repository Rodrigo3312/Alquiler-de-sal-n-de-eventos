#include <iostream>
#include "Clientes.h"
#include <cstring>

using namespace std;


void Clientes::cargarClientes()
{
    cout << "Ingrese DNI CLIENTES: ";
    cin >> dniCliente;

    cout << "Ingrese NOMBRE: ";
    cin >> nombre;

    cout << "Ingrese APELLIDO: ";
    cin >> apellido;

    cout << "Ingrese TELEFONO: ";
    cin >> telefono;

    cout << "Ingrese EMAIL: ";
    cin >> email;

    cout << "Ingrese FECHA DE NACIMIENTO: ";
    fechaDeNacimiento.cargarFecha();

    //cout << "Eliminado - esto no se muestra"<<endl;

}

void Clientes::mostrarClientes(){

cout << "--CLIENTES REGISTRADOS--"<<endl;

cout << "DNI CLIENTE: "<<dniCliente<<endl;
cout << "NOMBRE: " <<nombre<<endl;
cout << "APELLIDO: " <<apellido<<endl;
cout << "TELEFONO: "<<telefono<<endl;
cout << "EMAIL: " <<email<<endl;
cout << "FECHA DE NACIMIENTO: " <<endl; fechaDeNacimiento.mostrarFecha(); ///composicion

}
