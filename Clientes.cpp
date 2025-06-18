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



while (true){
          cout << "Ingrese DNI CLIENTES: ";
    cin >> dni;


       /// Validar rango de 7 a 8 dígitos antes de setDni
    if (dni < 1000000 || dni > 99999999)
    {
        cout << "ERROR: DNI FUERA DE RANGO (debe tener entre 7 y 8 digitos)." << endl;
        continue; /// vuelve a pedir el DNI
    }


    if(setDni(dni) == false){
        cout << "ESTE DNI YA ESTA REGISTRADO"<<endl;
        continue;
    }
break;    /// Si pasa ambas validaciones, salgo del bucle
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
{  ///agrugue validacion de rango
    if(_dni < 1000000|| _dni > 999999999){
        cout << "ERROR:DNI FUERA DE RANGO (debe tener 7 u 8 digitos)."<<endl;
        return false;
    }
}
    ArchivoClientes obj;

    if(obj.verificarDni(_dni) == true){
        dniCliente = _dni;
        return true;
    }else{ ///agregue este cout
        cout << "ERROR: ESTE DNI YA ESTA REGISTRADO."<<endl;

    return false;
    }

}

int Clientes::getDniCliente(){

return dniCliente;

}




