#include "arquivoes.h"
#include <stdlib.h>
#include <string.h>

void printar_TAD(Alunos TAD[], int *n)
{
    printf("\n");
    for (int i = 0; i < *n; i++)
    {
        printf("%d\n", TAD[i].chave);
        printf("%s", TAD[i].nome);
        printf("%s", TAD[i].endereco);
        printf("%s\n", TAD[i].telefone);
    }
}

void merge_int(int vetor[], int es, int me, int di, int *n)
{
    int vetor_aux[*n];
    int i = es, j = me + 1, k = 0;

    while (i <= me && j <= di)
    {
        if (vetor[i] <= vetor[j])
        {
            vetor_aux[k++] = vetor[i++];
        }
        else
        {
            vetor_aux[k++] = vetor[j++];
        }
    }

    while (i <= me)
    {
        vetor_aux[k++] = vetor[i++];
    }
    while (j <= di)
    {
        vetor_aux[k++] = vetor[j++];
    }

    for (i = es, k = 0; i <= di; i++, k++)
    {
        vetor[i] = vetor_aux[k];
    }
}

void merge_sort_int(int vetor[], int es, int di, int *n)
{
    int me = (es + di) / 2;

    if (es < di)
    {
        merge_sort_int(vetor, es, me, n);

        merge_sort_int(vetor, me + 1, di, n);

        merge_int(vetor, es, me, di, n);
    }
}

void tirar_chaves_repetidas(int vet[], int *n)
{
    for (int i = 0; i < *n - 1; i++)
    {
        if (vet[i] > -1)
        {
            for (int j = i + 1; j < *n; j++)
            {
                if (vet[i] == vet[j])
                {
                    vet[j] = -1;
                }
            }
        }
    }
}

void organizar_chave(char *nome_arq, Alunos TAD[])
{
    FILE *arq = fopen(nome_arq, "r");

    int n = 0;
    char buffer[50];

    if (arq)
    {
        fscanf(arq, "%d\n", &n);

        int vetaux[n];

        for (size_t i = 0; i < n; i++)
        {

            fscanf(arq, "%d\n", &vetaux[i]);
            fgets(buffer, sizeof(buffer), arq);
            fgets(buffer, sizeof(buffer), arq);
            fgets(buffer, sizeof(buffer), arq);
        }
        fclose(arq);

        merge_sort_int(vetaux, 0, n - 1, &n);

        tirar_chaves_repetidas(vetaux, &n);

        int a = 0;

        for (size_t i = 0; i < n; i++)
        {
            if (vetaux[i] > -1)
            {
                FILE *arq = fopen(nome_arq, "r");

                if (arq)
                {
                    fscanf(arq, "%d\n", &n);

                    while (!feof(arq))
                    {
                        fscanf(arq, "%d\n", &TAD[a].chave);

                        if (TAD[a].chave == vetaux[i])
                        {
                            fgets(TAD[a].nome, sizeof(TAD[a].nome), arq);
                            fgets(TAD[a].endereco, sizeof(TAD[a].endereco), arq);
                            fgets(TAD[a].telefone, sizeof(TAD[a].telefone), arq);
                            a++;
                        }
                        else
                        {
                            fgets(buffer, sizeof(buffer), arq);
                            fgets(buffer, sizeof(buffer), arq);
                            fgets(buffer, sizeof(buffer), arq);
                        }
                    }
                    fclose(arq);
                }
                else
                {
                    printf("\ndeu ruim para abrir o arquivo\n");
                }
            }
        }
    }
    else
    {
        printf("\ndeu ruim para abrir o arquivo\n");
    }

    printar_TAD(TAD, &n);
}

void organizar_string(char *nome_arq, Alunos TAD[])
{
    int aux, n, a = 0;
    char buffer[50];

    for (int i = 65; i < 123; i++)
    {
        FILE *arq = fopen(nome_arq, "r");

        if (arq)
        {
            fscanf(arq, "%d\n", &n);

            while (!feof(arq))
            {
                fscanf(arq, "%d\n", &aux);

                TAD[i].nome[0] = fgetc(arq);

                if (TAD[i].nome[0] == i)
                {
                    TAD[a].chave = aux;
                    fgets(TAD[i].nome, sizeof(TAD[i].nome), arq);
                    fgets(TAD[a].endereco, sizeof(TAD[a].endereco), arq);
                    fgets(TAD[a].telefone, sizeof(TAD[a].telefone), arq);
                    a++;
                }
                else
                {
                    fgets(buffer, sizeof(buffer), arq);
                    fgets(buffer, sizeof(buffer), arq);
                    fgets(buffer, sizeof(buffer), arq);
                }
            }
            fclose(arq);
        }
        else
        {
            printf("\nErro ao abrir o arquivo\n");
        }
    }

    printar_TAD(TAD, &n);
}

void salvarDados(FILE *arq, int n, Alunos TAD[])
{
    fprintf(arq, "%d\n", n);

    for (int i = 0; i < n; i++)
    {
        fprintf(arq, "%d\n", TAD[i].chave);
        fprintf(arq, "%s", TAD[i].nome);
        fprintf(arq, "%s", TAD[i].endereco);
        fprintf(arq, "%s", TAD[i].telefone);
    }
}

void restaurarDados(char *nome_arq, Alunos TAD[])
{
    int menu;

    do
    {
        printf("\n1-chave\n2- nome\n");

        if (scanf("%d", &menu) || (menu != 1 && menu != 2))
        {
            if (menu == 1)
            {
                organizar_chave(nome_arq, TAD);
            }

            if (menu == 2)
            {
                organizar_string(nome_arq, TAD);
            }
        }
        else
        {
            printf("opcao errada\n");
            fflush(stdin);
            system("pause");
            system("cls||clear");
        }
    } while (menu != 1 && menu != 2);
}