#include <stdio.h>
#include <stdlib.h>

// QP = quantidade de participantes
#define QP 16
// total de rodadas
#define roda 3

int main()
{
    char equipes[QP] = "ABCDEFGHIJKLMNOP", podio[4];
    int jogos = QP, pontuacao1, pontuacao2, c;

    for (int i = 0; i < roda; i++)
    {
        c = 0;

        for (int j = 0; j < jogos; j += 2)
        {
            if (i == roda - 1)
            {
                printf("FINAIS\n\n");
            }
            else
            {
                printf("RODADA %d\n\n", i + 1);
            }
        
            printf("Entre jogador %c e %c\n\nDigite a pontuacao de cada um respectivamente\n", equipes[j], equipes[j + 1]);
            scanf("%d%d", &pontuacao1, &pontuacao2);

            if (pontuacao1 > pontuacao2)
            {
                if (i == roda - 2 && j != jogos - 2)
                {
                    podio[2] = equipes[j + 1];
                }
                if (i == roda - 2 && j == jogos - 2)
                {
                    podio[3] = equipes[j + 1];
                }
                if (i == roda - 1)
                {
                    podio[0] = equipes[j];
                    podio[1] = equipes[j+1];
                }


                equipes[c] = equipes[j];
                printf("\nVENCEDOR: %c\n\n", equipes[c]);
                c++;
                system("pause");
            }
            if (pontuacao1 < pontuacao2)
            {
                if (i == roda - 2 && j != jogos - 2)
                {
                    podio[2] = equipes[j];
                }
                if (i == roda - 2 && j == jogos - 2)
                {
                    podio[3] = equipes[j];
                }
                if (i == roda - 1)
                {
                    podio[0] = equipes[j+1];
                    podio[1] = equipes[j];
                }

                equipes[c] = equipes[j + 1];
                printf("\nVENCEDOR: %c\n\n", equipes[c]);
                c++;
                system("pause");
            }
            if (pontuacao1 == pontuacao2)
            {
                printf("\nEMPATE\n\n");
                j -= 2;
                system("pause");
            }
            system("cls||clear");
        }

        jogos /= 2;
    }


    c = 0;

    while (c == 0 && QP > 3)
    {
        printf("DISPUTA PELO TERCEIRO LUGAR\n\n");
        printf("Entre jogador %c e %c\n\nDigite a pontuacao de cada um respectivamente\n", podio[2], podio[3]);
        scanf("%d%d", &pontuacao1, &pontuacao2);

        if (pontuacao1 > pontuacao2)
        {
            c++;
            printf("\nVENCEDOR: %c\n\n", podio[2]);
            system("pause");
        }
        if (pontuacao1 < pontuacao2)
        {
            podio[2] = podio[3];
            c++;
            printf("\nVENCEDOR: %c\n\n", podio[2]);
            system("pause");
        }
        if (pontuacao1 == pontuacao2)
        {
            printf("\nEMPATE\n\n");
            system("pause");
        }
        system("cls||clear");
    }

    printf("PRIMEIRO LUGAR: %c\nSEGUNDO: %c\nTERCEIRO: %c\n\n", podio[0], podio[1], podio[2]);

    return 0;
}