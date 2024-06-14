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
                aux[a] = ' ';
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

    do
    {

        printf("Digite uma chave: ");

        if (scanf("%d", &cadastro.chave))
        {
            teste = false;
        }
        else
        {
            blindagem_scanf();
        }

        fflush(stdin);

    } while (teste);

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
