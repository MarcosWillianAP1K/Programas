#include <stdio.h>

int main()
{

    float valor;

    printf("Digite o valor de compra: ");
    scanf("%f", &valor);

    if (valor < 20)
    {
        valor += valor * 0.45;
    }
    else
    {
        valor += valor * 0.30;
    }

    printf("\n\nValor final: %.2f", valor);

    return 0;
}