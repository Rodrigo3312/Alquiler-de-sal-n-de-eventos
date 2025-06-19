#include <iostream>
#include "Clientes.h"
#include <cstring>
#include "ArchivoClientes.h"

using namespace std;


void Clientes::cargarClientes()
{   int dni;
    while (true) {
    cout << "INGRESE DNI DEL CLIENTE (7 a 8 digitos): ";
    cin >> dni;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "ERROR: DEBE INGRESAR SOLO NUMEROS." << endl;
        continue;
    }

    if (dni < 1000000 || dni > 99999999) {
        cout << "ERROR: DNI FUERA DE RANGO." << endl;
        continue;
    }

    if(setDni(dni) == false){
        cout << "ESTE DNI YA ESTA REGISTRADO"<<endl;
          continue;
    }

    break;
}

    cin.ignore();

      cout << "INGRESE NOMBRE: ";
    cin.getline(nombre, 30);

      cout << "INGRESE APELLIDO: ";
      cin.getline(apellido, 30);



   while (true) {
    cout << "INGRESE TELEFONO (7 a 10 digitos): ";
    cin >> telefono;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "ERROR: SOLO SE PERMITEN NUMEROS." << endl;
        continue;
    }

    if (telefono < 1000000 || telefono > 9999999999) {
        cout << "ERROR: TELEFONO FUERA DE RANGO." << endl;
        continue;
    }

    break;
}
    cin.ignore();

while (true) {
    cout << "INGRESE EMAIL: ";
    cin.getline(email, 50);

    if (strchr(email, '@') && strchr(email, '.')) {
        break;
    } else {
        cout << "ERROR: EMAIL INVALIDO DEBE TENER '@' y '.'" << endl;
    }
}

    cout << "INGRESE FECHA DE NACIMIENTO: ";
    fechaDeNacimiento.cargarFecha();



}








void Clientes::mostrarClientes()
{

    cout << "--CLIENTES REGISTRADOS--"<<endl;

    cout << "DNI CLIENTE: "<<dniCliente<<endl;
    cout << "NOMBRE: " <<nombre<<endl;
    cout << "APELLIDO: " <<apellido<<endl;
    cout << "TELEFONO: "<<telefono<<endl;
    cout << "EMAIL: " <<email<<endl;
    cout << "FECHA DE NACIMIENTO: " <<endl;
    fechaDeNacimiento.mostrarFecha();

}


bool Clientes::setDni(int _dni){

    ArchivoClientes obj;

    if(obj.verificarDni(_dni) == true){
        dniCliente = _dni;
        return true;
    }else{
    return false;
    }

}

void Clientes::setNombre(const char *_nombre)
{
    strcpy(nombre, _nombre);
}

void Clientes::setApellido(const char *_apellido)
{
    strcpy(apellido, _apellido);
}

void Clientes::setEmail(const char *_email)
{
    strcpy(email, _email);
}

bool Clientes::setTelefono(int _telefono)
{
    return telefono;
}


int Clientes::getDniCliente()
{
    return dniCliente;
}

const char* Clientes::getNombre() {
    return nombre;
}

const char* Clientes::getApellido() {
    return apellido;
}

int Clientes::getTelefono() {
    return telefono;
}

const char* Clientes::getEmail() {
    return email;
}
