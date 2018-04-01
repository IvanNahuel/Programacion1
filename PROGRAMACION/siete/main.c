#include <stdio.h>
#include <stdlib.h>

int main()
{
    int notas;
    int edad;
    char sexo;

    int acomuladorProm = 0;
    float promedio;

    int notaMasBaja;
    char sexoNotaMasBaja;

    int contadorMayoresYNota;

    int MasJoven;
    int NotaDelMasJoven;
    char sexoMasJoven;

    int NotaPrimeraMujer;
    int EdadPrimeraMujer;
    int FlagMujer;

    int i =0;

    for (int i = 0; i<5; i++){
        printf("ingrese sus notas: ");
        scanf("%i",&notas);

        while (notas<0 || notas>10){
            printf("Error Reingrese su nota: ");
            scanf("%i",&notas);
        }
        acomuladorProm = notas+acomuladorProm;

        printf("ingrese su sexo: ");
        scanf("%c",&sexo);
        sexo = tolower (sexo);

        while (sexo !='f' && sexo !='m'){
            printf("Reingrese sexo [f o m]");
            scanf("%c",&sexo);
        }
        printf("ingrese su edad: ");
            scanf("%i",&edad);

        while (edad<0 ||edad >100){
            printf("Error Reingrese su edad [0-100]");
            scanf("%i",&edad);
        }

        if (i=0){
            notaMasBaja = notas;
            sexoNotaMasBaja = sexo;
            MasJoven = edad;
            NotaDelMasJoven = notas;

        }
        if (notas < notaMasBaja){
            notaMasBaja = notas;
            sexoNotaMasBaja = sexo;
        }
        if (edad >=18 && notas >=6){
            contadorMayoresYNota++;
        }
        if (edad<MasJoven){
            sexoMasJoven = sexo;
            NotaDelMasJoven = notas;
        }
        if (sexo =='f' && FlagMujer==0){
            NotaPrimeraMujer = notas;
            EdadPrimeraMujer = edad;
            FlagMujer = 1;
        }
    }
    promedio = acomuladorProm/5;
    printf("el promedio de las notas es: %i \n",acomuladorProm);        //calculo de promedio
    printf("La nota mas baja es %i y el sexo de esa persona es %c \n",notaMasBaja, sexoNotaMasBaja);
    printf("La cantidad de varones mayores a 18 son %i y su nota son mayor a 6 \n", contadorMayoresYNota);
    printf("la persona mas joven su sexo es %c y su nota es \n",sexoMasJoven,NotaDelMasJoven);

    if (FlagMujer==0){
        printf("no hubo ninguna mujer ");
    } else {
        printf("la primera mujer ingresada tenia %i y su nota era %i",EdadPrimeraMujer, NotaPrimeraMujer);
    }
}
