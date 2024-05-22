#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Q 5

struct estudantes
{
    char nome[20];
    float peso, ira, altura;
};
struct estudantes e[Q];




int main()
{
    for (int i = 0; i < Q; i++)
    {
        printf("cadastre as seguintes informacoes do estudante %d\n\nNome: ", i + 1);
        fflush(stdin);
        fgets(e[i].nome, sizeof(e[i].nome), stdin);
        fflush(stdin);

        int t = strlen(e[i].nome);

        e[i].nome[t - 1] = '\0';

        printf("Altura: ");
        scanf("%f", &e[i].altura);

        printf("Peso: ");
        scanf("%f", &e[i].peso);

        printf("IRA: ");
        scanf("%f", &e[i].ira);

        system("cls||clear");
    }

    float tp, ti, ta, *maa, *mea, *map, *mep, *mai, *mei;
    char *pnp, *pni, *pna;
    

    for (int i = 0; i < Q; i++)
    {
        tp += e[i].peso;
        ti += e[i].ira;
        ta += e[i].altura;

        if (i == 0)
        {
            maa = &e[i].altura;
            mea = &e[i].altura;
            map = &e[i].peso;
            mep = &e[i].peso;
            mai = &e[i].ira;
            mei = &e[i].ira;

            pnp = e[i].nome;
            pni = e[i].nome;
            pna = e[i].nome;
        }

        if (e[i].altura > *maa)
        {
            maa = &e[i].altura;
            pna = e[i].nome;
        }

        if (e[i].altura < *mea)
        {
            mea = &e[i].altura;
        }

        if (e[i].peso > *map)
        {
            map = &e[i].peso;
            pnp = e[i].nome;
        }

        if (e[i].peso < *mep)
        {
            mep = &e[i].peso;
        }

        if (e[i].ira > *mai)
        {
            mai = &e[i].ira;
            pni = e[i].nome;
        }

        if (e[i].ira < *mei)
        {
            mei = &e[i].ira;
        }
    }
    

    printf("IRA:\nMaior: %.2f\nMenor: %.2f\nMedia: %.2f\n\n", *mai, *mei, ti / Q);
    printf("ALTURA:\nMaior: %.2f\nMenor: %.2f\nMedia: %.2f\n\n", *maa, *mea, ta / Q);
    printf("PESO:\nMaior: %.2f\nMenor: %.2f\nMedia: %.2f\n\n", *map, *mep, tp / Q);

    printf("Alunos com maior...\n");

    printf("IRA: %s : %.2f\n", pni, *mai);
    printf("ALTURA: %s : %.2f\n", pna, *maa);
    printf("PESO: %s : %.2f\n", pnp, *map);
    
    return 0;
}