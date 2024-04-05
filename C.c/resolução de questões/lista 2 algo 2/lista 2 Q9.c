#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char v[10100];
char d[2];

void bubble(int *pposicao, int *ptam)
{
    char aux;

    for (int i = *pposicao; i < *ptam; i++)
    {
        aux = v[i];
        v[i] = v[i + 1];
        v[i + 1] = aux;
    }

    while (v[0] == '0' && (v[1] == '0' || v[1] != '\0'))
    {
        for (int i = 0; i < *ptam; i++)
        {
            aux = v[i];
            v[i] = v[i + 1];
            v[i + 1] = aux;
        }
    }
}

void arruma_digitacao()
{
    int t = strlen(v);

    for (int i = 0; i < t; i++)
    {

        if (v[i] == d[0])
        {
            bubble(&i, &t);
        }
    }
}

int main()
{

    printf("Digite a tecla defeituosa e em seguida o numero digitado\n\n");

    do
    {
        fflush(stdin);
        fgets(d, sizeof(d), stdin);
        fflush(stdin);
        fgets(v, sizeof(v), stdin);
        fflush(stdin);

        d[1] = '\0';
        v[strlen(v) - 1] = '\0';

        arruma_digitacao();

        printf("valor \n%s\n\n", v);

    } while (d[0] != '0' || v[0] != '0');

    return 0;
}