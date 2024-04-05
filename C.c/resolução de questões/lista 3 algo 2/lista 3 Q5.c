#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int valor, n = 0;

    srand(time(NULL));
    valor = rand() % 1000;

    do
    {
        printf("Tentativa passada %d\n\n", n);
        if (scanf("%d", &n) == 1)
        {
            if (n == valor)
            {
                printf("\nPARABENSSSSSS VOCE ACERTOU\n\n");
            }
            else if (n < valor)
            {
                printf("\nOpa, ainda esta muito baixo\n\n");
            }
            else
            {
                printf("\nOpa, ainda esta muito alto\n\n");
            }
        }
        else
        {
            fflush(stdin);
            printf("\nEsse caractere nao e valido\n\n");
        }
        system("pause");
        system("cls||clear");

    } while (n != valor);

    return 0;
}