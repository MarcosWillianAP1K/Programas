#include <stdio.h>
#include <stdlib.h>

#define TAM 10

int main()
{
    int vet[TAM];

    printf("Digite um numero entre de 1 a 20\nNumeros maiores ou menores serao desconsiderados\n");

    for (int i = 0; i < TAM; i++)
    {
        if (scanf("%d", &vet[i]) == 1)
        {
            if (vet[i] < 1 || vet[i] > 20)
            {
                i--;
            }
        }
        else{
            fflush(stdin);
            i--;
        }
    }
    system("cls||clear");

    printf("    Elemento\tValor\tHistograma");

    for (int i = 0; i < TAM; i++)
    {
        printf("\n\t%d\t%d\t", i, vet[i]);

        for (int j = 0; j < vet[i]; j++)
        {
            printf("*");
        }
    }

    return 0;
}