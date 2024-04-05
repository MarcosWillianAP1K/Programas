#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

char artigo[5][10] = {{"o "}, {"um "}, {"algum "}, {"todo "}, {"qualquer "}}; 
char substantivo[5][10] = {{"menino "}, {"homem "}, {"cachorro "}, {"carro "}, {"gato "}}; 
char verbo[5][10] = {{"passou "}, {"pulou "}, {"correu "}, {"saltos "}, {"andou "}}; 
char preposicao[5][10] = {{"sobre "}, {"sob "}, {"ante "}, {"ate "}, {"com "}};

int main()
{
    char frases[20][50];
    int t;

    srand(time(NULL));

    for (int i = 0; i < 20; i++)
    {
        strcpy(frases[i], artigo[rand() % 5]);
        strcat(frases[i], substantivo[rand() % 5]);
        strcat(frases[i], verbo[rand() % 5]);
        strcat(frases[i], preposicao[rand() % 5]);
        strcat(frases[i], artigo[rand() % 5]);
        strcat(frases[i], substantivo[rand() % 5]);

        t = strlen(frases[i]);

        frases[i][0] = toupper(frases[i][0]);
        frases[i][t - 1] = '.';

        printf("%s\n\n", frases[i]);
    }

    return 0;
}