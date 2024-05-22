#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define caracteres 50

void printar(char nome[][caracteres]);
void ajustar(char nome[]);
void formatacao(char nome[]);

int n, nome_maior;

int main()
{

    scanf("%d", &n);

    char nome[n][caracteres];

    for (int i = 0; i < n; i++)
    {
        fflush(stdin);
        fgets(nome[i], sizeof(nome[i]), stdin);
        fflush(stdin);

        ajustar(nome[i]);

        if (i == 0)
        {
            nome_maior = strlen(nome[i]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        formatacao(nome[i]);
    }

    printar(nome);
}

void printar(char nome[][caracteres])
{
    printf("\n\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s", nome[i]);
    }
}

void ajustar(char nome[])
{

    int t = strlen(nome);

    for (int i = 0; i < t; i++)
    {
        nome[i] = toupper(nome[i]);

        while (nome[i] == ' ' && nome[i + 1] == ' ')
        {
            for (int j = i; j < t; j++)
            {
                nome[j] = nome[j + 1];
            }
            t--;
            i--;
        }
    }

    if (t > nome_maior)
    {
        nome_maior = t;
    }
}

void formatacao(char nome[])
{
    int t;
    t = strlen(nome);

    for (int i = 0; i < nome_maior - t; i++)
    {
        for (int j = nome_maior; j >= 0; j--)
        {
            nome[j] = nome[j - 1];
        }
        nome[0] = ' ';
    }
}
