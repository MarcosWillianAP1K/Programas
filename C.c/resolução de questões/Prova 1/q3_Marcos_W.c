#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define lin 12
#define col 12

void preencher(double M[][col]);
double calcularArea(char operacao, double M[][col]);

int main()
{
    char operacao;
    double M[lin][col];

    do
    {
        fflush(stdin);
        scanf("%c", &operacao);
        fflush(stdin);

    } while (operacao != 'M' && operacao != 'S');

    preencher(M);

    printf("\n\n%.1lf", calcularArea(operacao, M));

    return 0;
}

// gerar numeros aleatorios para preencher a matriz
void preencher(double M[][col])
{
    srand(time(NULL));

    double a;
    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            a = rand() % 10;
            a /= 10;
            a += rand() % 100;

            M[i][j] = a;

            printf("%.1lf\t", M[i][j]);
        }
        printf("\n");
    }
}

double calcularArea(char operacao, double M[][col])
{
    int c = 1;
    double total = 0, ct = 0;

    for (int i = 1; i < lin; i++)
    {
        for (int j = 0; j < c; j++)
        {
        total += M[i][j];
        }
        ct += c;
        c++;
    }

    if (operacao == 'S')
    {
        return total;
    }
    else
    {
        return total / ct;
    }
}