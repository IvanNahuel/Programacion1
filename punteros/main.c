#include <stdio.h>
#include <stdlib.h>


int main()
{
    int vec[]={5,2,3,1,4};
    primera(vec);
    printf("\n");
    segunda(vec);
    printf("\n");
    tercera(&vec);
    printf("\n");
    cuarta(&vec);
}

void primera(int vec[]){
    for (int i=0;i<5;i++){
        printf("%d ",vec[i]);
    }
}
void segunda(int vec[]){
    for (int i=0;i<5;i++){
        printf("%d ",*(vec+i));
    }
}
void tercera (int*vec[]){
    for (int i=0; i<5;i++){
        printf("%d ",vec[i]);
    }
}
void cuarta(int*vec[]){
    for (int i=0;i<5;i++){
        printf("%d ",*(vec+i));
    }
}
