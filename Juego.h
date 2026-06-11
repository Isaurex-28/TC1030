/*
 * Proyecto TC1030 - clase Juego
 * Isauro Alejandro Garza Elizondo - A01715088
 *
 * Se define la clase Juego, que hereda de Producto.
 * Juego de mesa que se puede agregar al inventario y ser comprado
 */

#ifndef JUEGO_H
#define JUEGO_H

#include <iostream>
#include <string>
#include <sstream>
#include "Producto.h"

using namespace std;

class Juego : public Producto{
    private:
        string tipo; // Tipo de juego (bazas, cooperativo, manejo de recursos)
        int minJugadores; // Mínimo de jugadores del juego
        int maxJugadores; // Máximo de jugadores del juego
        string marca; // Marca del juego

    public: 
        // Constructor por default
        Juego():Producto(),tipo(""),minJugadores(0),maxJugadores(0),marca(""){}
        Juego(string,string,float,int,bool,string,int,int,string);
        
        void setTipo(string);
        void setMinJugadores(int);
        void setMaxJugadores(int);
        void setMarca(string);

        string getTipo();
        stringstream getJugadores();
        string getMarca();

        stringstream mostrarAdmin();
        stringstream mostrarCliente();
};

/**
 * Constructor con parámetros
 *
 * Inicializa los atributos de Producto y los propios de Juego.
 *
 * @param string nombre del juego, string id, float precio
 * @param int cantidad en inventario, bool disponibilidad
 * @param string tipo de juego, int mínimo de jugadores
 * @param int máximo de jugadores, string marca del juego
 * @return
 */
Juego::Juego(string nom, string id, float pri, int can, 
                bool dis, string tip,int min, int max, 
                string mar):Producto(nom,id,pri,can,dis){
        tipo = tip;
        minJugadores = min;
        maxJugadores = max;
        marca = mar;
}

/** 
 * setTipo asigna el tipo de juego
 * @param string tipo de juego
 * @return 
 */
void Juego::setTipo(string tip){
    tipo = tip;
}

/** 
 * setMinJugadores asigna el mínimo de jugadores
 * @param int mínimo de jugadores
 * @return 
 */
void Juego::setMinJugadores(int min){
    minJugadores = min;
}

/** 
 * setMinJugadores asigna el mínimo de jugadores
 * @param int máximo de jugadores
 * @return 
 */
void Juego::setMaxJugadores(int max){
    maxJugadores = max;
}

/** 
 * setMinJugadores asigna la marca del juego
 * @param string marca del juego
 * @return 
 */
void Juego::setMarca(string mar){
    marca = mar;
}

/** 
 * getTipo regresa la el tipo de juego
 * @param 
 * @return string tipo de juego
 */
string Juego::getTipo(){
    return tipo;
}

/** 
 * getJugadores regresa un stringstream con los jugudaores
 * de n a n.
 * @param 
 * @return stringstream con los jugadores necesarios para el juego
 */
stringstream Juego::getJugadores(){
    stringstream out;
    out << minJugadores << " a " << maxJugadores << endl;
    return out;
}

/** 
 * getUtilidad regresa la marca del juego
 * @param 
 * @return string marca del juego
 */
string Juego::getMarca(){
    return marca;
}

/**
 * mostrarAdmin utiliza polimorfismo para sobreescribir 
 * la funcion de la clase abstracta Producto.
 * Devuelve los datos completos del juego para el administrador,
 * (nombre, ID, marca, tipo, precio y cantidad en el inventario).
 *
 * @param
 * @return stringstream con la información del juego
 */
stringstream Juego::mostrarAdmin(){
    stringstream out;
    out << "Nombre: " << nombre << endl;
    out << "ID: " << ID << endl;
    out << "Marca: " << marca << endl;
    out << "Tipo: " << tipo << endl;   
    out << "Precio: $" << precio << endl;
    out << "Cantidad: " << cantidad << endl;
    return out;
}

/**
 * mostrarCliente utiliza polimorfismo para sobreescribir 
 * la funcion de la clase abstracta Producto.
 * Devuelve los datos completos del juego para el cliente,
 * (nombre, marca, tipo, precio, para cuantos jugadores).
 *
 * @param
 * @return stringstream con la información del juego
 */
stringstream Juego::mostrarCliente(){
    stringstream out;
    out << "Nombre: " << nombre << endl;
    out << "Marca: " << marca << endl;
    out << "Tipo: " << tipo << endl;   
    out << "Precio: $" << precio << endl;
    out << "Jugadores: " << minJugadores << " a " << maxJugadores << endl;
    if (disponible == false){
        out << "Este producto no esta disponible por el momento" << endl;
    }
    return out;
}


#endif
