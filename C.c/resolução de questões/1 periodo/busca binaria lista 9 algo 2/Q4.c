#include <stdio.h>

void codigo();


int main()
{
    int t;

    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        codigo();
    }

    return 0;
}

void codigo()
{
    int n, x, h = 0, c = 0;

    scanf("%d%d", &n, &x);

    int col[n];

    fflush(stdin);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &col[i]);
    }
    fflush(stdin);

    
    while (c < x)
    {
        h++;

        for (int i = 0; i < n; i++)
        {
            if (h > col[i])
            {
                c++;
            }
        }
    }

    if (c > x)
    {
        h--;
    }
    

    printf("%d\n\n", h);
}