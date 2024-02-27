#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    int n, t;

    t = 1;

    printf("digite um numero\n");
    scanf("%d", &n);

    if (n > 0){
        while(n >= 1){
            t = t * n;
            n--;
        }
    }
    else if(n < 0){
         while(n <= -1){
            t = t * n;
            n++;
        }
    }
    else{
        t = 0;
    }
    printf("\n%d", t);
    
    return 0;
}