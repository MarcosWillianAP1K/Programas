programa
{
	
	funcao inicio()
	{
		inteiro n1, n2, f

		escreva("digite o intervalo\n")
		leia (n1, n2)

		enquanto(n1 <= n2){
			se(n1 % 2 == 0){
				escreva(n1, " par\n")
			}
			senao{
				escreva(n1, " impar\n")
			}
			n1 = n1 + 1
		}
		faca{
		escreva("digite -1 para finalizar o programa\n")
		leia(f)
			se(f == -1){
				f = -1
			}
			senao{
				f = 0
			}
			
		}enquanto(f == 0)
		
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 324; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */