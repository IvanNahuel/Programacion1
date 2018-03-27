#include <stdio.h>
#include <stdlib.h>

int SumarDosValores (int numero1, int numero2);

int main()
{
   int numero1;
   int numero2;
   int resultado;
   printf("ingrese un numero entero: \n");
   scanf("%d",&numero1);
   printf("ingrese otro numero entero \n");
   scanf("%d",&numero2);
   resultado = SumarDosValores(numero1,numero2);
   printf("el resultado de las dos sumas es : %d",resultado);

}
int SumarDosValores(int numero1, int numero2){
int retorno;
retorno = numero1 + numero2;
return retorno;
}
