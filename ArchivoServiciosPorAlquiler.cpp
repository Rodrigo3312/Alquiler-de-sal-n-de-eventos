#include <iostream>
using namespace std;
#include "Alquileres.h"
#include "AlquileresArchivo.h"
#include "ArchivoServiciosPorAlquiler.h"
#include "ServicioArchivo.h"
#include "ServiciosPoralquiler.h"


int ArchivoServiciosPorAlquiler::agregarServicioPorAlquiler()
{
    ServiciosPorAlquiler obj;
    obj.cargarRelacion();

    int idServ = obj.getIdAlquiler();
    int idAlq = obj.getIdServicio();



 AlquileresArchivo archiAlqui;
    ServiciosArchivo archivoServi;


    if (!archivoServi.verificarIdServicio(idServ))
    {

        cout << "ERROR : NO EXISTE EL ID DEL SERVICIO" << endl;
        return -1;
    }
    if (!archiAlqui.verificarIdAlquiler(idAlq))
    {

        cout << "ERROR : NO EXISTE EL ID DEL ALQUILER" <<endl;
        return -1;
    }

    ///guarda si ambos existen
    FILE *pArchivo;
    pArchivo= fopen(nombreArchivo, "ab");

    if(pArchivo==nullptr)
    {
        return -1;
    }


    int escribio=fwrite(&obj, sizeof(ServiciosPorAlquiler), 1, pArchivo);
    fclose(pArchivo);

    float precio=archivoServi.obtenerPrecioServicio(idServ);
    archiAlqui.sumarImporteAlquiler(idAlq,precio);

    return escribio;
}


bool ArchivoServiciosPorAlquiler::listarServiciosPorAlquileres()
{

    ServiciosPorAlquiler obj;
    FILE *pArchivo;
    pArchivo = fopen(nombreArchivo, "rb");
    if(pArchivo==nullptr)
    {
        return -1;
    }
    while(fread(&obj, sizeof(obj),1,pArchivo)==1)
    {
        obj.mostrar();
        std::cout<<std::endl;
    }
    fclose(pArchivo);
    return true;

}


int ArchivoServiciosPorAlquiler::contarRegistrosServiciosPorAlquiler()
{
    FILE *pArchivo=fopen(nombreArchivo, "rb");
    if(pArchivo == nullptr)
    {
        return -1;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadS = ftell(pArchivo) / sizeof(ServiciosPorAlquiler);
    fclose(pArchivo);
    return cantidadS;
}



