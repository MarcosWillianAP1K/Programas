#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Y 22
#define X 22

int mat[Y][X], game_over = 0, a = Y / 2, l = X / 2, direcao_atual = 0, fruta = 0, tam_cobra = 1;

void printar_matriz()
{

    for (int i = 0; i < Y; i++)
    {
        for (int j = 0; j < X; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

void printar_game()
{

    for (int i = 0; i < Y; i++)
    {
        for (int j = 0; j < X; j++)
        {
            if (mat[i][j] == 0)
            {
                printf("# ");
            }
            if (mat[i][j] == 1)
            {
                printf("  ");
            }
            if (mat[i][j] == 3)
            {
                printf("O ");
            }
            if (mat[i][j] > 3)
            {
                printf("o ");
            }
            
            if (mat[i][j] == 2)
            {
                printf("& ");
            }
        }
        printf("\n");
    }
}

void spawn_fruta()
{
    int x, y;
    if (fruta == 0 && tam_cobra < (X * Y) - ((X + Y) * 2))
    {
        do
        {
            srand(time(NULL));
            x = rand() % X;
            y = rand() % Y;

        } while (mat[y][x] != 1);

        fruta++;
        mat[y][x] = 2;
    }
}

void preencher_inicial()
{
    for (int i = 0; i < Y; i++)
    {
        for (int j = 0; j < X; j++)
        {
            if (i == 0 || j == 0 || i == Y - 1 || j == X - 1)
            {
                mat[i][j] = 0;
            }
            else
            {
                mat[i][j] = 1;

                if (i == Y / 2 && j == X / 2)
                {
                    mat[i][j] = 3;
                }
            }
        }
    }
}

void movimento_do_corpo()
{

    int x = a, y = l, c = 3, aux;

    for (int i = 1; i < tam_cobra; i++)
    {
        //direçao 1
        if (mat[x][y - 1] == c + 1)
        {
            aux = mat[x][y];
            mat[x][y] = mat[x][y - 1];
            mat[x][y - 1] = aux;
            y--;
            c++;
        }

        //direçao 2
        if (mat[x - 1][y] == c + 1)
        {
            aux = mat[x][y];
            mat[x][y] = mat[x - 1][y];
            mat[x - 1][y] = aux;
            x--;
            c++;
        }

        //direçao 3
        if (mat[x + 1][y] == c + 1)
        {
            aux = mat[x][y];
            mat[x][y] = mat[x + 1][y];
            mat[x + 1][y] = aux;
            x++;
            c++;
        }

        //direçao 4
        if (mat[x][y + 1] == c + 1)
        {
            aux = mat[x][y];
            mat[x][y] = mat[x][y + 1];
            mat[x][y + 1] = aux;
            y++;
            c++;
        }
    }
}

void movimento_da_cobra()
{
    int aux;

    if (direcao_atual == 1)
    {
        if (mat[a][l - 1] != 1 && mat[a][l - 1] != 2)
        {
            game_over++;
        }
        if (mat[a][l - 1] == 2)
        {
            mat[a][l - 1] = tam_cobra + 3;
            tam_cobra++;
            fruta = 0;
        }

        aux = mat[a][l];
        mat[a][l] = mat[a][l - 1];
        mat[a][l - 1] = aux;

        movimento_do_corpo();

        l--;
    }

    if (direcao_atual == 2)
    {
        if (mat[a - 1][l] != 1 && mat[a - 1][l] != 2)
        {
            game_over++;
        }
         if (mat[a - 1][l] == 2)
        {
            mat[a - 1][l] = tam_cobra + 3;
            tam_cobra++;
            fruta = 0;
        }

        aux = mat[a][l];
        mat[a][l] = mat[a - 1][l];
        mat[a - 1][l] = aux;
       
        movimento_do_corpo();

        a--;
    }

    if (direcao_atual == 3)
    {
        if (mat[a + 1][l] != 1 && mat[a + 1][l] != 2)
        {
            game_over++;
        }
        if (mat[a + 1][l] == 2)
        {
            mat[a + 1][l] = tam_cobra + 3;
            tam_cobra++;
            fruta = 0;
        }

        aux = mat[a][l];
        mat[a][l] = mat[a + 1][l];
        mat[a + 1][l] = aux;

        movimento_do_corpo();

        a++;
    }

    if (direcao_atual == 4)
    {
        if (mat[a][l + 1] != 1 && mat[a][l + 1] != 2)
        {
            game_over++;
        }
        if (mat[a][l + 1] == 2)
        {
            mat[a][l + 1] = tam_cobra + 3;
            tam_cobra++;
            fruta = 0;
        }

        aux = mat[a][l];
        mat[a][l] = mat[a][l + 1];
        mat[a][l + 1] = aux;

        movimento_do_corpo();

        l++;
    }
}

void digitar_direcao()
{

    char direcao_aux;

    fflush(stdin);
    if (_kbhit())
    {
        direcao_aux = _getch();

        fflush(stdin);

        if ((direcao_aux == 'A' || direcao_aux == 'a') && direcao_atual != 4)
        {
            direcao_atual = 1;
        }

        if ((direcao_aux == 'W' || direcao_aux == 'w') && direcao_atual != 3)
        {
            direcao_atual = 2;
        }

        if ((direcao_aux == 'S' || direcao_aux == 's') && direcao_atual != 2)
        {
            direcao_atual = 3;
        }

        if ((direcao_aux == 'D' || direcao_aux == 'd') && direcao_atual != 1)
        {
            direcao_atual = 4;
        }
    }
}

int main()
{

    preencher_inicial();

    do
    {

        printar_game();

        digitar_direcao();

        movimento_da_cobra();

        spawn_fruta();

        system("cls||clear");
    } while (game_over == 0 && tam_cobra < (X * Y) - ((X + Y) * 2));

    if (game_over != 0)
    {
        printf("PERDEU BOBAO, SEU NOOB.");
    }
    if (tam_cobra >= (X * Y) - ((X + Y) * 2))
    {
        printf("GANHOU, A MISERAVEL.");
    }

    return 0;
}