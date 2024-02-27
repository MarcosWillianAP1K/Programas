#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// tamanho do vetor
#define max 200000

int main()
{

    // vetor
    int vetor[max];
    int aux, i, j, a;
    float m;
    double timer = 0, timerp = 0;

    // rodar bubble sort 30 vezes
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

        // Bubble sort
        // for pra todo o vetor
        for (i = 0; i < max; i++)
        {
            // for para testar cada posição do vetor
            for (j = 0; j < max - i; j++)
            {
                // condição para caso o vetor a frente seja menor
                if (vetor[j] > vetor[j + 1])
                {
                    // troca do primeiro vetor para o vetor da frente
                    aux = vetor[j];
                    vetor[j] = vetor[j + 1];
                    vetor[j + 1] = aux;
                }
            }
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