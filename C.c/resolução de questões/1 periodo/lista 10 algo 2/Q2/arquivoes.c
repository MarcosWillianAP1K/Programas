#include "arquivoes.h"

void blindagem_scanf()
{
    fflush(stdin);
    printf("\nDigitacao invalida\n");
    system("pause");
    system("cls||clear");
}

void tirar_n(char string[])
{
    int tamanho = strlen(string);

    string[tamanho - 1] = '\0';
}

bool verificar_chave(int *chave_aux)
{
    FILE *arq = fopen(nome_arq, "rb");

    if (arq)
    {
        fread(&n, sizeof(n), 1, arq);

        while (!feof(arq))
        {
            fread(&cadastro, sizeof(cadastro), 1, arq);

            if (cadastro.chave == *chave_aux)
            {
                fclose(arq);
                return true;
            }
        }
        fclose(arq);

        return false;
    }
    else
    {
        printf("\nFalha ao abrir arquivo\n\n");
        system("pause");
        return true;
    }
}

bool verificar_telefone()
{
    if (cadastro.telefone[0] == '\0')
    {
        printf("\nCampo vazio\n");
        return true;
    }

    for (int i = 0; cadastro.telefone[i] != '\0'; i++)
    {
        if (!isdigit((unsigned char)cadastro.telefone[i]) && cadastro.telefone[i] != ' ')
        {
            printf("\nDigitacao invalida\n");
            return true;
        }
    }

    char aux[16];
    int a = 1, tam = strlen(cadastro.telefone);

    aux[0] = '(';

    for (int i = 0; i < tam; i++)
    {
        if (cadastro.telefone[i] != ' ')
        {
            aux[a] = cadastro.telefone[i];
            a++;

            if (a == 3)
            {
                aux[a++] = ')';
                aux[a++] = ' ';
            }

            if (a == 10)
            {
                aux[a++] = '-';
            }
        }
    }
    aux[a] = '\0';

    strcpy(cadastro.telefone, aux);

    return false;
}

void formatar_arquivo()
{
    remove(nome_arq);

    FILE *arq = fopen(nome_arq, "ab");

    n = 0;

    fwrite(&n, sizeof(&n), 1, arq);

    fclose(arq);
}

void ler_arquivo()
{
    FILE *arq = fopen(nome_arq, "rb");

    if (arq)
    {
        fread(&n, sizeof(&n), 1, arq);

        if (n != 0)
        {
            printf("\n");
            for (int i = 0; i < n; i++)
            {
                fread(&cadastro, sizeof(cadastro), 1, arq);

                printf("Chave: %d\nNome: %s\nEndereco: %s\nTelefone: %s\n\n", cadastro.chave, cadastro.nome, cadastro.endereco, cadastro.telefone);
            }

            system("pause");
        }
        else
        {
            printf("\nArquivo vazio\n");
            system("pause");
        }

        fclose(arq);
    }
    else
    {
        printf("\nError ao abrir o arquivo\n\n");
        system("pause");
    }
}

void escrever_arquivo()
{
    system("cls||clear");

    bool teste = true;
    int chave_aux;

    do
    {

        printf("Digite uma chave: ");

        if (scanf("%d", &chave_aux))
        {
            fflush(stdin);

            teste = verificar_chave(&chave_aux);

            if (teste == true)
            {
                printf("\nChave ja existe, digite novamente\n\n");
                system("pause");
                system("cls||clear");
            }
        }
        else
        {
            blindagem_scanf();
        }

    } while (teste);

    cadastro.chave = chave_aux;

    teste = true;

    do
    {
        printf("\nDigite o nome(ate 30 caracteres): ");

        fgets(cadastro.nome, sizeof(cadastro.nome), stdin);
        fflush(stdin);

        tirar_n(cadastro.nome);

        teste = false;

    } while (teste);

    teste = true;

    do
    {
        printf("\nDigite o endereco(ate 50 caracteres): ");

        fgets(cadastro.endereco, sizeof(cadastro.endereco), stdin);
        fflush(stdin);

        tirar_n(cadastro.endereco);

        teste = false;

    } while (teste);

    teste = true;

    do
    {
        printf("\nDigite o telefone(com ddd): ");

        fgets(cadastro.telefone, sizeof(cadastro.telefone), stdin);
        fflush(stdin);

        tirar_n(cadastro.telefone);

        teste = verificar_telefone();

    } while (teste);

    n++;

    FILE *arq = fopen(nome_arq, "rb+");

    fseek(arq, 0, SEEK_END);

    fwrite(&cadastro, sizeof(cadastro), 1, arq);

    fseek(arq, 0, SEEK_SET);

    fwrite(&n, sizeof(int), 1, arq);

    fclose(arq);
}

void buscar_arquivo()
{
    bool teste;
    int chave_digitada;

    if (n != 0)
    {
        do
        {
            system("cls||clear");

            printf("Digite uma chave\n");
            if (scanf("%d", &chave_digitada))
            {
                teste = false;

                FILE *arq = fopen(nome_arq, "rb");

                fread(&n, sizeof(n), 1, arq);

                while (!feof(arq) && teste == false)
                {
                    fread(&cadastro, sizeof(cadastro), 1, arq);

                    if (cadastro.chave == chave_digitada)
                    {
                        teste = true;
                    }
                }

                fclose(arq);

                if (teste == true)
                {
                    printf("\n\nChave: %d\nNome: %s\nEndereco: %s\nTelefone: %s\n\n", cadastro.chave, cadastro.nome, cadastro.endereco, cadastro.telefone);
                    system("pause");
                }
                else
                {
                    printf("\n\nChave nao encontrada\n\n");
                    system("pause");
                }

                teste = false;
            }
            else
            {
                blindagem_scanf();
                teste = true;
            }

        } while (teste);
    }
    else
    {
        printf("\nArquivo vazio\n");
        system("pause");
    }
}
