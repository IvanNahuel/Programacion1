#include <stdio.h>
#include <stdlib.h>

int main()
{
    int flag = 1;
    int vec[]= {3,1,2,5,4};
    int aux;

    while (flag==1){
        flag = 0;
    for (int j = 1 ; j< 5; j++){
        if (vec[j]< vec [j-1]){
            aux = vec[j];
            vec[j] = vec[j-1];
            vec[j-1] = aux;
            flag = 1;

        }
    }
    }
    printf("%d",vec[0]);
    printf("%d",vec[1]);
    printf("%d",vec[2]);
    printf("%d",vec[3]);
    printf("%d",vec[4]);
}
