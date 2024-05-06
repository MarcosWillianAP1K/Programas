#include <stdio.h>
#include <stdlib.h>


void  mostrarNFibonacci(int n);

int main()
{
    int n;
    do
    {
        scanf("%d", &n);

        if (n <= 0 || n >= 46)
        {
            system("cls||clear");
        }

    } while (n <= 0 || n >= 46);

    mostrarNFibonacci(n);

    return 0;
}

void  mostrarNFibonacci(int n){

    int p1 = 0, p2 = 1, p3 = 0;

    printf("\n\n0 1");

    while (p3 < n)
    {
        p3 = p1 + p2;
        
        printf(" %d", p3);

        p1 = p2;
        p2 = p3;
    }
}