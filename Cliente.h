/*
 * Proyecto TC1030 - clase Administrador
 * Isauro Alejandro Garza Elizondo - A01715088
 *
 * Se define la clase Cliente, que hereda de Persona.
 * Cliente con email de contacto y numero de compras realizadas
 */

#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <string>
#include <sstream>
#include "Persona.h"

using namespace std;

class Cliente : public Persona {
    private:
        string contacto; // E-mail de contacto
        int numCompras; // Número de compras realizadas en la tienda

    public:
        // Constructor por default
        Cliente():Persona(), contacto(""), numCompras(0) {};
        Cliente(string, string, string);

        void setContacto(string);
        void registrarCompra();

        string getContacto();
        int getNumCompras();

        stringstream mostrar();
};

/**
 * Constructor con parámetros
 *
 * Inicializa los atributos de Persona y el contacto del cliente.
 * El contador de compras inicia en 0.
 *
 * @param string nombre del cliente, string id  
 * @param string con email
 */
Cliente::Cliente(string nom, string id, string con):Persona(nom, id),
                numCompras(0){
    contacto = con;
}

/** 
 * setContacto asigna el email al Cliente
 * @param string email
 * @return 
 */
void Cliente::setContacto(string con){
    contacto = con;
}

/** 
 * registrarCompra aumenta el contador cada que un cliente
 * realiza una compra
 * @param 
 * @return 
 */
void Cliente::registrarCompra(){
    numCompras++;
}

/** 
 * getContacto regresa el e-mail del Cliente
 * @param 
 * @return string contacto
 */
string Cliente::getContacto(){
    return contacto;
}

/** 
 * getNumCompras regresa la cantidad de compras realizadas
 * por el cliente
 * @param 
 * @return int número de compras
 */
int Cliente::getNumCompras(){
    return numCompras;
}

/**
 * mostrar utiliza polimorfismo de la funcion de la clase Persona.
 * devuelve los datos del cliente como un stringstream,
 * (nombre, ID, contacto y número de compras).
 *
 * @param
 * @return stringstream con la información del cliente
 */
stringstream Cliente::mostrar(){
    stringstream out;
    out << "Nombre: "   << nombre     << endl;
    out << "ID: "       << ID         << endl;
    out << "Contacto: " << contacto   << endl;
    out << "Compras: "  << numCompras << endl;
    return out;
}

#endif
