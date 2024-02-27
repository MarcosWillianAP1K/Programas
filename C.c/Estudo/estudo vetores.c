#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;

    printf("digite o tamanho do vetor\n");
    scanf("%d", &n);

    int vet[n], i;
    float t;

    system("cls||clear");
    for (i = 0; i < n; i++)
    {
        printf("digite valor da posicao %d de %d\n", i+1, n);
        scanf("%d", &vet[i]);
        t += vet[i];
        
        system("cls||clear");
    }

    for (i = 0; i < n; i++)
    {
        printf("%d ", vet[i]);
    }
    printf("\nmedia: %.2f", t / 5);

    return 0;
}