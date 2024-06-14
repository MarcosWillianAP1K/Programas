#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <stdbool.h>
#include <ctype.h>

#define nome_arq "dados.bin"

typedef struct
{
    int chave;
    char nome[30], endereco[50], telefone[16];
} Alunos;

Alunos cadastro;

int menu, n;

void blindagem_scanf();

void formatar_arquivo();

void ler_arquivo();

void escrever_arquivo();
