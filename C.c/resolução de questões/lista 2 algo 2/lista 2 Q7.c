#include <stdio.h>

int main()
{
    int vet[10];

    printf("Elemento\tValor");

    for (int i = 0; i < 10; i++)
    {
        vet[i] = (i + 1) * 2;

        printf("\n\t%d\t%d", i, vet[i]);
    }

    return 0;
}