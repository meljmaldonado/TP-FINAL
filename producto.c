#include <stdio.h>
#include <stdlib.h>
#include "producto.h"


void mostrarProducto(producto p){
    printf("\nNombre: %s", p.nombre);
    printf("\nPrecio: %d", &p.precio);
    printf("\nCantidad: %d", &p.cantidad);
}

producto crearProducto(){
    producto p;

    while(getchar() != '\n');

    printf("\nIngrese el NOMBRE del producto: ");
    gets(p.nombre);

    printf("\nIngrese el PRECIO del producto: ");
    scanf("%d", &p.precio);

    printf("\nIngrese la CANTIDAD del producto: ");
    scanf("%d", &p.cantidad);
    p.valido=1;
    return p;
}

void agregarProducto(char archivo[]){
    FILE *buf = fopen(archivo, "ab");

    char continuar = 's';
    producto aux;

    if(buf != NULL){
        while(continuar == 'S' || continuar == 's'){
            aux = crearProducto();

            fwrite(&aux, sizeof(producto), 1, buf);

            printf("\nIngresar S para seguir cargando producto: ");
            scanf(" %c", &continuar);
        }

        fclose(buf);
    }else{
        printf("\nError al intentar abrir el archivo");
    }
}


int leerListaProductos(char archivo[]){
    FILE *buf = fopen(archivo, "rb");
    producto aux;

    if(buf){
        while(fread(&aux, sizeof(producto), 1, buf)> 0){
            mostrarProducto(aux);
        }

    fclose(buf);
    }else{
        return 0;
    }

    return 1;
}



