#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//havia problema ao pecorrer os vetores

char v[1000];
char d[2];

void bubble(int *pposicao, int *ptam)
{

    for (int i = *pposicao; i < *ptam; i++)
    {
        v[i] = v[i + 1];
    }

    while (v[0] == '0' && (v[1] == '0' || v[1] != '\0'))
    {
        for (int i = 0; i < *ptam; i++)
        {
            v[i] = v[i + 1];
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
            printf("*");
            bubble(&i, &t);
            i--;
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

        v[strlen(v) - 1] = '\0';

        arruma_digitacao();

        printf("valor \n%s\n\n", v);

    } while (d[0] != '0' || v[0] != '0');

    return 0;
}