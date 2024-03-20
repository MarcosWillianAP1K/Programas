#include <stdio.h>

int main()
{

    int n1, n2, d, c = 0;

    scanf("%d %d", &n1, &n2); //20 24

    if (n1 < n2)
    {
        d = n1;
    }
    else
    {
        d = n2;
    }

    while (n1 % d != 0 || n2 % d != 0)
    {
        d--;
        c++;
    }

    printf("\n\n%d\ncontador: %d", d, c);

    return 0;
}