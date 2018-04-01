#include <stdio.h>
#include <stdlib.h>

int main()
{
//    Pedir por prompt el precio y el porcentaje de descuento, mostrar:
//1-El descuento en dinero,
//2-El precio con el descuento ,
//3-El IVA
//todos los anteriores e un solo alert
//4-Y solo e l precio con descuento más el IVA por id .
float precio;
float descuento;

float resultadoDesc;

printf("ingrese precio \n");
scanf("%f",&precio);

printf("ingrese el descuento \n");
scanf("%f",&descuento);

descuento = descuento/100;
resultadoDesc = descuento*precio;

printf("el descuento es de %.2f ",resultadoDesc);

//ESTE ESTA BIEN, EL RESULTADO DIO BIEN Y ME SALIO

}
