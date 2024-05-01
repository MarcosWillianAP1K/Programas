#include <stdio.h>
#include "my_string.h"

void funcao();

int main(void){

    char s1[100];
    char *s2 = "Hello, guys!";
    char *s3 = "Hello, Guys!";
    char s4[40] = "Hello, ";
    char *s5 = "guys! How are you?";
    char *s6 = " We are fine and you?";

    

    printf("%s", mystrcpy(s1, s2));


    return 0;
}

void funcao(){



}