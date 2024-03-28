#include <stdio.h>
#include <stdlib.h>

#define Q 40

int main()
{
    int n[Q], c = 0, t;

    do
    {
        printf("Digite a frenquencia que voce vai a biblioteca de 0 a 10\n");
        scanf("%d", &n[c++]);

        system("cls||clear");
    } while (n[c - 1] != -1 && c < Q);

    printf("Tabela de quantos digitaram\n\n");

    for (int i = 0; i <= 10; i++)
    {
        t = 0;

        printf("%d: ", i);

        for (int j = 0; j < c; j++)
        {
            if (n[j] == i)
            {
                t++;
            }
        }
        printf("%d\n", t);
    }

    return 0;
}