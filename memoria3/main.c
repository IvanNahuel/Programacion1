#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* vector;
    int* aux;

    vector = (int*) calloc (5,sizeof(int)); //busca 5 espacios y guarda la direccion de memoria del primer elemento

    if (vector==NULL){
        printf("no se pudp asignar memoria \n");
        exit(1);        //si termino  de manera brusca
    }

    for (int i=0;i<5;i++){
            printf("%d ", *(vector+i));
    }
}
