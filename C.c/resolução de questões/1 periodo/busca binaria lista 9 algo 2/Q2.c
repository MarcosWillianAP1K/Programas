#include <stdio.h>
#include <stdlib.h>

#define max 240

int n, k, t = 0;

int main()
{
    do
    {
        scanf("%d %d", &n, &k);

        if (!((n >= 1 && n <= 10) && (k >= 1 && k <= 240)))
        {
            system("cls||clear");
            fflush(stdin);
        }

    } while (!((n >= 1 && n <= 10) && (k >= 1 && k <= 240)));

    t = k;

    int i = 1;

    while (t <= max && i != n+1)
    {
        i++;
        t += 5 * i;
    }
    i--;

    printf("\n%d", i);
    

    return 0;
}