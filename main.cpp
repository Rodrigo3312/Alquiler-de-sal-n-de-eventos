#include <iostream>
#include "Clientes.h"
#include "Servicio.h"
#include "Alquileres.h"
#include "Fecha.h"
#include "ServiciosPoralquiler.h"
#include "ArchivoServiciosPorAlquiler.h"
#include "ArchivoClientes.h"

using namespace std;

int main()
{

    int opcion;

    Clientes obj;
    Servicios miServicio;
    Alquileres misAlquileres;

    ArchivoServiciosPorAlquiler servixal;
    ArchivoClientes archivo;
    do

    {
        system("cls");
        cout << "=======================================================" << endl;
        cout << "MENU PRINCIPAL - SISTEMA DE ALQUILERES:SALON DE EVENTOS" << endl;
        cout << "=======================================================" << endl;
        cout << "1.REGISTRAR NUEVO CLIENTE" << endl;
        cout << "2.REGISTRAR ALQUILERES" << endl;
        cout << "3.REGISTRAR SERVICIOS" << endl;
        cout << "4.ASIGNAR SERVICIOS A UN ALQUILER" << endl;
        cout << "5.MOSTRAR REGISTROS" << endl;
        cout << "6.SALIR" << endl;
        cout << "=======================================================" << endl;
        cout << "INGRESE UNA OPCION: " ;
        cin  >>  opcion;


        system("cls");
        switch(opcion)
        {
        case 1:

            archivo.agregarCliente();
            break;
        case 2:
            misAlquileres.cargarAlquileres();

            break;
        case 3:
            miServicio.cargarServicio();
            break;
        case 4:
              servixal.agregarServicioPorAlquiler();
            break;
        case 5:

            miServicio.mostrarServicio();
            misAlquileres.mostrarAlquileres();

            archivo.listarClientes();

            miServicio.mostrarCantidadRegistros();
            miServicio.listarTodosRegistros();

            misAlquileres.mostrarCantidadAlquileres();
            misAlquileres.listarTodosAlquileres();

            servixal.listarServiciosPorAlquileres();

            break;
        case 6:
            return 0;
        default:
            cout << "OPCION INVALIDA. POR FAVOR, INTENTE DE NUEVO." << endl;


        }
        system("pause");
    }

    while (true);

}
