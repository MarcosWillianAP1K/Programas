#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"

typedef struct
{
    int chave;
    char nome[30], endereco[50], telefone[14];
} alunos;

int main()
{
    int n, tipo, ordemchave;

    do
    {
        printf("Digite respectivamente o tamanho\nmetodo de ordenacao\n(0-bolha, 1-selecao e 2-insercao)\ne forma de geracao\n(0-crescente, 1-aletorio e 2-decrescente)\n");
        scanf("%d%d%d", &n, &tipo, &ordemchave);

        if (!(n >= 0 && n <= 2) || !(ordemchave >= 0 && ordemchave <= 2))
        {
            system("cls||clear");
            fflush(stdin);
        }
        
    } while ((n >= 0 && n <= 2) && (ordemchave >= 0 && ordemchave <= 2));

    alunos v[n];

    criar_ordernacao(v, &n, &tipo, &ordemchave);

    return 0;
}