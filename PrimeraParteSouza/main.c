#include <stdio.h>
#include <stdlib.h>


int main()
{
    FILE*f;

    int id;
    char nombre[20];
    char direccion[20];
    int cant;
    int contador = 0;

    int idR[3];
    char nombreR[20][3];
    char direccionR[20][3];


    f = fopen("Empleados.csv","r");

    if (f==NULL){
        printf("f es nulo");
        exit(1);
    }

    while (!feof(f)){
        cant = fscanf(f,"%d %s %s",&id,&nombre,&direccion);

        if (cant!=3){
            if (feof(f)){               //SIGNIFICA QUE LLEGO AL FINAL DE LA FILA
                break;                  //ENTONCES ROMPEME LA REPETITIVA
            } else {                    //SI NO, ENTONCES
                printf("Problemas para leer el archivo\n");     //HUBO PROBLEMAS DESCONOCIDOS
                exit(1);                                //SALIME DEL PROGRAMA
            }
        }
        //printf("%d %s %s",id,nombre,direccion);
        (*(contador+idR))=id;
        (*(contador+direccionR))=direccion;

        printf("%s",nombre[][0]);

        contador++;
        printf("\n");

    }
}
