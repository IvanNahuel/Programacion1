#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int legajo;
    char nombre[20];
    float sueldo;
    int estado;
}eEmpleado;

int main()
{
eEmpleado* unEmpleado;

unEmpleado = (eEmpleado*) malloc(sizeof(eEmpleado));        //conseguimos espacio

    if (unEmpleado == NULL){
    printf("no se pudo reservar espacio de memoria\n\n");
    exit(1);
}
    unEmpleado->legajo = 1234;
    strcpy(unEmpleado->nombre, "Juan");
    unEmpleado->sueldo = 20000;
    unEmpleado->estado =1;

    printf("%d %s %.2f \n",unEmpleado->legajo,unEmpleado->nombre,unEmpleado->sueldo);

    free(unEmpleado);


}
void empleadoSetLegajo(eEmpleado* empleado, int legajo){

    if (empleado!=NULL &&legajo>0){            //verifica que el puntero recibido no sea NULL y que legajo no sea negativo
    empleado->legajo = legajo;
    }
}

int empleadoGetLegajo(eEmpleado* empleado){
    int legajo=-1;

    if (empleado!=NULL){
        legajo = empleado->legajo;
    }
    return legajo;
}



