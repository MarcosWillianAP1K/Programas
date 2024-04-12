#include <stdio.h>

int main()
{
    //enteda como funciona ponteiro

    //declaração de uma variavel qualquer
    int n = 2;

    //declaração de um ponteiro do mesmo tipo da variavel
    int *ponteiro;

    
    //Como passar um endereço para ponteiro
    ponteiro = &n;


    //printar o endereço do ponteiro
    printf("%p\n", ponteiro);
    printf("%p\n", &n);

    //printar valor que esta no endereço da variavel
    printf("\n\n%d\n", *ponteiro);
    printf("%d\n", n);

    return 0;
}