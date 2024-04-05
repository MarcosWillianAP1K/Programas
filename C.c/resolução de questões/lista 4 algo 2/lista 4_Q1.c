#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Q_ALUNOS 5

struct alunos
{
    char nome[20];
    float altura, ira, peso;
};

struct alunos a[Q_ALUNOS];


void cadastro();
void printar_media();
void printar_maior();


int main()
{
    cadastro();

    printar_media();

    printar_maior();

    return 0;
}

void cadastro()
{
    for (int i = 0; i < Q_ALUNOS; i++)
    {
        printf("Cadastre o aluno\nNome: ");
        fflush(stdin);
        fgets(a[i].nome, sizeof(a[i].nome), stdin);
        fflush(stdin);

        //caso não enteda oque é isso, o fgets bota um \n no final, ai pra evitar que fique bangunçado o termial prefiro tirar ele
        int t = strlen(a[i].nome);
        a[i].nome[t - 1] = '\0';

        printf("\nPeso: ");
        scanf("%f", &a[i].peso);

        printf("\nAltura: ");
        scanf("%f", &a[i].altura);

        printf("\nIRA: ");
        scanf("%f", &a[i].ira);

        system("cls||clear");
    }
}

void printar_media()
{
    float tp = 0, ti = 0, ta = 0;

    for (int i = 0; i < Q_ALUNOS; i++)
    {
        tp += a[i].peso;
        ti += a[i].ira;
        ta += a[i].altura;
    }

    printf("Media peso: %.2f\nMedia altura: %.2f\nMedia IRA: %.2f", tp / Q_ALUNOS, ta / Q_ALUNOS, ti / Q_ALUNOS);
}

void printar_maior()
{
    float *pp, *pi, *pa;
    char *ppnome, *pinome, *panome;

    for (int i = 0; i < Q_ALUNOS; i++)
    {
        if (i == 0)
        {
            pp = &a[i].peso;
            pi = &a[i].ira;
            pa = &a[i].altura;

            ppnome = a[i].nome;
            pinome = a[i].nome;
            panome = a[i].nome;
        }

        if (*pp < a[i].peso)
        {
            pp = &a[i].peso;
            ppnome = a[i].nome;
        }
        
        if (*pi < a[i].ira)
        {
            pi = &a[i].ira;
            pinome = a[i].nome;
        }
        
        if (*pa < a[i].altura)
        {
            pa = &a[i].altura;
            panome = a[i].nome;
        }
    }

    printf("\n\nMaior peso: %s (%.2f)\nMaior altura: %s (%.2f)\nMaior IRA: %s (%.2f)\n", ppnome, *pp, panome, *pa, pinome, *pi);
}