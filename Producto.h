/*
 * Proyecto TC1030 - clase Producto
 * Isauro Alejandro Garza Elizondo - A01715088
 *
 * Se define la clase abstracta Producto, que es base para
 * Juego, Miniatura y Accesorio. 
 * Contiene los atributos comunes nombre, ID, precio, cantidad
 * y disponibilidad, así como sus métodos de acceso 
 * y los métodos virtuale puros mostrarAdmin() y mostrarCliente()
 */
#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Producto{
    protected:
        string nombre; // Nombre del producto
        string ID; // Identificador
        float precio; // Precio de venta
        int cantidad; // Cantidad en inventario
        bool disponible; // Está disponible?
        
    public:
        // Constructor default
        Producto():nombre(""),ID(""),precio(0.0),cantidad(0),disponible(false){};
        Producto(string,string,float,int,bool);
        
        void setNombre(string);
        void setPrecio(float);
        void setCantidad(int);
        void setDisponible(int);
        void setDisponible(bool);
        
        string getNombre();
        string getId();
        float getPrecio();
        int getCantidad();
        bool getDisponible();

        // Función virtual pura para que los administradores puedan ver su inventario
        virtual stringstream mostrarAdmin() = 0;
        // Función virtual pura para que los clientes puedan ver el catálogo
        virtual stringstream mostrarCliente() = 0;
};

/**
 * Constructor con parámetros
 *
 * Inicializa todos los atributos del producto.
 *
 * @param string nombre del producto, string id 
 * @param float precio, int cantidad en inventario
 * @param bool disponibilidad
 * @return
 */
Producto::Producto(string nom, string id, float pri, int can, bool dis){
    nombre = nom;
    ID = id;
    precio = pri;
    cantidad = can;
    disponible = dis;
}

/** 
 * setNombre asigna el nombre al producto
 * @param string nombre del producto
 * @return 
 */
void Producto::setNombre(string nom){
    nombre = nom;
}

/** 
 * setPrecio asigna el precio de venta al producto
 * @param float precio del producto
 * @return 
 */
void Producto::setPrecio(float pri){
    precio = pri;
}

/** 
 * setCantidad asigna la cantidad en inventario
 * @param int cantidad en inventario
 * @return 
 */
void Producto::setCantidad(int can){
    cantidad = can;
}

/** 
 * setDisponible asigna si el producto está disponible
 * @param int 0 o 1 según si está disponible
 * @return 
 */
void Producto::setDisponible(int dis){
    disponible = dis;
}

/** 
 * setDisponible asigna si el producto está disponible
 * @param bool true o false según si está disponible
 * @return 
 */
void Producto::setDisponible(bool dis){
    disponible = dis;
}

/** 
 * getNombre regresa el nombre del producto
 * @param 
 * @return string nombre
 */
string Producto::getNombre(){
    return nombre;
}

/** 
 * getID regresa el id del producto
 * @param 
 * @return string id
 */
string Producto::getId(){
    return ID;
}

/** 
 * getPrecio regresa el precio de venta 
 * @param 
 * @return float precio
 */
float Producto::getPrecio(){
    return precio;
}

/** 
 * getCantidad regresa la cantidad en inventario
 * @param 
 * @return int cantidad del producto
 */
int Producto::getCantidad(){
    return cantidad;
}

/** 
 * getDisponible regresa si el producto está disponible
 * @param 
 * @return bool true si está disponible
 */
bool Producto::getDisponible(){
    return disponible;
}

#endif
