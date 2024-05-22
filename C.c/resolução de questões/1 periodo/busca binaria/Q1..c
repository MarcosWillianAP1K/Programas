#include <stdio.h>
#include <stdbool.h>

int n;

void comparacao(int *vetor);
void preencher(int *vetor);

int main()
{
    scanf("%d", &n);

    int vet[n];

    preencher(vet);

    comparacao(vet);

    return 0;
}

void comparacao(int *vetor)
{
    printf("\n");

    bool teste;

    for (int i = 0; i < n; i++)
    {
        teste = false;

        for (int j = 0; j < n; j++)
        {
           if (i == *(vetor+j))
           {
            teste = true;
           }
        }

        if (teste == false)
        {
            printf("%d ", i);
        }
    }
}

void preencher(int *vetor)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &*(vetor+i));
    }
}