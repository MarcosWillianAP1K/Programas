#include <stdio.h>

#define num_notas 6

int ehPossivel(int valCompra, int valPago);

int main() {
    int valCompra, valPago;
    
    printf("Digite o valor da compra: ");
    scanf("%d", &valCompra);
    printf("Digite o valor pago: ");
    scanf("%d", &valPago);
    
    if (ehPossivel(valCompra, valPago)) {
        printf("E possivel dar o troco exato com duas notas.\n");
    } else {
        printf("Nao e possivel dar o troco exato com duas notas.\n");
    }
    
    return 0;
}

int ehPossivel(int valCompra, int valPago) {
    int notas[] = {2, 5, 10, 20, 50, 100};
    
    for (int i = 0; i < num_notas; i++) {
        for (int j = 0; j < num_notas; j++) {
            if (notas[i] + notas[j] == valPago - valCompra) {
                return 1;
            }
        }
    }
    
    return 0;
}