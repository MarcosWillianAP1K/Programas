#include <stdio.h>

int main()
{

    // difenrença entre x++; e ++x;
    // a difença esta na ordem de acontecimentos,
    // o primeiro ver a variavel e depois encremente, o segundo encrementa e depois ver a variavel

    int x = 1, y = 0;

    y = x++;

    // serio o mesmo que:
    // y = x;
    // x = x + 1;

    printf("%d\n%d\n\n", y, x);

    x = 1;
    y = 0;

    y = ++x;

    // serio o mesmo que:
    // x = x + 1;
    // y = x;

    printf("%d\n%d", y, x);
}