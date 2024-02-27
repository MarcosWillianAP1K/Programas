#include <stdio.h>

int main()
{

    struct horario
    {
        int *phora, *pminuto, *psegundo;
    };

    struct horario hoje;

    int hora = 200, minuto = 300, segundo = 400;

    // colocar endereço nos ponteiros dentro do struct
    hoje.phora = &hora;
    hoje.pminuto = &minuto;
    hoje.psegundo = &segundo;

    // printar o valor do ponteiro dentro do struct
    printf("%d:%d:%d\n\n", *hoje.phora, *hoje.pminuto, *hoje.psegundo);

    // printar o endereço de memoria do ponteiro dentro do struct
    printf("%d:%d:%d", hoje.phora, hoje.pminuto, hoje.psegundo);

    return 0;
}