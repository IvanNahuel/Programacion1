#include <stdio.h>
#include <stdlib.h>

int main()
{
  char nombre;
  char localidad;


  printf("ingrese su nombre ");
  scanf("%s",&nombre);

  printf("ingrese su localidad \n");
  scanf("%s",&localidad);

  printf("usted se llama %s ",nombre);
  printf(" y vive en %s \n ", localidad);


}
