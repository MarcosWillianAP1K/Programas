#include <stdio.h>
#include <string.h>

void maisculo(char *sPtr);

int main()
{
    char n[100];

    do
    {
        fgets(n, sizeof(n), stdin);

        //apenas para tirar o \n que o fgets coloca na string
        int t = strlen(n);
        n[t - 1] = '\0';

        maisculo(n);

        printf("\n\n%s\n\n", n);

    } while (n[0] == '0');

    return 0;
}

void maisculo(char *sPtr)
{
    while (*sPtr != '\0')
    {
        if(*sPtr >= 'a' && *sPtr <= 'z'){
            *sPtr -= 32;
        }
        sPtr++;
    }
}