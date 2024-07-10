#include <stdio.h>

int N, auxx;

void selecao_par(int vet[], int aux[], int posicao)
{
    int min;

    for (int i = 0; i < N; i++)
    {
        if (vet[i] % 2 == 0)
        {
            min = i;

            for (int j = i + 1; j < N; j++)
            {
                if (vet[min] > vet[j] && (vet[j] % 2 == 0))
                {
                    min = j;
                }
            }

            aux[posicao] = vet[min];
            posicao += 1;

            auxx = vet[i];
            vet[i] = vet[min];
            vet[min] = auxx;
        }
    }

    
}

void selecao_impar(int vet[], int aux[], int posicao)
{
    int min;

    for (int i = 0; i < N; i++)
    {
        if (vet[i] % 2 != 0)
        {
            min = i;

            for (int j = i + 1; j < N; j++)
            {
                if (vet[min] > vet[j] && (vet[j] % 2 != 0))
                {
                    min = j;
                }
            }

            aux[N - posicao - 1] = vet[min];
            posicao += 1;

            auxx = vet[i];
            vet[i] = vet[min];
            vet[min] = auxx;
        }
    }

}

int main()
{
    scanf("%d", &N);

    int vet[N], aux[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &vet[i]);
    }
    fflush(stdin);

    selecao_par(vet, aux, 0);
    selecao_impar(vet, aux, 0);

    printf("\n\n");

    for(int i = 0; i < N; i++)
    {
        printf("\n%d", aux[i]);
    }

    return 0;
}