#include <iostream>
#include <cstring>
#include <string>
#include "Servicio.h"
#include "ServicioArchivo.h"

using namespace std;


Servicios::Servicios()
{
    _idServicio = 0;

    strcpy(_nombreDeServicio,"");

    _precioDeServicio = 0;
}


Servicios::Servicios(int id, std::string nombreS, float precio)
{
    setIdServicio(id);
    setNombreDeServicio(nombreS);
    setPrecioDeServicio(precio);
}


void Servicios::cargarServicio()
{

    ServiciosArchivo pArchivo;



    int id;
    string nombreS;
    float precio;

    while(true)
    {
        cout << "INGRESE ID SERVICIO (0 a 999): ";
        cin  >> id;

        if (cin.fail()|| id < 0 || id > 999)
        {
            cin.clear();
            cin.ignore(10000,'\n');
            cout << "ID MUY LARGO REINGRESE: "<<endl;
            continue;
        }

        if(pArchivo.verificarIdServicio(id))
        {

            cout <<"ERROR : ESE ID YA EXISTE. INGRESE OTRO:"<<endl;
            continue;
        }

        cout << "ID CARGADO CORRECTAMENTE!" << endl;
        break;
    }




    cin.ignore();


        cout << "INGRESE NOMBRE DE SERVICIO: ";
        getline(cin, nombreS);



    cout << "INGRESE PRECIO DE SERVICIO: ";
    cin>> precio;
    while (precio <0)
    {
        cout <<  "ERROR: EL PRECIO NO PUEDE SER NEGATIVO! REINGRESE:";
        cin  >> precio;
    }


    setIdServicio(id);
    setNombreDeServicio(nombreS);
    setPrecioDeServicio(precio);

    if(pArchivo.guardar(*this))
    {
        cout << "SE GUARDO CORRECTAMENTE!" << endl;
    }
    else
    {
        cout << "HUBO UN ERROR NO SE GUARDO" <<endl;
    }

}


void Servicios::mostrarCantidadRegistros()
{
    ServiciosArchivo pArchivo;
    int cantidadRegistros = pArchivo.getCantidadRegistros();
    cout << "LA CANTIDAD DE REGISTROS QUE HAY SON: "<<cantidadRegistros<<endl;

}

void Servicios::listarTodosRegistros()
{
    ServiciosArchivo pArchivo;
    Servicios registro;
    int cantidadRegistros = pArchivo.getCantidadRegistros();

    for(int i = 0; i < cantidadRegistros ; i++)
    {

        registro = pArchivo.leerServicios(i);

        registro.mostrarServicio();
        cout << "=======================================================" << endl;
    }


}


void Servicios::mostrarServicio()
{
    cout << "=======================================================" << endl;
    cout << "--SERVICIOS REGISTRADOS--"<<endl;
    cout <<"EL ID DEL SERVICIO ES: "<<_idServicio<<endl;
    cout <<"NOMBRE DEL SERVICIO CONTRATADO: "<<_nombreDeServicio<<endl;
    cout <<"PRECIO DE SERVICIO: $"<<_precioDeServicio<<endl;
    cout << "=======================================================" << endl;
}

/*
std::string Servicios::toCSV(){
string str = "";
str = to_string(_idServicio) + ",";
str += string(_nombreDeServicio) + ",";
str += to_string(_precioDeServicio) + ",";

return str;
}
*/



int Servicios::getIdServicio()
{

    return _idServicio;
}

std::string Servicios::getNombreDeServicio()
{
    return _nombreDeServicio;
}

float Servicios::getPrecioDeServicio()
{
    return _precioDeServicio;

}


void Servicios::setIdServicio(int id)
{
    if (id >= 0 && id  <= 999)
    {
        _idServicio = id;
    }
}

void Servicios::setNombreDeServicio(std::string nombreS)
{

    strcpy(_nombreDeServicio,nombreS.c_str());

}


void Servicios::setPrecioDeServicio(float precio)
{
    if (precio >= 0)
    {
        _precioDeServicio = precio;
    }
}





