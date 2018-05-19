#ifndef Funciones_H_INCLUDED
#define Funciones_H_INCLUDED

typedef struct{
int codigoProveedor;
char Descripcion[50];
}eProveedores;

typedef struct{
int codigoProducto;
char Descripcion[50];
float importe;
int cantidad;
int IsEmpty;
int IdProvedor;


}eProductos;
/** \brief pasa un numero entero
 *
 * \param   posee como parametro un numero enteros
 *
 * \return devuelve un numero entero, la respuesta a la pregunta

*/

int Opciones();

/** \brief pasa un numero entero
 *
 * \param   posee como parametro un numero enteros
 *
 * \return devuelve un numero entero, la respuesta a la pregunta
*/
void inicializarProductos(eProductos vec[],int tam);

void AltasProductos(eProductos pro[],int tam,eProveedores prove[]);

int buscarLibre (eProductos vec[], int tam);

int buscarProducto (eProductos vec[], int tam,int codigo);

void BajarProducto (eProductos vec[],int tam, int Codigo);

void ModificarProducto (eProductos vec[],int tam, int codigo);

void Informar(eProductos vec[],int tam);

void listar(eProductos vec[],int tam,eProveedores prov[]);


#endif
