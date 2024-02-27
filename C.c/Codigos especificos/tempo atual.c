#include <stdio.h>
#include <time.h>

int main() {
    // Obter o tempo atual
    time_t tempoAtual;
    struct tm *infoTempo;

    time(&tempoAtual);
    infoTempo = localtime(&tempoAtual);

    // Exibir a data atual
    printf("Data atual: %02d/%02d/%04d\n", infoTempo->tm_mday, infoTempo->tm_mon + 1, infoTempo->tm_year + 1900);

    return 0;
}