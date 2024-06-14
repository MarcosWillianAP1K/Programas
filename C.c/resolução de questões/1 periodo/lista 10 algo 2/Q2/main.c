#include "arquivoes.h"

void verificar_se_existe_arquivo()
{
    FILE *arq = fopen(nome_arq, "rb");

    if (arq)
    {
        fread(&n, sizeof(&n), 1, arq);

        fclose(arq);
    }
    else
    {
        printf("Arquivo não existe, esta sendo criado um novo, aguarde...\n");
        system("pause");
        system("cls||clear");

        FILE *arq = fopen(nome_arq, "ab");

        n = 0;

        fwrite(&n, sizeof(&n), 1, arq);

        fclose(arq);
    }
}

int main()
{
    verificar_se_existe_arquivo();

    do
    {
        menu = -1;

        printf("1-Formatar\n2-Escrever\n3-Ler\n4-buscar\n0-Finalizar\n");

        if (scanf("%d", &menu))
        {
            switch (menu)
            {
            case 0:
                printf("\nFinalizando...\n\n");
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

        system("cls||clear");

    } while (menu != 0);

    return 0;
}