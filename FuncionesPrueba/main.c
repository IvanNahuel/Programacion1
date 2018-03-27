#include <stdio.h>
#include <stdlib.h>


int SumarValores(int numero);
int main()
{
    int numero;
    int otroNumero;
    printf("ingrese un numero entero: ");
    scanf("%d",&numero);
    otroNumero = SumarValores(numero);
    printf("el valor incrementado es: %d \n",otroNumero);

}

int SumarValores(int numero){
    int retorno;
    retorno = numero + 1;

    return retorno;
}

