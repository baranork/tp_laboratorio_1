#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"

#define TRUE 1
#define FALSE 0

#define T 10
#define TS 4
int empleadosCargados = 0;

int main()
{
    eEmployee lista[T];
    int opcion;
    int r;

    initEmployees(lista, T);

    eSector sectores[TS]= {{1,"Sistemas"},{2,"Contabilidad"},{3,"RRHH"},{4,"Seguridad"}};
    hardcodearDatosEmpleados(lista, T);
    do
    {
        opcion = menuDeOpciones("1.Agregar empleados\n2.Modificar empleados\n3.Dar de baja\n4.Informar\n5.Salir\n\n");

        switch(opcion)
        {
        case 1:
            addEmployee(lista, sectores, T, TS);
            empleadosCargados++;

            break;
        case 2:
            if(empleadosCargados == 0)
            {
                printf("No hay empleados cargados. Por favor, cargue un empleado antes de Informarlos\n\n");
            }
            else
            {
                modificarEmpleado(lista, sectores, T, TS);
            }

            break;
        case 3:
            if(empleadosCargados == 0)
            {
                printf("No hay empleados cargados. Por favor, cargue un empleado antes de Informarlos\n\n");
            }
            else
            {
                r = removeEmployee(lista, sectores, T, 0);
                if(r == 1){
                    empleadosCargados--;
                }

            }


            break;
        case 4:
            if(empleadosCargados == 0)
            {
                printf("No hay empleados cargados. Por favor, cargue un empleado antes de Informarlos\n\n");
            }
            else
            {
                menuMostrar(lista, sectores, T, TS);
            }
            break;
        case 5:
            break;
        default:
            printf("Opcion invalida. Por favor, intentelo de nuevo\n");
            system("pause");
            system("cls");
        }
        fflush(stdin);

    }
    while(opcion != 5);
    return 0;
}
