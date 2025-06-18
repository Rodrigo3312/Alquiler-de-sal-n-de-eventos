#include <iostream>
#include "Alquileres.h"
#include "AlquileresArchivo.h"
using namespace std;

AlquileresArchivo::AlquileresArchivo()
{
    _nombreArchivoAlquiler = "Alquiler.dat";

}

AlquileresArchivo::AlquileresArchivo(std::string nombreArchivo)
{
    _nombreArchivoAlquiler = nombreArchivo;

}

bool AlquileresArchivo::guardarA(Alquileres registroA)
{

    FILE *pAlqui;
    bool result;
    pAlqui = fopen (_nombreArchivoAlquiler.c_str(), "wb");
    if (pAlqui==nullptr)
    {
        return false;
    }

    result=fwrite(&registroA,sizeof(Alquileres),1,pAlqui);
    fclose(pAlqui);
    return result;

}




int AlquileresArchivo::getCantidadRegistrosAlquileres()
{

    int total,cantidad;
    FILE *pAlqui;
    pAlqui=fopen(_nombreArchivoAlquiler.c_str(),"rb");


    if(pAlqui==nullptr)
    {

        return 0;
    }
    fseek(pAlqui,0,SEEK_END);

    total=ftell(pAlqui);
    cantidad=total/sizeof(Alquileres);
    fclose(pAlqui);
    return cantidad;

}



Alquileres AlquileresArchivo::leerAlquileres(int pos)
{

    Alquileres leerAlquileres;
    FILE *pAlqui;

    pAlqui=fopen(_nombreArchivoAlquiler.c_str(),"rb");
    if (pAlqui==nullptr){

        return leerAlquileres;
    }

  fseek(pAlqui, pos * sizeof(Alquileres), SEEK_SET);
    fread(&leerAlquileres, sizeof(Alquileres), 1, pAlqui);
    fclose(pAlqui);
    return leerAlquileres;

}

/*
int AlquileresArchivo::verificarIdAlquiler(int _id){

    Alquileres verificar;
    FILE *pVerificar = fopen (_nombreArchivoAlquiler.c_str(),"rb");
    if (pVerificar == nullptr)
        return false;
    while(fread(&))





}
*/
