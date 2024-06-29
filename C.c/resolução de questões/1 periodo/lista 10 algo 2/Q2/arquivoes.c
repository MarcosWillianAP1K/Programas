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

    cadastro.chave = -1;

    FILE *arq = fopen(nome_arq, "ab");

    for (int i = 0; i < 1000; i++)
    {
        fwrite(&cadastro, sizeof(cadastro), 1, arq);
    }

    fclose(arq);
}

void ler_arquivo()
{
    bool teste = false;
    FILE *arq = fopen(nome_arq, "rb");

    if (arq)
    {
        printf("\n\n");
        while (!feof(arq))
        {
            fread(&cadastro, sizeof(cadastro), 1, arq);

            if (cadastro.chave > 0 && cadastro.chave <= 1000)
            {
                teste = true;
                printf("Chave: %d\nNome: %s\nEndereco: %s\nTelefone: %s\n\n", cadastro.chave, cadastro.nome, cadastro.endereco, cadastro.telefone);
            }
        }

        if (teste = false)
        {
            printf("arquivo vazio\n\n");
        }

        system("pause");

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

    FILE *arq = fopen(nome_arq, "rb+");

    fseek(arq, sizeof(cadastro) * chave_aux, SEEK_CUR);

    fwrite(&cadastro, sizeof(cadastro), 1, arq);

    fclose(arq);
}

void buscar_arquivo()
{
    bool teste;
    int chave_digitada;

    do
    {
        system("cls||clear");

        printf("Digite uma chave\n");
        if (scanf("%d", &chave_digitada))
        {
            if (chave_digitada > 0 && chave_digitada <= 1000)
            {

                teste = false;

                FILE *arq = fopen(nome_arq, "rb");

                fseek(arq, sizeof(cadastro) * chave_digitada, SEEK_CUR);

                fread(&cadastro, sizeof(cadastro), 1, arq);

                fclose(arq);

                if (cadastro.chave == chave_digitada)
                {
                    teste = true;
                }

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
        }
        else
        {
            blindagem_scanf();
            teste = true;
        }

    } while (teste);
}
