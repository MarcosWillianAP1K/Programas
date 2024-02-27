#include <stdio.h>
#include <stdlib.h>

void soma(int n1, int n2)
{
    printf("soma: %d\ndobro:\n%d\n%d", n1 + n2, n1 * 2, n2 * 2);
}

int main()
{
    int n1, n2;

    printf("Digite dois numeros\n");
    scanf("%d %d", &n1, &n2);
    printf("\n");

    soma(n1, n2);

    return 0;
}