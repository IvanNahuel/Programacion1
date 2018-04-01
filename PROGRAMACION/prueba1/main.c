#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero1;
    float numero2;
    float resultado;

    printf("Ingrese un numero entero y otro decimal \n");

    scanf ("%i",&numero1);
    scanf ("%f",&numero2);

    resultado = (numero1 + numero2);

    printf("%.2f",resultado);
}
