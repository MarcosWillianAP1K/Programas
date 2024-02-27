#include <stdio.h>
#include <stdlib.h>

int main(){

    int i;
    float r, n;

    printf("digite um numero\n");
    scanf("%f", &n);

    printf("\nAdicao\n");
    for (i = 0; i <= 10; i++){
        r = n + i;
        printf("\n%d + %.0f = %.0f", i, n, r);
    }

    printf("\n\n Subtracao\n");
    for (i = 0; i <= 10; i++){
        r = n - i;
        printf("\n%d - %.0f = %.0f", i, n, r);
    }

    printf("\n\nMultiplicacao\n");
    for (i = 0; i <= 10; i++){
        r = n * i;
        printf("\n%d x %.0f = %.0f", i, n, r);
    }

    printf("\n\nDivisao\n");
    for (i = 1; i <= 10; i++){
        r = n / i;
        printf("\n%d / %.0f = %.2f", i, n, r);
    }
    
    return 0;
}