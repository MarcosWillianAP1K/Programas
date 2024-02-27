#include <stdio.h>
#include <string.h>
#include <locale.h>

int main (){
    setlocale(LC_ALL, "Portguese");
    
    char s[10], a[10];

    scanf("%s", s);
    fflush(stdin);

    scanf("%s", a);
    fflush(stdin);

    strcat(s, a);
    

    puts(s);
}