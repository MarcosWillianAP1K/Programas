#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define nome_arq "Cadastros.bin"
#define max 1000

int menu;
FILE *arq;

typedef struct
{
    int codigo;
    char nome[30];
} registro;

registro cadastro;

void tirar_n(char string[])
{
    int tam = strlen(string);
    string[tam - 1] = '\0';
}

void preparar_arquivo()
{
    arq = fopen(nome_arq, "rb");

    if (arq)
    {
        fclose(arq);
    }
    else
    {
        arq = fopen(nome_arq, "wb");

        cadastro.codigo = 0;
        memset(cadastro.nome, '\0', strlen(cadastro.nome) + 1);

        for (int i = 0; i < max; i++)
        {
            fwrite(&cadastro, sizeof(cadastro), 1, arq);
        }

        fclose(arq);
    }
}

void jogar_no_arquivo()
{
    registro aux;

    arq = fopen(nome_arq, "rb+");

    while (fread(&aux, sizeof(aux), 1, arq))
    {
        if (aux.codigo == 0)
        {
            fseek(arq, sizeof(cadastro) * -1, SEEK_CUR);

            fwrite(&cadastro, sizeof(cadastro), 1, arq);

            fclose(arq);
            return;
        }
    }

    printf("\nArquivo cheio\n\n");

    system("pause");

    fclose(arq);
}

bool verificar_codigo(int *codigo)
{
    arq = fopen(nome_arq, "rb");

    while (fread(&cadastro, sizeof(cadastro), 1, arq))
    {
        if (cadastro.codigo == *codigo)
        {
            fclose(arq);

            return true;
        }
    }
    fclose(arq);

    return false;
}

void cadastrar()
{
    int codigo_aux;

    printf("\ncodigo: ");
    scanf("%d", &codigo_aux);

    if (verificar_codigo(&codigo_aux))
    {
        printf("\nCodigo ja cadastrado\n\n");

        system("pause");
        return;
    }

    cadastro.codigo = codigo_aux;

    printf("\nNome: ");
    fflush(stdin);
    fgets(cadastro.nome, sizeof(cadastro.nome), stdin);
    fflush(stdin);
    tirar_n(cadastro.nome);

    jogar_no_arquivo();

    printf("\n\nCadastrado com sucesso\n\n");

    system("pause");
}

void visualizar()
{
    bool teste = false;

    arq = fopen(nome_arq, "rb");

    printf("\n\n");

    while (fread(&cadastro, sizeof(cadastro), 1, arq))
    {
        if (cadastro.codigo != 0)
        {
            teste = true;
            printf("Codigo: %d\nnome: %s\n\n", cadastro.codigo, cadastro.nome);
        }
    }

    if (teste == false)
    {
        printf("arquivo vazio\n\n");
    }

    system("pause");

    fclose(arq);
}

void remover()
{
    int codigo_aux;

    printf("\n\nDigite o codigo: ");
    scanf("%d", &codigo_aux);

    arq = fopen(nome_arq, "rb+");

    while (fread(&cadastro, sizeof(cadastro), 1, arq))
    {
        if (codigo_aux == cadastro.codigo)
        {
            printf("\nRegistro removido\n");

            fseek(arq, sizeof(cadastro) * -1, SEEK_CUR);

            cadastro.codigo = 0;

            fwrite(&cadastro, sizeof(cadastro), 1, arq);

            fclose(arq);
            system("pause");

            return;
        }
    }
    fclose(arq);

    printf("\nArquivo nao encontrado\n\n");

    system("pause");
}

int main()
{
    preparar_arquivo();

    do
    {
        system("cls||clear");

        printf("1-Cadastrar\n2-Visualizar\n3-Remover registro\n4-Finalizar\nInforme o modulo: ");

        if (scanf("%d", &menu))
        {
            switch (menu)
            {
            case 1:
                cadastrar();
                break;

            case 2:
                visualizar();
                break;

            case 3:
                remover();
                break;

            case 4:

                break;

            default:
                printf("\n\nDigitacao errada\n\n");
                system("pause");
                break;
            }
        }
        else
        {
            fflush(stdin);
            printf("\n\nDigitacao errada\n\n");
            system("pause");
        }

    } while (menu != 4);
}