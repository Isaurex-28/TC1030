/*
 * Proyecto TC1030 - clase Administrador
 * Isauro Alejandro Garza Elizondo - A01715088
 *
 * Se define la clase Administrador, que hereda de Persona.
 * Administrador con usuario y contraseña para manejo de la tienda
 */


#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include <iostream>
#include <string>
#include <sstream>
#include "Persona.h"

using namespace std;

class Administrador : public Persona {
    private:
        string usuario; // Nombre de usuario
        string contrasena; // Contraseña para iniciar sesión

    public:
        // Constructor por default
        Administrador(): Persona(), usuario(""), contrasena(""){};
        Administrador(string, string, string, string);

        void setUsuario(string);
        void setContrasena(string);

        string getUsuario();

        bool verificar(string, string);
        stringstream mostrar();
};

/**
 * Constructor con parámetros
 *
 * Inicializa los atributos de Persona y los propios de administrador.
 *
 * @param string nombre del administrador, string id
 * @param string usuario, string contraseña
 * @return
 */
Administrador::Administrador(string nom, string id, string usr, string psw)
                            :Persona(nom, id){
        usuario = usr;
        contrasena = psw;
}

/** 
 * setUsuario asigna el usuario al Administrador
 * @param string usuario
 * @return 
 */
void Administrador::setUsuario(string usr){
    usuario = usr;
}

/** 
 * setContrasena asigna la contraseña al Administrador
 * @param string contraseña
 * @return 
 */
void Administrador::setContrasena(string psw){
    contrasena = psw;
}

/** 
 * getUsuario regresa el usuario del Administrador
 * @param 
 * @return string usuario
 */
string Administrador::getUsuario(){
    return usuario;
}

/** 
* verificar devuelve true si el usuario y contraseña coinciden
* con los ingresados
*
* @param string usuario, string contraseña
* @return bool true si coinciden
*/
bool Administrador::verificar(string usr, string psw){
    return usr == usuario && psw == contrasena;
}

/**
 * mostrar utiliza polimorfismo de la funcion de la clase Persona.
 * devuelve los datos del administrador como un stringstream,
 * (nombre, ID y nombre de usuario).
 *
 * @param
 * @return stringstream con la información del administrador
 */
stringstream Administrador::mostrar(){
    stringstream out;
    out << "Nombre: "  << nombre  << endl;
    out << "ID: "      << ID      << endl;
    out << "Usuario: " << usuario << endl;
    return out;
}

#endif
