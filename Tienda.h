#ifndef TIENDA_H
#define TIENDA_H

#include <iostream>
#include <string>
#include <sstream>
#include "Producto.h"
#include "Juego.h"
#include "Miniatura.h"
#include "Accesorio.h"

using namespace std;

class Tienda{
    private:
        string nombre;
        float fondos;
        Producto* productos[100];
        int numProductos;

        string usuario;
        string contrasena;
        bool admin;

    public: 
        Tienda():nombre(""),fondos(0.0),numProductos(0),admin(false){};
        Tienda(string,float,string,string):admin(false){};
        
        void setNombre(string);
        string getNombre();
        float getFondos();
        int getNumProductos();


        void iniciaSesion(string,string);

        stringstream muestraAdmin();
        stringstream muestraCliente();

        void agregaProducto();
        void retiraProducto();
        float compraProducto();
    };

Tienda::Tienda(string nom, float fon, string usr, string psw){
    nombre = nom;
    fondos = fon;
    usuario = usr;
    contrasena = psw;
}

void Tienda::setNombre(string nom){
    nombre = nom;
}

string Tienda::getNombre(){
    return nombre;
}

float Tienda::getFondos(){
    return fondos;
}

int Tienda::getNumProductos(){
    return numProductos;
}

void Tienda::iniciaSesion(string usr,string con){
    while (admin){
        if(usr == usuario && con == contrasena){
            admin = true;
        }
        else{
            cout << "Usuario o contraseña incorrectos, Vuelva a intentarlo" << endl;
            admin = false;
        }
    }
}

stringstream Tienda::muestraAdmin(){
    stringstream aux;
    for(int i = 0; i < numProductos; i++){
        aux << i + 1 <<".- "<< productos[i]->mostrarAdmin().str() << endl;
    }
    return aux;
}

stringstream Tienda::muestraCliente(){
    stringstream aux;
    for(int i = 0; i < numProductos; i++){
        aux << i + 1 <<".- "<< productos[i]->mostrarCliente().str() << endl;
    }
    return aux;
}

void agregaProducto(){
    
}

float Tienda::compraProducto(){
    int prod;
    bool found = false;
    muestraCliente();
    cout << "Número del producto: "; cin >> prod;
    for(int i = 0; i < numProductos; i++){
        if (i+1 == prod){
            found = true;
            if(productos[i]->getDisponible()){
                productos[i]->setCantidad(productos[i]->getCantidad()-1);
                return productos[i]->getPrecio();
            }
            else{
                cout << "Producto no disponible" << endl;
                return 0.0;
            }
        }
    }
    cout << "Producto no encontrado" << endl;
    return 0.0;
    }


#endif