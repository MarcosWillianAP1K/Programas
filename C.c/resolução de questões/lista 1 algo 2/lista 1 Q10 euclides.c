#include <stdio.h>

int main() {
    int num1, num2, temp, c = 0;
    
    scanf("%d %d", &num1, &num2);

    while (num2 != 0) {
        temp = num2;
        num2 = num1 % num2;
        num1 = temp;

        c++;
    }
    
    printf("O MDC %d\nContador: %d ", num1, c);
    
    return 0;
}