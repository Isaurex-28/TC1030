/*
 * Proyecto TC1030 - clase Tienda
 * Isauro Alejandro Garza Elizondo - A01715088
 *
 * Clase Tienda, que es el controlador principal del sistema.
 * Gestiona el inventario de hasta 100 productos, la lista de administradores
 * y la lista de clientes. 
 * En esta clase se gestiona, agregar, retirar y comprar productos, 
 * y visualización de datos.
 */

#ifndef TIENDA_H
#define TIENDA_H

#include <iostream>
#include <string>
#include <sstream>
#include "Producto.h"
#include "Juego.h"
#include "Miniatura.h"
#include "Accesorio.h"
#include "Persona.h"
#include "Administrador.h"
#include "Cliente.h"

using namespace std;

class Tienda{
    private:
        // Nombre de la tienda
        string nombre;
        // Fondos de la tienda
        float fondos;
        // Arreglo de productos
        Producto* productos[100];
        // Contador de productos
        int numProductos;
        // Arreglo de administadores
        Administrador* admins[10];
        // Contador de administradores
        int numAdmins;
        // Arreglo de clientes
        Cliente* clientes[100];
        // Contador de clientes
        int numClientes;
        // Booleano que indica si hay un administrador activo
        bool admin;

    public: 
        Tienda():nombre(""),fondos(0.0),numProductos(0),
                numAdmins(0),numClientes(0),admin(false){};
        Tienda(string,float);
        
        void setNombre(string);
        string getNombre();
        
        float getFondos();
        void setFondos(float);
        
        int getNumProductos();
        int getNumAdmins();
        int getNumClientes();

        bool getAdmin();
       
        bool iniciaSesion(string,string);

        stringstream muestraInventarioAdmin();
        stringstream muestraInventarioCliente();

        stringstream muestraListaAdmins();
        stringstream muestraListaClientes();

        void agregaProducto(string, string, float, int, bool, string, int, int, string);
        void agregaProducto(string, string, float, int, bool, float, string, string);
        void agregaProducto(string, string, float, int, bool, string, string, bool);
        
        void agregaAdmin(Administrador*);
        void agregaCliente(Cliente*);
        Cliente* buscaCliente(string);

        void retiraProducto(string);
        bool compraProducto(float, Tienda&);
    };

/**
 * Constructor con parámetros
 *
 * Crea una tienda con nombre y fondos iniciales. Los contadores
 * de productos, admins y clientes inician en 0.
 *
 * @param string nombre de la tienda, float fondos iniciales
 */
Tienda::Tienda(string nom, float fon):numProductos(0),
                numAdmins(0),numClientes(0),admin(false){
    nombre = nom;
    fondos = fon;
}

/** 
 * setNombre asigna el nombre de la tienda 
 * @param string nombre de la tienda
 * @return 
 */
void Tienda::setNombre(string nom){
    nombre = nom;
}

/** 
 * getNombre regresa el nombre de la tienda 
 * @param 
 * @return string nombre de la tienda
 */
string Tienda::getNombre(){
    return nombre;
}

/** 
 * getFombre regresa los fondos de la tienda 
 * @param 
 * @return float fondos de la tienda
 */
float Tienda::getFondos(){
    return fondos;
}

/** 
 * setFombre asigna los fondos de la tienda 
 * @param float fondos
 * @return 
 */
void Tienda::setFondos(float fon){
    fondos = fon;
}

/** 
 * getNumProductos regresa la cantidad actual de productos en 
 * el inventario
 * @param 
 * @return int con la cantidad de productos
 */
int Tienda::getNumProductos(){
    return numProductos;
}

/** 
 * getNumAdmins regresa la cantidad de administradores
 * registrados
 * @param 
 * @return int con la cantidad de administradores
 */
int Tienda::getNumAdmins(){
    return numAdmins;
}

/** 
 * getNumClientes regresa la cantidad de clientes
 * registrados
 * @param 
 * @return int con la cantidad de clientes
 */
int Tienda::getNumClientes(){
    return numClientes;
}

/** 
 * getAdmin regresa true o false dependiendo de si
 * hay un administrador activo
 * @param 
 * @return bool si hay administradores
 */
bool Tienda::getAdmin(){
    return admin;
}

 /**
 * iniciaSesion verifica los usuarios y contraseñas de
 * los administradores registrados. 
 * Si coinciden, activa la sesión de admin.
 * @param string usuario, string contraseña
 * @return bool true si las credenciales son correctas
 */
bool Tienda::iniciaSesion(string usr, string psw){
    for(int i = 0; i < numAdmins; i++){
        if(admins[i]->verificar(usr, psw)){
            admin = true;
            cout << endl << "Sesion iniciada como: " 
                 << admins[i]->getNombre() << endl;
            return true;
        }
    }
    cout << endl << "Usuario o contrasena incorrectos" << endl;
    admin = false;
    return false;
}

/**
 * muestraInventarioAdmin devuelve el inventario completo con datos
 * de administrador (ID, precio, cantidad) para todos los productos.
 *
 * @param
 * @return stringstream con la lista numerada de productos
 */
stringstream Tienda::muestraInventarioAdmin(){
    stringstream aux;
    if(numProductos > 0){
        for(int i = 0; i < numProductos; i++){
            aux << i + 1 <<".- "<< productos[i]->mostrarAdmin().str() << endl;
        }
    }
    else{
        aux << "No hay productos por mostrar"<< endl;
    }
    return aux;
}

/**
 * muestraInventarioCliente devuelve el inventario con los datos
 * visibles para clientes para todos los productos.
 *
 * @param
 * @return stringstream con la lista numerada de productos
 */
stringstream Tienda::muestraInventarioCliente(){
    stringstream aux;
    if(numProductos > 0){
        for(int i = 0; i < numProductos; i++){
            aux << i + 1 <<".- "<< productos[i]->mostrarCliente().str() << endl;
        }
    }
    else{
        aux << "No hay productos por mostrar"<< endl;
    }
    return aux;
}

/**
 * muestraListaAdmins devuelve la lista de administradores registrados.
 *
 * @param
 * @return stringstream con la información de cada administrador
 */
stringstream Tienda::muestraListaAdmins(){
    stringstream aux;
    for(int i = 0; i < numAdmins; i++){
        aux << i + 1 <<".- "<< endl << admins[i]->mostrar().str() << endl;
    }
    return aux;    
}

/**
 * muestraListaClientes devuelve la lista de clientes registrados.
 *
 * @param
 * @return stringstream con la información de cada cliente.
 */
stringstream Tienda::muestraListaClientes(){
    stringstream aux;
    for(int i = 0; i < numClientes; i++){
        aux << i + 1 <<".- "<< endl << clientes[i]->mostrar().str() << endl;
    }
    return aux;    
}

/**
 * agregaProducto crea y agrega un Juego al inventario.
 *
 * @param string nombre del juego, string ID, float precio
 * @param int cantidad en inventario, bool disponibilidad
 * @param string tipo de juego, int mínimo de jugadores
 * @param int máximo de jugadores, string marca
 * @return
 */
void Tienda::agregaProducto(string nom, string id, float pri, int can, 
                bool dis, string tip,int min, int max, 
                string mar){
    if(numProductos<99){
        productos[numProductos] = new Juego(nom,id,pri,can,dis,tip,min,max,mar);
        numProductos++;
    }
    else{
        cout << "Ya no tienes espacio en la tienda" << endl;
    }
}

/**
 * agregaProducto crea y agrega una Miniatura al inventario.
 *
 * @param string nombre de la miniatura, string ID, float precio
 * @param int cantidad en inventario, bool disponibilidad
 * @param float tamaño, string personaje, string material
 * @return
 */
void Tienda::agregaProducto(string nom, string id, float pri, int can, 
                bool dis, float tam,string per,string mat){
    if(numProductos<99){
        productos[numProductos] = new Miniatura(nom,id,pri,can,dis,tam,per,mat);
        numProductos++;
    }
    else{
        cout << "Ya no tienes espacio en la tienda" << endl;
    }
}

/**
 * agregaProducto crea y agrega un Accesorio al inventario.
 *
 * @param string nombre de la miniatura, string ID, float precio
 * @param int cantidad en inventario, bool disponibilidad
 * @param string utilidad, string color, bool se vende en paquete
 * @return
 */
void Tienda::agregaProducto(string nom, string id, float pri, int can, 
                bool dis, string uti,string col,bool paq){
    if(numProductos<99){
        productos[numProductos] = new Accesorio(nom,id,pri,can,dis,uti,col,paq);
        numProductos++;
    }
    else{
        cout << "Ya no tienes espacio en la tienda" << endl;
    }
}

/**
 * agregaAdmin agrega un administrador ya creado al arreglo de admins.
 *
 * @param Administrador* a puntero al administrador a agregar
 * @return
 */
void Tienda::agregaAdmin(Administrador* a){
    if(numAdmins < 10){
        admins[numAdmins] = a;
        numAdmins++;
    }
}

/**
 * agregaCliente agrega un cliente ya creado al arreglo de clientes.
 *
 * @param Cliente* c puntero al cliente a agregar
 * @return
 */
void Tienda::agregaCliente(Cliente* c){
    if(numClientes < 100){
        clientes[numClientes] = c;
        numClientes++;
    }
}

/**
 * buscaCliente busca un cliente por su ID en el arreglo de clientes.
 *
 * @param string id del cliente a buscar
 * @return Cliente* puntero al cliente encontrado, o nullptr si no existe
 */
Cliente* Tienda::buscaCliente(string id){
    for(int i = 0; i < numClientes; i++){
        if(clientes[i]->getID() == id){
            return clientes[i];
        }
    }
    return nullptr;
}

/**
 * retiraProducto busca un producto y lo elimina del inventario 
 * Desplaza los elementos para mantener el arreglo sin huecos.
 *
 * @param string id del producto a retirar
 * @return
 */
void Tienda::retiraProducto(string id){
    for(int i = 0; i < numProductos; i++){
        if(productos[i]->getId() == id){
        // Desplaza todos los elementos siguientes una posición hacia atrás
            for(int j = i; j < numProductos - 1; j++){
                productos[j] = productos[j + 1];
            }
            productos[numProductos - 1] = nullptr; // Vacía el último espacio
            numProductos--; // Reduce la cantidad de productos en inventario                         
            break;                                  
        }
    }
}

/**
 * compraProducto permite al cliente comprar un producto
 * del inventario. 
 * Se verifica disponibilidad, presupuesto y cantidad en el inventario.
 * Si la compra es exitosa, descuenta una unidad y suma el precio a los fondos.
 *
 * @param float presupuesto del cliente Tienda& t referencia a la tienda
 * @return bool true si la compra se realizó con éxito
 */
bool Tienda::compraProducto(float ppto, Tienda& t){
    int prod;
    cout << endl << muestraInventarioCliente().str();
    cout << "Numero (en la lista) del producto: "; cin >> prod; cin.ignore();
    for(int i = 0; i < numProductos; i++){
        if(i + 1 == prod){
            if(productos[i]->getDisponible()){
                // Avisa si el producto supera el presupuesto del cliente
                if(productos[i]->getPrecio() > ppto){
                    bool buy;
                    cout << "El producto sale de presupuesto" << endl;
                    cout << "Comprar aun asi? (0.- No / 1.- Si): ";
                    cin >> buy; cin.ignore();
                    if(!buy){
                     return false;
                    }
                }
                // Verifica que haya unidades disponibles
                if(productos[i]->getCantidad() == 0){
                    productos[i]->setDisponible(false);
                    cout << "Producto agotado" << endl;
                    return false;
                }
                else{
                    productos[i]->setCantidad(productos[i]->getCantidad() - 1);
                    t.setFondos(fondos + productos[i]->getPrecio());
                    return true;
                }
            }
            else{
                cout << "Producto no disponible" << endl;
                return false;
            }
        }
    }
    cout << "Producto no encontrado" << endl;
    return false;
}

#endif
