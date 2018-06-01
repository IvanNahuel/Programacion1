#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[200];
    int estado;
}EMovie;


/**
 *  inicializa los estados vacios por defecto
 *  @param structura a ajustar los estados
 *  @return no retorna nada
 */
void inicializarPeliculas(EMovie* peliculas);

/**
 *  Crea nuevas entidades en base a la structura definida
 *  @param structura a crear los datos, y la cant maxima de datos a crear
 *  @return no retorna nada
 */

void AltaPeliculas(EMovie pelis[],int tam);

/**
 *  Busca un espacio libre en el array y devuelve la posicion de ese espacio libre
 *  @param structura a buscar el espacio libre y el tamaño
 *  @return no retorna nada
 */

int BuscarEspacioLibre(EMovie* peliculas,int tam);

/**
 *  Busca un espacio libre en el array y devuelve la posicion de ese espacio libre
 *  @param structura a buscar el espacio libre y el tamaño
 *  @return retorna el indice
 */

MostrarPeliculas (EMovie* peliculas,int tam);
/**
 *  Es una funcion debug que usaba para verificar que los datos de hayan cargado correctamente, basicamente muestra
 todos los datos cargados

*/
void BajarPelicula (EMovie* peliculas,int tam);
/**
 *  Elimina peliculas del sistema
 *  @param structura a eliminar y el tamaño
 *  @return no retorna nada
 */

 void ModificarPelicula (EMovie* peliculas,int tam);
 /**
 *  modifica la pelicula pasada por codigo
 *  @param structura a modificar y el tamaño
 *  @return no retorna nada
 */

#endif // FUNCIONES_H_INCLUDED
