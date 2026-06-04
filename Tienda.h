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
        string nombre;
        float fondos;
        
        Producto* productos[100];
        int numProductos;

        Administrador* admins[10];
        int numAdmins;

        Cliente* clientes[100];
        int numClientes;

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

Tienda::Tienda(string nom, float fon):numProductos(0),
                numAdmins(0),numClientes(0),admin(false){
    nombre = nom;
    fondos = fon;
}

void Tienda::setNombre(string nom){
    nombre = nom;
}

string Tienda::getNombre(){
    return nombre;
}

float Tienda::getFondos(){
    return fondos;
}

void Tienda::setFondos(float fon){
    fondos = fon;
}

int Tienda::getNumProductos(){
    return numProductos;
}

int Tienda::getNumAdmins(){
    return numAdmins;
}

int Tienda::getNumClientes(){
    return numClientes;
}

bool Tienda::getAdmin(){
    return admin;
}

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

stringstream Tienda::muestraListaAdmins(){
    stringstream aux;
    for(int i = 0; i < numAdmins; i++){
        aux << i + 1 <<".- "<< endl << admins[i]->mostrar().str() << endl;
    }
    return aux;    
}

stringstream Tienda::muestraListaClientes(){
    stringstream aux;
    for(int i = 0; i < numClientes; i++){
        aux << i + 1 <<".- "<< endl << clientes[i]->mostrar().str() << endl;
    }
    return aux;    
}


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

void Tienda::agregaAdmin(Administrador* a){
    if(numAdmins < 10){
        admins[numAdmins] = a;
        numAdmins++;
    }
}

void Tienda::agregaCliente(Cliente* c){
    if(numClientes < 100){
        clientes[numClientes] = c;
        numClientes++;
    }
}

Cliente* Tienda::buscaCliente(string id){
    for(int i = 0; i < numClientes; i++){
        if(clientes[i]->getID() == id){
            return clientes[i];
        }
    }
    return nullptr;
}

void Tienda::retiraProducto(string id){
    for(int i = 0; i < numProductos; i++){
        if(productos[i]->getId() == id){
            for(int j = i; j < numProductos - 1; j++){
                productos[j] = productos[j + 1];
            }
            productos[numProductos - 1] = nullptr; 
            numProductos--;                         
            break;                                  
        }
    }
}

bool Tienda::compraProducto(float ppto, Tienda& t){
    int prod;
    cout << endl << muestraInventarioCliente().str();
    cout << "Numero (en la lista) del producto: "; cin >> prod; cin.ignore();
    for(int i = 0; i < numProductos; i++){
        if(i + 1 == prod){
            if(productos[i]->getDisponible()){
                if(productos[i]->getPrecio() > ppto){
                    bool buy;
                    cout << "El producto sale de presupuesto" << endl;
                    cout << "Comprar aun asi? (0.- No / 1.- Si): ";
                    cin >> buy; cin.ignore();
                    if(!buy){
                     return false;
                    }
                }

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
