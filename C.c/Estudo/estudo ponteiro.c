#include <stdio.h>

int main (){

    int x, y;
    x = 10;
    y = 20;

    //declaração do ponteiro
    int *ponteiro;
    //& serve para acessar ao endereço na memoria
    //atribuição do local na meoria do x
    ponteiro = &x;
    //e possivel fazer int *ponteiro = &x; , o * so declara que é um ponteiro, nao acessa valor na declaração

    //printar valor, acesso ao valor na memoria
    printf("%d\n\n", *ponteiro);

    //printar endereço na memoria que esta armazenado o valor da variavel, acesso a posição na memoria
    printf("%p\n\n", ponteiro);

    //Alterei o valor de x diretamente no local da memoria
    *ponteiro = y;

    printf("%d", x);

    return 0;
}