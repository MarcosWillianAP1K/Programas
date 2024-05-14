#include "dama.h"


int Linha = 8, Coluna = 8;

void Gerar_tabuleiro(int *Tabuleiro, int *Tabuleiro_peca)
{
    for (int i = 0; i < Linha; i++)
    {
        for (int j = 0; j < Coluna; j++)
        {
            if (i % 2 == 0)
            {
                if (j % 2 == 0)
                {
                    *(Tabuleiro + i * Coluna + j) = 2;
                }
                else
                {
                    *(Tabuleiro + i * Coluna + j) = 1;
                }
            }
            else
            {
                if (j % 2 == 0)
                {
                    *(Tabuleiro + i * Coluna + j) = 1;
                }
                else
                {
                    *(Tabuleiro + i * Coluna + j) = 2;
                }
            }

            *(Tabuleiro_peca + i * Coluna + j) = 0;
        }
    }

    for (int i = 0; i < Linha; i++)
    {
        for (int j = 0; j < Coluna; j++)
        {
            if (i == 0 || i == 1)
            {
                *(Tabuleiro_peca + i * Coluna + j) = 3;
            }
            
            if (i == Linha - 1 || i == Linha - 2)
            {
                *(Tabuleiro_peca + i * Coluna + j) = 4;
            }
        }   
    }
}