#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

struct cadastrar
{
    float preco;
    int codigo;
    char produto[50];
};

struct cadastrar c[4];

int menu, n = 0;

 do
 { 

    printf("_______MENU_______");
    printf("\n\n1-para cadastra \n2-produto ja cadastrado\n");
    scanf("%d", &menu);
    
    switch (menu){
    
     case 1:  

     if (n < 4){
      printf("nome do produto: ");
      fflush(stdin);
      gets(c[n].produto);

      printf("\nCodigo do produto: ");
      scanf("%d", &c[n].codigo);

      printf("\nPreco do produto: ");
      scanf("%f", &c[n].preco);
      
      n++;
      
      menu = 0;
     }
      else if(n > 3){
        printf("\nlimite alcancado");

      }
      system("pause");
      menu = 0;
      break;

      case 2:
       for (int i = 0; i < n; i++){
        printf("\nProduto: %s\nCodigo%d\nPreco%.2f\n\n", c[i].produto, c[i].codigo, c[i].preco);
       }
        system("PAUSE");
        menu = 0;

        break;
      
      default:
        printf("\nnumero errado idiota\n\n");
        system("PAUSE");
        menu = 0;
    
    }
    
    system("cls||clear");
    }while (menu == 0);


 return 0;
}
