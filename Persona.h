/*
 * Proyecto TC1030 - clase Persona
 * Isauro Alejandro Garza Elizondo - A01715088
 *
 * Se define la clase abstracta Persona, que es base para
 * Administrador y Cliente. 
 * Contiene los atributos comunes nombre e ID, así como sus 
 * métodos de acceso y el método virtual puro mostrar()
 */
#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Persona {
    protected:
        string nombre; // Nombre de la persona
        string ID; // Identificador de la persona

    public:
        // Constructor por default
        Persona(): nombre(""), ID(""){};
        Persona(string, string);

        void setNombre(string);
        void setID(string);

        string getNombre();
        string getID();

        // Funcion virtual pura, que se sobreescribe en Administrador y Cliente
        virtual stringstream mostrar() = 0; 
};

/**
 * Constructor con parámetros
 *
 * Inicializa los atributos nombre e ID con los valores recibidos.
 *
 * @param string nombre de la persona, string id
 * @return
 */
Persona::Persona(string nom, string id){
    nombre = nom;
    ID = id;
}

/** 
 * setNombre asigna el nombre a la persona
 * @param string nombre de la persona
 * @return 
 */
void Persona::setNombre(string nom){
    nombre = nom;
}

/** 
 * setID asigna el id a la persona
 * @param string ID de la persona
 * @return 
 */
void Persona::setID(string id){
    ID = id;
}

/** 
 * getNombre regresa el nombre de la persona
 * @param 
 * @return string nombre
 */
string Persona::getNombre(){
    return nombre;
}

/** 
 * getID regresa el id de la persona
 * @param 
 * @return string id
 */
string Persona::getID(){
    return ID;
}

#endif
