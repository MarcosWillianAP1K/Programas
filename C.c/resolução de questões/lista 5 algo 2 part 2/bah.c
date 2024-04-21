#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_CARTAS 52
#define NUM_FACES 13
#define NUM_NAIPES 4

typedef struct {
    char face[10];
    char naipe[10];
} Carta;

void preenche(Carta *deck, char *face[], char *naipe[]) {
    int i, j;
    for (i = 0; i < NUM_NAIPES; i++) {
        for (j = 0; j < NUM_FACES; j++) {
            strcpy(deck[i * NUM_FACES + j].face, face[j]);
            strcpy(deck[i * NUM_FACES + j].naipe, naipe[i]);
        }
    }
}

void troca(Carta *a, Carta *b) {
    Carta temp = *a;
    *a = *b;
    *b = temp;
}

void embaralha(Carta *deck) {
    srand(time(NULL));
    int i;
    for (i = 0; i < NUM_CARTAS; i++) {
        int j = rand() % NUM_CARTAS;
        troca(&deck[i], &deck[j]);
    }
}

void imprime(Carta *deck) {
    int i;
    for (i = 0; i < NUM_CARTAS; i++) {
        printf("%s de %s\n", deck[i].face, deck[i].naipe);
    }
}

int main() {
    Carta deck[NUM_CARTAS];
    char *faces[NUM_FACES] = {"As", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Valete", "Dama", "Rei"};
    char *naipes[NUM_NAIPES] = {"Copas", "Ouros", "Espadas", "Paus"};

    preenche(deck, faces, naipes);
    printf("Deck antes do embaralhamento:\n");
    imprime(deck);

    embaralha(deck);
    printf("\nDeck depois do embaralhamento:\n");
    imprime(deck);

    return 0;
}