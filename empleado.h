#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

typedef struct
{
    char nombre[30];
    char puesto[30];
    int sueldo;
    int legajo;
} empleado;


int leerListaEmpleados(char archivo[]);
void mostrarEmpleado(empleado A);
void agregarEmpleados(char archivo[]);
empleado crearEmpleado();





#endif // EMPLEADO_H_INCLUDED
