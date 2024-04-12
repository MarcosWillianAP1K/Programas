#include <stdio.h>
#include <math.h>

struct pontos
{
    float x1, x2, y1, y2, resultado;
    
};
struct pontos p;


void calcular();


int main()
{
    calcular();

    printf("\n\nDistancia: %.2f", p.resultado);

    return 0;
}

void calcular()
{
    printf("Digite os x1, y1, x2 e y2 respectivamente\n");
    scanf("%f%f%f%f", &p.x1, &p.y1, &p.x2, &p.y2);

    p.resultado = sqrt(pow((p.x1 - p.x2), 2) + pow((p.y1 - p.y2), 2));
}