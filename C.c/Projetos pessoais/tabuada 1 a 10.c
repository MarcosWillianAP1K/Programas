#include <stdio.h>
#include <stdlib.h>

int main(){

    int i; 
    float n, r;


    printf("ADICAO\n");
    for (i = 0; i < 11; i++){
        for (n = 0; n < 11; n++){
            r = n + i;
            printf("\n%d + %.0f = %.0f", i, n, r);
        }
        printf("\n");
        
    }

    printf("\n\nSubtracao\n");
    for (i = 0; i < 11; i++){
        for (n = 0; n < 11; n++){
            r = n - i;
            printf("\n%d - %.0f = %.0f", i, n, r);
        }
        printf("\n");
        
    }

    printf("\n\nMULTIPLICACAO\n");
    for (i = 0; i < 11; i++){
        for (n = 0; n < 11; n++){
            r = n * i;
            printf("\n%d x %.0f = %.0f", i, n, r);
        }
        printf("\n");
        
    }

    printf("\n\nDIVISAO\n");
    for (i = 1; i < 11; i++){
        for (n = 0; n < 11; n++){
            r = n / i;
            printf("\n%d / %.0f = %.2f", i, n, r);
        }
        printf("\n");
        
    }
    
    return 0;
}