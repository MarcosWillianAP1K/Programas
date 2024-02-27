#include <stdio.h>

int main(){

    int tam, aux;

    printf("digite o tamanho do vetor\n");
    scanf("%d", &tam);

    int vet[tam];


    for (int i = 0; i < tam; i++)
    {
        vet[i] = i + 1;
    }
    

    printf("Vetor original\n");
    for (int i = 0; i < tam; i++)
    {
        printf("%d ", vet[i]);
    }

    for (int i = 0; i < tam / 2; i++)
    {
        aux = vet[i];
        vet[i] = vet[tam - i - 1];
        vet[tam - i - 1] = aux;
    }

    printf("\n\nVetor invertido\n");
    for (int i = 0; i < tam; i++)
    {
        printf("%d ", vet[i]);
    }

    return 0;
}