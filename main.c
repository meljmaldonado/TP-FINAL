#include <stdio.h>
#include <stdlib.h>
#include <string.h>



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
            while(control2==1){
            printf("1)Lista de productos\n 2)Productos nuevos\n 3)Hisotirial de ventas\n 4)Volver atrás\n");
            scanf("%d", &menu2);
            system("cls");
            switch(menu2){
                case 1:
                    leerListaProductos("productos.bin");
                break;

                case 2:
                    agregarProducto("productos.bin");
                break;

                case 3:

                break;
                case 4:
                    control2=0;
                    break;
                }

            }

            break;

        case 2:
            while(control2==1){
            a = leerListaEmpleados("empleados.bin");

            if(a == 0)
            {
                printf("Por favor ingrese un empleado");
                agregarEmpleados("empleados.bin");
            }
            else
            {
                printf("1)Aregar empleado 2)Eleminar empleado 3)Modificar empleado 4)Volver atrás");
                scanf("%i", &menu2);

                system("cls");

                switch(menu2)
                {
                case 1:

                    agregarEmpleados("empleados.bin");

                    break;

                case 2:

                    break;
                case 4:
                    control2=0;
                    break;
                }
            }

            break;

                case 3:
                    control=0;
                    break;
        }
        }

    }

    return 0;
}



//Fun Productos
