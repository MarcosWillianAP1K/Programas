#include <stdio.h>

typedef struct
{
    int x, y;
} botao;

char *nomes[11] = {"PROXYCITY", "P.Y.N.G", "DNSUEY", "SERVERS", "HOST!", "CRIPTONIZE", "OFFLINE DAY", "SALT", "ANSWER", "RAR?", "WIFI ANTENNAS"};
int c;

void printar(botao *n);

int main()
{
    scanf("%d", &c);
    printf("\n");

    botao n[c];

    for (int i = 0; i < c; i++)
    {
        scanf("%d%d", &n[i].x, &n[i].y);
    }

    printar(n);

    return 0;
}

void printar(botao *n)
{
    printf("\n\n");
    for (int i = 0; i < c; i++)
    {
        printf("%s\n", nomes[n[i].x + n[i].y]);
    }
}