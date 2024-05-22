#include <stdio.h>
#include <math.h>

int main(){

    float x1, y1, x2, y2;

    printf("Digite as cordernadas x1, y1, x2, y2 dos dois pontos respectivamente\n");
    scanf("%f%f%f%f", &x1, &y1, &x2, &y2);

    printf("A DISTANCIA E: %.2f", sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));

    return 0; 
}