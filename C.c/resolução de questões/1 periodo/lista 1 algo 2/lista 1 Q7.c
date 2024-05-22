#include <stdio.h>

int main()
{
    int x, y, i, pares, res = 0, res1 = 1, inpares;

    scanf("%d %d", &x, &y);

    if (x < y - 2)
    {
        for (i = x; i <= y; i++)
        {
            if (i % 2 == 0)
            {
                pares = i;
                res = res + pares;
            }
            else
            {
                inpares = i;
                res1 = res1 * inpares;
            }
        }
    }
    printf("%d %d\n", res, res1);
}
