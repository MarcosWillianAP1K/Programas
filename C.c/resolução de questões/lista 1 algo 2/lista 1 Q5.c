#include <stdio.h>

int main()
{
    int idade_homem1, idade_homem2, idade_mulher1, idade_mulher2;

    printf("Digite a idade do primeiro homem: ");
    scanf("%d", &idade_homem1);

    printf("Digite a idade do segundo homem: ");
    scanf("%d", &idade_homem2);

    printf("Digite a idade da primeira mulher: ");
    scanf("%d", &idade_mulher1);

    printf("Digite a idade da segunda mulher: ");
    scanf("%d", &idade_mulher2);

    int soma_idades = (idade_homem1 > idade_homem2 ? idade_homem1 : idade_homem2) + (idade_mulher1 < idade_mulher2 ? idade_mulher1 : idade_mulher2);
    int produto_idades = (idade_homem1 < idade_homem2 ? idade_homem1 : idade_homem2) * (idade_mulher1 > idade_mulher2 ? idade_mulher1 : idade_mulher2);

    printf("A soma das idades do homem mais velho com a mulher mais nova é: %d\n", soma_idades);
    printf("O produto das idades do homem mais novo com a mulher mais velha é: %d\n", produto_idades);

    return 0;
}
