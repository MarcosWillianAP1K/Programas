#include <stdio.h>
#include <stdlib.h>

int main()
{

    int mat[3][3], mataux[3][3];
    int i, j;

    srand(time(NULL));

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            mat[i][j] = rand() % 100;
            mataux[i][j] = rand() % 100;

            mat[i][j] = mat[i][j] + mataux[i][j];
        }
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}