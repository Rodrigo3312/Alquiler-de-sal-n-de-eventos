#include <iostream>
#include "Alquileres.h"
#include "Fecha.h"
#include "Clientes.h"
#include "ArchivoClientes.h"
#include "AlquileresArchivo.h"
#include <string>
#include <cstring>

using namespace std;


Alquileres::Alquileres()
{
    _idAlquiler = 0;
    _dniCliente = 0;
    strcpy(_nombreDeEvento,"");
    _fechaDeEvento = Fecha();
    _fechaDeServicioContratado = Fecha();
    _horaDeServicioContratado = 0;
    _horaDeDuracionEvento = 0;
    _cantidadMaxpersonas = 0;
    _importeTotal = 0;
}

Alquileres::Alquileres(int idA, int dniC, std::string nombreEV, Fecha& fechaEV, Fecha& fechaSE, int hora, int duracion, int cantidad, float importe)
{
    setIdAlquiler(idA);
    setDniCliente(dniC);
    setNombreDeEvento(nombreEV);
    setFechaDeEvento(fechaEV);
    setFechaDeServicioContratado(fechaSE);
    setHoraDeServicioContratado(hora);
    setHoraDeDuracionEvento(duracion);
    setCantidadMaxPersonas(cantidad);
    setImporteTotal(importe);
}

void Alquileres::cargarAlquileres()
{

    AlquileresArchivo pArchivoA;

    int idA;
    int dniC;
    std::string nombreEV;
    Fecha fechaEV;
    Fecha fechaSE;
    int hora;
    int duracion ;
    int cantidad;

    const float precioPorPersonaPorHora= 500;


    while (true)
    {
        cout << "INGRESE ID PARA ESTE ALQUILER (SOLO DIGITOS DE 0 A 999): ";
        cin >> idA;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "ERROR: SOLO SE ACEPTAN NUMEROS ENTEROS DENTRO DEL RANGO (0 a 999)." << endl;
            continue;
        }


        if (idA < 0 || idA > 999)
        {
            cout << "ID FUERA DE RANGO (SOLO DIGITOS 0 A 999).REINGRESE! " << endl;
            continue;
        }


        if (pArchivoA.verificarIdAlquiler(idA))
        {
            cout << "ERROR: ESE ID YA EXISTE INGRESE OTRO. " << endl;
            continue;
        }


        cin.ignore(10000, '\n');
        cout << "ID CARGADO CORRECTAMENTE!" << endl;
        break;
    }


    ArchivoClientes archivoC;
    while(true)
    {
        cout << "INGRESE DNI DEL CLIENTE: ";
        cin >> dniC;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000,'\n');
            cout << "ERROR: INGRESE SOLO NUMEROS." << endl;
            continue;
        }



        if(archivoC.buscarClientePorDni(dniC) != -1)
        {
            cout << "CLIENTE ENCONTRADO Y VALIDADO CORRECTAMENTE!" << endl;
            break ;
        }
        else
        {
            cout << "ERROR: DNI NO ENCONTRADO.DEBE SER UN CLIENTE YA REGISTRADO." << endl;
        }
    }

    cin.ignore();

         cout <<"INGRESE NOMBRE DE EVENTO: ";
         getline(cin,nombreEV);





    do{
         cout <<"FECHA DE ESTE EVENTO: "<<endl;
         fechaEV.cargarFecha();
         if (pArchivoA.existeFechaReservada(fechaEV))
        {
         cout <<"ERROR: HAY UN ALQUILER RESERVADO PARA ESA FECHA. INTENTE CON OTRA."<<endl;
        }

}       while(pArchivoA.existeFechaReservada(fechaEV));


        cout <<"INGRESE FECHA ACTUAL DE ESTA CONTRATACION: "<<endl;
        fechaSE.cargarFecha();

        cout <<"INGRESE HORA ACTUAL DE ESTA CONTRATACION (DE 0 A 23 HORAS): ";
        cin >> hora;
        while (hora < 0 || hora > 23){
        cout << "HORA INVALIDA REINGRESE DE 0 A 23: ";
        cin >>hora;
}
        cout <<"INGRESE LA DURACION DE ESTE EVENTO (DE 2 A 12 HORAS): ";
        cin >> duracion;

        while (duracion < 2 || duracion > 12 ){
        cout << "DURACION RANGO INVALIDO REINGRESE : ";
        cin >>duracion;
}
        cout << "EL PRECIO POR PERSONA ES: $" << precioPorPersonaPorHora << endl;
        cout <<"INGRESE CANTIDAD DE PERSONAS A ASISTIR DE (100 a 400): ";
        cin >> cantidad;

        while(cantidad < 100 || cantidad > 400){
        cout << " RANGO DE INVITADOS INVALIDO REINGRESE DE (100 A 400) : ";
        cin >>cantidad;



}

    setIdAlquiler(idA);
    setDniCliente(dniC);
    setNombreDeEvento(nombreEV);
    setFechaDeEvento(fechaEV);
    setFechaDeServicioContratado(fechaSE);
    setHoraDeServicioContratado(hora);
    setHoraDeDuracionEvento(duracion);
    setCantidadMaxPersonas(cantidad);

    calcularImporteTotal();
    cout << "IMPORTE TOTAL CALCULADO (calculado como cantidad * horas * 500): $"<<getImporteTotal()<<endl;


    if(pArchivoA.guardarA(*this))
    {
        cout << "SE GUARDO EL ALQUILER CORRECTAMENTE!" << endl;
    }
    else
    {
        cout << "HUBO UN ERROR NO SE GUARDO EL ALQUILER" <<endl;
    }

}


void Alquileres::calcularImporteTotal()
{
    const float precioPorPersonaPorHora = 500;
    float importe=_cantidadMaxpersonas * _horaDeDuracionEvento * precioPorPersonaPorHora;
    setImporteTotal(importe);
}


void Alquileres::mostrarCantidadAlquileres()
{
    AlquileresArchivo pArchivoA;

    int cantidadRegistrosAlquires=pArchivoA.getCantidadRegistrosAlquileres();
    cout << "LA CANTIDAD DE ALQUILERES QUE HAY SON: "<<cantidadRegistrosAlquires<<endl;


}


void Alquileres::listarTodosAlquileres()
{
    AlquileresArchivo pArchivoA;
    Alquileres registro;
    int cantidadRegistrosAlquileres = pArchivoA.getCantidadRegistrosAlquileres();

    for(int i = 0; i < cantidadRegistrosAlquileres ; i++)
    {
        registro = pArchivoA.leerAlquileres(i);
        registro.mostrarAlquileres();
        cout << "=======================================================" << endl;
    }
}



void Alquileres::mostrarAlquileres()
{
    cout << "=======================================================" << endl;
    cout << "--ALQUILERES--"<<endl;
    cout << "EL ID DE ESTE ALQUILER ES: "<<_idAlquiler<<endl;
    cout <<"EL DNI DEL CLIENTE ES: "<<_dniCliente<<endl;
    cout <<"NOMBRE DE SALON: "<<_nombreDeEvento<<endl;
    cout <<"FECHA DE EVENTO: "<<endl;
    _fechaDeEvento.mostrarFecha();
    cout << "FECHA DE SERVICIO CONTRATADO: "<<endl;
    _fechaDeServicioContratado.mostrarFecha();
    cout <<"HORA DE CONTRATACION: "<<_horaDeServicioContratado<<endl;
    cout <<"DURACION DE EVENTO: "<<_horaDeDuracionEvento<<endl;
    cout <<"CANTIDAD DE PERSONAS PARA ESTE EVENTO: "<<_cantidadMaxpersonas<<endl;
    cout <<"IMPORTE TOTAL: $"<<_importeTotal<<endl;
    cout << "=======================================================" << endl;
}




///GETS ALQUILER
int Alquileres::getIdAlquiler()
{
    return _idAlquiler;
}
int Alquileres::getDniCliente()
{
    return _dniCliente;
}

std::string Alquileres::getNombreDeEvento()
{
    return _nombreDeEvento;
}
Fecha Alquileres::getFechaDeEvento()
{
    return _fechaDeEvento;
}

Fecha Alquileres::getFechaDeServicioContratado()
{
    return _fechaDeServicioContratado;
}

int Alquileres::getHoraDeServicioContratado()
{
    return _horaDeServicioContratado;
}

int Alquileres::getHoraDeDuracionEvento()
{
    return _horaDeDuracionEvento;
}
int Alquileres::getCantidadMaxPersonas()
{
    return _cantidadMaxpersonas;
}
float Alquileres::getImporteTotal()
{
    return _importeTotal ;
}
///SET'S ALQUILER

void Alquileres::setIdAlquiler(int idA)
{
    if (idA >= 0 && idA  <= 999)
    {
        _idAlquiler = idA;
    }

}


void Alquileres::setDniCliente(int dniC)
{
    _dniCliente = dniC;


}

void Alquileres::setNombreDeEvento(std::string nombreEV)
{
    if(nombreEV.empty())
    {
        cout << "ERROR EL NOMBRE NO PUEDE ESTAR VACIO" <<endl;
        return;
    }
    strcpy(_nombreDeEvento,nombreEV.c_str());
}



void Alquileres::setFechaDeEvento(Fecha& fechaEV)
{
    _fechaDeEvento = fechaEV;
}
void Alquileres::setFechaDeServicioContratado(Fecha& fechaSE)
{
    _fechaDeServicioContratado = fechaSE;
}



void Alquileres::setHoraDeServicioContratado(int hora)
{
    if (hora >=0 && hora <= 23)
    {
        _horaDeServicioContratado = hora;
    }

}

void Alquileres::setHoraDeDuracionEvento(int duracion)
{
    if (duracion >= 2 && duracion <= 12)
    {
        _horaDeDuracionEvento = duracion;
    }

}

void Alquileres::setCantidadMaxPersonas(int cantidad)
{
    if (cantidad >= 100 && cantidad <= 400)
    {
        _cantidadMaxpersonas = cantidad;
    }

}

void Alquileres::setImporteTotal(float importe)
{
    if(importe >= 0)
    {
        _importeTotal = importe;
    }
}
