#include <stdio.h>
#include "dama.h"
#include "printar_dama.h"


int Tabuleiro[8][8], Tabuleiro_peca[8][8];

int main()
{
    Gerar_tabuleiro((int *)Tabuleiro, (int *)Tabuleiro_peca);

    Printar_matriz((int *)Tabuleiro,(int *)Tabuleiro_peca);

    printf("\n\n");

    Printar_tabuleiro((int *)Tabuleiro, (int *)Tabuleiro_peca);

    return 0;
}   