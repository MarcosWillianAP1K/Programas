#include <stdio.h>
#include <string.h>

int main()
{
    char nome[20];
    int t, mod[20], c = 0;

    printf("Informe um nome: ");
    fgets(nome, sizeof(nome), stdin);

    t = strlen(nome);

    for (int i = 0; i < t - 1; i++)
    {
        if (nome[i] == 'R')
        {
            nome[i] = 'L';
            mod[c++] = i + 1;
        }
        if (nome[i] == 'r')
        {
            nome[i] = 'l';
            mod[c++] = i + 1;
        }
    }

    printf("Cebolinha falaria: %s", nome);
    if (c != 0)
    {
        printf("Houve troca nos caracteres: ");
    }
    else
    {
        printf("Nao houve troca de caracteres");
    }

    for (int i = 0; i < c; i++)
    {
        printf("%d", mod[i]);

        if (i != c - 1)
        {
            printf(", ");
        }
    }
    printf(".\n");

    return 0;
}