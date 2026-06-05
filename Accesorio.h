#ifndef ACCESORIO_H
#define ACCESORIO_H

#include <iostream>
#include <string>
#include <sstream>
#include "Producto.h"

using namespace std;

class Accesorio : public Producto{
    private:
        string utilidad;
        string color;
        bool paquete;

    public: 
        Accesorio():Producto(),utilidad(""),color(""),paquete(false){}
        Accesorio(string,string,float,int,bool,string,string,bool);
        
        void setUtilidad(string);
        void setColor(string);
        void setPaquete(bool);

        string getUtilidad();
        string getColor();
        bool getPaquete();

        stringstream mostrarAdmin();
        stringstream mostrarCliente();
};

Accesorio::Accesorio(string nom, string id, float pri, int can, 
                bool dis, string uti,string col,bool paq):Producto(nom,id,pri,can,dis){
    utilidad = uti;
    color = col;
    paquete = paq;
}

void Accesorio::setUtilidad(string uti){
    utilidad = uti;
}

void Accesorio::setColor(string col){
    color = col;
}

void Accesorio::setPaquete(bool paq){
    paquete = paq;
}


string Accesorio::getUtilidad(){
    return utilidad;
}

string Accesorio::getColor(){
    return color;
}

bool Accesorio::getPaquete(){
    return paquete;
}

stringstream Accesorio::mostrarAdmin(){
    stringstream out;
    out << "Nombre: " << nombre << endl;
    out << "ID: " << ID << endl;
    out << "Utilidad: " << utilidad << endl;
    out << "Color: " << color << endl;   
    out << "Precio: $" << precio << endl;
    out << "Cantidad: " << cantidad << endl;
    if (paquete == true){
        out << "Este producto se vende en paquete" << endl;
    }
    return out;
    return out;
}

stringstream Accesorio::mostrarCliente(){
    stringstream out;
    out << "Nombre: " << nombre << endl;
    out << "Utilidad: " << utilidad << endl;
    out << "Color: " << color << endl;   
    out << "Precio: $" << precio << endl;
    if (paquete == true){
        out << "Este producto se vende en paquete" << endl;
    }
    if (disponible == false){
        out << "Este producto no esta disponible por el momento" << endl;
    }
    return out;
}


#endif
