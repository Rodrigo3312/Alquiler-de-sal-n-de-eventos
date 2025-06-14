#include <iostream>
#include "Clientes.h"
#include "Servicio.h"
#include "Alquileres.h"
#include "Fecha.h"
#include "ServiciosPoralquiler.h"

///
#include "ArchivoServiciosPorAlquiler.h"
#include "ArchivoClientes.h"

using namespace std;

int main()
{

    int opcion;

    Clientes obj;
    Servicios miServicio;
    Alquileres misAlquileres;
    ///ServiciosPorAlquiler misServiciosPorAlquiler;

    ArchivoServiciosPorAlquiler servixal;
    ArchivoClientes archivo;
    do

    {
        system("cls");
        cout << "=======================================================" << endl;
        cout << "MENU PRINCIPAL - SISTEMA DE ALQUILERES:SALON DE EVENTOS" << endl;
        cout << "=======================================================" << endl;
        cout << "1.REGISTRAR NUEVO CLIENTE" << endl;
        cout << "2.REGISTRAR SERVICIOS" << endl;
        cout << "3.REGISTRAR ALQUILERES" << endl;
        cout << "4.MOSTRAR REGISTROS" << endl; ///solo para mostrar
        cout << "5.ASIGNAR SERVICIOS A UN ALQUILER" << endl;
        cout << "6.SALIR" << endl;
        cout << "=======================================================" << endl;
        cout << "INGRESE UNA OPCION: " ;
        cin  >>  opcion;


        system("cls");
        switch(opcion)
        {
        case 1:
            ///obj.cargarClientes();
              archivo.agregarCliente();
            break;
        case 2:
            miServicio.cargarServicio();
            break;
        case 3:
            misAlquileres.cargarAlquileres();
            break;
        case 4:
            ///archivos heap
            ///obj.mostrarClientes();


            miServicio.mostrarServicio();
            misAlquileres.mostrarAlquileres();
            ///archivos clientes
            archivo.listarClientes();
            ///archivos servicios
            miServicio.mostrarCantidadRegistros();
            miServicio.listarTodosRegistros();
            ///archivos alquileres
            misAlquileres.mostrarCantidadAlquileres();
            misAlquileres.listarTodosAlquileres();
            ///archivos serviciosXalquiler
            servixal.listarServiciosPorAlquileres();
            ///misServiciosPorAlquiler.mostrar();
            ///misServiciosPorAlquiler.listarServiciosPorAlquileres();
            break;
        case 5:
            servixal.agregarServicioPorAlquiler();
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
