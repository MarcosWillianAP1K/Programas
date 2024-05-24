#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

int t, n, total, necessario;

int main()
{
    do
    {
        scanf("%d", &t);
    } while (!(t >= 1 && t <= 10000));

    bool final[t];

    for (int j = 0; j < t; j++)
    {
        total = 0;

        do
        {
            scanf("%d", &n);

        } while (!(n >= 1 && n <= pow(10, 9)));

        int baldes[n];

        fflush(stdin);

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &baldes[i]);
        }

        fflush(stdin);

        necessario = n * 6;

        for (int i = 0; i < n; i++)
        {
            total = total + baldes[i];
        }

        if (total >= necessario)
        {
            final[j] = true;
        }
        else
        {
            final[j] = false;
        }
    }
    printf("\n\n");

    for (int i = 0; i < t; i++)
    {
        if (final[i] == true)
        {
            printf("YES\n");
        }
        else
        {
            printf("NAO\n");
        }
    }

    return 0;
}