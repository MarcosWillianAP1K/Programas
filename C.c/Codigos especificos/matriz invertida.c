#include <stdio.h>
#define coluna 3
#define linha 3

int main()
{

    int mat[linha][coluna];
    int aux, a = 0;

    for (int l = 0; l < linha; l++)
    {
        for (int c = 0; c < coluna; c++)
        {
            a++;
            mat[l][c] = a;
        }
        
    }
    

    printf("Matriz original\n");
    for (int l = 0; l < linha; l++)
    {
        for (int c = 0; c < coluna; c++)
        {
            printf("%d ", mat[l][c]);
        }
        printf("\n");
    }

    if (linha % 2 == 0)
    {
        for (int l = 0; l < linha / 2; l++)
        {
            for (int c = 0; c < coluna; c++)
            {
                aux = mat[l][c];
                mat[l][c] = mat[linha - l - 1][coluna - c - 1];
                mat[linha - l - 1][coluna - c - 1] = aux;
            }
        }
    }
    else
    {
        for (int l = 0; l <= linha / 2; l++)
        {
            if (linha / 2 == l)
            {
                for (int c = 0; c < coluna / 2; c++)
                {
                    aux = mat[l][c];
                    mat[l][c] = mat[linha - l - 1][coluna - c - 1];
                    mat[linha - l - 1][coluna - c - 1] = aux;
                }
            }
            else
            {
                for (int c = 0; c < coluna; c++)
                {
                    aux = mat[l][c];
                    mat[l][c] = mat[linha - l - 1][coluna - c - 1];
                    mat[linha - l - 1][coluna - c - 1] = aux;
                }
            }
        }
    }

    printf("\n\nMatriz ivertida\n");
    for (int l = 0; l < linha; l++)
    {
        for (int c = 0; c < coluna; c++)
        {
            printf("%d ", mat[l][c]);
        }
        printf("\n");
    }

    return 0;
}