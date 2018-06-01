#define TAM 50

void inicializarPeliculas(EMovie* peliculas){
    for (int i=0;i<TAM;i++){
        //peliculas[i].estado=1;
        (*(peliculas+i)).estado=1;
    }
}

void AltaPeliculas(EMovie pelis[],int tam) {
    EMovie nuevaPelicula;
    int indice;

    indice = BuscarEspacioLibre(pelis,tam);

    if (indice==-1){
        printf("\nEl sistema Esta lleno no se puede ingresar mas peliculas");
    } else {
        nuevaPelicula.estado=0;

        printf("\nIngrese el titulo de la pelicula: ");
        fflush(stdin);
        gets(nuevaPelicula.titulo);

        printf("\nIngrese el genero de la pelicula: ");
        fflush(stdin);
        gets(nuevaPelicula.genero);

        printf("\nIngrese la duracion de la pelicula: ");
        scanf("%d",&nuevaPelicula.duracion);

        printf("\nIngrese la descripcion de la pelicula: ");
        fflush(stdin);
        gets(nuevaPelicula.descripcion);

        printf("\nIngrese el puntaje de la pelicula: ");
        scanf("%d",&nuevaPelicula.puntaje);

        printf("\nIngrese el link de la imagen: ");
        fflush(stdin);
        gets(nuevaPelicula.linkImagen);

        pelis[indice] = nuevaPelicula;

        printf("\n------------------------Alta Peliculas Exitosa!!-------------------------------");
    }

}
int BuscarEspacioLibre(EMovie* peliculas,int tam){
    int indice =-1;
    for (int i=0; i<tam;i++){
        if ((*(peliculas+i)).estado==1){
            indice = i;
            break;
        }
    }
return indice;
}

MostrarPeliculas (EMovie* peliculas,int tam){          //MODO DEBUG NO LE HAGAS CASO
    for (int i=0;i<tam;i++){
        if ((*(peliculas+i)).estado==0){
            printf("%10s\t%10s",peliculas[i].titulo,peliculas[i].genero);
            printf("\n");
        }
    }
}
void BajarPelicula (EMovie* peliculas,int tam){
    int respuesta;
    printf("\n-------------------------------------------------------------------------------------------------\n");
    printf("\n     Codigo \t\t Titulo \t\t Genero\n");

    for (int i=0;i<tam;i++){
        if ( (*(peliculas+i)).estado==0){
            printf("%    2d \t %20s \t %10s",i,(*(peliculas+i)).titulo, (*(peliculas+i)).genero);
            printf("\n");
        }
    }

    printf ("\nIngrese el numero de la pelicula que desea eliminar: ");
    scanf("%d",&respuesta);

    while (respuesta<0||respuesta>tam){
        printf("ERROR Reingrese respuesta correcta");
        printf ("\nIngrese el numero de la pelicula que desea eliminar: ");
        scanf("%d",&respuesta);
    }
    (*(peliculas+respuesta)).estado=1;
    printf("---------------Baja Exitosa");
}

void ModificarPelicula (EMovie* peliculas,int tam){
    int respuesta;
    int SegundaRespuesta;
    EMovie ModPelis;

    for (int i=0;i<tam;i++){
        if ( (*(peliculas+i)).estado==0){
            printf("%    2d \t %20s \t %10s",i,(*(peliculas+i)).titulo, (*(peliculas+i)).genero);
            printf("\n");
        }
    }
    printf("\nIngrese el codigo de la pelicula que desea modificar: ");
    scanf("%d",&respuesta);

    while ( (*(peliculas+respuesta)).estado ==1 || respuesta<0 || respuesta>50){
        printf("ERROR");
        printf("\nIngrese el codigo de la pelicula que desea modificar: ");
        scanf("%d",&respuesta);
    }

        ModPelis.estado=0;
        printf("\nIngrese Nuevo Titulo de la pelicula: ");
        fflush(stdin);
        gets(ModPelis.titulo);

        printf("\nIngrese el nuevo genero : ");
        fflush(stdin);
        gets(ModPelis.genero);

        printf("\nIngrese la nueva duracion: ");
        scanf("%d",&ModPelis.duracion);

        printf("\nIngrese la nueva descripcion: ");
        fflush(stdin);
        gets(ModPelis.descripcion);

        printf("\nIngrese el nuevo puntaje: ");
        scanf("%d",ModPelis.puntaje);

        printf("\nIngrese el nuevo link: ");
        fflush(stdin);
        gets(ModPelis.linkImagen);

        peliculas[respuesta] = ModPelis;
}






