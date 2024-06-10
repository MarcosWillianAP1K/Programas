#include <stdio.h>

typedef struct
{
    int chave;
    char nome[30], endereco[50], telefone[14];
} Alunos;


void salvarDados(FILE *arq, int n, Alunos TAD[]);

void restaurarDados(char *nome_arq, Alunos TAD[]);