#ifndef JUEGO_H
#define JUEGO_H

#include <iostream>
#include <string>
#include <sstream>
#include "Producto.h"

using namespace std;

class Juego : public Producto{
    private:
        string tipo;
        int minJugadores;
        int maxJugadores;
        string marca;

    public: 
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

Juego::Juego(string nom, string id, float pri, int can, 
                bool dis, string tip,int min, int max, 
                string mar):Producto(nom,id,pri,can,dis){
        tipo = tip;
        minJugadores = min;
        maxJugadores = max;
        marca = mar;
}

void Juego::setTipo(string tip){
    tipo = tip;
}

void Juego::setMinJugadores(int min){
    minJugadores = min;
}

void Juego::setMaxJugadores(int max){
    maxJugadores = max;
}

void Juego::setMarca(string mar){
    marca = mar;
}

string Juego::getTipo(){
    return tipo;
}

stringstream Juego::getJugadores(){
    stringstream out;
    out << minJugadores << " a " << maxJugadores << endl;
    return out;
}

string Juego::getMarca(){
    return marca;
}

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
