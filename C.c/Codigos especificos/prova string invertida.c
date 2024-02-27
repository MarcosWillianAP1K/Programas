#include <stdio.h>
#include <string.h>

int main (){

    int tam, tamv;

    printf("Digite o Tamanho da string\n");
    scanf("%d", &tam);

    char nome[tam], aux[1];

    printf("\nDigite o nome\n");
    scanf("%s", &nome);

    printf("\n%s\n\n", nome);

    for (int i = 0; i < tam; i++)
    {
        printf("%d = %c  ",i , nome[i]);
    }
    

    tamv = strlen(nome);

    for (int i = 0; i < tamv / 2; i++)
    {
        aux[0] = nome[i];
        nome[i] = nome[tamv - i -1];
        nome[tamv - i- 1] = aux[0];
    }

    printf("\n\n%s\n\n%d\n\n", nome, tamv);

    for (int i = 0; i < tam; i++)
    {
        printf("%d = %c  ", i, nome[i]);
    }
    

    return 0;
}