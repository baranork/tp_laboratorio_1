#include "calculos.h"

int sumar(int a, int b)
{
    int resultadoSuma;

    resultadoSuma = a + b;

    return resultadoSuma;
}

int restar(int a, int b)
{
    int resultadoResta;

    resultadoResta = a - b;

    return resultadoResta;
}

float dividir(int a, int b)
{
    float resultadoDivision;

    if(b == 0)
    {
        resultadoDivision = 0;
    }
    else
    {
        resultadoDivision = (float)a / b;
    }

    return resultadoDivision;
}

int multiplicar(int a, int b)
{
    int resultadoMultiplicacion;

    resultadoMultiplicacion = a * b;

    return resultadoMultiplicacion;
}

int factoriar(int a)
{
    int resultadoFactorial;

    if (a < 0)
    {
        resultadoFactorial = -1;
    }
    else if (a == 0 || a == 1)
    {
        resultadoFactorial = 1;
    }
    else
    {
        resultadoFactorial = a * factoriar(a - 1);
    }

    return resultadoFactorial;
}


