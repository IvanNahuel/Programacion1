#include <stdio.h>
#include <stdlib.h>
typedef struct{
int id;
char nombre[20];
int edad;
int estado;
}eMascota;

int main()
{
    eMascota unaMascota;
    unaMascota.edad=5;
    unaMascota.id=1;

    strcpy(unaMascota.nombre, "colilla");

    eMascota muchasMascotas[5]= {{0,"Perla",2,1},{1,"Pepi",5,1},{2,"Min",2,1}};
    (muchasMascotas+3)->estado=0;
    (muchasMascotas+4)->estado=0;

    MostrarMascotas(muchasMascotas,6);

    CargarMascota(&muchasMascotas);
}

void MostrarMascotas(eMascota*vec,int tam){
      for (int i=0;i<tam;i++){
        if ((vec+i)->estado==1){
            MostrarMascota(vec+i);
        }
    }
}
void MostrarMascota(eMascota*Masc,int tam){
    printf("%d    %s    %d  \n",Masc->id, Masc->nombre, Masc->edad);
}
void CargarMascota (eMascota *vec){

    if (vec!=NULL){
        for (int i=0;i<6;i++){
            if ((vec+i)->estado==0){
                printf("Ingrese Nombre de mascota: ");
                scanf("%s",vec->nombre);
                fflush(stdin);
                printf("\nIngrese Id: ");
                scanf("%d",vec->id);
                printf("\nIngrese edad: ");
                scanf("%d",vec->edad);
                vec->estado=0;
            }
        }
    }
   // MostrarMascota(vec+3);
    MostrarMascotas(vec,6);
}





