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

eEmpleado gente[TAM];

inicializarEmpleados (gente, TAM);      //LLAMA A LA FUNCION INICIALIZAR EMPLEADO Y LE TIRA GENTE Y TAM y setea que ese slot estaVacio


printf("----------------------------------AB_Empleados----------------------------------\n\n");

do{

    switch (menu()){
    case 1:
        printf("Alta \n\n");
        buscarLibre(gente, TAM);
        indexLibre = buscarEmpleado();
        if (buscarLibre()=)
        printf("Ingrese el nombre :");
        fflush(stdin);
        scanf("%d",&gente.nombre[indexLibre]);

        printf("Ingrese Legajo");
        scanf("%d",&gente.legajo[indexLibre]);

        printf("Ingrese Sexo");
        fflush(stdin);
        scanf("%c",&gente.legajo[indexLibre]);

        printf("ingrese sueldo");
        scanf("%f",&gente.sueldo[indexLibre]);


       // buscarEmpleado(gente, TAM, );       //LEGAJO
        break;
    case 2:
        printf("Baja \n\n");
        break;
    case 3:
        printf("Modificacion \n\n");
        break;
    case 4:
        printf("Listar \n\n");
        mostrarEmpleado(gente);
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

void mostrarEmpleado(eEmpleado emp){
    if (emp.isEmpty !=1){           //mientras mostrar empleado sea distinto a uno
printf("%s \n",emp.nombre);
printf("%d \n",emp.legajo);
printf("%.2f \n",emp.sueldo);
printf("%c \n \n \n",emp.sexo);
    } else {
    //aca debaria haber un print que avise que los campos estan vacios, no puede mostrar nada

    }
}

int buscarLibre (eEmpleado vec[], int tam){
    int retorno;

    for (int i = 0; i < tam ; i++){
        if (vec[i].isEmpty==1){
                          //significa que hay un slots disponible
            retorno = i ; //guarda el indice en retorno
            break;        //rompe el for en caso de HABER encontrado un lugar disponible
        } else {
            retorno = -1;
        }
    //printf("Ingrese legajo del nuevo usuario \n");
   // scanf("%d",vec[i].legajo);

    return retorno;          //devuelve -1 si no hay lugar, SI HAY LUGAR DEVUELVE SU INDEX
    }
}

int buscarEmpleado(eEmpleado vec[], int tam, int legajo){ //NOTA: EL LEJAGO QUE YO LLAMARE SERA LA POSICION LIBRE (SUPONGO)

    for (int i = 0; i<tam; i++){
if (vec[i].isEmpty==0 && vec[i].legajo==){
        }
    }
}






