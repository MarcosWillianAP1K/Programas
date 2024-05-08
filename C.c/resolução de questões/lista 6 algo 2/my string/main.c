#include <stdio.h>
#include "my_string.h"


int main(void){

    char s1[100];
    char *s2 = "Hello, guys!";
    char *s3 = "Hello, Guys!";
    char s4[40] = "Hello, ";
    char *s5 = "guys! How are you?";
    char *s6 = " We are fine and you?";

    printf("%s", mystrcpy(s1, s2));
    printf("\n%s", mystrncpy(s1, s2, 5));
    printf("\n%d", mystrcmp(s3, s2));
    printf("\n%d", mystrncmp(s2, s3, 7));
    printf("\n%d", mystrncmp(s2, s3, 8));   
     printf("\n%s", mystrcat(s4, s5));
    printf("\n%s", mystrncat(s4, s6, 12)); 

    return 0;
}