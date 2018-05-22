#include <stdio.h>
#include <stdlib.h>
#define PATH "miArchivo.txt"

int main()
{

    FILE* pArchivo;
    char cadena[100]= "me fui";
    char cadena2[100]= "otro texto";
/*
    pArchivo = fopen(PATH,"w");       //modo escritura
    if (pArchivo!=NULL){
        fprintf(pArchivo, "Hola mundo");    //le agregamos algo al fichero en el segundo parametro
        fprintf(pArchivo, cadena);
        fprintf(pArchivo, "Aca con mascara: %s",cadena2);

        fclose(pArchivo);               //cerramos el fichero
    }
*/
    pArchivo = fopen(PATH,"r");

    if(pArchivo!=NULL){                 //mientras no sea el final del archivo leo y muestro
    while (!feof(pArchivo)){
    fgets(cadena,100,pArchivo);
    fclose(pArchivo);
    printf("La cadena es: %s",cadena);
        }
    }


}

