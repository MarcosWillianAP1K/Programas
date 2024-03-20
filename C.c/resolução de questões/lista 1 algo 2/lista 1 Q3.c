#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{

    char menu;
    int menu2;
    float valor;

    do
    {
        system("cls||clear");
        printf("======MENUUUU======");
        printf("\nSelecione a regiao que desejas ir\n\n");
        printf("A-Regiao Norte\nB-Regiao nordeste\nC-Centro-Oeste\nD-Regiao Sul\nE-Sair\n");
        fflush(stdin);
        scanf("%c", &menu);
        fflush(stdin);

        menu = toupper(menu);

        if (menu == 'A' || menu == 'B' || menu == 'C' || menu == 'D')
        {
            do
            {
                system("cls||clear");

                printf("\n0-Ida\n1-Ida e volta\n");
                if (scanf("%d", &menu2) == 1)
                {
                }
                else
                {
                    printf("\nOpcao errada\n");
                    fflush(stdin);
                    system("pause");
                }
            } while (menu2 != 0 && menu2 != 1);
        }

        switch (menu)
        {
        case 'A':
            if (menu2 == 0)
            {
                valor = 500;
            }
            else
            {
                valor = 900;
            }
            break;

        case 'B':
            if (menu2 == 0)
            {
                valor = 350;
            }
            else
            {
                valor = 650;
            }
            break;

        case 'C':
            if (menu2 == 0)
            {
                valor = 350;
            }
            else
            {
                valor = 600;
            }
            break;

        case 'D':
            if (menu2 == 0)
            {
                valor = 300;
            }
            else
            {
                valor = 550;
            }
            break;

        case 'E':
            break;

        default:
            printf("\nOpcao errada\n");
            system("pause");
            break;
        }

        if (menu == 'A' || menu == 'B' || menu == 'C' || menu == 'D')
        {
            printf("\nSeu valor Final e %.2f\n", valor);
            system("pause");
        }

    } while (menu != 'E');

    return 0;
}