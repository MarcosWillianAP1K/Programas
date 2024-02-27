#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    int n, i, a, c;

    
    

    do{
    
    printf("digite um numero\n");
    scanf("%d", &n);

    a = 1;

    for (i = 0; i < n; i++){

        printf("\n");
        
        for(c = 0; c < a; c++){
            printf("* ");
        }
        a++;
    }

    printf("\n");
    system("pause");
    system("cls||clear");
   
    }while (n >= 0);
    
    return 0;
}