#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, k, cont = 0;

void verificar_ordem(char *nomes[])
{
    for (int i = 65; i <= 122; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (nomes[j][0] == i)
            {
                cont++;
            }

            if (cont == k)
            {
                printf("\n\n%s\n", nomes[j]);
                return;
            }
        }
    }
}

int main()
{

    scanf("%d%d", &n, &k);

    // Detalhe, n teve jeito, tive que usar malloc para criar a matriz

    char **nomes = (char **)malloc(n * sizeof(char *));

    for (int i = 0; i < n; i++)
    {
        nomes[i] = (char *)malloc(20 * sizeof(char));
    }

    for (int i = 0; i < n; i++)
    {
        fflush(stdin);
        fgets(nomes[i], 20, stdin);
        fflush(stdin);
    }

    verificar_ordem(nomes);

    for (int i = 0; i < n; i++)
    {
        free(nomes[i]);
    }
    free(nomes);

    return 0;
}