#include <stdio.h>
#include <stdlib.h>
#define TAM 50

int menu();


typedef struct{
int dia;
int mes;
int anio;


}eFecha;

typedef struct{
int legajo;
char nombre [20];
char sexo;
float sueldo;
int isEmpty;
eFecha fechaIngreso;


}eEmpleado;

void inicializarEmpleados(eEmpleado vec[],int tam);

int main()
{
int salir = 0;
int indexLibre;
int LegajoAEliminar;
int LegajoAModificar;

eEmpleado gente[TAM];

inicializarEmpleados (gente, TAM);      //LLAMA A LA FUNCION INICIALIZAR EMPLEADO Y LE TIRA GENTE Y TAM y setea que ese slot estaVacio


printf("----------------------------------AB_Empleados----------------------------------\n\n");

do{

    switch (menu()){
    case 1:
        printf("Alta \n\n");
        altaEmpleados(gente,TAM);
        break;
    case 2:
        printf("Baja \n\n");        //pido legajo, coomparo legajo que si existe, de existir PREGUNTO de que si
                                    //se quiere eliminar a ese empleado, de ser asi, is empy de ese index lo hago en -1
        printf("Ingrese legajo del empleado que desea eliminar: \n");
        scanf("%d",&LegajoAEliminar);
        BajarEmpleado(gente,TAM,LegajoAEliminar);
        break;
    case 3:
        printf("*********************Modificacion************************** \n\n");
        printf("Ingrese legajo a modificar: ");
        scanf("%d",&LegajoAModificar);
        ModificarEmpleado(gente,TAM,LegajoAModificar);

        break;

    case 4:
        printf("***********************************Listado**************************************** \n\n");
        printf(".......Nombre...............Legajo.............Sueldo...............Sexo.........\n");

       for (int i = 0; i< TAM; i++){
            if (gente[i].isEmpty!=1){               //si gente INDEX es distinto a 1 imprimimelo
                ImprimirEmpleados(gente[i]);
            }
       }
        break;

    case 5:
        printf("Ordenar \n\n");
        break;

    case 6:
        salir = 1;
        printf("Salir \n\n");
    break;
    default:
        printf("Error Reingrese la opcion correcta \n\n");
    }
} while (salir !=1);
}

int menu(){

//system("cls");
int opcion;

printf("1-Alta \n");
printf("2-Baja \n");
printf("3-Modificar \n");
printf("4-Listar \n");
printf("5-Ordenar \n");
printf("6-Salir \n");

printf("Ingrese la opcion que desee \n");
scanf("%d",&opcion);

return opcion;
}

void inicializarEmpleados(eEmpleado vec[],int tam){

for (int i =0 ; i<tam ; i++){
        vec[i].isEmpty = 1;
    }
}

void ImprimirEmpleados (eEmpleado emp){

printf(".        %s                 %d                  %.2f                 %c         .\n",emp.nombre,emp.legajo,emp.sueldo,emp.sexo);
}

int buscarLibre (eEmpleado vec[], int tam){
   int indice = -1;

   for (int i =0 ; i<tam; i++){     //busca si hay un espacio en la memoria para cargar los nuevos datos

        if (vec[i].isEmpty==1){

            indice = i;
            break;
        }
   }
   return indice;
}

int buscarEmpleados (eEmpleado vec[], int tam,int legajo){
int indice =-1;
    for (int i =0;i <tam; i++){                             //determina si existe un legajo con el que ya creamos
        if (vec[i].isEmpty==0 &&vec[i].legajo ==legajo){
            indice = i;
            break;
        }
    }
    return indice;
}
void altaEmpleados(eEmpleado vec[],int tam){
    eEmpleado nuevoEmpleado;
    int indice;
    int libre;          //indice libre en la funcion buscar libre
    int legajo;         //legajo

    indice = buscarLibre(vec, tam);


    if (indice ==-1){
        printf("el sistema esta lleno");
    } else {
    printf("ingrese legajo:");
    scanf("%d",&legajo);

    libre = buscarEmpleados(vec,TAM,legajo);
    if (libre !=-1){
        printf("ya existe una persona con ese legajo \n\n");

        ImprimirEmpleados(vec[libre]);
    } else {
    nuevoEmpleado.isEmpty =0;
    nuevoEmpleado.legajo = legajo;

    printf("ingrese nombre: ");
    fflush(stdin);
    gets(nuevoEmpleado.nombre);

    printf("ingrese sexo: ");
    fflush(stdin);
    scanf("%c",&nuevoEmpleado.sexo);

    printf("ingrese sueldo: ");
    scanf("%f",&nuevoEmpleado.sueldo);

    printf("carga de datos Exitosa \n");

    //printf("ingrese fecha de ingrese d m a: ");

    vec[indice] = nuevoEmpleado;
        }
    }
}
void BajarEmpleado (eEmpleado vec[],int tam, int legajo){ //
    int respuesta=2;


        for (int i = 0 ;i<tam; i++){

            if (!(vec[i].legajo==legajo && vec[i].isEmpty==0)){
                printf("no existe ningun empleado con ese legajo \n");
                break;
            }
            else {
                printf("desea eliminar a : %s \n",vec[i].nombre);
                printf("1-Si \n ");
                printf("2-No \n");
                scanf("%d",&respuesta);

                while (respuesta!=1 && respuesta!=2){
                    printf("Error Reingrese respuesta correcta\n");
                    printf("desea eliminar a : %s \n",vec[i].nombre);
                    printf("1-Si \n ");
                    printf("2-No \n");
                    scanf("%d",&respuesta);
                }
                switch (respuesta){
                    case 1:
                    vec[i].isEmpty=1;
                    break;
                    case 2:
                    printf("Se ha cancelado la baja del empleado \n");
                    break;
                    break;
                }
                break;
        }
    }
}

void ModificarEmpleado (eEmpleado vec[],int tam, int legajo){
        int respuesta;
        int respuestaModificacionAOtro;

        for (int i = 0;i<tam;i++){
            if (!(vec[i].legajo==legajo && vec[i].isEmpty==0)){
                printf("\n no existe ningun empleado con ese legajo \n");
                break;
            }
            else {
                printf("\n Desea modificar los datos de: %s \n",vec[i].nombre);
                printf("1- Si \n");
                printf("2- No \n");
                scanf("%d",&respuesta);
                while (respuesta!=1 && respuesta !=2){
                    printf("Error Reingrese respuesta correcta \n");
                    printf("Desea modificar los datos de: %s \n",vec[i].nombre);
                    printf("1- Si \n");
                    printf("2- No \n");
                    scanf("%d",&respuesta);
                }
                switch (respuesta){
                    case 1:
                    printf("ingrese nuevo nombre: ");
                    fflush(stdin);
                    gets(vec[i].nombre);
                    printf("\n Se ha modificado el nombre exitosamente \n");
                    printf("Desea modificar otra cosa? Legajo,Sexo,Sueldo \n");
                    printf("1-Si \n");
                    printf("2-No \n");
                    scanf("%d",&respuestaModificacionAOtro);

                    while (respuestaModificacionAOtro !=1 && respuestaModificacionAOtro !=2){
                        printf("Error de respuesta, elija correctamente \n");
                        printf("Desea modificar otra cosa? Legajo,Sexo,Sueldo \n \n");
                        printf("1-Si \n");
                        printf("2-No \n");
                        scanf("%d",&respuestaModificacionAOtro);
                    }
                    if (respuestaModificacionAOtro==1){
                        printf("\n ingrese Nuevo Legajo: ");
                        scanf("%d",&vec[i].legajo);

                        printf("\n ingrese nuevo sexo: ");
                        fflush(stdin);
                        scanf("%c",&vec[i].sexo);

                        printf("\n ingrese nuevo sueldo:");
                        scanf("%f",&vec[i].sueldo);

                        printf("Se ha modificado el legajo, sexo y nombre \n");
                    } else {
                    printf("Solo se ha modificado el nombre: %s del legajo: %d \n",vec[i].nombre, vec[i].legajo);
                    break;
                    }
                    break;
                    case 2:
                    printf("Se ha cancelado la modificacion de los empleados \n");
                    break;
                }
                break;
            }
        }
}
void OrdenarEmpleados (eEmpleado vec[], int tamaño){
int AuxiliarLegajo;
char AuxiliarNombre [20];
char AuxiliarSexo;
float AuxiliarSueldo;



}








