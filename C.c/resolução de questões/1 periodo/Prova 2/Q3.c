#include <stdio.h>

#define entrada "entrada.txt"
#define saida "saida.txt"

FILE *ent, *sai;

int segundos_entrada, seg = 0, min = 0, hrs = 0;

void criar_arq()
{
    ent = fopen(entrada, "a");
    fclose(ent);

    sai = fopen(saida, "a");
    fclose(sai);
}

void conversor()
{
    while (segundos_entrada >= 60)
    {
        min++;
        segundos_entrada -= 60;
    }

    seg = segundos_entrada;

    while (min >= 60)
    {
        hrs++;
        min -= 60;
    }
}

int main()
{
    criar_arq();

    ent = fopen(entrada, "r");

    fscanf(ent, "%d\n", &segundos_entrada);

    fclose(ent);

    conversor();

    sai = fopen(saida, "w");

    fprintf(sai, "%d : %d : %d ", hrs, min, seg);

    fclose(sai);

    return 0;
}