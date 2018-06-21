#include <stdio.h>
#include <stdlib.h>

int main()
{

    int opciones;
    int nuevoNumero;

    int n1;
    int cant;
    int Numeros[7];
    int ContadorRep = 0;

    FILE*f;

    f = fopen("Archivo.txt","r");

    if (f==NULL){
        printf("f es nulo");
        exit(1);
    }

    while (!feof(f)){
        cant = fscanf(f,"%d",&n1);      //cant por fila
        printf("\n");

        if (cant !=1){                  //si la cant por fila es distinto a uno
            if (feof(f)){               //SIGNIFICA QUE LLEGO AL FINAL DE LA FILA
                break;                  //ENTONCES ROMPEME LA REPETITIVA
            } else {                    //SI NO, ENTONCES
                printf("Problemas para leer el archivo\n");     //HUBO PROBLEMAS DESCONOCIDOS
                exit(1);                                //SALIME DEL PROGRAMA
            }
        }

        printf("%d",n1);

        (*(Numeros+ContadorRep))=n1;            //CON ESTO SUBIMOS LOS DATOS DEL DISCO A LA  RAM
        ContadorRep++;                          //Avanzamos para poder seguir guardando numeros en el array

    }
    printf("\n\n");
    for (int i=0;i<7;i++){
        printf("%d",Numeros[i]);
        printf("\n");
    }

        printf("que posicion del numero desea modificar: ");
        scanf("%d",&opciones);
        while (opciones<0 || opciones>7){
            printf("\nIngrese valor correcto");
            scanf("%d",&opciones);
        }
        printf("\nSe va a modificar el %d: ", Numeros[opciones]);
        printf("Ingrese el nuevo numero: ");
        scanf("%d", &nuevoNumero);

        Numeros[opciones] = nuevoNumero;    //aqui reempleazo las variables, la nueva ingresa, y la nueva

        for (int i=0;i<7;i++){
        printf("%d",Numeros[i]);            //aca se modifico en la MEMORIA RAM, PERO NO EN EL DISCO, TODAVIA FALTA
        printf("\n");                       //QUEMAR ESA VARIABLE MODIFICADA EN EL FICHERO
    }

    printf("Ahora Actualizamos el archivo\n");
    printf("Archivo Actualizado\n");

    f = fopen("Archivo.txt","w");           //abrimos el archivo de escritura nuevamente

    for (int i=0;i<7;i++){
    fprintf(f,"%d \n",Numeros[i]);          //escribime en una columna de los archivos los numeros actuales
    printf("\n");                           // recorridos en el for
    }



    fclose(f);
}
