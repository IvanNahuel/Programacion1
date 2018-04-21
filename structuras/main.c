#include <stdio.h>
#include <stdlib.h>

void mostrarEmpleado(eEmpleado );


typedef struct{

char nombre[20];
int legajo;
float sueldo;
char sexo;



}eEmpleado;


int main()
{
int opcion;
int tam = 3;
int auxiliarLegajo;

//eEmpleado empleados = {"joseMaria",20,25.000,'m'};

eEmpleado otroEmpleado[]= {{"joseMaria",20,25.000,'m'},{"Maria",10 ,15.000,'f'},{"Pedro",1 ,10.000,'m'},{"flores",9 ,18.000,'m'}};
eEmpleado emp3;


//mostrarEmpleado(otroEmpleado[0]);
//mostrarEmpleado(otroEmpleado[1]);

for (int i =0 ;i<4 ; i++ ){
    mostrarEmpleado(otroEmpleado[i]);
}
printf("ingrese el modo que desea ordenar \n 1-ordenar por legajo");
scanf("%d",&opcion);

while (opcion!=1){
   printf("ingrese el modo que desea ordenar \n 1-ordenar por legajo");
scanf("%d",&opcion);
}


for (int i =0; i <tam-1 ; i++){
    for (int j = i+1 ; j<tam ; j++){

        if (otroEmpleado[i].legajo >otroEmpleado[j].legajo){

            auxiliarLegajo = otroEmpleado[i].legajo;
            otroEmpleado[i].legajo = otroEmpleado[j].legajo;
            otroEmpleado[j].legajo = auxiliarLegajo ;



        }


    }


}

for (int i =0 ;i<4 ; i++ ){
    mostrarEmpleado(otroEmpleado[i]);
}


//empleados.sexo = 'f';

/*
printf("%s \n",empleados.nombre);
printf("%d \n",empleados.legajo);
printf("%.2f \n",empleados.sueldo);
printf("%c \n",empleados.sexo);


printf("ingrese nombre \n");
fflush((stdin));
scanf("%s",&empleados.nombre);

printf("ingrese su legajo \n");
scanf("%d",&empleados.legajo);

printf("ingrese su sueldo \n");
scanf("%f",&empleados.sueldo);

printf("ingrese su sexo \n");
fflush((stdin));
scanf("%c",&empleados.sexo);

printf("%s \n",empleados.nombre);
printf("%d \n",empleados.legajo);
printf("%.2f \n",empleados.sueldo);
printf("%c \n",empleados.sexo);
//otroEmpleado = mostrarEmpleado(empleados);
*/
}

void mostrarEmpleado(eEmpleado emp){
printf("%s \n",emp.nombre);
printf("%d \n",emp.legajo);
printf("%.2f \n",emp.sueldo);
printf("%c \n \n \n",emp.sexo);

}











