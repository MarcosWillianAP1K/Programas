#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    int num, resete;

    do{
    
     printf("Digite um numero de 1 a 30\n");
     scanf("%d", &num);

     if (num >= 1 && num < 10){

        printf("primeiro lugar\n"); 
     }
     else 
     if(num >=11 && num <=20) {

        printf("segundo lugar\n");
     }
     else
     if (num >= 21 && num <= 30){

        printf("terceiro lugar\n");
    }
     else{

        printf("voce e idiota?\n"); 
     }

     system("pause");
     system("cls");
     resete = 0;

    }while (resete == 0);

    return 0;
}