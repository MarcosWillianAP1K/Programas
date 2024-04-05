#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int moeda()
{
    return rand() % 2;
}

int main()
{
    srand(time(NULL));

    int cara = 0, coroa = 0;

    for (int i = 0; i < 100; i++)
    {
        printf("%d = ", i + 1);

        if (moeda() == 0)
        {
            coroa++;
            printf("coroa\n");
        }
        else
        {
            cara++;
            printf("cara\n");
        }
    }

    printf("\n\nTeve %d caras e %d coroas\n\n", cara, coroa);

    return 0;
}