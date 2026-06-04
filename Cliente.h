#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <string>
#include <sstream>
#include "Persona.h"

using namespace std;

class Cliente : public Persona {
    private:
        string contacto;
        int numCompras;

    public:
        Cliente():Persona(), contacto(""), numCompras(0) {};
        Cliente(string, string, string);

        void setContacto(string);
        void registrarCompra();

        string getContacto();
        int getNumCompras();

        stringstream mostrar();
};

Cliente::Cliente(string nom, string id, string con):Persona(nom, id),
                numCompras(0){
    contacto = con;
}

void Cliente::setContacto(string con){
    contacto = con;
}

void Cliente::registrarCompra(){
    numCompras++;
}

string Cliente::getContacto(){
    return contacto;
}

int Cliente::getNumCompras(){
    return numCompras;
}

stringstream Cliente::mostrar(){
    stringstream out;
    out << "Nombre: "   << nombre     << endl;
    out << "ID: "       << ID         << endl;
    out << "Contacto: " << contacto   << endl;
    out << "Compras: "  << numCompras << endl;
    return out;
}

#endif