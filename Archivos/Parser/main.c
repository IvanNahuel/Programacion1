#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n1,n2,n3,n4;
    int cant;

    FILE*f;
    f = fopen("archivo.txt","r");

    if (f==NULL){
        exit(1);
    }
    while (!feof(f)){
        cant = fscanf(f,"%d,%d,%d,%d",&n1,&n2,&n3,&n4);
        if (cant!=4){
            if (feof(f)){
                break;
            } else {
            printf("Problemas para leer el archivo\n");
            exit(1);
            }
        }
        printf("%d %d %d %d\n",n1,n2,n3,n4);
    }
        fclose(f);
}
