#include <stdio.h>
#include <Windows.h>

int main() {
    int i;
    int loadingBarLength = 50; // Comprimento da barra de progresso

    printf("Loading:\n");
    printf("[");
    for(i = 0; i < loadingBarLength; i++) {
        printf(" ");
    }
    printf("]\r[");
    fflush(stdout); // Força a atualização do stdout

    for(i = 0; i < loadingBarLength; i++) {
        printf("#");
        fflush(stdout); // Força a atualização do stdout
        Sleep(100); // Pausa de 100 milissegundos
    }

    printf("]\n");
    printf("Loading complete!\n");

    return 0;
}