#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
    float n;

    do{
        printf("digite um numero\n");
        scanf("%f", &n);

        printf("metade: %.2f\ncubica: %.5f\n", n / 2, cbrt(n));

        system("pause");
        system("cls||clear");


    }while(n >= 0);

    return 0;
    
}