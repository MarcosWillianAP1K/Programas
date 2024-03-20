#include <stdio.h>

int main (){
    int valor=0, n=0;

    while (n >= 0)
    {
        valor += n;
        scanf("%d", &n);
    }

    printf("\nValor: %d", valor);
    
    return 0;
}