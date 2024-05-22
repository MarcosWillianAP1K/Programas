#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"

int main()
{
    int n, tipo, ordemchave, c = 0;

    printf("\n\n");
    scanf("%d %d", &n, &c);
    Alunos aluno[n];
    while (c > 0)
    {
        printf("Digite respectivamente o tamanho\nmetodo de ordenacao\n(0-bolha, 1-selecao e 2-insercao)\ne forma de geracao\n(0-crescente, 1-aletorio e 2-decrescente)\n");
        scanf("%d %d", &tipo, &ordemchave);

        criar_ordernacao(aluno, &n, &tipo, &ordemchave);
        c--;
    }

    return 0;
}