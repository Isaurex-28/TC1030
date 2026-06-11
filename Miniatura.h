/*
 * Proyecto TC1030 - clase Miniatura
 * Isauro Alejandro Garza Elizondo - A01715088
 *
 * Se define la clase Miniatura, que hereda de Producto.
 * Miniaturas de personajes y monstruos para juegos de Rol,
 * se especifica tamaño, personaje y material.
 */
#ifndef MINIATURA_H
#define MINIATURA_H

#include <iostream>
#include <string>
#include <sstream>
#include "Producto.h"

using namespace std;

class Miniatura : public Producto{
    private:
        float tamano; // Tamaño de la figura
        string personaje; // Personaje que representa
        string material; // Material del que está hecho

    public: 
        // Constructor default
        Miniatura():Producto(),tamano(0.0),personaje(""),material(""){}
        Miniatura(string,string,float,int,bool,float,string,string);
        
        void setTamano(float);
        void setPersonaje(string);
        void setMaterial(string);

        float getTamano();
        string getPersonaje();
        string getMaterial();

        stringstream mostrarAdmin();
        stringstream mostrarCliente();
};
/**
 * Constructor con parámetros
 *
 * Inicializa los atributos de Producto y los propios de Miniatura.
 *
 * @param string nombre de la miniatura, string id
 * @param float precio, int cantidad en inventario
 * @param bool disponibilidad, float tamaño 
 * @param string personaje, string material
 * @return
 */
Miniatura::Miniatura(string nom, string id, float pri, int can, 
                bool dis, float tam,string per,string mat):Producto(nom,id,pri,can,dis){
    tamano = tam;
    personaje = per;
    material = mat;
}

/** 
 * setTamano asigna el tamaño a la miniatura
 * @param float tamaño en centimetros
 * @return 
 */
void Miniatura::setTamano(float tam){
    tamano = tam;
}

/** 
 * setPersonaje asigna el personaje a la miniatura
 * @param string personaje representado
 * @return 
 */
void Miniatura::setPersonaje(string per){
    personaje = per;
}

/** 
 * setMaterial asigna el tipo de material a la miniatura
 * @param string tipo de material
 * @return 
 */
void Miniatura::setMaterial(string mat){
    material = mat;
}

/** 
 * getTamano regresa el tamaño de la miniatura
 * @param 
 * @return float con el tamaño en centímetros
 */
float Miniatura::getTamano(){
    return tamano;
}

/** 
 * getPersonaje regresa el personaje de la miniatura
 * @param 
 * @return string personaje representado
 */
string Miniatura::getPersonaje(){
    return personaje;
}

/** 
 * getMaterial regresa el material de la miniatura
 * @param 
 * @return string con el material
 */
string Miniatura::getMaterial(){
    return material;
}

/**
 * mostrarAdmin utiliza polimorfismo para sobreescribir 
 * la funcion de la clase abstracta Producto.
 * Devuelve los datos completos de la miniatura para el administrador,
 * (nombre, ID, personaje, tamaño, precio, cantidad en el inventario).
 *
 * @param
 * @return stringstream con la información de la miniatura
 */
stringstream Miniatura::mostrarAdmin(){
    stringstream out;
    out << "Nombre: " << nombre << endl;
    out << "ID: " << ID << endl;
    out << "Personaje: " << personaje << endl;
    out << "Tamaño: " << tamano << endl;   
    out << "Precio: $" << precio << endl;
    out << "Cantidad: " << cantidad << endl;
    return out;
}

/**
 * mostrarCliente utiliza polimorfismo para sobreescribir 
 * la funcion de la clase abstracta Producto.
 * Devuelve los datos completos del accesorio para el cliente,
 * (nombre, personaje, material, precio).
 *
 * @param
 * @return stringstream con la información de la miniatura
 */
stringstream Miniatura::mostrarCliente(){
    stringstream out;
    out << "Nombre: " << nombre << endl;
    out << "Personaje: " << personaje << endl;
    out << "Material: " << material << endl;   
    out << "Precio: $" << precio << endl;
    if (disponible == false){
        out << "Este producto no esta disponible por el momento" << endl;
    }
    return out;
}


#endif
