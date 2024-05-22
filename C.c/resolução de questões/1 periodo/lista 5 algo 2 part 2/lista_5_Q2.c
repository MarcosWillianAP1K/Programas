#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct
{
    char carta[20];

} carta;

void preenche(carta *deck, char *face[], char *naipe[]);
void printar(carta *deck);
void embaralhar(carta *deck);

int main()
{
srand(time(NULL));

    int n;
    carta deck[52];
    char *naipe[4] = {"Copas", "Ouros", "Espadas", "Paus"};
    char *face[13] = {"As", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Valete", "Dama", "Rei"};

    preenche(deck, face, naipe);

    scanf("%d", &n);

    if (n == 1)
    {
        embaralhar(deck);
    }

    printar(deck);

    return 0;
}

void preenche(carta *deck, char *face[], char *naipe[])
{
    int c = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            strcpy(deck[c].carta, naipe[i]);
            strcat(deck[c].carta, " de ");
            strcat(deck[c].carta, face[j]);
            c++;
        }
    }
}

void printar(carta *deck)
{
    for (int i = 0; i < 52; i++)
    {
        printf("%s\n", deck[i].carta);
    }
}

void embaralhar(carta *deck)
{
    char aux[20];

    int a;
    
    for (int i = 0; i < 52; i++)
    {
        a = rand() % 52;

       strcpy(aux, deck[i].carta);
       strcpy(deck[i].carta, deck[a].carta);
       strcpy(deck[a].carta, aux);
    }
}