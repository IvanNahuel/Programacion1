#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"
#include "funciones.c"
#define TAM 50


int main()
{
    eProductos productos[TAM];

    inicializarProductos(productos,TAM);
    int salir =0;
    int ProdEliminar;
    int prodModificar;
    int flagIngreso;

    do{
        switch (Opciones()){
            case 1:
            printf("\n---------------------------------------Alta-------------------------------------------\n");
            AltasProductos(productos,TAM);
            flagIngreso =1;
                break;
            case 2:
                printf("\-----------------------------------Baja--------------------------------------------\n");
                printf("Ingrese Codigo del producto que desea eliminar: ");

                scanf("%d",&ProdEliminar);
                BajarProducto(productos,TAM,ProdEliminar);
                break;
            case 3:
                printf("\n-----------------------------Modificaciones---------------------------------------\n");
                printf("Ingrese codigo del producto que desea modificar");
                scanf("%d",&prodModificar);
                ModificarProducto(productos,TAM,prodModificar);
                break;
            case 4:
                printf("\n--------------------------------Informes------------------------------------------\n");
                Informar(productos,TAM);

                break;
            case 5:
                printf("\n-------------------------------Listar----------------------------------------------\n");
                listar(productos,TAM);
                break;
            }

    }while(salir==0);
}






