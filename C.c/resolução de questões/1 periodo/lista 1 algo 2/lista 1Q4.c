#include <stdio.h>

int main()
{
    int maca;
    float valor;

    printf("Digite a quantidade de maca\n");
    scanf("%d", &maca);

    if (maca >= 12)
    {
        valor = maca * 1;
    }
    else{
        valor = maca * 1.3;
    }

    printf("\n\nValor: %.2f", valor);
    
    return 0;
}