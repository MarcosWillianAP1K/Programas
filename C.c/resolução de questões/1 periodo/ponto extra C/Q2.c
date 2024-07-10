#include <stdio.h>


int main()
{
    int n;

    scanf("%d", &n);

    int vet[n], contador = 0, x;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vet[i]);
    }
    fflush(stdin);

    scanf("%d", &x);

    for (int i = 0; i < n; i++)
    {
       if(vet[i] > x)
       {
            contador++;
       }
    }
    
    printf("\n%d", contador);
    

    return 0;
}