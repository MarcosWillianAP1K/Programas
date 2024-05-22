#include <stdio.h>


typedef struct {
    double real;
    double imag;
} Complexo;


void somaComplexo (Complexo num1, Complexo num2, Complexo *num3);

int main() {
    Complexo z1, z2, z3;

   
    while (1) {
        
        printf("Digite a parte real e imaginaria do primeiro numero complexo: ");
        scanf("%lf %lf", &z1.real, &z1.imag);

        
        printf("Digite a parte real e imaginaria do segundo numero complexo: ");
        scanf("%lf %lf", &z2.real, &z2.imag);
        
        somaComplexo(z1, z2, &z3);

        printf("A soma dos numeros complexos e: %.2lf + %.2lfi\n", z3.real, z3.imag);
    }

    return 0;
}

void somaComplexo(Complexo num1, Complexo num2, Complexo *num3) {
    num3->real = num1.real + num2.real;
    num3->imag = num1.imag + num2.imag;
}