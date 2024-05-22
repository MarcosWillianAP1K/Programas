#include <stdio.h>
#include <stdlib.h>

void inversao_do_numero(int *n)
{
    int aux = 0;

    while(*n != 0){

        aux *= 10;
        aux += *n % 10;
        *n /= 10;
    }
    
    printf("\n%d\n\n", aux);
}

int main()
{
    int n;

    do
    {

        if (scanf("%d", &n) == 1)
        {
            if (n >= 1000 && n <= 9999)
            {
                inversao_do_numero(&n);
            }
            else
            {
                printf("\nValor fora dos parametros\n\n");
                system("pause");
            }
        }
        else
        {
            fflush(stdin);
            printf("\nOps, voce digitou errado\n\n");
            system("Pause");
        }

    } while (n < 1000 || n > 9999);

    return 0;
}