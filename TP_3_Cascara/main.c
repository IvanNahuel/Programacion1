#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "funciones.c"

#define TAM 50


int main()
{
    EMovie Peliculas[TAM];
    char seguir='s';
    int opcion=0;

    int cantidadEscrita;
    FILE*pArchivo;
    int contDeAltas;

    inicializarPeliculas(Peliculas);

    while(seguir=='s')
    {
        printf("\n1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
            AltaPeliculas(Peliculas,TAM);
                break;
            case 2:
            BajarPelicula(Peliculas,TAM);

                break;
            case 3:
            ModificarPelicula(Peliculas,TAM);

            break;
            case 4:

            pArchivo = fopen("Prueba.html","wb");

            if (pArchivo==NULL){
                exit(1);
            }
            for (int i=0;i<TAM;i++){
                if (Peliculas[i].estado==0){
                    fprintf(pArchivo,"<!DOCTYPE html> <!-- Template by Quackit.com --> <html lang='en'> <head> <meta charset='utf-8'> <meta http-equiv='X-UA-Compatible' content='IE=edge'> <meta name='viewport' content='width=device-width, initial-scale=1'> <!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags --> <title>Lista peliculas</title> <!-- Bootstrap Core CSS --> <link href='css/bootstrap.min.css' rel='stylesheet'>  <!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles --> <link href='css/custom.css' rel='stylesheet'><!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries --><!-- WARNING: Respond.js doesn't work if you view the page via file:// --><!--[if lt IE 9]><script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'> </script> <script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script> <![endif]--> </head> <body> <div class='container'> <div class='row'> <!-- Repetir esto para cada pelicula --> <article class='col-md-4 article-intro'> <a href='#'> <img class='img-responsive img-rounded' src='%s' alt=''> </a> <h3> <a href='#'>%s</a> </h3> <ul> <li>Género: %s </li> <li>Puntaje: %d </li> <li>Duración: %d </li> </ul> <p>%s</p> </article> <!-- Repetir esto para cada pelicula --> </div> <!-- /.row --> </div> <!-- /.container --> <!-- jQuery --> <script src='js/jquery-1.11.3.min.js'></script> <!-- Bootstrap Core JavaScript --> <script src='js/bootstrap.min.js'></script> <!-- IE10 viewport bug workaround --> <script src='js/ie10-viewport-bug-workaround.js'></script> <!-- Placeholder Images --> <script src='js/holder.min.js'></script> </body> </html> ",Peliculas[i].linkImagen, Peliculas[i].titulo,Peliculas[i].genero,Peliculas[i].puntaje,Peliculas[i].duracion,Peliculas[i].descripcion);
                }
            }
            if (cantidadEscrita<1){
            printf("\nError al escribir el archivo");
            }
            fclose(pArchivo);

               break;
            case 5:


                seguir = 'n';
                break;
            case 6:
                MostrarPeliculas(Peliculas,TAM);
                break;
        }
    }

    return 0;
}

