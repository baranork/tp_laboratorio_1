#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto). *
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado *
     4. Modificar datos de empleado *
     5. Baja de empleado *
     6. Listar empleados *
     7. Ordenar empleados *
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto). *
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    int flag = 0;
    int r;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do
    {
        printf("1.Cargar datos (Desde texto)\n2.Cargar datos (Desde Binario)\n3.Alta de empleado\n4.Modificar datos de empleado\n5.Baja de empleado\n6.Listar empleados\n7.Ordener Empleados\n8.Guardar los datos (Texto)\n9.Guardar los datos (Binario)\n10.Salir (Salir sin antes haber guardado los datos resultara en la perdida de todas las modificaciones)\n");
        scanf("%d", &option);
        switch(option)
        {
        case 1:
            if(flag == 0)
            {
                r = controller_loadFromText("data.csv",listaEmpleados);
                if(r == 1)
                {
                    printf("Hubo un error. Por favor, intentelo de nuevo");
                }
                else
                {
                    printf("Datos cargados correctamente . . .\n");
                    system("pause");
                    system("cls");
                    flag = 1;
                }

            }

            else
            {
                printf("Ya se ha cargado un archivo.\n");
                system("pause");
                system("cls");
            }

            break;
        case 2:
            if(flag == 0)
            {
                r = controller_loadFromBinary("data.csv",listaEmpleados);
                if(r == 1)
                {
                    printf("Hubo un error. Por favor, intentelo de nuevo");
                }
                else
                {
                    printf("Datos cargados correctamente . . .\n");
                    system("pause");
                    system("cls");
                    flag = 1;
                }

            }

            else
            {
                printf("Ya se ha cargado un archivo.\n");
                system("pause");
                system("cls");
            }

            break;
        case 3:
            if(flag == 0)
            {
                printf("Todavia no se ha cargado ningun dato. Cargue una lista e intentelo de nuevo\n");
                system("pause");
                system("cls");
            }
            else
            {
                controller_addEmployee(listaEmpleados);
                system("pause");
                system("cls");
            }


            break;
        case 4:
            if(flag == 0)
            {
                printf("Todavia no se ha cargado ningun dato. Cargue una lista e intentelo de nuevo\n");
                system("pause");
                system("cls");
            }
            else
            {
                controller_editEmployee(listaEmpleados);
                system("pause");
                system("cls");
            }

            break;
        case 5:
            if(flag == 0)
            {
                printf("Todavia no se ha cargado ningun dato. Cargue una lista e intentelo de nuevo\n");
                system("pause");
                system("cls");
            }
            else
            {
                controller_removeEmployee(listaEmpleados);
                system("pause");
                system("cls");
            }

            break;
        case 6:
            if(flag == 0)
            {
                printf("Todavia no se ha cargado ningun dato. Cargue una lista e intentelo de nuevo\n");
                system("pause");
                system("cls");
            }
            else
            {
                controller_ListEmployee(listaEmpleados);
                system("pause");
                system("cls");
            }

            break;
        case 7:
                if(flag == 0)
            {
                printf("Todavia no se ha cargado ningun dato. Cargue una lista e intentelo de nuevo\n");
                system("pause");
                system("cls");
            }
            else
            {
                controller_sortEmployee(listaEmpleados);
                system("pause");
                system("cls");
            }


            break;
        case 8:
                        if(flag == 0)
            {
                printf("Todavia no se ha cargado ningun dato. Cargue una lista e intentelo de nuevo\n");
                system("pause");
                system("cls");
            }
            else
            {
                controller_saveAsText("data.csv",listaEmpleados);
                system("pause");
                system("cls");
            }

            break;
        case 9:
            break;
        }
        fflush(stdin);
    }
    while(option != 10);
    return 0;
}
