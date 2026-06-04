#ifndef MINIATURA_H
#define MINIATURA_H

#include <iostream>
#include <string>
#include <sstream>
#include "Producto.h"

using namespace std;

class Miniatura : public Producto{
    private:
        float tamano;
        string personaje;
        string material;

    public: 
        Miniatura():Producto(),tamano(0.0),personaje(""),material(""){}
        Miniatura(string,string,float,int,bool,float,string,string);
        
        void setTamano(float);
        void setPersonaje(string);
        void setMaterial(string);

        float getTamano();
        string getPersonaje();
        string getMaterial();

        stringstream mostrarAdmin();
        stringstream mostrarCliente();
};

Miniatura::Miniatura(string nom, string id, float pri, int can, 
                bool dis, float tam,string per,string mat):Producto(nom,id,pri,can,dis){
    tamano = tam;
    personaje = per;
    material = mat;
}

void Miniatura::setTamano(float tam){
    tamano = tam;
}

void Miniatura::setPersonaje(string per){
    personaje = per;
}

void Miniatura::setMaterial(string mat){
    material = mat;
}


float Miniatura::getTamano(){
    return tamano;
}

string Miniatura::getPersonaje(){
    return personaje;
}

string Miniatura::getMaterial(){
    return material;
}

stringstream Miniatura::mostrarAdmin(){
    stringstream out;
    out << "Nombre: " << nombre << endl;
    out << "ID: " << ID << endl;
    out << "Personaje: " << personaje << endl;
    out << "Tamaño: " << tamano << endl;   
    out << "Precio: $" << precio << endl;
    out << "Cantidad: " << cantidad << endl;
    return out;
}

stringstream Miniatura::mostrarCliente(){
    stringstream out;
    out << "Nombre: " << nombre << endl;
    out << "Personaje: " << personaje << endl;
    out << "Material: " << material << endl;   
    out << "Precio: $" << precio << endl;
    if (disponible == false){
        out << "Este producto no esta disponible por el momento" << endl;
    }
    return out;
}


#endif
