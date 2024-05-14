#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "sortingm.h"

#define maior_char 50

int MOV = 0, COMP = 0;

void printar(int *n)
{
    printf("Vetor de %d:  %d MOV  %d COMP\n\n", *n, MOV, COMP);
}

void gerarDados(Alunos v[], int *n, int *ordemChave)
{
    srand(time(NULL));

    if (*ordemChave == 0)
    {
        for (int i = 0; i < *n; i++)
        {
            v[i].chave = i;
            strcpy(v[i].endereco, "Rua pimtombeira");
            strcpy(v[i].nome, "Yudi");
            strcpy(v[i].telefone, "4002-8922");
        }

        
    }

    if (*ordemChave == 1)
    {
        for (int i = 0; i < *n; i++)
        {
            v[i].chave = rand() % *n + 10;
            strcpy(v[i].endereco, "Rua pimtombeira");
            strcpy(v[i].nome, "Yudi");
            strcpy(v[i].telefone, "4002-8922");
        }
        
    }

    if (*ordemChave == 2)
    {
        for (int i = 0; i < *n; i++)
        {
            v[i].chave = *n - i - 1;
            strcpy(v[i].endereco, "Rua pimtombeira");
            strcpy(v[i].nome, "Yudi");
            strcpy(v[i].telefone, "4002-8922");
        }
        
    }
}

void bubble(Alunos v[], int *n)
{
    int intaux;
    char charaux[maior_char];

    for (int i = 0; i < *n - 1; i++)
    {
        for (int j = 0; j < *n - i - 1; j++)
        {
            if (v[j].chave > v[j + 1].chave)
            {
                intaux = v[j].chave;
                v[j].chave = v[j + 1].chave;
                v[j + 1].chave = intaux;

                strcpy(charaux, v[j].endereco);
                strcpy(v[j].endereco, v[j + 1].endereco);
                strcpy(v[j + 1].endereco, charaux);

                strcpy(charaux, v[j].nome);
                strcpy(v[j].nome, v[j + 1].nome);
                strcpy(v[j + 1].nome, charaux);

                strcpy(charaux, v[j].telefone);
                strcpy(v[j].telefone, v[j + 1].telefone);
                strcpy(v[j + 1].telefone, charaux);

                MOV++;
            }
            COMP++;
        }
    }
}

void selection(Alunos v[], int *n)
{
    int intaux, min;
    char charaux[maior_char];

    for (int i = 0; i < *n - 1; i++)
    {
        min = i;

        for (int j = i + 1; j < *n; j++)
        {
            if (v[j].chave < v[min].chave)
            {
                min = j;
            }
            COMP++;
        }
        MOV++;

        intaux = v[i].chave;
        v[i].chave = v[min].chave;
        v[min].chave = intaux;

        strcpy(charaux, v[i].endereco);
        strcpy(v[i].endereco, v[min].endereco);
        strcpy(v[min].endereco, charaux);

        strcpy(charaux, v[i].nome);
        strcpy(v[i].nome, v[min].nome);
        strcpy(v[min].nome, charaux);

        strcpy(charaux, v[i].telefone);
        strcpy(v[i].telefone, v[min].telefone);
        strcpy(v[min].telefone, charaux);
    }
}

void insertion(Alunos v[], int *n)
{
    int intaux, j;
    char charaux1[maior_char], charaux2[maior_char], charaux3[maior_char];

    for (int i = 1; i < *n; i++)
    {
        intaux = v[i].chave;
        j = i - 1;

        strcpy(charaux1, v[i].endereco);
        strcpy(charaux2, v[i].nome);
        strcpy(charaux3, v[i].telefone);

        while ((j >= 0) && (intaux < v[j].chave))
        {
            v[j + 1].chave = v[j].chave;
            strcpy(v[j + 1].endereco, v[j].endereco);
            strcpy(v[j + 1].nome, v[j].nome);
            strcpy(v[j + 1].telefone, v[j].telefone);
            j--;
            MOV++;
        }
        COMP++;

        v[j + 1].chave = intaux;
        strcpy(v[j + 1].endereco, charaux1);
        strcpy(v[j + 1].nome, charaux2);
        strcpy(v[j + 1].telefone, charaux3);
    }
}

void ordernar(Alunos v[], int *tipo, int *n)
{
    if (*tipo == 0)
    {
        bubble(v, n);
    }

    if (*tipo == 1)
    {
        selection(v, n);
    }

    if (*tipo == 2)
    {
        
        insertion(v, n);
    }
}

void criar_ordernacao(Alunos v[], int *n, int *tipo, int *ordem_de_chave)
{
    MOV = 0;
    COMP = 0;

    gerarDados(v, n, ordem_de_chave);

    ordernar(v, tipo, n);

    printar(n);
}