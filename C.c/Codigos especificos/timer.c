#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main(){
    //Inicia o tempo
    double time_spent = 0.0;



    //Inicio pra começar o contador/
    clock_t begin = clock();
    
    //Coloca suas funções/

    clock_t end = clock();
    //Termina o contador/

    //Faz a conversão do tempo/
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

    //Exibe/    
    printf("\nThe elapsed time is %lf seconds", time_spent);
    
    return 0;
}