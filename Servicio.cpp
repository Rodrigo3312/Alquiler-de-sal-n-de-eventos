#include <iostream>
#include <cstring>
#include <string>
#include "Servicio.h"
#include "ServicioArchivo.h"

using namespace std;
///CONSTRUCTOR POR DEFECTO
Servicios::Servicios()
{
    _idServicio = 0;

    strcpy(_nombreDeServicio,""); /// como lograr una cadena vacia? ""=cadena vacia

    /// strcpy permite copiar un vector de char a otro char de derecha

    ///funciona de izquierda a derecha como si fuese una asignacion

    /// y se necesita el uso declarar una biblioteca:#include <cstring>
    _precioDeServicio = 0.0f;
}

///CONSTRUCTOR CON PARAMETROS
Servicios::Servicios(int id, std::string nombreS, float precio)  /// puedo tener o no std por usar el using namespace pero esta por que lo copie de su clase xd
{
    setIdServicio(id);  ///  llama a todos sus setters, reutilizar codigo

    ///
    setNombreDeServicio(nombreS);
    setPrecioDeServicio(precio);
}





///METODOS DE CLASE SERVICIO

void Servicios::cargarServicio()
{

    ServiciosArchivo pArchivo;


    ///Servicios servicios;  /// crea el objeto llamando al constructor vacio
    int id;
    string nombreS;
    float precio;


    cout << "INGRESE ID SERVICIO (0 a 999): ";
    cin  >> id;

    while (cin.fail()|| id < 0 || id > 999)
    {
        cin.clear();
        cin.ignore(10000,'\n');
        cout << "ID MUY LARGO REINGRESE: ";
        cin >>id;
    }


    cin.ignore(); // Limpiar buffer antes del getline

    while (true)
    {
        cout << "INGRESE NOMBRE DE SERVICIO: ";
        getline(cin, nombreS);

        if (nombreS.empty())
        {
            cout << "ERROR: EL NOMBRE NO PUEDE ESTAR VACIO!" << endl;
        }
        else if (nombreS.length() > 49)
        {
            cout << "ERROR: EL NOMBRE ES MUY LARGO!" << endl;
        }
        else
        {
            break;
        }
    }


    cout << "INGRESE PRECIO DE SERVICIO: ";
    cin>> precio;
    while (precio <0.0f)
    {
        cout <<  "ERROR: EL PRECIO NO PUEDE SER NEGATIVO! REINGRESE:";
        cin  >> precio;
    }

    ///reemplaza por una nueva instancia de servicios pero con el constructor que recibe parametros
    ///genera un nuevo objeto que pisa el anterior pero con los datos

    ///servicios=Servicios(id,nombreS,precio);

    ///Servicios servicios;

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

///mostrar de archivos
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

///
void Servicios::mostrarServicio()
{
    cout << "=======================================================" << endl;
    cout << "--SERVICIOS REGISTRADOS--"<<endl;
    cout <<"EL ID DEL SERVICIO ES: "<<_idServicio<<endl;
    cout <<"NOMBRE DEL SERVICIO CONTRATADO: "<<_nombreDeServicio<<endl;
    cout <<"PRECIO DE SERVICIO: "<<_precioDeServicio<<endl;
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
///GETTER'S
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

///SETTER'S BLINDADO BASICO
void Servicios::setIdServicio(int id)  ///valida rango
{
    if (id >= 0 && id  <= 999)
    {
        _idServicio = id;
    }
}

void Servicios::setNombreDeServicio(std::string nombreS) ///valida que no este vacio , sea de 49 limite caracteres
{
    if (nombreS.empty())
    {
        cout << "ERROR: El NOMBRE NO PUEDE ESTAR VACIO!" << endl;
        return;
    }
    if (nombreS.length()>49)
    {

        cout << "ERROR: EL NOMBRE ES MUY LARGO (MAX 49 caracteres)"<<endl;
        return;


    }
    strcpy(_nombreDeServicio,nombreS.c_str());  /// c_str hace la conversion de ese vector de char a algo que esta en string, se podia hacer en el constructor o en los propios set

}



void Servicios::setPrecioDeServicio(float precio) ///valida que no sea negativo
{
    if (precio >= 0.0f)
    {
        _precioDeServicio = precio;
    }
}





