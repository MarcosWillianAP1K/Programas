#include <stdio.h>
#include <math.h>

typedef struct
{
    double x, y;
} ponto;

double distancia(ponto p1, ponto p2);

int main()
{
    ponto p1, p2;

    scanf("digite os pontos\n");
    scanf("%lf%lf%lf%lf", &p1.x, &p1.y, &p2.x, &p2.y);

    printf("distancia: %.4lf", distancia(p1, p2));

    return 0;
}

double distancia(ponto p1, ponto p2)
{
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}