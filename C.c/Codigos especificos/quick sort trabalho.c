#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// tamanho do vetor
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

//quick sort
void quick_sort(int vetor[], int start, int end)
{
    int pivo, es, di, aux;

    // atribuição dos valores pivo, ponteiro esquerdo(es) e direito(di)
    pivo = vetor[start];
    es = start;
    di = end;

    // condição de repetição enquanto os ponteiros nao se ultrupassaram
    while (es <= di)
    {

        // movimento do ponteiro da esquerda
        while (vetor[es] < pivo)
        {
            es++;
        }

        // movimento do ponteiro da direita
        while (vetor[di] > pivo)
        {
            di--;
        }

        // troca de valores entre ponteiros
        if (es <= di)
        {
            aux = vetor[es];
            vetor[es] = vetor[di];
            vetor[di] = aux;
            es++;
            di--;
        }
    }

    // quebra/divisão de vetores e subvetores
    // vetor da esquerda
    if (start < di)
    {
        quick_sort(vetor, start, di);
    }

    // vetor da direita
    if (es < end)
    {
        quick_sort(vetor, es, end);
    }
}

//inicio
int main()
{
    // vetor
    int vetor[max];
    float m;
    double timer = 0, timerp = 0;

    // rodar 30 vezes
    for (int a = 0; a < 30; a++)
    {
        // chamada da função para randomizar
        rand_vet(vetor);

        // inicio do timer
        clock_t begin = clock();

        // chamada da função quick
        quick_sort(vetor, 0, max - 1);

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