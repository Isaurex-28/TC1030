#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Persona {
    protected:
        string nombre;
        string ID;

    public:
        Persona(): nombre(""), ID(""){};
        Persona(string, string);

        void setNombre(string);
        void setID(string);

        string getNombre();
        string getID();

        virtual stringstream mostrar() = 0;
};

Persona::Persona(string nom, string id){
    nombre = nom;
    ID = id;
}

void Persona::setNombre(string nom){
    nombre = nom;
}

void Persona::setID(string id){
    ID = id;
}

string Persona::getNombre(){
    return nombre;
}

string Persona::getID(){
    return ID;
}

#endif