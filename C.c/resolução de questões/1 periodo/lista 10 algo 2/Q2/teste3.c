#include <stdio.h>
#include <Windows.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int main()
{
char string[10] = "marcos";

    memset(string, 'a', strlen(string) + 1);

    printf("ola %s ola", string);

    return 0;
}