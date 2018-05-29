#include <stdio.h>
#include <stdlib.h>

int main()
{
    int*x;

    x= (int*) malloc(sizeof(int));  //conseguimos ese espacio

    if (x == NULL){
        printf("no se pudp asignar memoria \n");
        exit(1);        //si termino  de manera brusca
    }

    printf("ingrese un numero: ");
    scanf("%d",x);

    printf("el numero ingresado es %d\n", *x);  //

    free(x);
}
