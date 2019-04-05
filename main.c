#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"

int main()
{
    int numeroUno;
    int numeroDos;
    int suma;
    int resta;
    float division;
    int multiplicacion;
    int factorialUno;
    int factorialDos;
    int opcion;
    char seguir = 's';

    printf("Ingrese el primer numero: ");
    scanf("%d", &numeroUno);

    printf("Ingrese el segundo numero: ");
    scanf("%d", &numeroDos);

    do
    {
        fflush(stdin);
        system("cls");
        printf("Numero 1 = %d\nNumero 2 = %d\n\n1.Sumar\n2.Restar\n3.Dividir\n4.Multiplicar\n5.Factorial\n6.Salir\nIngrese una opcion: ", numeroUno, numeroDos);
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            suma = sumar(numeroUno, numeroDos);
            printf("\nEl resultado de la suma es: %d\n", suma);
            break;
        case 2:
            resta = restar(numeroUno, numeroDos);
            printf("\nEl resultado de la resta es: %d\n", resta);
            break;
        case 3:
            division = dividir(numeroUno, numeroDos);
            if(division == 0){
                printf("\nNo se puede dividir por cero\n");
            }
            else{
            printf("\nEl resultado de la division es: %.3f\n", division);
            }
            break;
        case 4:
            multiplicacion = multiplicar(numeroUno, numeroDos);
            printf("\nEl resultado de la multiplicacion es: %d\n", multiplicacion);
            break;
        case 5:
            factorialUno = factoriar(numeroUno);
            factorialDos = factoriar(numeroDos);
            if(factorialUno == -1 || factorialDos == -1){
                printf("\nNo se puede factoriar un numero negativo\n");
            }
            else{
            printf("\nEl resultado del factorial del primer numero es: %d\nY el resultado del factorial del segundo numero es: %d\n", factorialUno, factorialDos);
            }
            break;
        case 6:
            seguir = 'n';
            break;
        default:
            printf("\nOpcion ingresada invalida.\n");
            break;
        }

        system("pause");
        system("cls");
    }
    while(seguir == 's');

    return 0;
}
