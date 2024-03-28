#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char n[20];
    int t;

    printf("Digite um nome em minusculo ate 20 caracteres\n");
    fgets(n, sizeof(n), stdin);
    printf("\n");

    t = strlen(n);

    for (int i = 0; i < t - 1; i++)
    {
        n[i] = toupper(n[i]);

        printf("%c ", n[i]);
    }
    
    return 0;
}