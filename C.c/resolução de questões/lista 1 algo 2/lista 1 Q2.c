#include <stdio.h>

int main()
{

    float salario, inss;

    printf("Digite o seu salario: ");
    scanf("%f", &salario);

    if (salario > 600 && salario <= 1200)
    {
        inss = salario * 0.20;
        salario -= inss;
    }
    else if (salario > 1200 && salario <= 2000)
    {
        inss = salario * 0.25;
        salario -= inss;
    }
    else if (salario > 2000)
    {
        inss = salario * 0.3;
        salario -= inss;
    }

    printf("\nSeu salario: %.2f\nINSS: %.2f", salario, inss);

    return 0;
}