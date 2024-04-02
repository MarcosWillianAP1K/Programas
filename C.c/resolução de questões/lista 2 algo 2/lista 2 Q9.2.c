#include <stdio.h>
#include <stdlib.h>


void arruma_digitacao(char *pd, char v[])
{
     


    for (int i = 0; i < strlen(v); i++)
    {
      printf("*");
        if (v[i] == *pd)
        {
            v[i] = ' ';
        }
    }

    
}

int main()
{
    char d;
    char v[20];

    printf("Digite a tecla defeituosa e em seguida o numero digitado\n\n");

    do
    {
        scanf("%c", &d);

        fflush(stdin);
        fgets(v, sizeof(v), stdin);
        fflush(stdin);

        v[strlen(v) - 1] = '\0';

        if (d != 0 || v != 0)
        {
            arruma_digitacao(&d, v);

            printf("\n\nvalor %s\n\n", v);
        }

    } while (d != 0 || v != 0);

    return 0;
}