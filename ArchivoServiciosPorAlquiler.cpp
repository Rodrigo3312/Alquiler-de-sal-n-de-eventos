#include <iostream>
using namespace std;
#include "ArchivoServiciosPorAlquiler.h"
#include "ServiciosPoralquiler.h"

int ArchivoServiciosPorAlquiler::agregarServicioPorAlquiler(){
    ServiciosPorAlquiler obj;
    obj.cargarRelacion();
    FILE *pArchivo;
    pArchivo= fopen(nombreArchivo, "ab");
    if(pArchivo==nullptr){
        return -1;
    }
    int escribio=fwrite(&obj, sizeof(ServiciosPorAlquiler), 1, pArchivo);
    fclose(pArchivo);
    return escribio;
}

bool ArchivoServiciosPorAlquiler::listarServiciosPorAlquileres(){

    ServiciosPorAlquiler obj;
    FILE *pArchivo;
    pArchivo = fopen(nombreArchivo, "rb");
    if(pArchivo==nullptr){
            return -1;
    }
    while(fread(&obj, sizeof(obj),1,pArchivo)==1){
        obj.mostrar();
        std::cout<<std::endl;
    }
    fclose(pArchivo);
    return true;

}


int ArchivoServiciosPorAlquiler::contarRegistrosServiciosPorAlquiler(){
    FILE *pArchivo=fopen(nombreArchivo, "rb");
    if(pArchivo == nullptr){
        return -1;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadS = ftell(pArchivo) / sizeof(ServiciosPorAlquiler);
    fclose(pArchivo);
    return cantidadS;
}
