 #include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Estructuras

typedef struct
{
    char nombre[30];
    int precio;
    int cantidad;
} producto;

typedef struct
{
    char nombre[30];
    char puesto[30];
    int sueldo;
    int legajo;
} empleado;

//Prototipado

int leerListaEmpleados(char archivo[]);
void mostrarEmpleado(empleado A);
void agregarEmpleados(char archivo[]);
empleado crearEmpleado();

//Productos

producto crearProducto();
void mostrarProducto(producto p);
void agregarProducto(char archivo[]);
int leerListaProductos(char archivo[]);


int main()
{
    int control = 1, menu, menu2, a;

    while(control == 1)
    {
        printf("1) Productos\n 2) Empleados \n");
        scanf("%i", &menu);

        system("cls");

        switch(menu)
        {
        case 1:

            printf("1)Lista de productos\n 2)Productos nuevos\n 3)Hisotirial de ventas");
            scanf("%d", &menu2);

            switch(menu2){
                case 1:
                    leerListaProductos("productos.bin");
                break;

                case 2:
                    agregarProducto("productos.bin");
                break;

                case 3:

                break;

            }

            break;

        case 2:

            a = leerListaEmpleados("empleados.bin");

            if(a == 0)
            {
                printf("Por favor ingrese un empleado");
                agregarEmpleados("empleados.bin");
            }
            else
            {
                printf("1)Aregar empleado 2)Eleminar empleado 3)Modificar empleado");
                scanf("%i", &menu2);

                system("cls");

                switch(menu2)
                {
                case 1:

                    agregarEmpleados("empleados.bin");

                    break;

                case 2:

                    break;
                }
            }

            break;
        }

        printf("Quiere seguir operando?");
        scanf("%i", &control);
    }

    return 0;
}

int leerListaEmpleados(char archivo[])
{
    FILE *buf = fopen(archivo, "rb");
    empleado aux;

    if(buf)
    {
        while(fread(&aux, sizeof(empleado), 1, buf) > 0)
        {
            mostrarEmpleado(aux);
        }

        fclose(buf);
    }
    else
    {
        return 0;
    }

    return 1;
}

void mostrarEmpleado(empleado A)
{
    printf("Nombre: %s Legajo: %i\n Puesto: %s Sueldo: %i\n\n",
           A.nombre,
           A.legajo,
           A.puesto,
           A.sueldo);
}

void agregarEmpleados(char archivo[])
{
    FILE *buf = fopen(archivo, "ab");

    char control = 's';
    empleado aux;

    if(buf)
    {
        while(control == 's')
        {
            aux = crearEmpleado();

            fwrite(&aux, sizeof(empleado), 1, buf);

            printf("Ingrese S para agregar otro empleado o N para terminar la operacion.");

            fflush(stdin);
            scanf("%c", &control);
        }

        fclose(buf);

        system("cls");
    }
    else
    {
        printf("ERROR");
    }
}

empleado crearEmpleado()
{
    empleado aux;
    int menu;

    while(getchar() != '\n');

    printf("Ingrese el nombre del empleado:");
    gets(aux.nombre);

    printf("Ingrese el legajo");
    scanf("%i", &aux.legajo);

    printf("Elija el puesto: 1-Cajero 2-Repositor 3-Limpieza 4-Seguridad");
    scanf("%i", &menu);

    switch(menu)
    {
    case 1:

        strcpy(aux.puesto, "Cajero");
        aux.sueldo = 640000;

        break;

    case 2:

        strcpy(aux.puesto, "Repositor");
        aux.sueldo = 640000;

        break;

    case 3:

        strcpy(aux.puesto, "Limpieza");
        aux.sueldo = 500000;

        break;

    case 4:

        strcpy(aux.puesto, "Seguridad");
        aux.sueldo = 800000;

        break;

        return aux;
    }
}
//Fun Productos

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

