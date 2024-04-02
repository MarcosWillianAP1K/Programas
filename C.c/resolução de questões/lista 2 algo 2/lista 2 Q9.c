#include <stdio.h>
#include <stdlib.h>


void contador_de_algarismo(int *p, int n)
{
    if (n < 0)
    {
        n *= -1;
    }

    while (n != 0)
    {
        n /= 10;
        *p += 1;
    }
}

void arruma_digitacao(char *pd, int *pv)
{
    int tam = 0;    

    contador_de_algarismo(&tam, *pv);


    char vstring[tam];
    
    sprintf(vstring, "%d", *pv);

    for (int i = 0; i < tam; i++)
    {
        
        if (vstring[i] == *pd)
        {
            vstring[i] = ' ';
        }
    }

    

    *pv = atoi(vstring);
    
}

int main()
{
    int v;
    char d;

    printf("Digite a tecla defeituosa e em seguida o numero digitado\n\n");

    do
    {
        
        scanf("%c", &d);
        scanf("%d", &v);
        

        if (d != 0 || v != 0)
        {
            arruma_digitacao(&d, &v);

            printf("valor %d\n\n", v);
        }

    } while (d != '0' || v != 0);

    return 0;
}