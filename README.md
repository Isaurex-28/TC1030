# TC1030

# Contexto
Una tienda de juegos de mesa tiene complicaciones para mostrar todo su catálogo cuando los clientes preguntan por los artículos en venta.
Por lo que deciden crear una tienda en línea que se actualice en tiempo real para manejar sus artículos y que los clientes puedan ver y apartar 
juegos, miniaturas, accesorios y todo lo que la tienda tiene para ofrecer.

El inventario se maneja a través de la clase Tienda, que tiene acceso a la clase de Producto de la que se heredan las diferentes cosas que maneja la tienda. (Jueos, Miniaturas y Accesorios). Además los clientes pueden registrarse y tener un conteo de compras que después podría ser usada para programas de lealtad/beneficios.

# Diagrama de clases
<img width="5884" height="2796" alt="UML - TC1030" src="https://github.com/user-attachments/assets/4302bb5e-bd2f-4322-80b7-cad2d41ac850" />


# Funcionalidad
El programa emula una Tienda en línea. Se puede acceder como Administrador o como Cliente.
Para acceder como Administrador es necesario contar con un registro previo de tu usuario y contraseña.
Los clientes pueden iniciar sesión para registrar sus compras en su cuenta, o pasar a la tienda como invitados.

Los administradores pueden:
* Consultar el inventario y los fondos de la tienda
* Agregar y retirar produtos del inventario
* Registrar administradores y clientes
* Consultar listas de administradores y clientes


Los clientes pueden:
* Definir su presupuesto
* Ver el catálogo de productos
* Comprar los productos disponibles

# Casos donde no funciona
Al ingresar un tipo de dato que no sea entero en cualquiera de los menús
Al ingresar un número diferente a 0 o 1 en las preguntas de Sí y No

# Correcciones 
Consultar el archivo correcciones.txt

# Instrucciones
compilar con: `g++ main.cpp -o main`

correr en linux: `/main.out`

correr en windows: `.\‎/main.exe`

