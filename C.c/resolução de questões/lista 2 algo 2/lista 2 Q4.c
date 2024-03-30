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

        if (n[i] != 0)
        {
            for (int j = i + 1; j < TAM; j++)
            {
                if (n[i] == n[j])
                {
                    teste++;
                    n[j] = 0;
                }
            }

            if (teste != 0)
            {
                printf("%d\n", n[i]);
                t++;
            }
            else
            {
                n[i] = 0;
            }
        }
    }

    if (t == 0)
    {
       printf("Nao a nenhum numero repetido\n");
    }
    
    return 0;
}