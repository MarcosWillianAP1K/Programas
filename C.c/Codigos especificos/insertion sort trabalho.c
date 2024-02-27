#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// tamanho do vetor
#define max 200000

int main()
{
    // vetor
    int vetor[max];
    int i, j, aux, a;
    float m;
    double timer = 0, timerp = 0;

    // rodar 30 vezes
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

        // for para cada posição do vetor, detalhe, começa pela posição 1 inves de 0
        for (i = 1; i < max; i++)
        {
            // aux vira o valor da posição i, e j recebe valor da posição anterio a i
            aux = vetor[i];
            j = i - 1;

            // condição para saber se o valor da posição i e menor aos do lado da esquerda
            while ((j >= 0) && (aux < vetor[j]))
            {
                // o vetor da direita recebe o valor vetor da esquerda, sendo j a posição do vetor
                vetor[j + 1] = vetor[j];
                j--;
            }
            // atribui valor da posição i(o aux) para a posição certa
            vetor[j + 1] = aux;
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