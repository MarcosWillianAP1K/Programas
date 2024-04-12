#include <stdio.h>


void cubo(int *nPtr);

int main()
{
    int n;

    do
    {

        if (scanf("%d", &n) == 1)
        {
            cubo(&n);

            printf("\n%d", n);
        }
        else
        {
            fflush(stdin);
        }
        printf("\n\n");
    } while (n != 0);

    return 0;
}

void cubo(int *nPtr){

    *nPtr = *nPtr * *nPtr * *nPtr;
}