#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Producto{
    protected:
        string nombre;
        string ID;
        float precio;
        int cantidad;
        bool disponible;
        
    public:
        Producto():nombre(""),ID(""),precio(0.0),cantidad(0),disponible(false){};
        Producto(string,string,float,int,bool);
        
        void setNombre(string);
        void setPrecio(float);
        void setCantidad(int);
        void setDisponible(int);
        void setDisponible(bool);
        
        string getNombre();
        string getId();
        float getPrecio();
        int getCantidad();
        bool getDisponible();
        
        virtual stringstream mostrarAdmin() = 0;
        virtual stringstream mostrarCliente() = 0;
};



Producto::Producto(string nom, string id, float pri, int can, bool dis){
    nombre = nom;
    ID = id;
    precio = pri;
    cantidad = can;
    disponible = dis;
}


void Producto::setNombre(string nom){
    nombre = nom;
}

void Producto::setPrecio(float pri){
    precio = pri;
}

void Producto::setCantidad(int can){
    cantidad = can;
}

void Producto::setDisponible(int dis){
    disponible = dis;
}

void Producto::setDisponible(bool dis){
    disponible = dis;
}

string Producto::getNombre(){
    return nombre;
}

string Producto::getId(){
    return ID;
}

float Producto::getPrecio(){
    return precio;
}

int Producto::getCantidad(){
    return cantidad;
}

bool Producto::getDisponible(){
    return disponible;
}

#endif
