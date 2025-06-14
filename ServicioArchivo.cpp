#include "ServicioArchivo.h"
#include "Servicio.h"
#include <cstdio>
#include <iostream>
using namespace std;

ServiciosArchivo::ServiciosArchivo(){
_nombreArchivo = "Servicio.dat";

}

ServiciosArchivo::ServiciosArchivo(std::string nombreArchivo){
_nombreArchivo = nombreArchivo;
}


bool ServiciosArchivo::guardar(Servicios registro){

FILE *pFile; ///  puntero file
bool result; /// si es 1 pudo escribir si es 0 no pudo.
pFile = fopen(_nombreArchivo.c_str(),"ab");  ///abrir archivo ab para agregar "wb" para eliminar los registros

if(pFile == nullptr){

    return false;
}     ///preguntar que pfile noo sea nulo , si no pudo registrar, abrirlo como escritura retorna falso
      /// si pasa este if , si, se abrio como escritura.

result=fwrite(&registro,sizeof (Servicios),1,pFile);   ///escribir
 /// pedir la direccion de memoria &registro
 /// tamaño del registro sizeof (servicios)
 /// cantidad cuantas veces va registrar o guardar 1
 /// nombre del puntero pFile
 fclose(pFile); ///cerrar el archivo
return result;
}



int ServiciosArchivo::getCantidadRegistros(){
 int total,cantidad;

 FILE *pFile;

 pFile = fopen(_nombreArchivo.c_str(), "rb");
 if (pFile == nullptr){
    return 0;

 }
 fseek(pFile,0,SEEK_END);




 total=ftell(pFile);
 cantidad= total / sizeof (Servicios);
 fclose(pFile);
 return cantidad;

}


Servicios ServiciosArchivo::leerServicios(int pos) {

    Servicios leer;
    FILE *pFile;

   pFile = fopen(_nombreArchivo.c_str(),"rb");
    if (pFile == nullptr) {

        return leer;
    }

 fseek(pFile, pos * sizeof(Servicios), SEEK_SET);
    fread(&leer, sizeof(Servicios), 1, pFile);
    fclose(pFile);
    return leer;

}
