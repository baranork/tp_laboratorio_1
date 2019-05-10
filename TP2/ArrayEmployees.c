#include "ArrayEmployees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/////////////////////////////////////////////////////////////////////////////////////FUNCIONES ARRAY EMPLOYEES////////////////////////////////////////////////////////////////////////////////////////
int initEmployees(eEmployee lista[], int t) //Inicializar empleados a LIBRE
{
    int i;
    for(i=0; i<t; i++)
    {
        lista[i].isEmpty = 0;
    }
    return 0;
}




/** \brief Solicita al usuario una serie de datos y los guarda
 *
 * \param lista Es la estructura donde se guardan los datos
 * \param sector Es la estructura donde se guardan los nombres y cantidades de los sectores
 * \param tam Es el tamaño de la cantidad de empleados posibles
 * \param ts Es el tamaño de la cantidad de sectores
 *
 */
void addEmployee(eEmployee lista[], eSector sector[], int tam, int ts)
{
    int i;
    int id;
    int idsector;
    int r;
    float sueldo;
    int flag = 0;
    int flag1 = 0;
    int flag2 = 0;


system("cls");

    i = buscarLibre(lista, tam);
    if(i!=-1)
    {
        do
        {
            printf("Ingrese id: ");
            scanf("%d", &id);
            printf("\n");
            r = findEmployeeById(lista, tam, id);
            if(r == -1){
                lista[i].id = id;
                flag = 1;
                break;
            }
            else{
                printf("Ya existe un empleado con ese ID. Por favor, elija otro\n\n");
            }
        }while(flag == 0);

        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(lista[i].name);
        printf("\n");
        printf("Ingrese apellido: ");
        fflush(stdin);
        gets(lista[i].lastName);
        printf("\n");
        do{
            printf("Ingrese sector: \n");
        mostrarSector(sector, ts);
        scanf("%d", &idsector);
        printf("\n");

        if(idsector < ts+1 && idsector > 0){
            lista[i].sector = idsector;
            flag1 = 1;
            break;
        }
        else{
            printf("Esa opcion no es valida. Por favor, intentelo nuevamente\n");
        }
        }while(flag1==0);

        do{
             printf("Ingrese salario: ");
        scanf("%f", &sueldo);
        printf("\n");
        if(sueldo > 0){
            lista[i].salary = sueldo;
            break;
        }
        else{
            printf("El sueldo no puede ser negativo o cero. Por favor, ingrese otro sueldo\n\n");
        }




        }while(flag2 == 0 );

       printf("Empleado registrado\n");
        lista[i].isEmpty = 1;

    }
    else
    {
        printf("No hay espacio\n");
    }
    system("pause");
    system("cls");

}


/** \brief Pide al usuario un id y si lo encuentra, lo borra
 *
 * \param lista[] eEmployee Son los empleados existentes
 * \param sector[] eSector Son los sectores existentes
 * \param t int Cantidad de emepleados posibles
 * \param id int ID del empleado al que se busca borrar
 * \return int Si se puedo borrar o no el usuario
 *
 */
int removeEmployee(eEmployee lista[], eSector sector[], int t, int id)
{


    int i;
    int loEncontro = 0;
    int opcion;
    int flag = 0;
    int borrado = 0;

    printEmployees(lista, sector, t);
    printf("Ingrese id del empleado a borrar: ");
    scanf("%d", &id);

    for(i=0; i<t; i++)
    {
        if(id == lista[i].id)
        {
            do
            {
                printf("Esta seguro que desea borrar a este empleado?: %s, %s\n 1.Si\n 2.No\n\n", lista[i].lastName, lista[i].name);
                scanf("%d", &opcion);
                if(opcion == 2)
                {
                    break;
                    flag=1;
                }
                else if(opcion == 1)
                {
                    lista[i].isEmpty = 0;
                    printf("Empleado borrado\n");
                    borrado = 1;
                    flag=1;

                }
            }
            while(flag==0);



            loEncontro = 1;
            break;
        }

    }

    if(loEncontro==0)
    {
        printf("El dato no existe\n");
    }



    return borrado;
}


/** \brief Ordena los empleados de distintas formas
 *
 * \param lista[] eEmployee Son los empleados existentes
 * \param sector[] eSector  Son los sectores existentes
 * \param t int Cantidad de emepleados posibles
 * \param orden int Es la forma en la que se pide el ordenamiento
 * \return void
 *
 */
void sortEmployees(eEmployee lista[], eSector sector[], int t, int orden)
{
    int i;
    int j;
    eEmployee aux;
    if(orden == 3)
    {
        printf("Orden por sector\n");
        for(i=0; i<t; i++)
        {
            for(j=i+1; j<t; j++)
            {
                if(lista[j].sector > lista[i].sector)
                {
                    aux = lista[j];
                    lista[j] = lista[i];
                    lista[i] = aux;


                }


            }

        }
        printEmployees(lista, sector, t);
    }

    else if(orden == 2)
    {
        printf("Orden Alfabetico (Ascendente)\n");
        for(i=0; i<t; i++)
        {
            for(j=i+1; j<t; j++)
            {
                if(strcmp(lista[j].lastName, lista[i].lastName)<0)
                {
                    aux = lista[j];
                    lista[j] = lista[i];
                    lista[i] = aux;


                }


            }

        }
        printEmployees(lista, sector, t);
    }
    else if(orden == 1)
    {
        printf("Orden Alfabetico (Descendente)\n");
        for(i=0; i<t; i++)
        {
            for(j=i+1; j<t; j++)
            {
                if(strcmp(lista[j].lastName, lista[i].lastName)>0)
                {
                    aux = lista[j];
                    lista[j] = lista[i];
                    lista[i] = aux;

                }

            }

        }
        printEmployees(lista, sector, t);

    }
}




/** \brief Muestra los empleados en pantalla
 *
 * \param lista[] eEmployee Son los empleados existentes
 * \param sector[] eSector Son los sectores existentes
 * \param t int Cantidad de emepleados posibles
 * \return void
 *
 */
void printEmployees(eEmployee lista[], eSector sector[], int t)
{
    int i;
    int index = 0;
    int j;
    for(i=0; i<t; i++)
    {
        if(lista[i].isEmpty == 1)
        {
            j = lista[i].sector;
            printf("  %d. %9s, %9s %13s   ID: %1d  Sueldo: %.2f\n", index+1, lista[i].lastName, lista[i].name, sector[j-1].nombreSector, lista[i].id, lista[i].salary);
            index++;
        }

    }
    printf("\n");

}

/** \brief Busca un empleado por su ID
 *
 * \param lista[] eEmployee Son los empleados existentes
 * \param t int Cantidad de emepleados posibles
 * \param id int ID del empleado al que se busca
 * \return int Si se puedo encontrar o no
 *
 */
int findEmployeeById(eEmployee lista[], int t, int id)
{
    int r = -1;
    int i;
    for(i=0; i<t; i++)
    {
        if(id == lista[i].id)
        {
            r = i;
            break;
        }
    }
    return r;
}

///////////////////////////////////////////////////////////////////////////////////////////OTRAS FUNCIONES///////////////////////////////////////////////////////////////////////////////////////////



/** \brief Muestra un mensaje al usuario y devuelve una opcion para menu
 *
 * \param mensaje[] char Mensaje a mostrar
 * \return int Opcion elegida por el usuario
 *
 */
int menuDeOpciones(char mensaje[])
{
    int opcion;
    printf("%s", mensaje);
    scanf("%d", &opcion);

    return opcion;
}


/** \brief Busca un lugar libre para empleado
 *
 * \param lista[] eEmployee Son los empleados existentes
 * \param tam int Cantidad de emepleados posible
 * \return int Si se encontro un lugar o no
 *
 */
int buscarLibre(eEmployee lista[], int tam)
{
    int i;
    int index=-1;
    for(i=0; i<tam; i++)
    {
        if(lista[i].isEmpty==0)
        {
            index = i;
            break;
        }
    }
    return index;
}


/** \brief Submenu que muestra las opciones de listado
 *
 * \param lista[] eEmployee Son los empleados existentes
 * \param sector[] eSector Son los sectores existentes
 * \param tam int Cantidad de emepleados posible
 * \param ts int Cantidad de sectores posible
 * \return void
 *
 */
void menuMostrar(eEmployee lista[], eSector sector[], int tam, int ts)
{
    int opcion;
    system("cls");

    do
    {
        opcion = menuDeOpciones("Informar:\n\n1.Empleados por orden alfabetico\n2.Empleados por sector\n3.Total y promedio de salarios\n4.Empleados con salario mayor al promedio\n5.Atras\n\n");

        switch(opcion)
        {
        case 1:
            menuMostrarOrden(lista, sector, tam, ts);
            system("cls");
            break;
        case 2:
            sortEmployees(lista, sector, tam, 3);
            system("pause");
            system("cls");
            break;
        case 3:
            sumarPromediarSueldos(lista, tam);
            break;
        case 4:
            mayorAlPromedio(lista, tam);
            break;
        case 5:
            system("cls");
            break;

        }
    }
    while(opcion != 5);
}

/** \brief Suma, promedia y muestra los sueldos de los empleados
 *
 * \param lista[] eEmployee Son los empleados existentes
 * \param t int Cantidad de emepleados posible
 * \return void
 *
 */
void sumarPromediarSueldos(eEmployee lista[], int t)
{
    float acumuladorSueldos = 0;
    float promedioSueldos;
    int contador = 0;
    int i;

    for(i=0; i<t; i++)
    {
        if(lista[i].isEmpty == 1)
        {
            acumuladorSueldos = acumuladorSueldos + lista[i].salary;
            contador++;
        }
    }
    promedioSueldos = acumuladorSueldos / (float)contador;
    printf("Total de salarios: $%.2f\nPromedio de salarios: $%.2f\n", acumuladorSueldos, promedioSueldos);
}

/** \brief Busca la cantidad de empleados con sueldos mayores al promedio y los muestra
 *
 * \param lista[] eEmployee Son los empleados existentes
 * \param t int Cantidad de emepleados posible
 * \return void
 *
 */
void mayorAlPromedio(eEmployee lista[], int t)
{
    float acumuladorSueldos = 0;
    float promedioSueldos;
    int contador = 0;
    int contadorMayor = 0;
    int i;

    for(i=0; i<t; i++)
    {
        if(lista[i].isEmpty == 1)
        {
            acumuladorSueldos = acumuladorSueldos + lista[i].salary;
            contador++;
        }
    }
    promedioSueldos = acumuladorSueldos / (float)contador;

    for(i=0; i<t; i++)
    {
        if(lista[i].isEmpty == 1 && lista[i].salary > promedioSueldos)
        {
            contadorMayor++;
        }
    }
    printf("La cantidad de empleados con un sueldo mayor al promedio es de: %d\n\n", contadorMayor);

}

/** \brief  Muestra un submenu que permite elegir de que forma se ordenaran alfabeticamente los empleados
 *
 * \param lista[] eEmployee Son los empleados existentes
 * \param sector[] eSector Son los sectores existentes
 * \param tam int Cantidad de emepleados posible
 * \param ts int Cantidad de sectores posible
 * \return void
 *
 */
void menuMostrarOrden(eEmployee lista[], eSector sector[], int tam, int ts)
{
    int opcion;

    do
    {
        opcion = menuDeOpciones("Empleados por orden alfabetico:\n\n1.Ascendente\n2.Descendente\n3.Atras\n");

        switch(opcion)
        {
        case 1:
            sortEmployees(lista, sector, tam, 2);
            break;
        case 2:
            sortEmployees(lista, sector, tam, 1);
            break;
        case 3:

            break;
        }
    }
    while(opcion != 3);
}

/** \brief Muestra los nombres de cada sector
 *
 * \param sector[] eSector   Son los sectores existentes
 * \param ts int Cantidad de sectores posible
 * \return void
 *
 */
void mostrarSector(eSector sector[], int ts)
{
    int i;
    for(i=0; i<ts; i++)
    {
        printf("  %d. %s\n", i+1, sector[i].nombreSector);
    }
}

/** \brief Hardcodea datos de empleados para testing de codigo
 *
 * \param lista[] eEmployee Son los empleados existentes
 * \param tam int Cantidad de emepleados posible
 * \return void
 *
 */
void hardcodearDatosEmpleados(eEmployee lista[], int tam)
{
    int i;
    int id[]= {1,8,9,7,2,4};
    char name[][51]= {"John","Fiorella","Luca","Ivan","Candela","Santiago"};
    char lastName[][51]= {"Casas","Aragon","Charly","Lopez","Galeno","Suarez"};
    float salary[]= {250.00, 100.25, 500.75, 750, 10.25, 600};
    int sector[]= {2,2,3,1,3,2};

    for(i=0; i<6; i++)
    {
        lista[i].id = id[i];
        strcpy(lista[i].name, name[i]);
        strcpy(lista[i].lastName, lastName[i]);
        lista[i].isEmpty = 1;
        lista[i].salary = salary[i];
        lista[i].sector = sector[i];



    }
}

/** \brief Permite modificar datos de un empleado
 *
 * \param lista[] eEmployee Son los empleados existentes
 * \param sector[] eSector Son los sectores existentes
 * \param t int Cantidad de emepleados posible
 * \param ts int Cantidad de sectores posible
 * \return void
 *
 */
void modificarEmpleado(eEmployee lista[], eSector sector[], int t, int ts)
{
    int id;
    int opcion;
    int index;
    int numeroSector;
    float oldSueldo;

    printEmployees(lista, sector, t);
    printf("Ingrese ID del empleado a modificar: ");
    scanf("%d", &id);

    index = findEmployeeById(lista, t, id);
    system("cls");

    if(index == -1)
    {
        printf("No se encontro el empleado. ID invalido");
    }
    else
    {
        printf("Empleado elegido: %s,%s ID: %1d  Sueldo: %.2f\n", lista[index].lastName, lista[index].name, lista[index].id, lista[index].salary);
        opcion = menuDeOpciones("\nQue desea modificar?\n 1.Nombre\n 2.Apellido\n 3.Sueldo\n 4.Sector\n 5.Salir\n\n");

        switch(opcion)
        {
        case 1:
            printf("Ingrese el nuevo nombre: ");
            fflush(stdin);
            gets(lista[index].name);

            printf("\nNombre cambiado correctamente\n");
            printf("%s,%s  ID: %d\n\n", lista[index].lastName, lista[index].name, lista[index].id);

            system("pause");
            system("cls");
            break;
        case 2:
            printf("Ingrese el nuevo apellido: ");
            fflush(stdin);
            gets(lista[index].lastName);

            printf("\nApellido cambiado correctamente\n");
            printf("%s,%s  ID: %d\n\n", lista[index].lastName, lista[index].name, lista[index].id);

            system("pause");
            system("cls");
            break;
        case 3:
            oldSueldo = lista[index].salary;
            printf("Ingrese el nuevo sueldo: ");

            fflush(stdin);
            scanf("%f", &lista[index].salary);

            printf("\nSueldo cambiado correctamente\n");
            printf("%s,%s  ID: %d  Sueldo anterior: $%.2f\n Sueldo nuevo: $%.2f\n\n", lista[index].lastName, lista[index].name, lista[index].id, oldSueldo, lista[index].salary);

            system("pause");
            system("cls");
            break;
        case 4:

            printf("Ingrese el nuevo sector: ");
            mostrarSector(sector, 4);
            fflush(stdin);
            scanf("%d", &numeroSector);

            printf("%d", numeroSector);
            lista[index].sector = numeroSector;
            printf("\nSector cambiado correctamente\n");
            system("pause");
            system("cls");
            break;

        case 5:
            break;


        }
    }

}


