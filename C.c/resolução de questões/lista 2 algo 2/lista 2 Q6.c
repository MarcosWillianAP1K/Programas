#include <stdio.h>

#define linha 4
#define coluna 4

int main()
{
    //[10] linha [10] coluna
    int mat1[linha][coluna], mat2[linha][coluna], c = 1, lin = 0, col = 0;
    
    printf("MATRIZ 1\n\n");
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            mat1[i][j] = c;
            mat2[i][j] = c;
            c++;

            printf("%d\t", mat1[i][j]);
        }
        printf("\n");
    }

    printf("\nMATRIZ 2\n\n");

    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            printf("%d\t", mat2[i][j]);
        }
        printf("\n");
    }

    printf("\nPRODUTO DAS MATRIZE\n\n");

    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            mat1[i][j] *= mat2[lin][col];
            printf("%d\t", mat1[i][j]);

            lin++;
        }
        printf("\n");
        lin = 0;
        col++;
    }

    return 0;
}