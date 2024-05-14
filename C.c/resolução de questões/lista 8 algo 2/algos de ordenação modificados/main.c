#include <stdio.h>
#include <stdlib.h>
#include "sortingm.h"

int main()
{
    int n = 100, tipo, ordemchave;

    do
    {
        printf("metodo de ordenacao\n(0-bolha, 1-selecao e 2-insercao)\ne forma de geracao\n(0-crescente, 1-aletorio e 2-decrescente)\n");
        scanf("%d%d", &tipo, &ordemchave);

        if (!(ordemchave >= 0 && ordemchave <= 2))
        {
            system("cls||clear");
            fflush(stdin);
        }

    } while (!(ordemchave >= 0 && ordemchave <= 2));

    if (tipo == 0)
    {
        printf("Bubble\n\n");
    }

    if (tipo == 1)
    {
        printf("Selection\n\n");
    }

    if (tipo == 2)
    {
        printf("Insertion\n\n");
    }

    if (ordemchave == 0)
    {
        printf("Melhor caso\n\n");
    }

    if (ordemchave == 1)
    {
        printf("Medio caso\n\n");
    }

    if (ordemchave == 2)
    {
        printf("Pior caso\n\n");
    }

    while (n <= 1000)
    {
        Alunos aluno[n];

        criar_ordernacao(aluno, &n, &tipo, &ordemchave);

        n += 100;
    }

    return 0;
}