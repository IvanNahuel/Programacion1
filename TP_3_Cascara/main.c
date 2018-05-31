#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TAM 50

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[50];
    int estado;
}EMovie;

int main()
{
    EMovie Peliculas[];
    char seguir='s';
    int opcion=0;

    inicializarPeliculas(Peliculas);




    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Generar pagina web\n");
        printf("4- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:


                break;
            case 2:


                break;
            case 3:


               break;
            case 4:


                seguir = 'n';
                break;
        }
    }

    return 0;
}
void inicializarPeliculas(EMovie peliculas[]){
    for (int i=0;i<TAM;i++){
        peliculas[i].estado=0;
    }
}

void AltaPeliculas(EMovie pelis[],int tam) {
    EMovie nuevaPelicula;
    int indice;

    indice = BuscarEspacioLibre(pelis,tam);

    if (indice==-1){
        printf("\nEl sistema Esta lleno no se puede ingresar mas peliculas");
    } else {
        nuevaPelicula.estado=0;

        printf("\nIngrese el titulo de la pelicula: ");
        fflush(stdin);
        gets(nuevaPelicula.titulo);

        printf("\nIngrese el genero de la pelicula: ");
        fflush(stdin);
        gets(nuevaPelicula.genero);

        printf("\nIngrese la duracion de la pelicula: );
        scanf("%d",&nuevaPelicula.duracion);

        printf("\nIngrese la descripcion de la pelicula: );
        fflush(stdin);
        gets(nuevaPelicula.descripcion);

        printf("\nIngrese el puntaje de la pelicula: ")
        scanf("%d",&nuevaPelicula.puntaje);

        printf("\Ingrese el link de la imagen");
        gets(nuevaPelicula.linkImagen);

        pelis[indice] = nuevaPelicula;

        printf("------------------------Alta Peliculas Exitosa!!-------------------------------");
    }

}
int BuscarEspacioLibre(EMovie vec[],int tam){
    int indice -1;
    for (int i=0; i<tam;i++){
        if ( (vec+i)-> ==1){
            indice = i;
            break;
        }
    }
return indice;
}




