#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* vector;
    int* aux;

    vector = (int*) malloc (sizeof(int)*5); //busca 5 espacios y guarda la direccion de memoria del primer elemento

    if (vector==NULL){
        printf("no se pudp asignar memoria \n");
        exit(1);        //si termino  de manera brusca
    }

    for (int i=0;i<5;i++){
            printf("ingrese un numero: ");
            scanf("%d",vector+i);
    }
    for (int i=0;i<5;i++){
            printf("%d ", *(vector+i));
    }
    printf("\n\n");

    aux = (int*)realloc(vector, 10*sizeof(int));

    if (aux !=NULL){
       vector = aux;
       printf("\nSe pudo agrandar el array con exito\n");
    }
        for (int i=5;i<10;i++){
            printf("ingrese un numero: ");
            scanf("%d",vector+i);
    }
        for (int i=0;i<10;i++){
            printf("%d ", *(vector+i));
    }


}
