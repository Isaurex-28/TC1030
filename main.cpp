#include <iostream>
#include <string>
#include <sstream>
#include "Tienda.h"
#include "Producto.h"
#include "Juego.h"
#include "Miniatura.h"
#include "Accesorio.h"

using namespace std;

void agregarProducto(Tienda& t){
    int tipo;

    cout << endl << "Tipo de producto: " << endl;
    cout << "1.- Juego" << endl;
    cout << "2.- Miniatura" << endl;
    cout << "3.- Accesorio" << endl;
    cout << "Escribe el numero: "; cin >> tipo; cin.ignore();

    string nom; 
    string id = to_string(t.getNumProductos()+1);
    float pri;
    int can;
    bool dis;

    cout << endl << "Nombre: "; getline(cin, nom);
    cout << "ID: "<< id << endl;
    cout << "Precio: $"; cin >> pri;
    cout << "Cantidad: "; cin >> can;
    cout << "Disponible (0.- No / 1.- Si): "; cin >> dis; cin.ignore();

    switch(tipo){
        case 1:{
            string tip;
            int min;
            int max;
            string mar;

            cout << "Tipo de juego: "; getline(cin, tip);
            cout << "Minimo de jugadores: "; cin >> min;
            cout << "Maximo de jugadores: "; cin >> max;
            cin.ignore();
            cout << "Marca: "; getline(cin, mar);
            t.agregaProducto(nom, id, pri, can, dis, tip, min, max, mar);
            break;
        }
        case 2:{
            float tam;
            string per;
            string mat;

            cout << "Tamanio (cm): "; cin >> tam;
            cin.ignore();
            cout << "Personaje: "; getline(cin, per);
            cout << "Material: "; getline(cin, mat);
            t.agregaProducto(nom, id, pri, can, dis, tam, per, mat);
            break;
        }
        case 3:{
            string uti;
            string col;
            bool paq;

            cout << "Utilidad: "; getline(cin, uti);
            cout << "Color: "; getline(cin, col);
            cout << "Viene en paquete (1/0): "; cin >> paq;
            t.agregaProducto(nom, id, pri, can, dis, uti, col, paq);
            break;
        }
        default:
            cout << "Tipo no válido" << endl;
    }
    cout << endl << "Producto agregado correctamente" << endl;
}

void registrarAdministrador(Tienda& t){
    
    if(t.getNumAdmins() >= 10){
        cout << endl << "No puedes registrar mas administradores" << endl;
        return;
    }

    string nom; 
    string id = to_string(t.getNumAdmins()+1); 
    string usr; 
    string psw;

    cout << endl << "Registrar un Nuevo Administrador" << endl;
    cout << "Nombre: "; getline(cin, nom);
    cout << "Tu ID sera: " << id << endl;
    cout << "Usuario: "; getline(cin, usr);
    cout << "Contrasena: "; getline(cin, psw);

    t.agregaAdmin( new Administrador(nom, id, usr, psw));
    cout << endl << "Administrador registrado correctamente" << endl;
}

void registrarCliente(Tienda& t){
    
    if(t.getNumClientes() >= 100){
        cout << endl << "No puedes registrar mas administradores" << endl;
        return;
    }

    string nom; 
    string id = to_string(t.getNumClientes()+1); 
    string con; 

    cout << endl << "Registrar un Nuevo Cliente" << endl;
    cout << "Nombre: "; getline(cin, nom);
    cout << "Tu ID sera: "<< id << endl;
    cout << "Medio de contacto (correo electronico): "; getline(cin, con);

    t.agregaCliente(new Cliente(nom, id, con));
    cout << endl << "Cliente registrado correctamente" << endl;
}

void menuAdmin(Tienda& t){

    if(t.getNumAdmins() == 0){
        int op;
        cout << endl << "No hay administradores registrados" << endl;
        cout << "Deseas registrar un administrador?" << endl;
        cout << "1.- Si" << endl;
        cout << "2.- No" << endl;
        cout << "Escribe el numero: "; cin >> op; cin.ignore();
        if(op == 1){
            registrarAdministrador(t);
        }
        return; // regresa al menu principal
    }

    bool admin_login = false;
    bool salir = false;
    
    string user;
    string password;

    while(!admin_login && !salir){
        cout << endl << "Iniciar sesion" << endl;
        cout << "Usuario: "; getline(cin,user);
        cout << "Contrasena: "; getline(cin,password);
        bool login = t.iniciaSesion(user, password);
        if(login){
            admin_login = true;
        }
        else{
            int tryagain;
            cout << endl << "Deseas volver a intentarlo?" << endl;
            cout << "1.- Si" << endl;
            cout << "2.- No" << endl;
            cout << "Escribe el numero: "; cin >> tryagain; 
            cin.ignore();
            if(tryagain == 2){
                salir = true;
            }
        }
    }
    if(t.getAdmin()){ 
        int admin_choice;
        bool admin_menu = true;
        while(admin_menu){
            cout << endl << "Que deseas hacer?" << endl;
            cout << "1.- Ver fondos e inventario de productos" << endl;
            cout << "2.- Agregar producto al inventario" << endl;
            cout << "3.- Retirar producto del invetario" << endl;
            cout << "4.- Registrar Administrador" << endl;
            cout << "5.- Registrar Cliente" << endl;
            cout << "6.- Ver lista de Administradores" << endl;
            cout << "7.- Ver lista de Clientes" << endl;
            cout << "8.- Salir" << endl;
            cout << "Escribe el numero: "; cin >> admin_choice;
            cin.ignore();
            switch(admin_choice){
                case 1:{
                    cout << "Fondos: $" << t.getFondos() << endl;
                    cout << endl << t.muestraInventarioAdmin().str();
                    break;
                }
                case 2:{
                    bool more = true;
                    while(more){
                    agregarProducto(t);
                    cout << endl << "Deseas agregar otro producto?" << endl;
                    cout << "0.- No" << endl;
                    cout << "1.- Si" << endl;
                    cout << "Escribe el numero: "; cin >> more;
                    cin.ignore(); 
                    }
                    break;
                }
                case 3:{
                    bool more = true;
                    while(more){
                        string id;
                        cout << endl << t.muestraInventarioAdmin().str();
                        cout << "Que producto deseas retirar?" << endl;
                        cout << "ID: "; getline(cin, id);
                        t.retiraProducto(id);
                        cout << endl << "Deseas retirar otro producto?" << endl;
                        cout << "0.- No" << endl;
                        cout << "1.- Si" << endl;
                        cout << "Escribe el numero: "; cin >> more;
                        cin.ignore();                                      
                    }
                    break;                                
                }
                case 4:{
                    registrarAdministrador(t);
                    break;
                }
                case 5:{
                    registrarCliente(t);
                    break;
                }
                case 6:{
                    cout << endl << t.muestraListaAdmins().str();
                    break;
                }
                case 7:{
                    cout << endl << t.muestraListaClientes().str();
                    break;
                }
                case 8:
                    admin_menu = false;
                    break;

                default:
                    cout << "Opcion no valida" << endl;
            }
        }
    }
}

void menuCliente(Tienda& t){
    bool cliente_login = false;
    bool invitado = false;
    Cliente* activo;
    while(!cliente_login && !invitado){
        int login_option;
        cout << endl << "1.- Iniciar Sesion" << endl;
        cout << "2.- Registrarse" << endl;
        cout << "3.- Continuar como invitadx" << endl;
        cout << "Escribe el numero: "; cin >> login_option; cin.ignore();
        switch(login_option){
            case 1:{
                string id;
                if(t.getNumClientes() > 0){
                    cout << endl << "Escribe tu ID de cliente: " << endl;
                    cin >> id; cin.ignore();
                    activo = t.buscaCliente(id);
                    cout << endl << "Bienvenidx " << activo->getNombre() << endl;
                    cliente_login = true;
                }
                else{
                    cout << endl << "No hay clientes registrados, debes registrarte" << endl;
                }
                break;
            }
            case 2:{
                registrarCliente(t);
                break;
            }
            case 3:{
                invitado =  true;
                break;
            }
            default:
                cout << "Opcion no valida" << endl;
        } 
    }

    float presupuesto;

    cout << endl << "Cual es tu presupuesto? $"; cin >> presupuesto;
    cin.ignore();

    int client_choice;
    bool menu = true;

     while(menu){
        cout << endl << "Que deseas hacer?" << endl;
        cout << "1.- Ver catalogo de productos" << endl;
        cout << "2.- Comprar producto" << endl;
        cout << "3.- Salir" << endl;
        cout << "Escribe el numero: "; cin >> client_choice;
        switch(client_choice){
            case 1:{
                cout << t.muestraInventarioCliente().str() << endl;
                break;
            }
            case 2:{
                bool compra = t.compraProducto(presupuesto,t);
                if(compra && cliente_login){
                    activo->registrarCompra();
                    cout << "Compras realizadas: " 
                    << activo->getNumCompras() << endl;
                }
                break;
            }
            case 3:{
                menu = false;
                break;
            }    
            default:
                cout << "Opcion no valida" << endl;            
        }
    }
}


int main(){
    string nombre;
    float fondos;
    string user;
    string password;

    cout << endl << "Vamos a crear tu tienda" << endl;
    cout << endl << "Nombre de la tienda: "; getline(cin,nombre);
    cout << "Fondos iniciales: $"; cin >> fondos; cin.ignore(); 

    Tienda myStore(nombre,fondos);
    cout << endl << "Tienda creada con exito" << endl;

    bool menu = true;
    while(menu){
        int access;
        cout << endl << "Acceder como: " << endl;
        cout << "1.- Administrador" << endl;
        cout << "2.- Cliente" << endl;
        cout << "3.- Salir" << endl;
        cout << "Escribe el numero: "; cin >> access; cin.ignore();
        switch(access){
            case 1:{
                menuAdmin(myStore);
                break;
            }
            case 2:{
                menuCliente(myStore);
                break;
            }
            case 3:{
                menu = false;
                break;
            }
            default:
                cout << "Opcion no valida" << endl;
        }
    }
    return 0;
}        



    

