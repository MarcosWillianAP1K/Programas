#include <stdio.h>

void printar_matriz (int mat[]){

for (int i = 0; i < 10; i++)
{
    for (int j = 0; j < 10; j++)
    {
        printf("%d ", mat[i][j]);
    }
    printf("\n");
}

   
}

void preencher_matriz (int *p, int *pf){

    for ( p = p; p < pf; p++)
    {
        *p = 0;
    }
}

int main (){

    int mat[10][10];

    preencher_matriz(mat, mat + (sizeof(mat) / 4) - 1);

    printar_matriz(mat);

    return 0;
}