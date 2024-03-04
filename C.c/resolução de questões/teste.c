#include <stdio.h>

int main (){

int mat [10][10] = {{1, 2}, {3, 4}}, *p;

p = mat;

printf("%d\n%d\n", *p + 3, sizeof(mat) /4);

    return 0;
}