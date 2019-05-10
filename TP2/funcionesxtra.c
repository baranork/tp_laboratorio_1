/*
#include <stdio.h>

int menuDeOpciones(char mensaje[])
{
    int opcion;
    printf("%s", mensaje);
    scanf("%d", &opcion);

    return opcion;
}

void cargarEmpleado(eEmployee lista[], eSector sector[], int tam, int ts)
{
    int i;

    i = buscarLibre(lista, tam);
    if(i!=-1)
    {
        printf("Ingrese id: ");
        scanf("%d", &lista[i].id);
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(lista[i].name);
        printf("Ingrese apellido: ");
        fflush(stdin);
        gets(lista[i].lastName);
        printf("Ingrese sector: \n");
        mostrarSector(sector, ts);
        scanf("%d", &lista[i].sector);
        printf("Ingrese salario: ");
        scanf("%d", &lista[i].salary);



        lista[i].isEmpty = 1;

    }
    else
    {
        printf("No hay espacio");
    }

}

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
*/
