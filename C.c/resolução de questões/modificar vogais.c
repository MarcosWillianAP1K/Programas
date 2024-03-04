#include <stdio.h>
#include <string.h>

void troca(char *pvetor, char troca)
{
    *pvetor = troca;
}

void pecorrer_vetor(char *pvetor, char const *pvetorfinal)
{
    for (pvetor = pvetor; pvetor < pvetorfinal; ++pvetor)
    {
        if (*pvetor == 'a')
        {
            troca(pvetor, 'u');
        }
        else if (*pvetor == 'A')
        {
            troca(pvetor, 'U');
        }
        else if (*pvetor == 'e')
        {
            troca(pvetor, 'o');
        }
        else if (*pvetor == 'E')
        {
            troca(pvetor, 'O');
        }
        else if (*pvetor == 'i')
        {
            troca(pvetor, 'u');
        }
        else if (*pvetor == 'I')
        {
            troca(pvetor, 'U');
        }
        else if (*pvetor == 'o')
        {
            troca(pvetor, 'a');
        }
        else if (*pvetor == 'O')
        {
            troca(pvetor, 'A');
        }
        else if (*pvetor == 'u')
        {
            troca(pvetor, 'e');
        }
        else if (*pvetor == 'U')
        {
            troca(pvetor, 'E');
        }
    }
}

int main()
{
    char frase[100];

    fgets(frase, sizeof(frase), stdin);

    printf("\n%s\n", frase);

    pecorrer_vetor(frase, frase + strlen(frase) - 1);

    printf("\n%s\n", frase);

    return 0;
}