#include "ServicioArchivo.h"
#include "Servicio.h"
#include <cstdio>
#include <iostream>
using namespace std;

ServiciosArchivo::ServiciosArchivo()
{
    _nombreArchivo = "Servicio.dat";

}
ServiciosArchivo::ServiciosArchivo(std::string nombreArchivo)
{
    _nombreArchivo = nombreArchivo;
}



float ServiciosArchivo::obtenerPrecioServicio(int id) {
    Servicios obj;
    FILE* pPrecio = fopen(_nombreArchivo.c_str(), "rb");
    if (pPrecio == nullptr) return 0;

    while (fread(&obj, sizeof(Servicios), 1, pPrecio)) {
        if (obj.getIdServicio() == id) {
            fclose(pPrecio);
            return obj.getPrecioDeServicio(); // supondremos que existe ese método
        }
    }

    fclose(pPrecio);
    return 0;
}





bool ServiciosArchivo::guardar(Servicios registro)
{

    FILE *pFile;
    bool result;
    pFile = fopen(_nombreArchivo.c_str(),"ab");

    if(pFile == nullptr)
    {

        return false;
    }
    result=fwrite(&registro,sizeof (Servicios),1,pFile);

    fclose(pFile);
    return result;
}


int ServiciosArchivo::getCantidadRegistros()
{
    int total,cantidad;

    FILE *pFile;

    pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (pFile == nullptr)
    {
        return 0;

    }
    fseek(pFile,0,SEEK_END);

    total=ftell(pFile);
    cantidad= total / sizeof (Servicios);
    fclose(pFile);
    return cantidad;

}


Servicios ServiciosArchivo::leerServicios(int pos)
{

    Servicios leer;
    FILE *pFile;

    pFile = fopen(_nombreArchivo.c_str(),"rb");
    if (pFile == nullptr)
    {

        return leer;
    }

    fseek(pFile, pos * sizeof(Servicios), SEEK_SET);
    fread(&leer, sizeof(Servicios), 1, pFile);
    fclose(pFile);
    return leer;

}

bool ServiciosArchivo::verificarIdServicio(int id)
{
    Servicios verificarId;
    FILE* pVerifica= fopen(_nombreArchivo.c_str(),"rb");

    if(pVerifica==nullptr)return false;
    while (fread(&verificarId,sizeof (Servicios),1,pVerifica))
    {
        if (verificarId.getIdServicio()== id)
        {
            fclose(pVerifica);
            return true;
        }
    }
    fclose(pVerifica);
    return false;


}
