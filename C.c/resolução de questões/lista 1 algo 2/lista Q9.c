#include <stdio.h>

int main()
{
    int l, c;

    scanf("%d %d", &l, &c);

    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if(j == 0 || j == c-1 || i == 0 || i == c-1){
            printf("*");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
    
    return 0;
}