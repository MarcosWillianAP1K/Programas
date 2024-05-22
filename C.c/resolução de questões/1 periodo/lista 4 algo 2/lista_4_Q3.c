#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <time.h>

struct cartas
{
    char carta[13][20];
};
struct cartas c[4];

char valores[13][10] = {{"As"}, {"Dois"}, {"Tres"}, {"Quatro"}, {"Cinco"}, {"Seis"}, {"Sete"}, {"Oito"}, {"Nove"}, {"Dez"}, {"Valete"}, {"Dama"}, {"Rei"}};

void gerador();
void printar();
void embaralhar();

int main()
{
    int menu;

    srand(time(NULL));

    gerador();

    printf("0- Embaralhar\n1-Printar em ordem\n");
    scanf("%d", &menu);
    system("cls||clear");

    if (menu == 1)
    {
        printar();
    }
    else
    {
        embaralhar();
    }

    return 0;
}

void gerador()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            strcpy(c[i].carta[j], valores[j]);
            strcat(c[i].carta[j], " de ");

            if (i == 0)
            {
                strcat(c[i].carta[j], "Paus");
            }

            if (i == 1)
            {
                strcat(c[i].carta[j], "Ouro");
            }

            if (i == 2)
            {
                strcat(c[i].carta[j], "Copas");
            }

            if (i == 3)
            {
                strcat(c[i].carta[j], "Espadas");
            }
        }
    }
}

void printar()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            printf("%s\n", c[i].carta[j]);
        }
        printf("\n");
    }
}

void embaralhar()
{
    char aux[20];
    int i2, j2;
    
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            i2 = rand() % 4; 
            j2 = rand() % 13;

            strcpy(aux, c[i].carta[j]);
            strcpy(c[i].carta[j], c[i2].carta[j2]);
            strcpy(c[i2].carta[j2], aux);
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            printf("%s\n", c[i].carta[j]);
        }
        printf("\n");
    }
}
