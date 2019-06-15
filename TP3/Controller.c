#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Controller.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = 1;
    int contador = 0;
    FILE* f;

    f = fopen(path, "r");

    if(f != NULL)
    {
        parser_EmployeeFromText(f, pArrayListEmployee);
        retorno = 0;
    }


    //fread(pArrayListEmployee, sizeof(LinkedList), 4, f);
    fclose(f);
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = 1;
    FILE* f;

    f = fopen(path, "rb");

    if(f != NULL)
    {
        parser_EmployeeFromBinary(f, pArrayListEmployee);
        retorno = 0;
    }

    fclose(f);
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int opcion;
    int id;
    char nombre [20];
    char horasTrabajadas[5];
    char sueldo [8];
    char idstr [8];

    Employee* nuevoEmpleado;
    nuevoEmpleado = employee_new();

    if(nuevoEmpleado != NULL)
    {
        id = controller_lastID(pArrayListEmployee);
        id++;

        fflush(stdin);

        do
        {
            printf("\nIngrese el nombre del nuevo empleado: ");
            fflush(stdin);
            gets(nombre);
        }
        while(!(strcmp(nombre, "")));

        do
        {
            fflush(stdin);
            printf("\nIngrese la cantidad de horas trabajadas del nuevo empleado: ");
            fflush(stdin);
            gets(horasTrabajadas);
        }
        while(!(strcmp(horasTrabajadas, "")));

        do
        {

            fflush(stdin);
            printf("\nIngrese el sueldo del nuevo empleado: ");
            fflush(stdin);
            gets(sueldo);
        }
        while(!(strcmp(sueldo, "")));

        fflush(stdin);

        snprintf(idstr, 10, "%d", id);

        nuevoEmpleado = employee_newParametros(idstr, nombre, horasTrabajadas, sueldo);

        ll_add(pArrayListEmployee, nuevoEmpleado);


    }
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int opcion;
    int opcionModificar;
    char nuevoNombre[20];
    int nuevasHorasTrabajadas;
    int nuevoSueldo;
    Employee* empleadoAModificar;

    printf("Seleccione Numero de Control del empleado a editar o ingrese 0 para mostrar la lista\n");
    fflush(stdin);
    scanf("%d", &opcion);
    fflush(stdin);

    if(opcion != 0)
    {
        empleadoAModificar = ll_get(pArrayListEmployee, opcion-1);
        system("cls");

        printf("Que desea modificar?\n1.Nombre\n2.Horas Trabajadas\n3.Sueldo\n4.Volver\n");
        fflush(stdin);
        scanf("%d", &opcionModificar);

        switch(opcionModificar)
        {
        case 1:
            printf("El nombre actual del empleado es: %s\nIngrese el nuevo nombre del empleado: ", empleadoAModificar->nombre);
            fflush(stdin);
            gets(nuevoNombre);
            printf("Esta seguro que desea cambiar el nombre del empleado de: %s a: %s?\n1.Si\n2.No\n", empleadoAModificar->nombre, nuevoNombre);
            fflush(stdin);
            scanf("%d", &opcionModificar);
            if(opcionModificar!=1)
            {
                printf("No se ha cambiado el nombre del empleado");
            }
            else
            {
                strcpy(empleadoAModificar->nombre, nuevoNombre);
                printf("Se ha modificado el nombre del empleado");
            }

            break;
        case 2:
            printf("Las horas trabajadas del empleado son: %d\nIngrese la modificacion de las horas trabajadas: ", empleadoAModificar->horasTrabajadas);
            fflush(stdin);
            scanf("%d", &nuevasHorasTrabajadas);
            printf("Esta seguro que desea cambiar las horas trabajadas del empleado de: %d a: %d?\n1.Si\n2.No\n", empleadoAModificar->horasTrabajadas, nuevasHorasTrabajadas);
            fflush(stdin);
            scanf("%d", &opcionModificar);
            fflush(stdin);
            if(opcionModificar!=1)
            {
                printf("No se han cambiado las horas trabajadas del empleado");
            }
            else
            {
                empleadoAModificar->horasTrabajadas = nuevasHorasTrabajadas;
                printf("Se han modificado las horas trabajadas del empleado");
            }

            break;
        case 3:
            printf("El sueldo del empleado es: %d\nIngrese el nuevo sueldo: ", empleadoAModificar->sueldo);
            fflush(stdin);
            scanf("%d", &nuevoSueldo);
            printf("Esta seguro que desea cambiar el sueldo del empleado de: %d a: %d?\n1.Si\n2.No\n", empleadoAModificar->sueldo, nuevoSueldo);
            fflush(stdin);
            scanf("%d", &opcionModificar);
            fflush(stdin);
            if(opcionModificar!=1)
            {
                printf("No se han cambiado las horas trabajadas del empleado");
            }
            else
            {
                empleadoAModificar->sueldo = nuevoSueldo;
                printf("Se ha modificado el sueldo del empleado");
            }

            break;

        default:
            break;
        }

    }
    else
    {
        controller_ListEmployee(pArrayListEmployee);

    }
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int opcion;
    int opcionBorrado;
    Employee* empleadoABorrar;

    printf("Seleccione Numero de Control del empleado a eliminar o ingrese 0 para mostrar la lista\n");
    fflush(stdin);
    scanf("%d", &opcionBorrado);
    fflush(stdin);

    if(opcionBorrado == 0)
    {
        fflush(stdin);
        controller_ListEmployee(pArrayListEmployee);
        printf("Seleccione Numero de Control del empleado a eliminar: ");
        fflush(stdin);
        scanf("%d", &opcionBorrado);
    }

    fflush(stdin);
    empleadoABorrar = ll_get(pArrayListEmployee, opcionBorrado);

    printf("Esta seguro que desea eliminar al empleado: %s ID: %d?\n1.Si\n2.No\n", empleadoABorrar->nombre, empleadoABorrar->id);
    fflush(stdin);
    scanf("%d", &opcion);
    fflush(stdin);

    if(opcion != 1)
    {
        printf("El empleado no se ha eliminado");
    }
    else
    {
        printf("El empleado ha sido eliminado correctamente");
        ll_remove(pArrayListEmployee, opcionBorrado);
    }
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int id;
    char nombre[40];
    int horasTrabajadas;
    int sueldo;
    int len;
    int i;
    int contador = 0;

    Employee* empleadoAMostrar;

    len = ll_len(pArrayListEmployee);

    printf(" ID     NOMBRE         HORAS TRABAJADAS  SUELDO   NUMERO DE CONTROL\n");

    for(i=0; i<len; i++)
    {
        empleadoAMostrar = ll_get(pArrayListEmployee, i);
        if(empleadoAMostrar!=NULL)
        {
            employee_getId(empleadoAMostrar, &id);
            employee_getNombre(empleadoAMostrar, nombre);
            employee_getHorasTrabajadas(empleadoAMostrar, &horasTrabajadas);
            employee_getSueldo(empleadoAMostrar, &sueldo);

            printf("%-4d - %-14s -       %4d       - $%-7d   %d\n", id, nombre, horasTrabajadas, sueldo, contador);
            contador++;
        }

    }


    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int opcion;

    do
    {
        printf("Ordenar por:\n1.ID\n2.Nombre\n3.Horas Trabajadas\n4.Sueldo\n5.Atras");
        fflush(stdin);
        scanf("%d", &opcion);

        switch(opcion)
        {

        case 1:
            fflush(stdin);
            printf("Ordenar:\n1.Ascendentemente\n2.Descendentemente\n");
            fflush(stdin);
            scanf("%d", &opcion);
            printf("Por favor espere. Ordenamiento en proceso . . .");
            fflush(stdin);
            ll_sort(pArrayListEmployee,employee_CompareByID,opcion-1);
            break;
        case 2:
            fflush(stdin);
            printf("Ordenar:\n1.Ascendentemente\n2.Descendentemente\n");
            fflush(stdin);
            scanf("%d", &opcion);
            printf("Por favor espere. Ordenamiento en proceso . . .");
            fflush(stdin);
            ll_sort(pArrayListEmployee,employee_CompareByNombre,opcion-1);
            break;
        case 3:
            fflush(stdin);
            printf("Ordenar:\n1.Ascendentemente\n2.Descendentemente\n");
            fflush(stdin);
            scanf("%d", &opcion);
            printf("Por favor espere. Ordenamiento en proceso . . .");
            fflush(stdin);
            ll_sort(pArrayListEmployee,employee_CompareByHoras,opcion-1);
            break;
        case 4:
            fflush(stdin);
            printf("Ordenar:\n1.Ascendentemente\n2.Descendentemente\n");
            fflush(stdin);
            scanf("%d", &opcion);
            printf("Por favor espere. Ordenamiento en proceso . . .");
            fflush(stdin);
            ll_sort(pArrayListEmployee,employee_CompareBySueldo,opcion-1);
            break;

        }
    }while(opcion != 5);
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int i;
    int len;
    FILE* pFile = fopen(path, "w");
    Employee* unEmpleado;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        len = ll_len(pArrayListEmployee);
        fprintf(pFile, "");

        for(i=0; i<len; i++)
        {
            unEmpleado = ll_get(pArrayListEmployee, i);
            fprintf(pFile, "%d,%s,%d,%d\n", unEmpleado->id, unEmpleado->nombre, unEmpleado->horasTrabajadas, unEmpleado->sueldo);
        }
        fclose(pFile);

    }

    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{

    return 1;
}

int controller_lastID(LinkedList* pArrayListEmployee)
{
    int id;
    int len;
    int i;

    Employee* empleadoAMostrar;

    len = ll_len(pArrayListEmployee);

    for(i=0; i<len; i++)
    {
        empleadoAMostrar = ll_get(pArrayListEmployee, i);
        if(empleadoAMostrar!=NULL)
        {
            employee_getId(empleadoAMostrar, &id);
        }
    }
    return id;
}

