#include <stdio.h>
#include <math.h>

typedef struct
{
    float x1, x2;
} Raizes;

void calculo(float a, float b, float c, Raizes *r);

int main()
{
    float a, b, c;
    Raizes r;
    
    do{

    printf("digite o a, b e c da equacao\n");
    scanf("%f%f%f", &a, &b, &c);

    calculo(a, b, c, &r);

    if (pow(b,2) - 4 * a * c > 0)
    {
    printf("\nresultado de x1 e x2 respectivos\n%.2f  %.2f\n\n", r.x1, r.x2);
    }
    else{
        printf("\ncomplexo\n\n");
    }
    
    }while(a >= 0 || a <=0);

    return 0;
}

void calculo(float a, float b, float c, Raizes *r)
{
    //(*r).x1 é e a mesma coisa que r->x1, apenas tenho preferencia para codar assim

    (*r).x1 = (-b + sqrt(pow(b,2) - 4 * a * c)) / (2 * a);
    (*r).x2 = (-b - sqrt(pow(b,2) - 4 * a * c)) / (2 * a);
}