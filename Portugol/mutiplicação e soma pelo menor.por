programa
{
	
	funcao inicio()
	{
		inteiro A, B, T, F

		escreva("Digite dois valores\n ")
		leia(A, B)

		T = A * B

		se (A > B){
			F = B + T
		}
		senao 
		se (A < B){
			F = A + T
		}
		senao F = T + A

		escreva("Seu resultado é ", F)

		
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 245; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */