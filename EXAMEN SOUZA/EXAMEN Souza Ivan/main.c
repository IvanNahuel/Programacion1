#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"
#include "funciones.c"
#define TAM 50


int main(){
    eProductos productos[TAM];
    eProveedores proveedores[]={{0,"P&G"},{1,"Mayorista San juan"},{2,"Emanuel"},{3,"Pampa Linda"},{4,"Lactosa"},{5,"Peperina"}};

    inicializarProductos(productos,TAM);
    AltasProductos(productos,TAM,proveedores);
    int salir =0;
    int ProdEliminar;
    int prodModificar;
    int flagIngreso=0;


    do{
        switch (Opciones(productos,proveedores)){
            case 1:

            AltasProductos(productos,TAM,proveedores);
            flagIngreso =1;
                break;

            case 2:
                printf("\-----------------------------------Baja--------------------------------------------\n");
                listarProductos(productos,TAM);


                printf("Ingrese Codigo del producto que desea eliminar: ");
                scanf("%d",&ProdEliminar);
                BajarProducto(productos,TAM,ProdEliminar);
                break;
            case 3:
                printf("\n-----------------------------Modificaciones---------------------------------------\n");

                listarProductos(productos,TAM);
                printf("Ingrese codigo del producto que desea modificar: ");
                scanf("%d",&prodModificar);
                ModificarProducto(productos,TAM,prodModificar);
                break;
            case 4:
                printf("\n--------------------------------Informes------------------------------------------\n");
                Informar(productos,TAM);

                break;
            case 5:
                printf("\n-------------------------------Listar----------------------------------------------\n");
                listar(productos,TAM,proveedores);
                break;
            }
    }while(salir==0);
    return 0;
}











