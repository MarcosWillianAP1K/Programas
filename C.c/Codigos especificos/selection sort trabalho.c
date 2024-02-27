#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// tamanho do vetor
#define max 200000

int main()
{
    // vetor
    int vetor[max];
    int i, j, min, aux, a;
    float m;
    double timer = 0, timerp = 0;

    // rodar selection sort 30 vezes
    for (a = 0; a < 30; a++)
    {
        // gerar numeros aleatorios em cada posição do vetor
        srand(time(NULL));
        for (i = 0; i < max; i++)
        {
            vetor[i] = rand() % max;
        }
        
        // inicio do timer
        clock_t begin = clock();

        // selection sort
        // for para todo o vetor
        for (i = 0; i < max - 1; i++)
        {
            min = i;

            // testar cada posição do vetor
            for (j = i + 1; j < max; j++)
            {
                // condição para descobrir o min
                if (vetor[j] < vetor[min])
                {
                    // min = posição encontrada(j)
                    min = j;
                }
            }
            // troca o min pela posição i(da esquerda pra direita)
            aux = vetor[i];
            vetor[i] = vetor[min];
            vetor[min] = aux;
        }
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