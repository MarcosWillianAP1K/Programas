#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "arquivoes.h"

#define MAX 10
#define loop 1
#define nome_arq "alunos.txt"

Alunos TAD[MAX];

void gerarDados();

int main()
{
    gerarDados();

    int menu;

    do
    {

        printf("1- Salvar\n2-Restaurar\n3-Sair\n");

        if (scanf("%d", &menu))
        {
            if (menu >= 1 && menu <= 3)
            {
                if (menu == 1)
                {
                    FILE *arq = fopen(nome_arq, "w");

                    if (arq)
                    {
                        salvarDados(arq, MAX, TAD);
                        fclose(arq);
                    }
                    else
                    {
                        printf("\nproblema ao abrir o arquivo\n");
                        system("pause");
                    }

                }

                if (menu == 2)
                {
                    restaurarDados(nome_arq, TAD);
                }
            }
            else
            {
                printf("opcao errada\n");
                fflush(stdin);
                system("pause");
                system("cls||clear");
            }
        }
        else
        {
            printf("opcao errada\n");
            fflush(stdin);
            system("pause");
            system("cls||clear");
        }
    } while (menu != 3);

    return 0;
}

void gerarDados()
{
    srand(time(NULL));

    for (int i = 0; i < MAX; i++)
    {
        TAD[i].chave = rand() % 100;
        strcpy(TAD[i].endereco, "Rua pimtombeira\n");
        strcpy(TAD[i].nome, "Yudi\n");
        strcpy(TAD[i].telefone, "4002-8922\n");
    }
}