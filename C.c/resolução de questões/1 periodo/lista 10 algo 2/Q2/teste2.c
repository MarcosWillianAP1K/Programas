#include <stdio.h>
#include <Windows.h>
#include <stdbool.h>
#include <stdlib.h>

int main()
{
    int timer = 0;

    while (timer != 10)
    {

        printf("\rArquivo nao existe, esta sendo criado um novo, aguarde      ");
        fflush(stdout);
        printf("\rArquivo nao existe, esta sendo criado um novo, aguarde");
        fflush(stdout);

        for (int i = 0; i < 3; i++)
        {
            printf(" .");
            fflush(stdout);
            Sleep(250);
        }
        timer++;
    }

    return 0;
}