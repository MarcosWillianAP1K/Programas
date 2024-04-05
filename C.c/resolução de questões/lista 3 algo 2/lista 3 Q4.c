#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int ponto, soma, menu;

    srand(time(NULL));

    do
    {
        ponto = 0;

        system("cls||clear");
        printf("Jogue os dados(Aperte enter)\n");
        system("pause");

        soma = ((rand() % 6) + 1) + ((rand() % 6) + 1);

        printf("\nSoma: %d", soma);

        if (soma == 7 || soma == 11)
        {
            printf("\nParabens, voce ganhou\n\n");
        }
        else if (soma == 2 || soma == 3 || soma == 12)
        {
            printf("\nQue pena, perdeu\n\n");
        }
        else
        {
            ponto = soma;
            soma = 0;

            while (soma != ponto && soma != 7)
            {
                system("cls||clear");
                printf("Ponto: %d\n\nJogue os dados(Aperte enter)\n", ponto);
                system("pause");

                soma = ((rand() % 6) + 1) + ((rand() % 6) + 1);

                printf("\n\nSoma: %d\n", soma);

                if (soma == ponto)
                {
                    printf("\nParabens, voce ganhou\n\n");
                }

                if (soma == 7)
                {
                    printf("\nQue pena, perdeu\n\n");
                }
                system("pause");
            }
        }

        printf("\nDeseja jogar novamente?\n1-Sim\n2-Nao\n");
        scanf("%d", &menu);

    } while (menu != 2);

    return 0;
}