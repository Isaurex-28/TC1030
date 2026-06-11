/*
 * Proyecto TC1030 - clase Accesorio
 * Isauro Alejandro Garza Elizondo - A01715088
 *
 * Se define la clase Accesorio, que hereda de Producto.
 * Representa un accesorio o complemento en la tienda, con atributos
 * específicos como utilidad, color y si se vende en paquete.
 */


#ifndef ACCESORIO_H
#define ACCESORIO_H

#include <iostream>
#include <string>
#include <sstream>
#include "Producto.h"

using namespace std;

class Accesorio : public Producto{
    private:
        string utilidad; // Uso del producto
        string color; // Color del accesorio
        bool paquete; // Se vende en paquete?

    public: 
        // Constructor por default
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

/**
 * Constructor con parámetros
 *
 * Inicializa los atributos de Producto y los específicos de Accesorio.
 *
 * @param string nombre del accesorio, string id, float precio
 * @param int cantidad en inventario, bool disponibilidad, string utilidad 
 * @param string color, bool true si se vende en paquete
 * @return
 */
Accesorio::Accesorio(string nom, string id, float pri, int can, 
                bool dis, string uti,string col,bool paq):Producto(nom,id,pri,can,dis){
    utilidad = uti;
    color = col;
    paquete = paq;
}

/** 
 * setUtilidad asigna la utilidad al accesorio
 * @param string funcion del accesorio
 * @return 
 */
void Accesorio::setUtilidad(string uti){
    utilidad = uti;
}

/** 
 * setUtilidad asigna el color al accesorio
 * @param string color del accesorio
 * @return 
 */
void Accesorio::setColor(string col){
    color = col;
}

/** 
 * setUtilidad asigna si el accesorio se vende en paquete
 * @param bool true si se vende en paquete
 * @return 
 */
void Accesorio::setPaquete(bool paq){
    paquete = paq;
}

/** 
 * getUtilidad regresa la utilidad al accesorio
 * @param 
 * @return string funcion del accesorio
 */
string Accesorio::getUtilidad(){
    return utilidad;
}

/** 
 * getColor regresa el color del accesorio
 * @param 
 * @return string color del accesorio
 */
string Accesorio::getColor(){
    return color;
}

/** 
 * getPaquete regresa si el accesorio se vende en paquete
 * @param 
 * @return bool true si se vende en paquete
 */
bool Accesorio::getPaquete(){
    return paquete;
}

/**
 * mostrarAdmin utiliza polimorfismo para sobreescribir 
 * la funcion de la clase abstracta Producto.
 * Devuelve los datos completos del accesorio para el administrador,
 * (ID, utilidad, color, precio, cantidad en el inventario y si se vende en paquete).
 *
 * @param
 * @return stringstream con la información del accesorio
 */
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

/**
 * mostrarCliente utiliza polimorfismo para sobreescribir 
 * la funcion de la clase abstracta Producto.
 * Devuelve los datos completos del accesorio para el cliente,
 * (nombre, utilidad, color, precio, y si se vende en paquete).
 *
 * @param
 * @return stringstream con la información del accesorio
 */
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
