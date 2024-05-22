typedef struct
{
    int chave;
    char nome[30], endereco[50], telefone[14];
} Alunos;

void criar_ordernacao(Alunos v[], int *n, int *tipo, int *ordem_de_chave);