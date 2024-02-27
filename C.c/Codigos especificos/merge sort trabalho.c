#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// tamnho do vetor
#define max 200000

// gerar numeros aleatorios em cada posição do vetor
void rand_vet(int vetor[])
{
    srand(time(NULL));

    for (int i = 0; i < max; i++)
    {
        vetor[i] = rand() % max;
    }
}

// Função para Intercarlação dos vetores
void merge(int *vetor[], int es, int me, int di)
{
    int vetor_aux[max];
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

// Função para divisão e conquista
void merge_sort(int vetor[], int es, int di)
{
    int me = (es + di) / 2;

    if (es < di)
    {
        merge_sort(vetor, es, me);

        merge_sort(vetor, me + 1, di);

        merge(vetor, es, me, di);
    }
}

// inicio
int main()
{
    // vetor
    int vetor[max];
    float m;
    double timer = 0, timerp = 0;

    // rodar 30 vezes
    for (int a = 0; a < 30; a++)
    {
        // chama função para randomizar o vetor
        rand_vet(vetor);

        // inicio do timer
        clock_t begin = clock();

        // função do merge sort
        merge_sort(vetor, 0, max - 1);

        // fim do timer
        clock_t end = clock();

        // soma e tranformação em segundos o timer
        timer += (double)(end - begin) / CLOCKS_PER_SEC;
        timerp = (double)(end - begin) / CLOCKS_PER_SEC;

        // exibir tempo por rodada
        printf("rodada %d : %f seg\n", a + 1, timerp);
    }
    // media de tempo
    m = timer / 30;

    // exibir tempo total e media
    printf("\ntempo total %f seg\nmedia %f seg", timer, m);

    return 0;
}