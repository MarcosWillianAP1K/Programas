#include <stdio.h>
#include "dama.h"
#include "printar_dama.h"

extern int Linha, Coluna;

void Printar_matriz(int *Tabuleiro, int *Tabuleiro_peca)
{
    for (int i = 0; i < Linha; i++)
    {
        for (int j = 0; j < Coluna; j++)
        {
            printf("%d ", *(Tabuleiro + i * Coluna + j));
        }

        printf("            ");

        for (int j = 0; j < Coluna; j++)
        {
            printf("%d ", *(Tabuleiro_peca + i * Coluna + j));
        }
        printf("\n");
    }
}

void Printar_tabuleiro(int *Tabuleiro, int *Tabuleiro_peca)
{
    printf("   A B C D E F G H \n");
    printf(" __________________\n");
    for (int i = 0; i < Linha; i++)
    {
        printf("%d|", i + 1);
        for (int j = 0; j < Coluna; j++)
        {
            if (*(Tabuleiro_peca + i * Coluna + j) == 0)
            {
                printf(" #");
            }
            else
            {
                if (*(Tabuleiro_peca + i * Coluna + j) == 3)
                {
                    printf(" X");
                }

                if (*(Tabuleiro_peca + i * Coluna + j) == 4)
                {
                    printf(" O");
                }     
            }
        }
        printf("\n");
    }
}