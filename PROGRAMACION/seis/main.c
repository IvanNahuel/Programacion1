#include <stdio.h>
#include <stdlib.h>

int main()
{
   int nota;

   printf("ingrese su nota \n");
   scanf("%i",&nota);

   while (nota <0 || nota >10){
    printf("Error reingrese su nota [0-10] \n");
    scanf("%i",&nota);
   }

   switch (nota){
    case 0:
    case 1:
    case 2:
    case 3:
    printf("la proxima se puede \n");
    break;
    case 4:
    case 5:
    printf("debes preocuparte mas\n");
    case 6:
    printf("raspando\n");
    break;
    default:
    printf("aprobo");

    if (nota >8){
        printf(" muy bien");
    }
   }
}
