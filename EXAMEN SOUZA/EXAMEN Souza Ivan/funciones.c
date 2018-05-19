//#include <stdio.h>
//#include <stdlib.h>
#define TAM 50

int Opciones(){
    int opcion;


    printf("\n1-Alta \n");
    printf("2-Baja \n");
    printf("3-Modificar \n");
    printf("4-Informar \n");
    printf("5-Listar \n");

    printf("Ingrese la opcion que desee \n");
    scanf("%d",&opcion);

    return opcion;
}


void inicializarProductos(eProductos vec[],int tam){

for (int i =0 ; i<tam ; i++){
        vec[i].IsEmpty = 1;
    }
}

void AltasProductos(eProductos pro[],int tam,eProveedores prove[]){
        eProductos nuevoProducto;
        int indice;
        int cod;
        int codProve;

    indice = buscarLibre(pro, tam);

    if (indice ==-1){
        printf("el sistema esta lleno \n");
    } else {
        nuevoProducto.IsEmpty = 0;
        nuevoProducto.codigoProducto = indice;

        printf("Ingrese Descripcion del producto: ");
        fflush(stdin);
        gets(nuevoProducto.Descripcion);

        printf("\nIngrese Importe: ");
        scanf("%f",&nuevoProducto.importe);

        printf("\ningrese cantidad: ");
        scanf("%d",&nuevoProducto.cantidad);

        MostrarProveedores(prove);

        printf("\n\ningrese codigo de proveedor: ");
        scanf("%d",&nuevoProducto.IdProvedor);

        while (!(nuevoProducto.IdProvedor>-1 && nuevoProducto.IdProvedor<6)){
            printf("\nERROR Ingrese el codigo de proveedor correcto: ");
            scanf("%d",&nuevoProducto.IdProvedor);
        }
        pro[indice]=nuevoProducto;
        printf ("!!Alta Exitosa!!");
        }
    }
void MostrarProveedores (eProveedores vec[]){
            printf("Codigo proveedor            Descripcion\n");
        for (int j=0; j<6;j++){
            printf("%2d\t\t%10s\n",vec[j].codigoProveedor,vec[j].Descripcion);
        }
}

int buscarLibre (eProductos vec[], int tam){
   int indice = -1;

   for (int i =0 ; i<tam; i++){     //busca si hay un espacio en la memoria para cargar los nuevos datos

        if (vec[i].IsEmpty==1){

            indice = i;
            break;
        }
   }
   return indice;
}

int buscarProducto (eProductos vec[], int tam,int codigo){
int indice =-1;
    for (int i =0;i <tam; i++){
        if (vec[i].IsEmpty==0 &&vec[i].codigoProducto == codigo){
            indice = i;
            break;
        }
    }
    return indice;
}

void BajarProducto (eProductos vec[],int tam, int Codigo){ //
    int respuesta=2;
        //printf("el codigo a eliminar es %d",Codigo);
        for (int i = 0 ;i<tam; i++){

            if (( vec[i].IsEmpty==0 && vec[Codigo].codigoProducto!=Codigo )){
                printf("no existe ningun producto con ese codigo \n");
                break;
            }
            else if (vec[i].codigoProducto==Codigo &&vec[i].IsEmpty==0){
                printf("desea eliminar a : %s \n",vec[i].Descripcion);
                printf("1-Si \n");
                printf("2-No \n");
                scanf("%d",&respuesta);

                while (respuesta!=1 && respuesta!=2){
                    printf("Error Reingrese respuesta correcta\n");
                    printf("desea eliminar a : %s \n",vec[i].Descripcion);
                    printf("1-Si \n ");
                    printf("2-No \n");
                    scanf("%d",&respuesta);
                }
                switch (respuesta){
                    case 1:
                    vec[i].IsEmpty=1;
                    break;
                    case 2:
                    printf("Se ha cancelado la baja del producto \n");
                    break;
                    break;
                }
                break;
        } else if  ( vec[i].IsEmpty==1&& vec[Codigo].codigoProducto!=Codigo ){
            printf("No se ha encontrado ese codigo, tal vez ya fue eliminado o nunca fue creado");
        }
    }
}

void ModificarProducto (eProductos vec[],int tam, int codigo){
        int respuesta;
        for (int i = 0;i<tam;i++){
            if (( vec[i].IsEmpty==0 && vec[codigo].codigoProducto!=codigo )){
                printf("\n no existe ningun producto con ese codigo \n");
                break;
            }
            else if (vec[i].codigoProducto==codigo &&vec[i].IsEmpty==0){ {
                printf("\n Desea modificar los datos de: %s \n",vec[i].Descripcion);
                printf("1- Si \n");
                printf("2- No \n");
                scanf("%d",&respuesta);

                while (respuesta!=1 && respuesta !=2){
                    printf("Error Reingrese respuesta correcta \n");
                    printf("\n Desea modificar los datos de: %s \n",vec[i].Descripcion);
                    printf("1- Si \n");
                    printf("2- No \n");
                    scanf("%d",&respuesta);
                }
                switch (respuesta){
                    case 1:

                    printf("Ingrese nueva Descripcion: ");
                    fflush(stdin);
                    gets(vec[i].Descripcion);

                    printf("\ningrese un nuevo Importe: ");
                    scanf("%f",&vec[i].importe);

                    printf("ingrese nuevas cantidades: ");
                    scanf("%d",&vec[i].cantidad);

                    printf("Modificacion de producto Exitosa!!!");

                    break;
                    case 2:
                    printf("Se ha cancelado la modificacion de los productos \n");
                    break;
                }
                break;
            }
           // break;
        }
    }
}

void listarProductos(eProductos vec[],int tam){
            printf("\n-------------------------------------------------------------------------------------\n");
            printf("  Codigo           Descripcion            Importe         Stock\n");
        for (int i=0; i<tam;i++){
            if (vec[i].IsEmpty==0){
                printf("%2d\t%20s\t\t %4.2f\t\t %3d\t\n",vec[i].codigoProducto,vec[i].Descripcion,vec[i].importe,vec[i].cantidad);
            }
        }
}

void Informar(eProductos vec[],int tam){
    int contadorA = 0;
    float promedioA;
    float acumA = 0;
    int contadorProductosA=0;
    int contadorProducB=0;            //los que no superan ese promedio
    int contStockMayorD=0;
    int contStockMenorC=0;

    //int SumaA;

    for (int i =0; i< tam; i++){                    //CON ESTE FOR SACO EL PUNTO A
        if (vec[i].IsEmpty==0){
            contadorA++;
            acumA = vec[i].importe+ acumA;
        }
    }
        promedioA = acumA/contadorA;

    for (int i =0; i< tam; i++){
        if (vec[i].IsEmpty==0 && vec[i].importe >promedioA ){
            contadorProductosA++;
        } else if (vec[i].IsEmpty==0 && vec[i].importe <promedioA ) {
            contadorProducB++;
        }
        //------------------------Separador---------------PUNTOS (C Y D)-----------
        if (vec[i].IsEmpty==0 && vec[i].cantidad <=10){
            contStockMenorC++;
        } else if (vec[i].IsEmpty==0 && vec[i].cantidad >10){
            contStockMayorD++;
        }
    }


        printf("\nA)-Total y promedio de los importes\n");
        printf("El promedio de todos los productos es; %.3f\n",promedioA);
        if (contadorProductosA>0){
            printf("\nLa cantidad de productos que superan el total promedio son: %d",contadorProductosA);
        } else {
            printf("\nNingun producto Supera el promedio total");
        }

        //--------------------------------------------Separador-----------------------------
        printf("\n\nB)-Cantidad de productos que no superan el promedio de %.3f son: %d",promedioA,contadorProducB);
        //--------------------------------------------Separador-----------------------------
        printf("\n\nC)-La cantidad de productos que su stock es menor o igual a 10 es: %d",contStockMenorC);

        printf("\n\nD)-La cantidad de productos que su stock es mayor a 10 es: %d",contStockMayorD);

        printf("\n---------------------------Fin Informes------------------------------------------\n");
}

void listar(eProductos vec[],int tam,eProveedores prov[]){
eProductos Aux;
eProductos auxInt;
int promedio;
int contador=0;
int acum=0;
int AuxiliarIdProv;

OrdenarImpresion(vec, tam);



printf("\n\n\nProductos que en cantidad son menor o igual a 10\n");

printf("\n\tDescripcion--------------Codigo-----------Importe-----------------Cantidad\n");
    for (int i=0;i<tam;i++){
        if (vec[i].IsEmpty==0 && vec[i].cantidad<=10){
            printf("%20s \t\t %2d \t\t  %3.3f \t\t %3d\n",vec[i].Descripcion, vec[i].codigoProducto, vec[i].importe, vec[i].cantidad);
        }
    }
printf("\n\n\nProductos que en cantidad son Mayores a 10\n");

printf("\n\tDescripcion--------------Codigo-----------Importe-----------------Cantidad\n");
    for (int i=0;i<tam;i++){
         if  (vec[i].IsEmpty==0 && vec[i].cantidad >10){
            printf("%20s \t\t %2d \t\t  %3.3f \t\t %3d\n",vec[i].Descripcion, vec[i].codigoProducto, vec[i].importe, vec[i].cantidad);
        }
    }

    for (int i =0; i< tam; i++){
        if (vec[i].IsEmpty==0){
            contador++;
            acum = vec[i].importe+ acum;
        }
    }
    promedio = acum/contador;
    printf("\n-------------Productos Menor al importe------------------------------------\n");
    printf("\n\n\tDescripcion--------------Codigo-----------Importe-----------------Cantidad\n");
    for (int i =0;i<tam;i++){
        if (vec[i].IsEmpty==0 && vec[i].importe<promedio){ //menor
             printf("%20s \t\t %2d \t\t  %3.3f \t\t %3d\n",vec[i].Descripcion, vec[i].codigoProducto, vec[i].importe, vec[i].cantidad);
        }
    }
    printf("\n-------------Productos Mayor al importe--------------------------------------\n");
    printf("\n\nDescripcion--------------Codigo-----------Importe-----------------Cantidad--\n");
        for (int i =0;i<tam;i++){
            if (vec[i].IsEmpty==0 && vec[i].importe>promedio){
             printf("%20s \t\t %2d \t\t  %3.3f \t\t %3d\n",vec[i].Descripcion, vec[i].codigoProducto, vec[i].importe, vec[i].cantidad);
        }
    }

    printf("\n--------------Proveedores de productos que en stock es menor o igual a 10----\n");
    printf("\n\----------Proveedor-------------------------Descripcion-----------Cantidad\n");
        for (int i=0;i<tam;i++){
            if (vec[i].IsEmpty==0 && vec[i].cantidad<=10){
            for (int j=0;j<6;j++){
                if (vec[i].IdProvedor==prov[j].codigoProveedor){
                    printf("%20s\t\t %20s\t\t %2d\n",prov[j].Descripcion,vec[i].Descripcion,vec[i].cantidad);
                }
            }
        }
    }
    printf("\n\n");
}
//-----------------------------------------------------------------------------------------------------------------------------
void OrdenarImpresion(eProductos vec[],int tam){
    eProductos aux;
        for (int i=0;i<tam;i++){
            if (vec [i].IsEmpty==0)  {

                for (int k=0; k<tam-1; k++){
                    for (int j=i+1;j<tam;j++){

                        if (strcmp(vec[k].Descripcion,vec[j].Descripcion)>0){
                            aux=vec[k];
                            vec[k]=vec[j];
                            vec[j]=aux;
                        } else {
                            if (strcmp(vec[k].Descripcion,vec[j].Descripcion)==0){
                                if (vec[k].importe<vec[j].importe){
                                   aux=vec[k];
                                    vec[k]=vec[j];
                                    vec[j]=aux;
                                }
                            }
                        }
                    }
                }
            }
        }
            printf("\n\n\tDescripcion--------------Codigo-----------Importe-----------------Cantidad\n");
        for (int m=0 ;m<tam;m++){
            if (vec [m].IsEmpty==0)  {
            printf("\n%20s \t\t %2d \t\t %3.3f \t\t %3d\n",vec[m].Descripcion, vec[m].codigoProducto, vec[m].importe, vec[m].cantidad);
            }
        }
}

