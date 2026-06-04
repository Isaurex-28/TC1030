#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include <iostream>
#include <string>
#include <sstream>
#include "Persona.h"

using namespace std;

class Administrador : public Persona {
    private:
        string usuario;
        string contrasena;

    public:
        Administrador(): Persona(), usuario(""), contrasena(""){};
        Administrador(string, string, string, string);

        void setUsuario(string);
        void setContrasena(string);

        string getUsuario();

        bool verificar(string, string);
        stringstream mostrar();
};

Administrador::Administrador(string nom, string id, string usr, string psw)
                            :Persona(nom, id){
        usuario = usr;
        contrasena = psw;
}

void Administrador::setUsuario(string usr){
    usuario = usr;
}

void Administrador::setContrasena(string psw){
    contrasena = psw;
}

string Administrador::getUsuario(){
    return usuario;
}

bool Administrador::verificar(string usr, string psw){
    return usr == usuario && psw == contrasena;
}

stringstream Administrador::mostrar(){
    stringstream out;
    out << "Nombre: "  << nombre  << endl;
    out << "ID: "      << ID      << endl;
    out << "Usuario: " << usuario << endl;
    return out;
}

#endif