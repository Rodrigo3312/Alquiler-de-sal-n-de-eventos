#include <iostream>
using namespace std;
#include "ArchivoClientes.h"

bool ArchivoClientes::modificarRegistro( int posicion, const Clientes& nuevoReg){
    FILE *pCliente=fopen(nombre, "rb+");
    if(pCliente == nullptr){
        return false;
    }
    fseek(pCliente,(posicion * sizeof(Clientes)), SEEK_SET);
    bool resultadoOk = fwrite(&nuevoReg, sizeof(Clientes), 1, pCliente);
    fclose(pCliente);
    return resultadoOk;
}

int ArchivoClientes::contarRegistros(){
    FILE *pCliente=fopen(nombre, "rb");
    if(pCliente == nullptr){
        return -1;
    }
    fseek(pCliente, 0, SEEK_END);
    int cantidadR = ftell(pCliente) / sizeof(Clientes);
    fclose(pCliente);
    return cantidadR;
}
int ArchivoClientes::agregarCliente(){

    Clientes obj;
    obj.cargarClientes();
    FILE *pCliente;
    pCliente=fopen(nombre,"ab");
    if(pCliente==nullptr){
        return -1;
    }

    int escribio=fwrite(&obj, sizeof(Clientes),1,pCliente);

    fclose(pCliente);
    return escribio;


}

bool ArchivoClientes::listarClientes(){
    Clientes obj;
    FILE *pClientes;
    pClientes=fopen(nombre,"rb");

    if(pClientes==nullptr){
     std::cout<<"ERROR DE ARCHIVO"<<std::endl;
        return false;
    }


    while(fread(&obj, sizeof(obj),1,pClientes)==1){
        obj.mostrarClientes();
        std::cout<<std::endl;
    }

    fclose(pClientes);
    return true;
}

bool ArchivoClientes::verificarDni(int dni){

     Clientes obj;
    FILE *pClientes;
    pClientes=fopen(nombre,"rb");

    if(pClientes==nullptr){
     std::cout<<"ERROR DE ARCHIVO"<<std::endl;
        return false;
    }


    while(fread(&obj, sizeof(obj),1,pClientes)==1){

        if(obj.getDniCliente() == dni){
            return false;
        }

    }

    fclose(pClientes);
    return true;

}

    int ArchivoClientes::buscarClientePorDni(int dni){
    Clientes obj;
    FILE *pClientes=fopen(nombre,"rb");
    if (pClientes==nullptr)return -1;
    int pos = 0;
    while (fread (&obj,sizeof (Clientes),1,pClientes)){
        if(obj.getDniCliente()==dni){

            fclose(pClientes);
            return pos;
        }

        pos++;
    }

    fclose(pClientes);
    return -1;
    }
