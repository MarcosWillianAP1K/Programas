typedef struct
{
    int chave;
    char nome[30], endereco[50], telefone[14];
} alunos;

void criar_ordernacao(alunos v[], int *n, int *tipo, int *ordem_de_chave);