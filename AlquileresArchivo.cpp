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
    pAlqui = fopen (_nombreArchivoAlquiler.c_str(), "ab");
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


bool AlquileresArchivo::verificarIdAlquiler(int id){

    Alquileres verificar;
    FILE *pVerificar = fopen (_nombreArchivoAlquiler.c_str(),"rb");
    if (pVerificar == nullptr)
        return false;
    while(fread(&verificar,sizeof (Alquileres),1,pVerificar)){

        if (verificar.getIdAlquiler()==id){

            fclose(pVerificar);
            return true;
        }

    }


fclose(pVerificar);
return false;


}


bool AlquileresArchivo::sumarImporteAlquiler(int idAlq, float monto) {
    Alquileres obj;
    FILE* pSuma = fopen(_nombreArchivoAlquiler.c_str(), "rb+");
    if (pSuma == nullptr)
        return false;

    int pos = 0;

    while (fread(&obj, sizeof(Alquileres), 1, pSuma)) {
        if (obj.getIdAlquiler() == idAlq) {
            obj.setImporteTotal(obj.getImporteTotal() + monto);
            fseek(pSuma, sizeof(Alquileres) * pos, SEEK_SET);
            fwrite(&obj, sizeof(Alquileres), 1, pSuma);
            fclose(pSuma);
            return true;
        }
        pos++;
    }
    fclose(pSuma);
    return false;
}

















bool AlquileresArchivo::existeFechaReservada(const Fecha& fecha){
Alquileres reservada;

FILE *pReservada=fopen(_nombreArchivoAlquiler.c_str(),"rb");

if (pReservada==nullptr) return false;

while (fread(&reservada,sizeof(Alquileres),1,pReservada)){

    if (reservada.getFechaDeEvento().esIgual(fecha)){

        fclose(pReservada);
        return true;
    }

}

fclose(pReservada);
return false;

}
