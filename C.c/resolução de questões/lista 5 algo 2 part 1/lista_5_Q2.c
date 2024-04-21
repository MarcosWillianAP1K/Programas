#include <stdio.h>
#include <math.h>

typedef struct
{
    float x, y;
} Pontos;

void calculo(Pontos p1, Pontos p2, float *distancia);

int main()
{
    float distancia;
    Pontos p1, p2;

    printf("Digite as cordernadas do x1, y1, x2 e y2 respectivamente\n");
    scanf("%f%f%f%f", &p1.x, &p1.y, &p2.x, &p2.y);

    calculo(p1, p2, &distancia);

    printf("\n\ndistancia e %.2f\n", distancia);

    return 0;
}

void calculo(Pontos p1, Pontos p2, float *distancia)
{
    *distancia = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}