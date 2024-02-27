#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

// Definição dos tamanhos
#define TAM_COD 5
#define TAM_NOME 50
#define TAM_ESTOQUE 10
#define TAM_USUARIO 20
#define TAM_SENHA 10
#define TAM_USU_CAD 10

time_t tempoAtual;
struct tm *infoTempo;

// varivel da data
int data_atual[3];

// n responvel pela posição do struct do estoque, u pela posição do struct do usuario, e o p_u e responsavel para saber qual usario esta logado, sendo ela o valor da posição desse usuario
int n = 0, u = 0 + 2, p_u;

// armazenamento e declaração dos dados do estoque
struct estoque
{
    char nome[TAM_NOME + 1];
    char codigo[TAM_COD + 1];
    float preco;
    int datafab[3], dataval[3];
    int quant;
};
struct estoque e[TAM_ESTOQUE];

// armazenamento e declaração dos dados dos usuarios
// detalhe, o tipo se refere a adm e cliente, sendo 1= adm e 2=cliente
struct usuario
{
    char usuario[TAM_USUARIO + 1];
    char senha[TAM_SENHA + 1];
    float saldo;
    int tipo;
};
struct usuario usu[TAM_USU_CAD];

void tira_n(char string[])
{
    // essa função é responvel para tira o \n que o fgets coloca, em todo fgets eu chamo ela

    // caso a string seja diferente de nada
    if (string != NULL)
    {
        // se a ultima posição escrita seja um \n, substitui por \0
        if (strlen(string) > 0 && string[strlen(string) - 1] == '\n')
        {
            string[strlen(string) - 1] = '\0';
        }
    }
}

int verificar_vencimento(int dia, int mes, int ano)
{
    //aqui verificamos se a data de validade ja venceu, sendo o teste 0 para nao venceu e teste diferente de 0 venceu
    int teste = 0;

    if (ano < data_atual[2])
    {
        teste++;
    }
    if (mes < data_atual[1] && ano == data_atual[2])
    {
        teste++;
    }
    if (dia < data_atual[0] && mes == data_atual[1] && ano == data_atual[2])
    {
        teste++;
    }

    return teste;
}

int verificar_data_fab(int dia, int mes, int ano, int id, int p)
{
    //verifica se a data e valida, ou seja se existe 
    int teste = 0, menu, a = 0;

    if (dia > 0 && dia < 32)
    {

        if (mes > 0 && mes < 13)
        {
            if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia == 31)
            {
                teste++;
            }
            else if (mes == 2 && dia > 29)
            {
                teste++;
            }
            else
            {
                if (mes == 2 && dia == 29 && ano % 4 != 0)
                {
                    teste++;
                }

                //no caso da fabricação tem q ser igual ou menor a data atual
                if (ano > data_atual[2])
                {
                    teste++;
                }
                else if (mes > data_atual[1] && ano == data_atual[2])
                {
                    teste++;
                }
                else if (dia > data_atual[0] && mes == data_atual[1] && ano == data_atual[2])
                {
                    teste++;
                }

                //o id e resposavel por verificar se a data de fab passa da data de val, caso seja 0 sera testadom caso contrario nao
                //isso pq no cadastro, e digitado a fab primeiro, então não temos ainda validade, para evitar aparecer o menu com 00/00/0000, coloquei essa condição
                if (id == 0)
                {
                    if (ano > e[p].dataval[2])
                    {
                        a++;
                    }
                    if (mes > e[p].dataval[1] && ano == e[p].dataval[2])
                    {
                        a++;
                    }
                    if (dia > e[p].dataval[0] && mes == e[p].dataval[1] && ano == e[p].dataval[2])
                    {
                        a++;
                    }

                    if (a != 0)
                    {
                        do
                        {
                            system("cls||clear");
                            printf("\nA data %02d/%02d/%04d esta a frente da data de validade %02d/%02d/%04d.\nTem certeza que deseja manter?\n\n1-Sim\n2-Nao\n", dia, mes, ano, e[p].dataval[0], e[p].dataval[1], e[p].dataval[2]);
                            scanf("%d", &menu);

                            switch (menu)
                            {
                            case 1:

                                break;
                            case 2:
                                teste++;
                                break;

                            default:
                                printf("\nOpcao errada.");
                                system("pause");
                                break;
                            }
                        } while (menu != 1 && menu != 2);
                    }
                }
            }
        }
        else
        {
            teste++;
        }
    }
    else
    {
        teste++;
    }

    return teste;
}

int verificar_data_val(int dia, int mes, int ano, int p)
{
//verifica se a data e valida
    int teste = 0, menu, a = 0;

    if (dia > 0 && dia < 32)
    {

        if (mes > 0 && mes < 13)
        {
            if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia == 31)
            {
                teste++;
            }
            else if (mes == 2 && dia > 29)
            {
                teste++;
            }
            else
            {
                if (mes == 2 && dia == 29 && ano % 4 != 0)
                {
                    teste++;
                }
                else
                {
                    //diferente da fab aqui ja testa direto se a validade e inferio a fabricação, isso pq em ambos caso pelo editar ou cadastra ja temos a fabricação
                    if (ano < e[p].datafab[2])
                    {
                        a++;
                    }
                    if (mes < e[p].datafab[1] && ano == e[p].datafab[2])
                    {
                        a++;
                    }
                    if (dia < e[p].datafab[0] && mes == e[p].datafab[1] && ano == e[p].datafab[2])
                    {
                        a++;
                    }

                    if (a != 0)
                    {
                        do
                        {
                            system("cls||clear");
                            printf("\nA data %02d/%02d/%04d esta atras da data de fabricacao %02d/%02d/%04d.\nTem certeza que deseja manter?\n\n1-Sim\n2-Nao\n", dia, mes, ano, e[p].datafab[0], e[p].datafab[1], e[p].datafab[2]);
                            scanf("%d", &menu);

                            switch (menu)
                            {
                            case 1:

                                break;
                            case 2:
                                teste++;
                                break;

                            default:
                                printf("\nOpcao errada.");
                                system("pause");
                                break;
                            }
                        } while (menu != 1 && menu != 2);
                    }
                }
            }
        }
        else
        {
            teste++;
        }
    }
    else
    {
        teste++;
    }

    return teste;
}

int editar_compra(int p)
{
    // apenas um menu para adms, quando selecionado um produto é perguntado se deseja compra ou editar
    int menu;

    do
    {
        system("cls||clear");

        printf("Produto: %s\nCodigo: %s\nPreco: %.2f\nFabricacao: %02d/%02d/%04d\nValidade: %02d/%02d/%04d\nQuantidade: %d\n\n", e[p].nome, e[p].codigo, e[p].preco, e[p].datafab[0], e[p].datafab[1], e[p].datafab[2], e[p].dataval[0], e[p].dataval[1], e[p].dataval[2], e[p].quant);
        printf("Deseja compra ou editar o produto?\n1-Compra\n2-Editar\n");

        if (scanf("%d", &menu) == 1)
        {
            switch (menu)
            {
            case 1:
                break;
            case 2:
                break;
            default:
                printf("Opcao errada\n\n");
                system("pause");
                break;
            }
        }
        else
        {
            fflush(stdin);
            printf("Opcao errada\n\n");
            system("pause");
        }

    } while (menu != 1 && menu != 2);

    return menu;
}

void editar_produto(int p)
{
    // na função editar podemos editar as informações do produto selecionado, caso seja valida, sera sunstitiuida
    //ela faz os mesmos testes encontrados na função cadastra
    int menu, dia, mes, ano, teste, quant_aux;
    float preco_aux;
    char nome_aux[TAM_NOME + 2], cod_aux[TAM_COD + 2];

    do
    {
        teste = 0;

        system("cls||clear");

        printf("Produto: %s\nCodigo: %s\nPreco: %.2f\nFabricacao: %02d/%02d/%04d\nValidade: %02d/%02d/%04d\nQuantidade: %d\n\n", e[p].nome, e[p].codigo, e[p].preco, e[p].datafab[0], e[p].datafab[1], e[p].datafab[2], e[p].dataval[0], e[p].dataval[1], e[p].dataval[2], e[p].quant);
        printf("Oque editar?\n1-Nome\n2-Codigo\n3-Preco\n4-Data de fabricao\n5-Data de validade\n6-quantidade\n7-voltar\n");

        if (scanf("%d", &menu) == 1)
        {
            switch (menu)
            {
            case 1:
                printf("\nEditando...\n");

                fflush(stdin);
                fgets(nome_aux, sizeof(nome_aux), stdin);
                tira_n(nome_aux);
                fflush(stdin);

                if (strlen(nome_aux) < TAM_NOME + 1 && strlen(nome_aux) > 0)
                {
                    sprintf(e[p].nome, nome_aux);
                }

                if (strlen(nome_aux) > TAM_NOME)
                {
                    printf("\nNome muito grande, nao e possivel substituir\n\n");
                    system("pause");
                }

                if (strlen(nome_aux) == 0)
                {
                    printf("\nCampo de escrita vazio, nao e possivel substituir");
                    system("pause");
                }

                break;
            case 2:
                printf("\nEditando...\n");

                fflush(stdin);
                fgets(cod_aux, sizeof(cod_aux), stdin);
                tira_n(cod_aux);
                fflush(stdin);

                if (strlen(cod_aux) < TAM_COD + 1 && strlen(cod_aux) > 0)
                {
                    for (int i = 0; i < n; i++)
                    {
                        if (strcmp(cod_aux, e[i].codigo) == 0 && i != p)
                        {
                            teste++;
                        }
                    }

                    if (teste == 0)
                    {
                        sprintf(e[p].codigo, cod_aux);
                    }
                }

                if (strlen(cod_aux) > TAM_NOME)
                {
                    printf("\ncodigo muito grande, nao é possivel substituir\n\n");
                    system("pause");
                }

                if (strlen(cod_aux) == 0)
                {
                    printf("\nCampo de escrita vazio, nao e possivel substituir");
                    system("pause");
                }
                break;
            case 3:
                printf("\nEditando...\n");

                if (scanf("%f", &preco_aux) == 1)
                {
                    e[p].preco = preco_aux;
                }
                else
                {
                    fflush(stdin);
                    printf("\nPreco invalida, nao foi possivel substituir\n");
                    system("pause");
                }
                break;
            case 4:
                printf("\nEditando...\n");

                printf("Dia\n");

                if (scanf("%d", &dia) == 1)
                {
                    printf("\nMes\n");

                    if (scanf("%d", &mes) == 1)
                    {
                        printf("\nAno\n");

                        if (scanf("%d", &ano) == 1)
                        {
                            teste = verificar_data_fab(dia, mes, ano, 0, p);
                        }
                        else
                        {
                            fflush(stdin);
                            teste++;
                        }
                    }
                    else
                    {
                        fflush(stdin);
                        teste++;
                    }
                }
                else
                {
                    fflush(stdin);
                    teste++;
                }

                if (teste != 0)
                {
                    printf("\nData invalida, nao foi possivel modificar\n\n");
                    system("pause");
                }
                else
                {
                    e[p].datafab[0] = dia;
                    e[p].datafab[1] = mes;
                    e[p].datafab[2] = ano;
                }
                break;
            case 5:
                printf("\nEditando...\n");

                printf("Dia\n");

                if (scanf("%d", &dia) == 1)
                {
                    printf("\nMes\n");

                    if (scanf("%d", &mes) == 1)
                    {
                        printf("\nAno\n");

                        if (scanf("%d", &ano) == 1)
                        {
                            teste = verificar_data_val(dia, mes, ano, p);
                        }
                        else
                        {
                            fflush(stdin);
                            teste++;
                        }
                    }
                    else
                    {
                        fflush(stdin);
                        teste++;
                    }
                }
                else
                {
                    fflush(stdin);
                    teste++;
                }

                if (teste != 0)
                {
                    printf("\nData invalida, nao foi possivel modificar\n\n");
                    system("pause");
                }
                else
                {
                    e[p].dataval[0] = dia;
                    e[p].dataval[1] = mes;
                    e[p].dataval[2] = ano;
                }
                break;
            case 6:
                printf("\nEditando...\n");

                if (scanf("%d", &quant_aux) == 1)
                {
                    if (e[p].quant < 0)
                    {
                        printf("\nQuantidade invalida, nao foi possivel substituir\n");
                        system("pause");
                    }
                    else
                    {
                        e[p].quant = quant_aux;
                    }
                }
                else
                {
                    fflush(stdin);
                    printf("\nQuantidade invalida, nao foi possivel substituir\n");
                    system("pause");
                }
                break;
            case 7:
                break;
            default:
                printf("\nOpcao errada\n\n");
                system("pause");
                break;
            }
        }
        else
        {
            fflush(stdin);
            printf("Opcao errada\n\n");
            system("pause");
        }
    } while (menu != 7);
}

int editar_usuario(int p)
{
    // na função editar podemos editar as informações do usuario, caso seja valida, sera sunstitiuida
    //ela faz os mesmos testes encontrados na função cadastra
    int menu, teste, menu2, volta_tudo = 0, t;
    char usuario_aux[TAM_USUARIO + 2], senha_aux[TAM_SENHA + 2];

    do
    {
        system("cls||clear");
        printf("Usuario: %s\nSenha: %s\nSaldo: %.2f Reais\nTipo: ", usu[p].usuario, usu[p].senha, usu[p].saldo);
        if (usu[p].tipo == 1)
        {
            printf("Adiministrador\n");
        }
        else
        {
            printf("Cliente\n");
        }
        printf("\nOque deseja editar?\n1-Usuario\n2-Senha\n3-Tipo da conta\n4-voltar\n");

        if (scanf("%d", &menu) == 1)
        {
            switch (menu)
            {
            case 1:
                teste = 0;

                printf("Editando...\n");

                fflush(stdin);
                fgets(usuario_aux, sizeof(usuario_aux), stdin);
                tira_n(usuario_aux);
                fflush(stdin);

                if (strlen(usuario_aux) > TAM_USUARIO || strlen(usuario_aux) == 0)
                {
                    teste++;
                }

                t = strlen(usuario_aux);

                for (int i = 0; i < t; i++)
                {
                    if (usuario_aux[i] == ' ')
                    {
                        teste++;
                    }
                }

                for (int i = 0; i < u; i++)
                {
                    if (strcmp(usuario_aux, usu[i].usuario) == 0)
                    {
                        teste++;
                    }
                }

                if (teste == 0)
                {
                    sprintf(usu[p].usuario, usuario_aux);
                }
                else
                {
                    printf("\nUsuario invalido ou ja existe, nao é possivel substituir\n\n");
                    system("pause");
                }

                break;
            case 2:

                teste = 0;

                printf("\nEditando...\n");

                fflush(stdin);
                fgets(senha_aux, sizeof(senha_aux), stdin);
                tira_n(senha_aux);
                fflush(stdin);

                if (strlen(senha_aux) > TAM_SENHA || strlen(senha_aux) == 0)
                {
                    teste++;
                }

                t = strlen(senha_aux);

                for (int i = 0; i < t; i++)
                {
                    if (senha_aux[i] == ' ')
                    {
                        teste++;
                    }
                }

                if (teste == 0)
                {
                    sprintf(usu[p].senha, senha_aux);
                }
                else
                {
                    printf("\nSenha invalida, digite novamente\n");
                    system("pause");
                }
                break;

            case 3:

                printf("\nEditando...");
                printf("\n1-Administador\n2-Cliente\n");

                if (scanf("%d", &menu) == 1)
                {
                    switch (menu)
                    {
                    case 1:
                        usu[p].tipo = 1;
                        break;

                    case 2:
                        if (p == p_u && usu[p].tipo == 1)
                        {
                            printf("\nATENCAO:\nA conta em questao e do tipo administradora\ncaso voce troque para cliente apos sair nao tera\n acesso a opcoes de administradores e tera que usar\noutra conta para voltar para adiministrador.\n\nDeseja continuar?\n");
                            printf("1-Sim\n2-Nao\n");

                            if (scanf("%d", &menu2) == 1)
                            {
                                if (menu2 == 1)
                                {
                                    volta_tudo = 1;
                                    usu[p].tipo = 2;
                                }
                            }
                            else
                            {
                                fflush(stdin);
                                printf("Opcao errada\n\n");
                                system("pause");
                            }
                        }
                        else
                        {
                            usu[p].tipo = 2;
                        }
                        break;

                    default:
                        printf("Opcao errada\n\n");
                        system("pause");
                        break;
                    }
                }
                else
                {
                    fflush(stdin);
                    printf("Opcao errada\n\n");
                    system("pause");
                }

                break;

            case 4:
                break;

            default:
                printf("Opcao errada\n\n");
                system("pause");
                break;
            }
        }
        else
        {
            fflush(stdin);
            printf("Opcao errada\n\n");
            system("pause");
        }

    } while (menu != 4 && volta_tudo != 1);

    system("cls||clear");

    return volta_tudo;
}

void remover_produto(int p)
{

    if (p < n - 1)
    {

        // Bubble movendo ate a ultima posicao
        for (int i = p; i < n; i++)
        {
            // nome
            sprintf(e[i].nome, e[i + 1].nome);

            // codigo
            sprintf(e[i].codigo, e[i + 1].codigo);

            // preço
            e[i].preco = e[i + 1].preco;

            // data fabricação
            // dia
            e[i].datafab[0] = e[i + 1].datafab[0];

            // mes
            e[i].datafab[1] = e[i + 1].datafab[1];

            // ano
            e[i].datafab[2] = e[i + 1].datafab[2];

            // data de validade
            // dia
            e[i].dataval[0] = e[i + 1].dataval[0];

            // mes
            e[i].dataval[1] = e[i + 1].dataval[1];

            // ano
            e[i].dataval[2] = e[i + 1].dataval[2];

            // quantidade
            e[i].quant = e[i + 1].quant;
        }
    }
    n--;
}

void remover_usuario(int p)
{
    if (p < u - 1)
    {
        // Bubble movendo ate a ultima posição
        for (int i = p; i < u; i++)
        {
            // usuario
            sprintf(usu[i].usuario, usu[i + 1].usuario);

            // senha
            sprintf(usu[i].senha, usu[i + 1].senha);

            // saldo
            usu[i].saldo = usu[i + 1].saldo;

            // tipo do usuario
            usu[i].tipo = usu[i + 1].tipo;
        }
    }
    u--;
}

void compra_produto(int p)
{
//permite compra o produto selecionado
    int quant_aux, menu;

    do
    {
        system("cls||clear");
        printf("Saldo: %.2f Reais\n\n", usu[p_u].saldo);
        printf("Produto: %s\nCodigo: %s\nPreco: %.2f\nFabricacao: %02d/%02d/%04d\nValidade: %02d/%02d/%04d\nQuantidade: %d\n\n", e[p].nome, e[p].codigo, e[p].preco, e[p].datafab[0], e[p].datafab[1], e[p].datafab[2], e[p].dataval[0], e[p].dataval[1], e[p].dataval[2], e[p].quant);
        printf("Deseja compra quantas unidades/peso?\n");

        if (scanf("%d", &quant_aux) == 1)
        {
            if (quant_aux <= e[p].quant && quant_aux >= 0)
            {
                printf("\nTOTAL: %.2f", quant_aux * e[p].preco);
                printf("\nDesejas continuar?\n1-Sim\n2-Nao\n");

                if (scanf("%d", &menu) == 1)
                {
                    if (menu == 1)
                    {
                        if (usu[p_u].saldo >= (quant_aux * e[p].preco))
                        {
                            e[p].quant -= quant_aux;
                            usu[p_u].saldo -= (quant_aux * e[p].preco);
                        }
                        else
                        {
                            printf("\nSaldo insuficiente\n");
                            system("pause");
                        }
                    }
                }
                else
                {
                    fflush(stdin);
                    printf("Opcao errada\n\n");
                    system("pause");
                }
            }
            else
            {
                printf("\nValor invalido\n");
                system("pause");
            }
        }
        else
        {
            fflush(stdin);
            printf("\nValor invalido\n\n");
            system("pause");
        }
    } while ((quant_aux < 0 && quant_aux > e[p].quant) || (menu != 1 && menu != 2));

    system("cls||clear");
}

void confirma_produto(int p)
{
    // essa função mostra o produto selecionado ou cadastrado caso seje chamada pelo cadastro
    // nela tem acesso a confirma alteração/cadastro, editar e remover
    int menu;

    do
    {
        system("cls||clear");

        printf("Produto: %s\nCodigo: %s\nPreco: %.2f\nFabricacao: %02d/%02d/%04d\nValidade: %02d/%02d/%04d\nQuantidade: %d\n\n", e[p].nome, e[p].codigo, e[p].preco, e[p].datafab[0], e[p].datafab[1], e[p].datafab[2], e[p].dataval[0], e[p].dataval[1], e[p].dataval[2], e[p].quant);
        printf("1-Confirmar\n2-editar\n3-remover/excluir\n");

        if (scanf("%d", &menu) == 1)
        {
            system("cls||clear");

            switch (menu)
            {
            case 1:

                break;
            case 2:
                editar_produto(p);
                break;
            case 3:
                remover_produto(p);
                break;

            default:
                printf("Opcao errada\n\n");
                system("pause");
                break;
            }
        }
        else
        {
            fflush(stdin);
            printf("Opcao errada\n\n");
            system("pause");
        }
    } while (menu != 1 && menu != 3);
}

int confirma_usuario(int p)
{
    // semelhante a confirma produto, aqui tem acesso a editar, confirma e remover usuario
    int menu, menu2, volta_tudo = 0;

    do
    {
        system("cls||clear");
        printf("Usuario: %s\nSenha: %s\nSaldo: %.2f Reais\nTipo: ", usu[p].usuario, usu[p].senha, usu[p].saldo);
        if (usu[p].tipo == 1)
        {
            printf("Adiministrador\n");
        }
        else
        {
            printf("Cliente\n");
        }
        printf("\n1-Confirmar\n2-editar\n3-remover/excluir\n");

        if (scanf("%d", &menu) == 1)
        {
            switch (menu)
            {
            case 1:

                break;
            case 2:
                volta_tudo = editar_usuario(p);
                break;
            case 3:
                if (p_u == p)
                {
                    printf("\nO usuario e o mesmo em uso.");
                }

                printf("\nTem certeza que deseja remover o usuario?\n1-Sim\n2-Nao\n");

                if (scanf("%d", &menu2) == 1)
                {
                    if (menu2 == 1)
                    {
                        if (p_u == p)
                        {
                            volta_tudo = 1;
                        }
                        remover_usuario(p);
                    }
                }
                else
                {
                    fflush(stdin);
                    printf("Opcao errada\n\n");
                    system("pause");
                }
                break;

            default:
                printf("Opcao errada\n\n");
                system("pause");
                break;
            }
        }
        else
        {
            fflush(stdin);
            printf("Opcao errada\n\n");
            system("pause");
        }

    } while (menu != 1 && menu != 3 && volta_tudo != 1);
    system("cls||clear");

    return volta_tudo;
}

void printar_produto_ordem_cadastrada(int c, int vet[])
{
    system("cls||clear");
    int con = 0;

//caso c seja par printa na ordem crescente, caso seja impar inverte
    if (c % 2 == 0)
    {
        //pecorre o struct
        for (int i = 0; i < n; i++)
        {
            // condição para printar, caso seja adm ou se o produto não esta vencido, clientes não tem acesso a produtos vencidos
            if (usu[p_u].tipo == 1 || verificar_vencimento(e[i].dataval[0], e[i].dataval[1], e[i].dataval[2]) == 0)
            {
                printf("%d:\nProduto: %s\nCodigo: %s\nPreco: %.2f\nFabricacao: %02d/%02d/%04d\nValidade: %02d/%02d/%04d\nQuantidade: %d\n\n", con + 1, e[i].nome, e[i].codigo, e[i].preco, e[i].datafab[0], e[i].datafab[1], e[i].datafab[2], e[i].dataval[0], e[i].dataval[1], e[i].dataval[2], e[i].quant);
                //armazena a posição do produto
                vet[con] = i;
                con++;
            }
        }
    }
    else
    {
        for (int i = n - 1; i > -1; i--)
        {
            // condição para printar, caso seja adm ou se o produto não esta vencido, clientes não tem acesso a produtos vencidos
            if (usu[p_u].tipo == 1 || verificar_vencimento(e[i].dataval[0], e[i].dataval[1], e[i].dataval[2]) == 0)
            {  
                printf("%d:\nProduto: %s\nCodigo: %s\nPreco: %.2f\nFabricacao: %02d/%02d/%04d\nValidade: %02d/%02d/%04d\nQuantidade: %d\n\n", con + 1, e[i].nome, e[i].codigo, e[i].preco, e[i].datafab[0], e[i].datafab[1], e[i].datafab[2], e[i].dataval[0], e[i].dataval[1], e[i].dataval[2], e[i].quant);
                //armazena a posição do produto
                vet[con] = i;
                con++;
            }
        }
    }
}

void printar_produto_ordem_alfabetica(int c, int vet[])
{
    system("cls||clear");
    int tam = 0;
    char vet_aux[n][1], aux;

//aqui armazena as letras dos nomes do struct em um vetor, e não deixa com que as iguais seja repetidos
    for (int i = 0; i < n; i++)
    {

        vet_aux[tam][0] = e[i].nome[0];

        for (int j = 0; j < tam; j++)
        {
            if (vet_aux[j][0] == e[i].nome[0])
            {
                tam--;
            }
        }
        tam++;
    }

    //organiza em ordem alfabetica
    for (int i = 0; i < tam - 1; i++)
    {
        for (int j = 0; j < tam - i - 1; j++)
        {

            if (strcmp(vet_aux[j], vet_aux[j + 1]) > 0)
            {
                aux = vet_aux[j][0];
                vet_aux[j][0] = vet_aux[j + 1][0];
                vet_aux[j + 1][0] = aux;
            }
        }
    }

    int con = 0;

//caso c seja par printa na ordem crescente, caso seja impar inverte
    if (c % 2 == 0)
    {
        //pecorre o vetor auxiliar
        for (int i = 0; i < tam; i++)
        {
            //pecorre o struct
            for (int j = 0; j < n; j++)
            {
                //caso tenha a primeira letra igual printa
                if (vet_aux[i][0] == e[j].nome[0])
                {
                    // condição para printar, caso seja adm ou se o produto não esta vencido, clientes não tem acesso a produtos vencidos
                    if (usu[p_u].tipo == 1 || verificar_vencimento(e[j].dataval[0], e[j].dataval[1], e[j].dataval[2]) == 0)
                    {
                        printf("%d:\nProduto: %s\nCodigo: %s\nPreco: %.2f\nFabricacao: %02d/%02d/%04d\nValidade: %02d/%02d/%04d\nQuantidade: %d\n\n", con + 1, e[j].nome, e[j].codigo, e[j].preco, e[j].datafab[0], e[j].datafab[1], e[j].datafab[2], e[j].dataval[0], e[j].dataval[1], e[j].dataval[2], e[j].quant);
                        //armazena a posição do vetor
                        vet[con] = j;
                        con++;
                    }
                }
            }
        }
    }
    else
    {
        //pecorre o vetor auxiliar
        for (int i = tam - 1; i > -1; i--)
        {
            //pecorre o struct
            for (int j = n - 1; j > -1; j--)
            {
                //caso tenha a primeira letra igual printa
                if (vet_aux[i][0] == e[j].nome[0])
                {
                    // condição para printar, caso seja adm ou se o produto não esta vencido, clientes não tem acesso a produtos vencidos
                    if (usu[p_u].tipo == 1 || verificar_vencimento(e[j].dataval[0], e[j].dataval[1], e[j].dataval[2]) == 0)
                    {
                        
                        printf("%d:\nProduto: %s\nCodigo: %s\nPreco: %.2f\nFabricacao: %02d/%02d/%04d\nValidade: %02d/%02d/%04d\nQuantidade: %d\n\n", con + 1, e[j].nome, e[j].codigo, e[j].preco, e[j].datafab[0], e[j].datafab[1], e[j].datafab[2], e[j].dataval[0], e[j].dataval[1], e[j].dataval[2], e[j].quant);
                        //armazena a posição do vetor
                        vet[con] = j;
                        con++;
                    }
                }
            }
        }
    }
}

void printar_produto_ordem_preco(int c, int vet[])
{
    system("cls||clear");
    float vet_aux[n], aux;
    int min, tam = 0;

//aqui armazena os valores dos preços do struct em um vetor, e não deixa com que valores iguais seja repetidos
    for (int i = 0; i < n; i++)
    {
        vet_aux[tam] = e[i].preco;

        for (int j = 0; j < tam; j++)
        {
            if (vet_aux[j] == e[i].preco)
            {
                tam--;
            }
        }
        tam++;
    }

//organiza o vetor em crescente
    for (int i = 0; i < tam; i++)
    {
        min = i;

        for (int j = i + 1; j < tam; j++)
        {
            if (vet_aux[j] < vet_aux[min])
            {
                min = j;
            }
        }
        aux = vet_aux[i];
        vet_aux[i] = vet_aux[min];
        vet_aux[min] = aux;
    }

    int con = 0;

//caso c seja par printa na ordem crescente, caso seja impar inverte
    if (c % 2 == 0)
    {
        //pecorre o vetor auxiliar
        for (int i = 0; i < tam; i++)
        {
            //pecorre o struct
            for (int j = 0; j < n; j++)
            {
                //caso tenha um preço igual printa
                if (vet_aux[i] == e[j].preco)
                {
                    if (usu[p_u].tipo == 1 || verificar_vencimento(e[j].dataval[0], e[j].dataval[1], e[j].dataval[2]) == 0)
                    {
                        // condição para printar, caso seja adm ou se o produto não esta vencido, clientes não tem acesso a produtos vencidos
                        printf("%d:\nProduto: %s\nCodigo: %s\nPreco: %.2f\nFabricacao: %02d/%02d/%04d\nValidade: %02d/%02d/%04d\nQuantidade: %d\n\n", con + 1, e[j].nome, e[j].codigo, e[j].preco, e[j].datafab[0], e[j].datafab[1], e[j].datafab[2], e[j].dataval[0], e[j].dataval[1], e[j].dataval[2], e[j].quant);
                        //armazena a posição do produto
                        vet[con] = j;
                        con++;
                    }
                }
            }
        }
    }
    else
    {
        //pecorre o vetor auxiliar
        for (int i = tam - 1; i > -1; i--)
        {
            //pecorre o struct
            for (int j = n - 1; j > -1; j--)
            {
                //caso tenha um preço igual printa
                if (vet_aux[i] == e[j].preco)
                {
                    if (usu[p_u].tipo == 1 || verificar_vencimento(e[j].dataval[0], e[j].dataval[1], e[j].dataval[2]) == 0)
                    {
                        printf("%d:\nProduto: %s\nCodigo: %s\nPreco: %.2f\nFabricacao: %02d/%02d/%04d\nValidade: %02d/%02d/%04d\nQuantidade: %d\n\n", con + 1, e[j].nome, e[j].codigo, e[j].preco, e[j].datafab[0], e[j].datafab[1], e[j].datafab[2], e[j].dataval[0], e[j].dataval[1], e[j].dataval[2], e[j].quant);
                        //armazena a posição do produto
                        vet[con] = j;
                        con++;
                    }
                }
            }
        }
    }
}

void printar_produto_ordem_quantidade(int c, int vet[])
{
    system("cls||clear");
    int vet_aux[n], aux, min, tam = 0;

    //aqui armazena os valores da quantidade do struct em um vetor, e não deixa com que valores iguais seja repetidos
    for (int i = 0; i < n; i++)
    {
        vet_aux[tam] = e[i].quant;

        for (int j = 0; j < tam; j++)
        {
            if (vet_aux[j] == e[i].quant)
            {
                tam--;
            }
        }
        tam++;
    }

    //organiza o vetor em crescente
    for (int i = 0; i < tam - 1; i++)
    {
        min = i;

        for (int j = i + 1; j < tam; j++)
        {
            if (vet_aux[j] < vet_aux[min])
            {
                min = j;
            }
        }
        aux = vet_aux[i];
        vet_aux[i] = vet_aux[min];
        vet_aux[min] = aux;
    }

    int con = 0;
    
    //caso c seja par printa na ordem crescente, caso seja impar inverte
    if (c % 2 == 0)
    {   
        //pecorre o vetor auxiliar
        for (int i = 0; i < tam; i++)
        {   
            //pecorre struct
            for (int j = 0; j < n; j++)
            {   
                //caso tenha um quantidade igual printa
                if (vet_aux[i] == e[j].quant)
                {
                    // condição para printar, caso seja adm ou se o produto não esta vencido, clientes não tem acesso a produtos vencidos
                    if (usu[p_u].tipo == 1 || verificar_vencimento(e[j].dataval[0], e[j].dataval[1], e[j].dataval[2]) == 0)
                    {
                        printf("%d:\nProduto: %s\nCodigo: %s\nPreco: %.2f\nFabricacao: %02d/%02d/%04d\nValidade: %02d/%02d/%04d\nQuantidade: %d\n\n", con + 1, e[j].nome, e[j].codigo, e[j].preco, e[j].datafab[0], e[j].datafab[1], e[j].datafab[2], e[j].dataval[0], e[j].dataval[1], e[j].dataval[2], e[j].quant);
                        //armazena a posição do produto
                        vet[con] = j;
                        con++;
                    }
                }
            }
        }
    }
    else
    {
        //pecorre o vetor auxiliar
        for (int i = tam - 1; i > -1; i--)
        {
            //pecorre struct
            for (int j = n - 1; j >= 0; j--)
            {
                //caso tenha um quantidade igual printa
                if (vet_aux[i] == e[j].quant)
                {
                    // condição para printar, caso seja adm ou se o produto não esta vencido, clientes não tem acesso a produtos vencidos
                    if (usu[p_u].tipo == 1 || verificar_vencimento(e[j].dataval[0], e[j].dataval[1], e[j].dataval[2]) == 0)
                    {
                        printf("%d:\nProduto: %s\nCodigo: %s\nPreco: %.2f\nFabricacao: %02d/%02d/%04d\nValidade: %02d/%02d/%04d\nQuantidade: %d\n\n", con + 1, e[j].nome, e[j].codigo, e[j].preco, e[j].datafab[0], e[j].datafab[1], e[j].datafab[2], e[j].dataval[0], e[j].dataval[1], e[j].dataval[2], e[j].quant);
                        //armazena a posição do produto
                        vet[con] = j;
                        con++;
                    }
                }
            }
        }
    }
}

void ordem_de_print_produto()
{
    // menu de para selecionar a ordem de print dos produtos, o c é responsavel pela inversão das listagens, e o vetor armazena na ordem listada as posições respectivas dos produtos
    int menu, c = 0, vet[n], selecao;

    do
    {
        printf("Saldo: %.2f Reais\n\n", usu[p_u].saldo);
        printf("Organizar \n1-Ordem alfabetica\n2-Por preco\n3-Ordem cadastrada\n4-Quantidade\n5-Selecione o numero do produto\n6-voltar\n");

        if (scanf("%d", &menu) == 1)
        {

            switch (menu)
            {
            case 1:
                printar_produto_ordem_alfabetica(c, vet);
                c++;
                break;
            case 2:
                printar_produto_ordem_preco(c, vet);
                c++;
                break;

            case 3:
                printar_produto_ordem_cadastrada(c, vet);
                c++;
                break;
            case 4:
                printar_produto_ordem_quantidade(c, vet);
                c++;
                break;
            case 5:

                if (c > 0)
                {
                    printf("\nDigitando\n");

                    if (scanf("%d", &selecao) == 1)
                    {
                        // a seleção deve estar entre os listados
                        if (selecao > 0 && selecao < n + 1)
                        {
                            // caso seja adm o usuario logado, ele podera escolher se deseja compra ou editar tal produto
                            if (usu[p_u].tipo == 1)
                            {

                                if (editar_compra(vet[selecao - 1]) == 1)
                                {
                                    compra_produto(vet[selecao - 1]);
                                }
                                else
                                {
                                    confirma_produto(vet[selecao - 1]);
                                }
                            }

                            if (usu[p_u].tipo == 2)
                            {
                                compra_produto(vet[selecao - 1]);
                            }
                        }
                        else
                        {
                            printf("Opcao errada\n");
                            system("pause");
                            system("cls||clear");
                        }
                    }
                    else
                    {
                        fflush(stdin);
                        printf("Opcao errada\n");
                        system("pause");
                        system("cls||clear");
                    }
                }
                else
                {
                    printf("\nSelecione um modo de organizacao primeiro\n");
                    system("pause");
                    system("cls||clear");
                }

                break;
            case 6:
                break;

            default:
                system("cls||clear");
                printf("Opcao errada\n");
                system("pause");
                system("cls||clear");
                break;
            }
        }
        else
        {
            fflush(stdin);
            system("cls||clear");
            printf("Opcao errada\n");
            system("pause");
            system("cls||clear");
        }
    } while (menu != 6);
}

void procurar_produto_nome()
{
    int menu, c = 0, selecao;
    char nome_aux[TAM_NOME + 2];

    do
    {
        int numero = 0, vet[n];

        //deve digitar ao menos um nome
        if (c != 0)
        {
            int tam = strlen(nome_aux);

            //for pecorre o vetor
            for (int i = 0; i < n; i++)
            {
                int teste = 0;

                //testa letra por letra
                for (int j = 0; j < tam; j++)
                {
                    if (nome_aux[j] != e[i].nome[j])
                    {
                        teste++;
                    }
                }

                //caso todas as letras digitadas seja identicas, ira printar o produto
                if (teste == 0)
                {
                    // condição para printar, caso seja adm ou se o produto não esta vencido, clientes não tem acesso a produtos vencidos
                    if (usu[p_u].tipo == 1 || verificar_vencimento(e[i].dataval[0], e[i].dataval[1], e[i].dataval[2]) == 0)
                    {
                        vet[numero] = i;
                        numero++;
                        printf("%d:\nProduto: %s\nCodigo: %s\nPreco: %.2f\nFabricacao: %02d/%02d/%04d\nValidade: %02d/%02d/%04d\n\n", numero, e[i].nome, e[i].codigo, e[i].preco, e[i].datafab[0], e[i].datafab[1], e[i].datafab[2], e[i].dataval[0], e[i].dataval[1], e[i].dataval[2]);
                    }
                }
            }
        }

        if (numero == 0 && c != 0)
        {
            printf("Nada encontrado.\n\n");
        }

        printf("Saldo: %.2f Reais\n\n", usu[p_u].saldo);
        printf("1-Digite o nome\n2-Selecione o numero do produto\n3-Voltar\n");

        if (scanf("%d", &menu) == 1)
        {
            switch (menu)
            {
            case 1:
                printf("\nDigitando...\n");
                fflush(stdin);
                fgets(nome_aux, sizeof(nome_aux), stdin);
                tira_n(nome_aux);
                fflush(stdin);
                c++;
                break;
            case 2:
                if (c > 0)
                {
                    printf("\nDigitando...\n");
                    if (scanf("%d", &selecao) == 1)
                    {
// a seleção deve estar entre os listados
                        if (selecao <= numero && selecao > 0)
                        {
                            
                    // caso seja adm o usuario logado, ele podera escolher se deseja compra ou editar tal produto
                            if (usu[p_u].tipo == 1)
                            {

                                if (editar_compra(vet[selecao - 1]) == 1)
                                {
                                    compra_produto(vet[selecao - 1]);
                                }
                                else
                                {
                                    confirma_produto(vet[selecao - 1]);
                                }
                            }

                            if (usu[p_u].tipo == 2)
                            {
                                compra_produto(vet[selecao - 1]);
                            }
                        }
                        else
                        {
                            printf("Opcao errada\n");
                            system("pause");
                        }
                    }
                    else
                    {
                        fflush(stdin);
                        printf("Opcao errada\n");
                        system("pause");
                    }
                }
                else
                {
                    printf("Digite um nome primeiro\n");
                    system("pause");
                }
                break;
            case 3:
                break;

            default:

                printf("Opcao errada\n");
                system("pause");
                break;
            }
        }
        else
        {
            fflush(stdin);
            printf("Opcao errada\n");
            system("pause");
        }
        system("cls||clear");
    } while (menu != 3);
}

void procurar_produto_codigo()
{
    int menu, c = 0, selecao;
    char codigo_aux[TAM_COD + 2];

    do
    {
        int numero = 0, vet[n];

        //deve digitar ao menos um codigo
        if (c != 0)
        {   
            //for pecorre o vetor
            for (int i = 0; i < n; i++)
            {   
                // caso encontre um codigo identico, ele printa
                if (strcmp(codigo_aux, e[i].codigo) == 0)
                {
                    // condição para printar, caso seja adm ou se o produto não esta vencido, clientes não tem acesso a produtos vencidos
                    if (usu[p_u].tipo == 1 || verificar_vencimento(e[i].dataval[0], e[i].dataval[1], e[i].dataval[2]) == 0)
                    {
                        vet[numero] = i;
                        numero++;
                        printf("%d:\nProduto: %s\nCodigo: %s\nPreco: %.2f\nFabricacao: %02d/%02d/%04d\nValidade: %02d/%02d/%04d\n\n", numero, e[i].nome, e[i].codigo, e[i].preco, e[i].datafab[0], e[i].datafab[1], e[i].datafab[2], e[i].dataval[0], e[i].dataval[1], e[i].dataval[2]);
                    }
                }
            }
        }

        if (numero == 0 && c != 0)
        {
            printf("Nada encontrado.\n\n");
        }

        printf("Saldo: %.2f Reais\n\n", usu[p_u].saldo);
        printf("1-Digite o codigo\n2-Selecione o numero do produto\n3-Voltar\n");

        if (scanf("%d", &menu) == 1)
        {
            switch (menu)
            {
            case 1:
                printf("\nDigitando...\n");
                fflush(stdin);
                fgets(codigo_aux, sizeof(codigo_aux), stdin);
                tira_n(codigo_aux);
                fflush(stdin);
                c++;
                break;
            case 2:
                if (c > 0)
                {
                    printf("\nDigitando...\n");

                    if (scanf("%d", &selecao) == 1)
                    {
                        // a seleção deve estar entre os listados
                        if (selecao <= numero && selecao > 0)
                        {
                            // caso seja adm o usuario logado, ele podera escolher se deseja compra ou editar tal produto
                            if (usu[p_u].tipo == 1)
                            {

                                if (editar_compra(vet[selecao - 1]) == 1)
                                {
                                    compra_produto(vet[selecao - 1]);
                                }
                                else
                                {
                                    confirma_produto(vet[selecao - 1]);
                                }
                            }

                            if (usu[p_u].tipo == 2)
                            {
                                compra_produto(vet[selecao - 1]);
                            }
                        }
                        else
                        {
                            printf("Opcao errada\n");
                            system("pause");
                        }
                    }
                    else
                    {
                        fflush(stdin);
                        printf("Opcao errada\n");
                        system("pause");
                    }
                }
                else
                {
                    printf("Digite um codigo primeiro\n");
                    system("pause");
                }
                break;
            case 3:
                break;

            default:

                printf("Opcao errada\n");
                system("pause");
                break;
            }
        }
        else
        {
            fflush(stdin);
            printf("Opcao errada\n");
            system("pause");
        }
        system("cls||clear");
    } while (menu != 3);
}

void procurar_produto_preco()
{
    int menu, c = 0, selecao;
    float preco_aux;
    do
    {
        int numero = 0, vet[n];

        // c deve ter ao menos escrito um preço
        if (c != 0)
        {
            // for pecorre todo struct
            for (int i = 0; i < n; i++)
            {
                // teste se o preço é igual ao digitado
                if (e[i].preco == preco_aux)
                {
                    // condição para printar, caso seja adm ou se o produto não esta vencido, clientes não tem acesso a produtos vencidos
                    if (usu[p_u].tipo == 1 || verificar_vencimento(e[i].dataval[0], e[i].dataval[1], e[i].dataval[2]) == 0)
                    {
                        vet[numero] = i;
                        numero++;
                        printf("%d:\nProduto: %s\nCodigo: %s\nPreco: %.2f\nFabricacao: %02d/%02d/%04d\nValidade: %02d/%02d/%04d\n\n", numero, e[i].nome, e[i].codigo, e[i].preco, e[i].datafab[0], e[i].datafab[1], e[i].datafab[2], e[i].dataval[0], e[i].dataval[1], e[i].dataval[2]);
                    }
                }
            }
        }

        if (numero == 0 && c != 0)
        {
            printf("Nada encontrado.\n\n");
        }

        printf("Saldo: %.2f Reais\n\n", usu[p_u].saldo);
        printf("1-Digite o preco\n2-Selecione o numero do produto\n3-Voltar\n");

        if (scanf("%d", &menu) == 1)
        {
            switch (menu)
            {
            case 1:
                printf("\nDigitando...\n");

                if (scanf("%f", &preco_aux) == 1)
                {
                    c++;
                }
                else
                {
                    fflush(stdin);
                    printf("Preco invalido\n");
                    system("pause");
                }
                break;
            case 2:
                if (c > 0)
                {
                    printf("\nDigitando...\n");

                    if (scanf("%d", &selecao) == 1)
                    {
                        // a seleção deve estar entre os listados
                        if (selecao <= numero && selecao > 0)
                        {
                            // caso seja adm o usuario logado, ele podera escolher se deseja compra ou editar tal produto
                            if (usu[p_u].tipo == 1)
                            {

                                if (editar_compra(vet[selecao - 1]) == 1)
                                {
                                    compra_produto(vet[selecao - 1]);
                                }
                                else
                                {
                                    confirma_produto(vet[selecao - 1]);
                                }
                            }

                            if (usu[p_u].tipo == 2)
                            {
                                compra_produto(vet[selecao - 1]);
                            }
                        }
                        else
                        {
                            printf("Opcao errada\n");
                            system("pause");
                        }
                    }
                    else
                    {
                        fflush(stdin);
                        printf("Opcao errada\n");
                        system("pause");
                    }
                }
                else
                {
                    printf("Digite um preco primeiro\n");
                    system("pause");
                }
                break;
            case 3:
                break;

            default:

                printf("Opcao errada\n");
                system("pause");
                break;
            }
        }
        else
        {
            fflush(stdin);
            printf("Opcao errada\n");
            system("pause");
        }
        system("cls||clear");
    } while (menu != 3);
}

void procurar_produto_vencidos()
{

    int teste, vet[n], numero, menu, selecao;

    do
    {
        numero = 0;

        // for para pecorrer todo o stuct do estoque
        for (int i = 0; i < n; i++)
        {
            // variavel que verifica o vencimento, e retorna teste, sendo 0 para não vencido e diferente de 0 vencido
            teste = verificar_vencimento(e[i].dataval[0], e[i].dataval[1], e[i].dataval[2]);

            // condição para printar
            if (teste != 0)
            {
                // guarda a posição do produto
                vet[numero] = i;
                numero++;
                printf("%d:\nProduto: %s\nCodigo: %s\nPreco: %.2f\nFabricacao: %02d/%02d/%04d\nValidade: %02d/%02d/%04d\n\n", numero, e[i].nome, e[i].codigo, e[i].preco, e[i].datafab[0], e[i].datafab[1], e[i].datafab[2], e[i].dataval[0], e[i].dataval[1], e[i].dataval[2]);
            }
        }

        if (numero == 0)
        {
            printf("Nada encontrado.\n\n");
        }

        printf("Saldo: %.2f Reais", usu[p_u].saldo);
        printf("\n\n1-Selecione o numero do produto\n2-voltar\n");

        if (scanf("%d", &menu) == 1)
        {

            switch (menu)
            {
            case 1:
                printf("\nDigitando...\n");

                if (scanf("%d", &selecao) == 1)
                {
                    // a seleção deve estar entre os listados
                    if (selecao <= numero && selecao > 0)
                    {
                        // chama a função dando a posição das informações que desejo modificar no struct
                        confirma_produto(vet[selecao - 1]);
                    }
                    else
                    {
                        printf("Opcao errada\n");
                        system("pause");
                    }
                }
                else
                {
                    fflush(stdin);
                    printf("Opcao errada\n");
                    system("pause");
                }
                break;

            case 2:
                break;

            default:
                printf("Opcao errada\n");
                system("pause");
                break;
            }
        }
        else
        {
            fflush(stdin);
            printf("Opcao errada\n");
            system("pause");
        }

    } while (menu != 2);
}

void procurar_produto_por()
{
    // menu para selecionar o metodo de busca pelo produto
    int menu;

    if (usu[p_u].tipo == 1)
    {
        do
        {

            system("cls||clear");
            printf("Procurar por....\n1-Nome\n2-Codigo\n3-Preco\n4-Procurar produtos vencidos\n5-voltar\n");

            if (scanf("%d", &menu) == 1)
            {
                system("cls||clear");

                switch (menu)
                {
                case 1:
                    procurar_produto_nome(n);
                    break;
                case 2:
                    procurar_produto_codigo(n);
                    break;
                case 3:
                    procurar_produto_preco(n);
                    break;
                case 4:
                    procurar_produto_vencidos(n);
                    break;
                case 5:
                    break;

                default:
                    system("cls||clear");
                    printf("Opcao errada\n");
                    system("pause");
                    break;
                }
            }
            else
            {
                fflush(stdin);
                system("cls||clear");
                printf("Opcao errada\n");
                system("pause");
            }

        } while (menu != 5);
    }
    else
    {
        do
        {
            system("cls||clear");
            printf("Procurar por....\n1-Nome\n2-Codigo\n3-Preco\n4-voltar\n");

            if (scanf("%d", &menu) == 1)
            {
                system("cls||clear");

                switch (menu)
                {
                case 1:
                    procurar_produto_nome(n);
                    break;
                case 2:
                    procurar_produto_codigo(n);
                    break;
                case 3:
                    procurar_produto_preco(n);
                    break;
                case 4:
                    break;

                default:
                    system("cls||clear");
                    printf("Opcao errada\n");
                    system("pause");
                    break;
                }
            }
            else
            {
                fflush(stdin);
                system("cls||clear");
                printf("Opcao errada\n");
                system("pause");
            }
        } while (menu != 4);
    }
}

void printar_usuario_ordem_alfabetica(int c, int vet[])
{
    system("cls||clear");
    int tam = 0;
    char vet_aux[n][1], aux;

    // for para pecorret todo struct do usuario
    for (int i = 0; i < u; i++)
    {
        // pega apenas a primeira letra do nome
        vet_aux[tam][0] = usu[i].usuario[0];

        // for faz o teste se ja tem a letra no vetor, evitando repetir letras.
        for (int j = 0; j < tam; j++)
        {
            if (vet_aux[j][0] == usu[i].usuario[0])
            {
                // vetor diminui
                tam--;
            }
        }
        // vetor aumenta
        tam++;
    }

    // Organização em ordem alfabetica do vetor com as primeiras letras de todos os usuarios
    for (int i = 0; i < tam - 1; i++)
    {
        for (int j = 0; j < tam - i - 1; j++)
        {

            if (strcmp(vet_aux[j], vet_aux[j + 1]) > 0)
            {
                aux = vet_aux[j][0];
                vet_aux[j][0] = vet_aux[j + 1][0];
                vet_aux[j + 1][0] = aux;
            }
        }
    }

    // varivel para o vetor que guarda a posição de cada usuario no struct
    int con = 0;

    // caso o c seja par ele printa na ordem normal, caso seja impar printa inverso
    if (c % 2 == 0)
    {
        // for para pecorrer o vetor_aux com as letras em ordem alfabetica
        for (int i = 0; i < tam; i++)
        {
            // for para pecorrer todo o struct e printar apenas os que tenham a primeira letra igual a do vetor auxiliar
            for (int j = 0; j < u; j++)
            {
                if (vet_aux[i][0] == usu[j].usuario[0])
                {
                    printf("%d:\nUsuario: %s\nSenha: %s\nSaldo: %.2f Reais\nTipo: ", con + 1, usu[j].usuario, usu[j].senha, usu[j].saldo);
                    if (usu[j].tipo == 1)
                    {
                        printf("Adiministrador\n\n");
                    }
                    else
                    {
                        printf("Cliente\n\n");
                    }
                    // vetor salvando a posição
                    vet[con] = j;
                    con++;
                }
            }
        }
    }
    else
    {
        // for para pecorrer o vetor_aux com as letras em ordem alfabetica inversa
        for (int i = tam - 1; i > -1; i--)
        {
            // for para pecorrer todo o struct e printar apenas os que tenham a primeira letra igual a do vetor auxiliar
            for (int j = u - 1; j > -1; j--)
            {
                if (vet_aux[i][0] == usu[j].usuario[0])
                {
                    printf("%d:\nUsuario: %s\nSenha: %s\nSaldo: %.2f Reais\nTipo: ", con + 1, usu[j].usuario, usu[j].senha, usu[j].saldo);
                    if (usu[j].tipo == 1)
                    {
                        printf("Adiministrador\n\n");
                    }
                    else
                    {
                        printf("Cliente\n\n");
                    }
                    // vetor salvando a posição
                    vet[con] = j;
                    con++;
                }
            }
        }
    }
}

void printar_usuario_ordem_cadastrada(int c, int vet[])
{
    system("cls||clear");
    // varivel para o vetor que guarda a posição de cada usuario no struct
    int con = 0;

    // caso o c seja par ele printa na ordem normal, caso seja impar printa inverso
    if (c % 2 == 0)
    {
        // for para pecorrer e printar o struct
        for (int i = 0; i < u; i++)
        {

            printf("%d:\nUsuario: %s\nSenha: %s\nSaldo: %.2f Reais\nTipo: ", con + 1, usu[i].usuario, usu[i].senha, usu[i].saldo);
            if (usu[i].tipo == 1)
            {
                printf("Adiministrador\n\n");
            }
            else
            {
                printf("Cliente\n\n");
            }
            // vetor salvando a posição
            vet[con] = i;
            con++;
        }
    }
    else
    {
        // for para pecorrer e printar o struct inversamente
        for (int i = u - 1; i > -1; i--)
        {
            printf("%d:\nUsuario: %s\nSenha: %s\nSaldo: %.2f Reais\nTipo: ", con + 1, usu[i].usuario, usu[i].senha, usu[i].saldo);
            if (usu[i].tipo == 1)
            {
                printf("Adiministrador\n\n");
            }
            else
            {
                printf("Cliente\n\n");
            }
            // vetor salvando a posição
            vet[con] = i;
            con++;
        }
    }
}

int procurar_usuario()
{

    system("cls||clear");
    int menu, c = 0, selecao, volta_tudo = 0;
    char usuario_aux[TAM_USUARIO + 2];

    do
    {
        // vet e numero responsavel pelo tamanho do mesmo
        int numero = 0, vet[u];

        // c tem q ser diferente, ou seja tem q ao menos digitar um nome primeiro
        if (c != 0)
        {
            int tam = strlen(usuario_aux);

            // for responvel para passar por todo struct
            for (int i = 0; i < u; i++)
            {
                int teste = 0;

                // for para testar letra por letra
                for (int j = 0; j < tam; j++)
                {
                    if (usuario_aux[j] != usu[i].usuario[j])
                    {
                        teste++;
                    }
                }

                // caso todas as letras do auxiliar seja iguais as do usuario especifico, ele printa
                if (teste == 0)
                {
                    // vetor guarda a posição no struct que esta esse usuario
                    vet[numero] = i;
                    numero++;
                    printf("%d:\nUsuario: %s\nSenha: %s\nSaldo: %.2f Reais\nTipo: ", numero, usu[i].usuario, usu[i].senha, usu[i].saldo);
                    if (usu[i].tipo == 1)
                    {
                        printf("Adiministrador\n\n");
                    }
                    else
                    {
                        printf("Cliente\n\n");
                    }
                }
            }
        }

        if (numero == 0 && c != 0)
        {
            printf("Nada encontrado.\n\n");
        }

        printf("1-Digite o usuario\n2-Selecione o numero do usuario\n3-Voltar\n");

        if (scanf("%d", &menu) == 1)
        {
            switch (menu)
            {
            case 1:
                // digita o nome
                printf("\nDigitando...\n");
                fflush(stdin);
                scanf("%s", usuario_aux);
                tira_n(usuario_aux);
                fflush(stdin);
                c++;
                break;
            case 2:
                if (c > 0)
                {

                    printf("\nDigitando...\n");
                    if (scanf("%d", &selecao) == 1)
                    {
                        // a seleção deve estar entre os listados
                        if (selecao <= numero && selecao > 0)
                        {
                            // chama a função dando a posição das informações que desejo modificar no struct
                            volta_tudo = confirma_usuario(vet[selecao - 1]);
                        }
                        else
                        {
                            printf("Opcao errada\n");
                            system("pause");
                        }
                    }
                    else
                    {
                        fflush(stdin);
                        printf("Opcao errada\n");
                        system("pause");
                    }
                }
                else
                {
                    printf("Digite um usuario primeiro\n");
                    system("pause");
                }
                break;
            case 3:
                break;

            default:

                printf("Opcao errada\n");
                system("pause");
                break;
            }
        }
        else
        {
            fflush(stdin);
            printf("Opcao errada\n");
            system("pause");
        }
        system("cls||clear");
    } while (menu != 3 && volta_tudo != 1);

    return volta_tudo;
}

int ordem_de_print_usuarios()
{
    // menu de para selecionar a ordem de print dos usuarios, o c é responsavel pela inversão das listagens, e o vetor armazena na ordem listada as posições respectivas dos usuarios
    int menu, c = 0, vet[u], selecao, volta_tudo = 0;

    do
    {

        printf("Organizar\n");
        printf("1-Ordem alfabetica\n2-Ordem cadastrada\n3-selecione o numero do usuario\n4-Procura por usuario\n5-voltar\n");

        if (scanf("%d", &menu) == 1)
        {
            switch (menu)
            {
            case 1:
                printar_usuario_ordem_alfabetica(c, vet);
                c++;
                break;

            case 2:
                printar_usuario_ordem_cadastrada(c, vet);
                c++;
                break;

            case 3:
                if (c > 0)
                {
                    printf("\nDigitando\n");

                    if (scanf("%d", &selecao) == 1)
                    {
                        if (selecao > 0 && selecao < u + 1)
                        {
                            volta_tudo = confirma_usuario(vet[selecao - 1]);
                        }
                        else
                        {
                            printf("Opcao errada\n");
                            system("pause");
                            system("cls||clear");
                        }
                    }
                    else
                    {
                        fflush(stdin);
                        printf("Opcao errada\n");
                        system("pause");
                        system("cls||clear");
                    }
                }
                else
                {
                    printf("\nSelecione um modo de organizacao primeiro\n");
                    system("pause");
                    system("cls||clear");
                }
                break;

            case 4:
                procurar_usuario();
                break;
            case 5:
                break;

            default:
                printf("Opcao errada\n\n");
                system("pause");
                break;
            }
        }
        else
        {
            fflush(stdin);
            system("cls||clear");
            printf("Opcao errada\n\n");
            system("pause");
        }

    } while (menu != 5 && volta_tudo != 1);

    return volta_tudo;
}

void cadastrar_usuario()
{
    // cadastrar usuario segue logica parecida com oque foi vista no cadastro de produto

    char usuario_aux[TAM_USUARIO + 2], senha_aux[TAM_SENHA + 2];
    int t, teste, menu;

    // usuario
    do
    {
        teste = 0;

        system("cls||clear");
        printf("Digite o nome do usuario (ate %d caracteres e sem espaco)\n", TAM_USUARIO);

        fflush(stdin);
        fgets(usuario_aux, sizeof(usuario_aux), stdin);
        tira_n(usuario_aux);

        // teste com o usuario digitado, se ja exist, tamanho ou se tem espaço
        if (strlen(usuario_aux) > TAM_USUARIO)
        {
            teste++;
        }
        t = strlen(usuario_aux);
        for (int i = 0; i < t; i++)
        {
            if (usuario_aux[i] == ' ')
            {
                teste++;
            }
        }

        for (int i = 0; i < u; i++)
        {
            if (strcmp(usuario_aux, usu[i].usuario) == 0)
            {
                teste++;
            }
        }

        if (strlen(usuario_aux) == 0)
        {
            printf("\nCampo de escrita vazio\n");
            system("pause");
        }

        if (teste != 0)
        {
            printf("\nUsuario ja existe ou invalido, digite novamente\n");
            system("pause");
        }

    } while (teste != 0 || strlen(usuario_aux) == 0);

    // copia o auxiliar par ao oficial
    sprintf(usu[u].usuario, usuario_aux);

    // senha
    do
    {
        teste = 0;

        system("cls||clear");
        printf("Digite a senha (ate %d caracteres e sem espaco)\n", TAM_SENHA);

        fflush(stdin);
        fgets(senha_aux, sizeof(senha_aux), stdin);
        tira_n(senha_aux);
        fflush(stdin);

        // teste com o senha digitada, tamanho ou se tem espaço
        if (strlen(senha_aux) > TAM_SENHA)
        {
            teste++;
        }
        t = strlen(senha_aux);
        for (int i = 0; i < t; i++)
        {
            if (senha_aux[i] == ' ')
            {
                teste++;
            }
        }

        if (strlen(senha_aux) == 0)
        {
            printf("\nCampo de escrita vazio\n");
            system("pause");
        }

        if (teste != 0)
        {
            printf("\nSenha invalida, digite novamente\n");
            system("pause");
        }

    } while (teste != 0 || strlen(senha_aux) == 0);

    // copia o auxiliar para o oficial
    sprintf(usu[u].senha, senha_aux);

    // como e um novo usuario o saldo sempre vai ser 0
    usu[u].saldo = 0;

    // aqui muda se o usuario logado e adm ou cliente, caso seja cliente, todo usuario cadastrado sera cliente, caso seja adm, podera escolher se que q seja adm ou cliente
    if (usu[p_u].tipo == 1)
    {
        do
        {
            system("cls||clear");
            printf("Qual tipo da conta?\n1-Adiministrador\n2-Cliente\n");

            if (scanf("%d", &menu) == 1)
            {
                switch (menu)
                {
                case 1:
                    usu[u].tipo = 1;
                    break;
                case 2:
                    usu[u].tipo = 2;
                    break;
                default:
                    printf("\nOpcao errada\n\n");
                    system("pause");
                    break;
                }
            }
            else
            {
                fflush(stdin);
                printf("\nOpcao errada\n\n");
                system("pause");
            }

        } while (menu != 1 && menu != 2);
    }
    else
    {
        usu[u].tipo = 2;
    }

    confirma_usuario(u);
}

void cadastrar_produto()
{
    // variaveis auxiliar, para não influenciar no struct
    char codigo_aux[TAM_COD + 2], nome_aux[TAM_NOME + 2];
    int teste;

    // cadastra nome
    do
    {
        system("cls||clear");
        printf("Digite o nome do produto (ate %d caracteres)\n", TAM_NOME);

        fflush(stdin);
        fgets(nome_aux, sizeof(nome_aux), stdin);
        // essa função é responvel para tira o \n que o fgets coloca, em todo fgets eu chamo ela
        tira_n(nome_aux);

        // apenas verifica se ele ultrapassa do tamanho maximo ou não tem nada digitado
        if (strlen(nome_aux) > TAM_NOME)
        {
            printf("\nNome muito grande, nao e possivel cadastra lo, tente novamente.\n\n");
            system("pause");
        }
        if (strlen(nome_aux) == 0)
        {
            printf("\nCampo de escrita vazio\n");
            system("pause");
        }

    } while (strlen(nome_aux) > TAM_NOME || strlen(nome_aux) == 0);

    // copia o auxiliar para a variavel oficial do struct
    sprintf(e[n].nome, nome_aux);

    // codigo
    do
    {
        teste = 0;

        system("cls||clear");
        printf("Digite o codigo de ate %d digitos\n", TAM_COD);

        fflush(stdin);
        fgets(codigo_aux, sizeof(codigo_aux), stdin);
        tira_n(codigo_aux);
        fflush(stdin);

        // faz os teste se o codigo ultrupassa do tamanho ou não tem nada digitado
        if (strlen(codigo_aux) > TAM_COD)
        {
            printf("\ncodigo muito grande, nao e possivel cadastra lo, tente novamente.\n\n");
            system("pause");
        }
        else
        {
            // verifica se tem algum codigo igual, caso tenha ira printar a mensagem e devera digitar novamente
            for (int i = 0; i < n; i++)
            {
                if (strcmp(codigo_aux, e[i].codigo) == 0)
                {
                    teste++;
                    printf("\nCodigo ja existente, Digite novamente.\n");
                    system("pause");
                }
            }
        }

        if (strlen(codigo_aux) == 0)
        {
            printf("\nCampo de escrita vazio\n");
            system("pause");
        }

    } while (strlen(codigo_aux) > TAM_COD || teste != 0 || strlen(codigo_aux) == 0);

    // copia o auxiliar para a oficial
    sprintf(e[n].codigo, codigo_aux);

    // preço
    do
    {
        teste = 0;

        system("cls||clear");
        printf("Digite o preco\n");
        if (scanf("%f", &e[n].preco) == 1)
        {
            // o preço tem q ser maior que 0
            if (e[n].preco < 0)
            {
                teste++;
                printf("\npreco invalido, digite novamente.");
                system("pause");
            }
        }
        else
        {
            fflush(stdin);
            teste++;
            printf("\npreco invalido, digite novamente.");
            system("pause");
        }
    } while (teste != 0);

    // data de fabricação
    do
    {
        teste = 0;

        system("cls||clear");
        printf("Digite a data de fabricacao\n");

        printf("\nDia\n");

        if (scanf("%d", &e[n].datafab[0]) == 1)
        {
            printf("\nMes\n");

            if (scanf("%d", &e[n].datafab[1]) == 1)
            {
                printf("\nAno\n");

                if (scanf("%d", &e[n].datafab[2]) == 1)
                {
                    // apos digitar numeros inteiros, chama esse função para testar se é uma data valida, o numero 1 no parametro tem motivo la na função
                    teste = verificar_data_fab(e[n].datafab[0], e[n].datafab[1], e[n].datafab[2], 1, n);
                }
                else
                {
                    fflush(stdin);
                    teste++;
                }
            }
            else
            {
                fflush(stdin);
                teste++;
            }
        }
        else
        {
            fflush(stdin);
            teste++;
        }

        if (teste != 0)
        {
            printf("\nData invalida, digite novamente\n");
            system("pause");
        }

    } while (teste != 0);

    // data de validade
    do
    {
        teste = 0;

        system("cls||clear");
        printf("Data de fabricacao %02d/%02d/%04d\n\n", e[n].datafab[0], e[n].datafab[1], e[n].datafab[2]);
        printf("Digite a data de validade\n");

        printf("\nDia\n");

        if (scanf("%d", &e[n].dataval[0]) == 1)
        {
            printf("\nMes\n");

            if (scanf("%d", &e[n].dataval[1]) == 1)
            {
                printf("\nAno\n");

                if (scanf("%d", &e[n].dataval[2]) == 1)
                {
                    // a mesma logica da varificação de fabricação, porem não tem o 1, pois n precisa
                    teste = verificar_data_val(e[n].dataval[0], e[n].dataval[1], e[n].dataval[2], n);
                }
                else
                {
                    fflush(stdin);
                    teste++;
                }
            }
            else
            {
                fflush(stdin);
                teste++;
            }
        }
        else
        {
            fflush(stdin);
            teste++;
        }

        if (teste != 0)
        {
            printf("\nData invalida, digite novamente\n");
            system("pause");
            system("cls||clear");
        }
    } while (teste != 0);

    // quantidade
    do
    {
        teste = 0;

        system("cls||clear");
        printf("Digite a quantidade.\n");

        if (scanf("%d", &e[n].quant) == 1)
        {
            // a quantidade tem q ser maior q 0
            if (e[n].quant < 0)
            {
                teste++;
                printf("\nQuantidade invalida, digite novamente.\n\n");
                system("pause");
            }
        }
        else
        {
            fflush(stdin);
            teste++;
            printf("\nQuantidade invalida, digite novamente.\n\n");
            system("pause");
        }
    } while (teste != 0);

    // apos o cadastro concluido, chama esse função
    confirma_produto(n);
}

void saldo()
{
    // aqui  simples, apenas adiciona e remove saldo do usuario logado, apenas digitar um valor valido.
    int menu;
    float valor;

    printf("Saldo: %.2f Reais\n\n", usu[p_u].saldo);
    printf("Deseja adcionar ou sacar?\n1-Adicionar\n2-Sacar\n3-Voltar\n");

    if (scanf("%d", &menu) == 1)
    {

        switch (menu)
        {
        case 1:
            printf("\nDigite o valor\n");

            if (scanf("%f", &valor))
            {
                if (valor >= 0)
                {
                    usu[p_u].saldo += valor;
                }
                else
                {
                    printf("\nValor invalido\n");
                    system("pause");
                }
            }
            else
            {
                fflush(stdin);
                printf("\nValor invalido\n");
                system("pause");
            }

            break;

        case 2:
            printf("\nDigite o valor\n");

            if (scanf("%f", &valor))
            {
                if (valor >= 0 && (usu[p_u].saldo - valor) >= 0)
                {
                    usu[p_u].saldo -= valor;
                }
                else
                {
                    printf("\nValor invalido\n");
                    system("pause");
                }
            }
            else
            {
                fflush(stdin);
                printf("\nValor invalido\n");
                system("pause");
            }
            break;
        case 3:
            break;

        default:
            printf("\nValor invalido\n");
            system("pause");
            break;
        }
    }
    else
    {
        fflush(stdin);
        printf("\nValor invalido\n");
        system("pause");
    }
}

int menu_adm()
{
    // menu do adiministrador, tem acesso a todas opções.

    // a varivael volta_tudo, é responsavel pra caso o usuario logado seja excluido ou trocado para cliente, então ira voltar tudo, ate a parte de digitar usuario e senha, evitando quebrar o codigo
    int menu, menu2, volta_tudo = 0;

    // inicio do menu
    do
    {

        system("cls||clear");

        // algumas informações adicionais
        printf("Saldo: %.2f Reais\n\n", usu[p_u].saldo);
        printf("=========MENU========\n");
        printf("1-Cadastrar produto\n2-ver produtos cadastrados\n3-procurar produto por...\n4-resetar tudo\n5-Cadastrar usuario\n6-ver usuarios\n7-Trocar de usuario\n8-Saldo da conta\n9-finalizar\n\n%d produtos cadastrados\n", n);
        printf("Capacidade maxima ate %d produtos\n\n", TAM_ESTOQUE);
        printf("Data atual: %02d/%02d/%04d\n\n", data_atual[0], data_atual[1], data_atual[2]);

        // vou comentar apenas agora, o if do scanf, evita do codigo quebra caso seja digitado algo difente do tipo da variavel, caso digite algo diferente ele entra no else e limpa o buffer
        if (scanf("%d", &menu) == 1)
        {
            system("cls||clear");

            switch (menu)
            {
            case 1:

                // o if evita que seja cadastrado mais um produto alem da capacidade do estoque
                if (n < TAM_ESTOQUE)
                {
                    cadastrar_produto();
                    n++;
                }
                else
                {
                    printf("\nEstoque cheio.\n");
                    system("pause");
                }
                break;

            

            case 2:

                // o if faz com que seja printado produtos apenas quando tiver produtos
                if (n > 0)
                {
                    ordem_de_print_produto();
                }
                else
                {
                    printf("\nNenhum produto cadastrado\n");
                    system("pause");
                }
                break;

            case 3:

                // mesmo caso do segundo case
                if (n > 0)
                {
                    procurar_produto_por();
                }
                else
                {
                    printf("\nNenhum produto cadastrado\n");
                    system("pause");
                }
                break;

            case 4:

                // apenas zera a varivel n, a responvel pela posição do struct
                printf("\nTem certeza que deseja resetar tudo?\n\n1-Sim\n2-Nao\n");
                scanf("%d", &menu);

                if (menu == 1)
                {
                    n = 0;
                }
                break;

            case 5:
                cadastrar_usuario();
                u++;
                break;

            case 6:
                volta_tudo = ordem_de_print_usuarios();
                break;
            case 7:
                printf("Apos a confirmacao voce devera colocar usuario e senha novamente.\nDeseja continuar?\n1-Sim\n2-Nao\n");

                if (scanf("%d", &menu2) == 1)
                {
                    if (menu2 == 2)
                    {
                        menu = 0;
                    }
                }
                else
                {
                    fflush(stdin);
                    printf("\nOpcao errada\n\n");
                    system("pause");
                }
                break;
            case 8:
                saldo();
                break;

            case 9:

                printf("Finalizando\n");
                printf("\nVolte sempre\n");
                system("pause");
                break;

            default:

                printf("Opcao errada\n\n");
                system("pause");

                break;
            }
        }
        else
        {
            fflush(stdin);
            system("cls||clear");
            printf("Opcao errada\n\n");
            system("pause");
        }
    } while (menu != 9 && menu != 7 && volta_tudo != 1);

    if (volta_tudo == 1)
    {
        menu = 7;
    }

    return menu;
}

int menu_cliente()
{
    // menu do cliente, opções que o cliente não tem acesso
    int menu, menu2;

    // inicio do menu
    do
    {

        system("cls||clear");

        // printa algumas informações adicionais
        printf("Saldo: %.2f Reais\n\n", usu[p_u].saldo);
        printf("=========MENU========\n");
        printf("1-Ver produtos\n2-Procurar produto por...\n3-Saldo da conta\n4-Cadastrar usuario\n5-Trocar de usuario\n6-Finalizar\n\n%d produtos disponiveis\n", n);

        printf("Data atual: %02d/%02d/%04d\n\n", data_atual[0], data_atual[1], data_atual[2]);

        // vou comentar apenas agora, o if do scanf, evita do codigo quebra caso seja digitado algo difente do tipo da variavel, caso digite algo diferente ele entra no else e limpa o buffer
        if (scanf("%d", &menu) == 1)
        {
            system("cls||clear");

            switch (menu)
            {
            case 1:

                // apenas printa caso tenha ao menos um produto cadastrado
                if (n > 0)
                {
                    ordem_de_print_produto();
                }
                else
                {
                    printf("\nNenhum produto disponivel, volte outra hora.\n");
                    system("pause");
                }

                break;

            case 2:

                // mesma situação do primeiro case
                if (n > 0)
                {
                    procurar_produto_por();
                }
                else
                {
                    printf("\nNenhum produto disponivel, volte outra hora.\n");
                    system("pause");
                }
                break;

            case 3:
                saldo();
                break;

            case 4:
                cadastrar_usuario();
                u++;
                break;

            case 5:
                printf("Apos a confirmacao voce devera colocar usuario e senha novamente.\nDeseja continuar?\n1-Sim\n2-Nao\n");

                if (scanf("%d", &menu2) == 1)
                {
                    if (menu2 == 2)
                    {
                        menu = 0;
                    }
                }
                else
                {
                    fflush(stdin);
                    printf("\nOpcao errada\n\n");
                    system("pause");
                }
                break;

            case 6:
                printf("Finalizando\n");
                printf("\nVolte sempre\n");
                system("pause");
                break;
            default:

                printf("Opcao errada\n\n");
                system("pause");

                break;
            }
        }
        else
        {
            fflush(stdin);
            system("cls||clear");
            printf("Opcao errada\n\n");
            system("pause");
        }
    } while (menu != 6 && menu != 5);

    return menu;
}

int main()
{
    setlocale(LC_ALL, "Portguese");
    // Definir a variavel do tempo atual
    time(&tempoAtual);
    infoTempo = localtime(&tempoAtual);

    data_atual[0] = infoTempo->tm_mday;
    data_atual[1] = infoTempo->tm_mon + 1;
    data_atual[2] = infoTempo->tm_year + 1900;

    // Definindo os 2 primeiros usuarios
    sprintf(usu[0].usuario, "marcos");
    sprintf(usu[0].senha, "123");
    usu[0].saldo = 100000;
    usu[0].tipo = 1;

    sprintf(usu[1].usuario, "marcoscliente");
    sprintf(usu[1].senha, "123");
    usu[1].saldo = 1000;
    usu[1].tipo = 2;

    // declaração de variaveis
    int teste, a;
    char usuario_aux[TAM_USUARIO];
    char senha_aux[TAM_SENHA];

    do
    {
        do
        {
            system("cls||clear");
            teste = 0;

            // Digitação do usuario e senha
            printf("Ola bem vindo ao \n\nMARCAO ATACADO\n\ndigite um usuario e senha para ter acesso\n\n");

            printf("Usuario\n");
            fflush(stdin);
            fgets(usuario_aux, sizeof(usuario_aux), stdin);
            tira_n(usuario_aux);
            fflush(stdin);

            printf("\nSenha\n");
            fgets(senha_aux, sizeof(senha_aux), stdin);
            tira_n(senha_aux);
            fflush(stdin);

            // pecorre todos os usuarios
            for (int i = 0; i < u; i++)
            {
                // testa se o usuario digitado existe
                if (strcmp(usuario_aux, usu[i].usuario) == 0)
                {
                    // caso exista o teste acresentara,e o p_u indicara a posição no struct desse usuario
                    teste++;
                    p_u = i;
                }
            }

            // aqui testa se a senha esta correta, condizendo com o usuario
            if (strcmp(senha_aux, usu[p_u].senha) == 0)
            {
                // caso sim, acresenta e teste = 2
                teste++;
            }

            // caso teste não seja igual a 2, ou seja algum dos testes antes falhou, ira printar a mensagem
            if (teste != 2)
            {
                printf("\nUsuario/senha incorretos, tente novamente\n");
                system("pause");
            }
        } while (teste != 2);

        // com a posição do usuario no struct definida, ele verifica qual o tipo para chamar o menu adequado
        if (usu[p_u].tipo == 1)
        {
            a = menu_adm();
        }
        else
        {
            a = menu_cliente();
        }

        // a varivael a vereferese a opção de ambos menu, caso a opção seja finalizar e pra finalizar o codigo
    } while (a != 6 && a != 9);

    return 0;
}