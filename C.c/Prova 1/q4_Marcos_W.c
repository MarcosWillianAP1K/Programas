#include <stdio.h>

#define sequencia 3

void mostraSequencias(int n);

int main()
{
    int n;

    do
    {
        scanf("%d", &n);
    } while (n <= 1 || n >= 1000);

    mostraSequencias(n);

    return 0;
}

void mostraSequencias(int n)
{
    int p1, p2, aux;

    printf("\n\n");

    for (int i = 0; i < n; i++)
    {
        p1 = i+1;
        p2 = i+1;

        printf("%d", p1);

        for (int j = 0; j < sequencia-1; j++)
        {
            printf(" %d", p1*p2);
            
            aux = p1;
            p1 = p2;
            p2 = aux * p2;
        }
        printf("\n");
    }
}