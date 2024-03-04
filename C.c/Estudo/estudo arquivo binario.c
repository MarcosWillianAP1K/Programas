#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10

typedef struct
{
    char nome[50], sexo;
    int idade;
} cadastro;

cadastro lista[TAM];

int quant = 0;

void ler_arquivo()
{
    FILE *arq = fopen("cadastrp2.txt", "rb");

    if (arq)
    {
        fscanf(arq, "%d\n", &quant);
        
        2
        fread(lista, sizeof(cadastro), quant, arq);

        fclose(arq);
    }
    else
    {
        printf("\ndeu ruim paizao\n");
        system("pause");
    }
}

void salvar_arquivo()
{
    FILE *arq = fopen("cadastrp2.txt", "wb");

    if (arq)
    {
        fprintf(arq, "%d\n", quant);
       
        fwrite(lista, sizeof(cadastro), quant, arq);

        fclose(arq);
    }
    else
    {
        printf("\ndeu ruim paizao\n");
        system("pause");
    }
}

void excluir() {}

void editar() {}

void Printar()
{
    for (int i = 0; i < quant; i++)
    {
        printf("Nome: %sIdade: %d\nSexo: %c\n\n", lista[i].nome, lista[i].idade, lista[i].sexo);
    }
    system("pause");
}

void Cadastrar()
{
    printf("Nome: \n");
    fflush(stdin);
    fgets(lista[quant].nome, sizeof(lista[quant].nome), stdin);
    fflush(stdin);

    printf("Digite a idade e sexo (M ou F)\n");
    scanf("%d %c", &lista[quant].idade, &lista[quant].sexo);
}

void menu()
{
    int menu;

    do
    {
        system("cls||clear");
        printf("======MENU=====\n\n");
        printf("1-Cadastrar Pessoa\n2-Mostra pessoas cadastradas\n3-Editar cadastro\n4-Excluir cadastro\n5-Sair\n\n%d Pessoas cadastradas\n", quant);
        scanf("%d", &menu);
        system("cls||clear");

        switch (menu)
        {
        case 1:
            if (quant < TAM)
            {
                Cadastrar();
                quant++;
                salvar_arquivo();
            }
            else
            {
                printf("\nCapaciade maxima atingida\n");
                system("pause");
            }
            break;

        case 2:
            Printar();
            break;

        case 3:
            editar();
            break;

        case 4:
            excluir();
            break;

        case 5:
            break;

        default:
            printf("\nOpcao errada\n");
            system("pause");
            break;
        }
    } while (menu != 5);
}

int main()
{
    ler_arquivo();

    menu();

    return 0;
}