#include <stdio.h>
#include <stdlib.h>

#define TAM 10

int main()
{
    int n[TAM];

    printf("Digite 10 numeros inteiros entre 10 e 100.\nNumeros menores ou maiores serao desconsiderados.\n");

    for (int i = 0; i < TAM; i++)
    {
        if (scanf("%d", &n[i]) == 1)
        {
            if (n[i] < 10 || n[i] > 100)
            {
                i--;
            }
        }
        else
        {
            fflush(stdin);
            i--;
        }
    }
    system("cls||clear");

    int teste, t = 0;

    for (int i = 0; i < TAM; i++)
    {
        teste = 0;

        for (int j = 0; j < TAM; j++)
        {
            if (n[i] == n[j] && i != j)
            {
                teste++;
            }
        }

        if (teste == 0)
        {
            printf("%d\n", n[i]);
            t++;
        }
    }

    if (t == 0)
    {
        printf("Todos os numeros se repetem\n\n");
    }

    return 0;
}