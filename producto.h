#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

typedef struct
{
    char nombre[30];
    int precio;
    int cantidad;
    int valido;
} producto;


producto crearProducto();
void mostrarProducto(producto p);
void agregarProducto(char archivo[]);
int leerListaProductos(char archivo[]);


#endif // PRODUCTO_H_INCLUDED
