#include <stdio.h>
#include <stdlib.h>
#define TAM 20

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

/**
 * Obtiene el primer indice libre del array.
 * param lista: el array se pasa como parametro.
 */
int ObtenerEspacioLibre(EPersona lista[], int tam);
/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * param lista: el array se pasa como parametro. dni: el dni a ser buscado en el array.
 */
int BuscarPorDni(EPersona lista[], int dni, int tam);

int main()
{
    char seguir='s';
    int opcion=0;
    int dniBaja;
    EPersona persona[TAM];
    inicializarPersonar(persona, TAM);

    while(seguir=='s')
    {
        printf("\n");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                printf("-----------------------------------------Alta Personas--------------------------------------------\n");
                altaPersonas(persona, TAM);
                break;
            case 2:
                printf("-----------------------------------------Baja Personas--------------------------------------------\n");
                printf("Ingrese el dni de la persona que quiere borrar :");
                scanf("%d",&dniBaja);
                BajarPersona(persona, TAM, dniBaja);
                break;
            case 3:
                 printf("--------------------------------------------Personas---------------------------------------------\n");
                 ImprimirPersonas(persona,TAM);
                break;
            case 4:
                GraficoEdades(persona,TAM);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
void inicializarPersonar(EPersona vec[],int tam){

for (int i=0 ; i<tam; i++){
        vec[i].estado = 1;      //el estado 1 representa el campo vacio
    }
}
void altaPersonas(EPersona vec[],int tam){
    EPersona NuevaPersona;
    int indice;
    int buscar;
    int dni;

    indice = ObtenerEspacioLibre(vec, tam);

    if (indice == -1){
        printf("El sistema esta lleno, no se puede ingresar mas personas \n");
    } else {
        printf("ingrese dni de la persona que quiere registrar: ");
        scanf("%d",&dni);
    }
    buscar =BuscarPorDni(vec,dni,TAM);

    if (buscar ==-1) {
        NuevaPersona.estado = 0;
        NuevaPersona.dni = dni;

        printf("\n-Ingrese nombre: ");
        fflush(stdin);
        gets(NuevaPersona.nombre);

        printf("\n-Ingrese Edad: ");
        scanf ("%d",&NuevaPersona.edad);

        vec[indice] = NuevaPersona;

        printf("\n-Alta de personas Exitosa\n");
    }
}

int ObtenerEspacioLibre(EPersona lista[], int tam){
    int indice = -1;            //valor por defecto si no ha encontrado un indice
    for (int i=0; i<tam;i++){
        if (lista[i].estado==1){
            indice = i;
            break;
        }
    }
return indice;
}
int BuscarPorDni(EPersona lista[], int dni, int tam){
    int indice = -1;
    for (int i=0; i<tam;i++){
        if (lista[i].dni==dni &&lista[i].estado==0){
            indice =i;                  //retornamos el indice donde hay coincidencias De DNI
            printf("Ya existe una persona con ese DNI, Su nombre es: %s",lista[i].nombre);
            break;
        }
    }
    return indice;
}
void BajarPersona (EPersona vec[],int tam,int dni){
    int respuesta;
        for(int i =0;i<tam;i++){
            if (!(vec[i].estado==0 && vec[i].dni ==dni)){
                printf("\nNo existe ninguna persona con ese dni \n");
                break;
            } else {
                printf("Desea eliminar a: %s ?\n",vec[i].nombre);
                printf("1-Si \n");
                printf("2-No \n");
                scanf("%d",&respuesta);
            }
            while (respuesta!=1 && respuesta!=2){
                printf("Error Reingrese respuesta \n");
                printf("Desea eliminar a: %s ?\n",vec[i].nombre);
                printf("1-Si \n");
                printf("2-No \n");
                scanf("%d",&respuesta);
            }
            switch (respuesta){
        case 1:
            vec[i].estado=1;
            break;
        case 2:
            printf("Se ha cancelado la baja de la persona: %s \n",vec[i].nombre);
            break;
            }
            break;
        }
}
void ImprimirPersonas (EPersona vec[],int tam){
int auxDni;
int auxEdad;
char auxNombre[20];

   /*    for (int i=0; i<tam-1; i++){
            for (int j=i+1; j<tam; j++){
                if (strcmp(vec[i],vec[j])>0){

                    auxDni = vec[i].dni;
                    vec[i].dni = vec[j].dni;
                    vec[j].dni = auxDni;

                    strcpy(auxNombre,vec[i].nombre);
                    strcpy(vec[i].nombre, vec[j].dni);
                    strcpy(vec[j].dni,auxNombre);

                    auxEdad = vec[i].edad;
                    vec[i].edad = vec[j].edad;
                    vec[j].dni = auxEdad;
                }
            }
       }        */
                printf("\n|              Nombre                      |      Edad   |   DNI      | \n");
        for (int i =0; i<tam; i++){
            if (vec[i].estado==0){
                printf("|%25s                 |      %2d     |   %8d |\n",vec[i].nombre, vec[i].edad, vec[i].dni);
            }
        }
                printf("----------------------------------------------------------------------------");
}
void GraficoEdades(EPersona vec[],int tam) {
    int menorA18 =0;
    int entre19Y35 =0;
    int mayorA35 =0;
    char asterisco = '*';

printf("\n------------------------------------Grafico de edades---------------------------------------------------------\n\n\n\n\n\n");
    for (int i=0;i<tam; i++){
        if (vec[i].edad<=18 && vec[i].estado ==0){
            menorA18++;
        }else if (vec[i].edad >18 && vec[i].edad <=35 && vec[i].estado ==0){
            entre19Y35++;
        } else if (vec[i].edad >35 && vec[i].estado ==0) {
            mayorA35++;
        }
    }
    for (int i=0;i<tam;i++){
        if (vec[i].estado==0){
            if (menorA18>0){
                printf("%1c",asterisco);
                menorA18--;
            }
            if (entre19Y35>0){
                printf("             %1c",asterisco);
                entre19Y35--;
            }
            if (mayorA35>0){
                printf("                         %1c",asterisco);
                mayorA35--;
            }
            printf("\n");
        }
    }
        printf(" <18       >19<35        >35");
}







