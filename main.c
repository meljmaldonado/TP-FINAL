#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menuProductos();
void menuEmpleados();


int main()
{
    int control = 1, control2, menu, menu2, a;

    while(control == 1)
    {
        printf("1) Productos\n 2) Empleados \n 3) Cerrar programa \n");
        scanf("%i", &menu);
        control2=1;
        system("cls");

        switch(menu)
        {
        case 1:
            menuProductos();

            break;

        case 2:
            menuEmpleados();
            break;

        case 3:
            control=0;
            break;
        }
    }



    return 0;
}


void menuProductos(){
int control=1, menu;
 while(control==1){
            printf("1)Lista de productos\n 2)Productos nuevos\n 3)Hisotirial de ventas\n 4)Volver atrás\n");
            scanf("%d", &menu);
            system("cls");
            switch(menu){
                case 1:
                    leerListaProductos("productos.bin");
                break;

                case 2:
                    agregarProducto("productos.bin");
                break;

                case 3:

                break;
                case 4:
                    control=0;
                    break;
                }

            }
}

void menuEmpleados(){
int control=1, menu, aux;
 while(control==1){
            aux = leerListaEmpleados("empleados.bin");

            if(aux == 0)
            {
                printf("No se encontraron empleados registrados\n\n");
            }
                printf("1)Aregar empleado 2)Eleminar empleado 3)Modificar empleado 5)Volver atras");
                scanf("%i", &menu);

                system("cls");

                switch(menu)
                {
                case 1:

                    agregarEmpleados("empleados.bin");

                    break;

                case 2:

                    break;
                case 5:
                    control=0;
                    break;
                }



 }
}
