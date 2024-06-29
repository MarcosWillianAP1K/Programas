#include "arquivoes.h"

void verificar_se_existe_arquivo()
{
    FILE *arq = fopen(nome_arq, "rb");

    if (arq)
    {

        fclose(arq);
    }
    else
    {
        timer = 0;

        while (timer != 6)
        {

            printf("\rArquivo nao existe, esta sendo criado um novo, aguarde      ");
            fflush(stdout);
            printf("\rArquivo nao existe, esta sendo criado um novo, aguarde");
            fflush(stdout);

            for (int i = 0; i < 3; i++)
            {
                printf(" .");
                fflush(stdout);
                Sleep(250);
            }
            timer++;
        }

        formatar_arquivo();
    }
}

int main()
{
    system("cls||clear");
    verificar_se_existe_arquivo();

    do
    {
        system("cls||clear");
        printf("1-Formatar\n2-Escrever\n3-Ler\n4-buscar\n0-Finalizar\n");

        if (scanf("%d", &menu))
        {
            switch (menu)
            {
            case 0:
                printf("\n");

                timer = 0;

                while (timer != 4)
                {

                    printf("\rFinalizando      ");
                    fflush(stdout);
                    printf("\rFinalizando");
                    fflush(stdout);

                    for (int i = 0; i < 3; i++)
                    {
                        printf(" .");
                        fflush(stdout);
                        Sleep(250);
                    }
                    timer++;
                }
                break;

            case 1:
                formatar_arquivo();
                break;

            case 2:
                escrever_arquivo();
                break;

            case 3:
                ler_arquivo();
                break;

            case 4:
                buscar_arquivo();
                break;

            default:
                printf("\nOpcao invalida\n");
                system("pause");
                break;
            }
        }
        else
        {
            blindagem_scanf();
        }

    } while (menu != 0);

    return 0;
}