#include <stdio.h>

int main (){

struct horario
{
    int hora, minuto, segundo;
};

//declarando ponteiro no struct
struct horario agora, *depois;

//definindo o endereço do ponteiro
depois = &agora;

//o parentese e para o compilador ler primeiro que é um ponteiro(valor), para depois sim modificar o valor
(*depois).hora = 20;
(*depois).minuto = 20;
(*depois).segundo = 20;

printf("%d:%d:%d\n\n", agora.hora, agora.minuto, agora.segundo);

//outra maneiro de fazer (atalho)
depois->hora = 30;
depois->minuto = 30;
depois->segundo = 30;


printf("%d:%d:%d", agora.hora, agora.minuto, agora.segundo);

    return 0;
}