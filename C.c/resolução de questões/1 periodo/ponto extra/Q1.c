#include <stdio.h>

int n, m, pi = 0;

void organiza(int vetor[], int vetaux[]);

int main()
{
    scanf("%d", &n);

    int vetor[n], vetaux[n];

    for (int i = 0; i < n; i++)
    {
        pi = 0;

        do
        {
            scanf("%d", &m);
        } while (!(m >= 1 && m <= 1000));

        for (int i = 0; i < m; i++)
        {
            scanf("%d", &vetor[i]);
            fflush(stdin);
            vetaux[i] = vetor[i];
        }

        organiza(vetor, vetaux);

        printf("\n%d\n\n", pi);

        //for (int i = 0; i < m; i++)
        //{
        //    printf("%d  ", vetor[i]);
        //}
        //printf("\n\n");
    }

    return 0;
}

void organiza(int vetor[], int vetaux[])
{
    // algo de ordenação usado foi o selection

    int max, aux;

    for (int i = 0; i < m - 1; i++)
    {
        max = i;

        for (int j = i + 1; j < m; j++)
        {
            if (vetor[max] < vetor[j])
            {
                max = j;
            }
        }

        aux = vetor[i];
        vetor[i] = vetor[max];
        vetor[max] = aux;
    }

    for (int i = 0; i < m; i++)
    {
        if (vetaux[i] == vetor[i])
        {
            pi++;
        }
    }
}