programa
{
	
	funcao inicio()
	{
		inteiro n1, n2, n3, c

		
		c = 1

		escreva("digite os numeros\n")
		leia(n1, n2)

		escreva("\n", n1, "\n", n2, "\n")

		enquanto(c <= 20){

			se(n2 % 2 == 0){
				n3 = n1 - n2
				escreva(n3, "\n")
			}
			senao {
				n3 = n1 + n2
				escreva(n3, "\n")
			}
			

			n1 = n2
			n2 = n3

			c = c + 1
		}
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 224; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */