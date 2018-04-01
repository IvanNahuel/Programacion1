#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero1;
    int numero2;

    float resultado;

    printf("ingrese un numero: \n");
    scanf("%i",&numero1);

    printf("ingrese otro numero: \n");
    scanf("%i",&numero2);

    if (numero1 == numero2){
        printf("%i%i",numero1, numero2);
    } else if (numero1>= numero2){
        resultado = (float) numero1 / numero2;      //parseo el resultado de esos dos numeros y los guardo
        printf("%.2f",resultado);
    } else {
        resultado =(int) numero1 + numero2;
        printf("%f \n",resultado);

        if (resultado <=50){
            printf("la suma es %f y es menor a 50");
        }

    }

}
