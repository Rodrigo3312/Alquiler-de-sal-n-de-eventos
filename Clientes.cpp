#include <iostream>
#include "Clientes.h"
#include <cstring>
#include "ArchivoClientes.h"

using namespace std;

bool validarPalabraNombre=false;

void validarPalabra(char datoChar[], int tamanio){

    int contadorErrores=0;
    int numero = 0;
    for(int i=0; i < tamanio; i++){
        if(datoChar[i]== numero){
        contadorErrores++;
        }
        numero++;
    }
    if(contadorErrores > 0){
        cout << "ERROR. Debe ingresar solo letras. Usted ingreso " <<contadorErrores << "numeros."<<endl;
        validarPalabraNombre = false;
    }else if(contadorErrores == 0){
    validarPalabraNombre = true;
    }


}

void Clientes::cargarClientes()
{
    int dni;
    cout << "Ingrese DNI CLIENTES: ";
    cin >> dni;
    if(setDni(dni) == false){
        cout << "ESTE DNI YA ESTA REGISTRADO"<<endl;
        return;
    }

    while(validarPalabraNombre == false){//sacar validar palabra y numeros
    cout << "Ingrese NOMBRE: ";
    cin >> nombre;
    validarPalabra(nombre,30);
    }


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
cout << "FECHA DE NACIMIENTO: " <<endl; fechaDeNacimiento.mostrarFecha();

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

int Clientes::getDniCliente(){

return dniCliente;

}




