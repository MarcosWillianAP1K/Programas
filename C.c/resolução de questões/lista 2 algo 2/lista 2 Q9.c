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

void arruma_digitacao(int *pd, int *pv)
{
    int tam = 0;    

    contador_de_algarismo(&tam, *pv);

    printf("\n%d", *pd);

    char vstring[tam];
    printf("\n%d", tam);

    sprintf(vstring, "%d", *pv);

    printf("\n%s", vstring);

    for (int i = 0; i < tam; i++)
    {
        //sa desgraça de if n funciona
        if (vstring[i] == '7')
        {
            vstring[i] = '\0';
            printf("\ndeu bom");
        }
    }

    printf("\n%s\n", vstring);

    *pv = (int)strtol(vstring, NULL, 10);
    
}

int main()
{
    int d, v;

    printf("Digite a tecla defeituosa e em seguida o numero digitado\n\n");

    do
    {
        scanf("%d %d", &d, &v);

        if (d != 0 || v != 0)
        {
            arruma_digitacao(&d, &v);

            printf("valor %d\n\n", v);
        }

    } while (d != 0 || v != 0);

    return 0;
}