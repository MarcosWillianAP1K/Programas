#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define lin 12
#define col 12

double mat[lin][col];
char op;

void preencher();
void printar();
void operacao();

int main()
{

    do
    {
        fflush(stdin);
        scanf("%c", &op);
        fflush(stdin);
    } while (op != 'M' && op != 'S');
    

    preencher();

    printar();

    operacao();

    return 0;
}

void preencher()
{
    srand(time(NULL));

    double n;

    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            n = (rand() % 10);
            n = n / 10;
            n += rand() % 100;

            mat[i][j] = n;
        }
    }
}

void printar()
{

    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%.1lf\t", mat[i][j]);
        }
        printf("\n");
    }
}

void operacao()
{
    int c = 1, ct = 0;
    double t = 0;

    for (int i = 0; i < lin / 2 - 1; i++)
    {
        for (int j = c; j < col - c; j++)
        {
            t += mat[i][j];
        }
        ct += c * 2;
        c++;
    }

    if (op == 'S')
    {
        printf("\n\n%.1lf", t);
    }

    if (op == 'M')
    {
        printf("\n\n%.1lf", t / ((((lin / 2) - 1) * col) - ct));
    }
}