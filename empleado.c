#include <stdio.h>
#include <stdlib.h>
#include "empleado.h"


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
        system("pause");
        system("cls");
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
    }

    aux.valido=1;
    return aux;
}
