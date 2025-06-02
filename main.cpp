#include <iostream>
#include "Clientes.h"
#include "Servicio.h"
#include "Alquileres.h"

using namespace std;

int main()
{

    int opcion;

    Clientes obj;
    Servicios miServicio;
    Alquileres misAlquileres;
    do

    {
        system("cls");
        cout << "=======================================================" << endl;
        cout << "MENU PRINCIPAL - SISTEMA DE ALQUILERES:SALON DE EVENTOS" << endl;
        cout << "=======================================================" << endl;
        cout << "1.REGISTRAR NUEVO CLIENTE" << endl;
        cout << "2.SERVICIOS" << endl;
        cout << "3.ALQUILERES" << endl;
        cout << "4.REGISTROS" << endl;
        cout << "5.SALIR" << endl;
        cout << "=======================================================" << endl;
        cout << "INGRESE UNA OPCION: " ;
        cin  >>  opcion;


        system("cls");
        switch(opcion)
        {
        case 1:
            obj.cargarClientes();


            break;
        case 2:
            miServicio.cargarServicio();
            break;
        case 3:
            misAlquileres.cargarAlquileres();
            break;
        case 4:
            obj.mostrarClientes();
            miServicio.mostrarServicio();
            misAlquileres.mostrarAlquileres();
            break;
        case 5:
            return 0;
        default:
            cout << "OPCION INVALIDA. POR FAVOR, INTENTE DE NUEVO." << endl;


        }
        system("pause");
    }

    while (true);

}
