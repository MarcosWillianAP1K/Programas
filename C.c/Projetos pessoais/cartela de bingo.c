#include <stdio.h>
#include <time.h>
#include <stdlib.h>



int main(){

    int mat[4][4];
    int n, i, d, t1, t2;
srand(time(NULL));

    for (n = 0; n < 5; n++){
        
        for (i = 0; i < 5; i++){
            
            if(i > 0 || n > 0){
                do{
                    d = 0;

                    mat[n][i] = rand() % 51;

                    for(t1 = 0; t1 <= n; t1++){

                    
                        for(t2 = 0; t2 < i; t2++){
                    
                            if (mat[n][i] == mat[t1][t2] && (n != t1 || i != t2)){
                                d++;
                            }
                        
                        }
                        
                       
                    }
                } while (d != 0);
                
                printf("%d\t", mat[n][i]);
            }
            else{ 
                mat[n][i] = rand() % 51;
                printf("%d\t", mat[n][i]);
            }
            printf("\n");
        }
        
    }

    return 0;
    
}
