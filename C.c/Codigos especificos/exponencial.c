#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){

    float a, b;
    
    printf("digite dois numeros\n");
    scanf("%f %f", &a, &b);

    printf("%.2f", pow(a, b));



    return 0;
}