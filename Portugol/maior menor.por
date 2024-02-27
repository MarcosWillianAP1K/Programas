programa
{
	
	funcao inicio()
	{
	inteiro f, c, ma, me, n

	c = 1
	ma = 0
	me = 99999
	
	escreva("quantidade de numeros\n")
	leia(f)

	enquanto(c <= f){
		escreva("\nnumeros\n")
		leia(n)

		se(n > ma){
			ma = n
			se (c == 1){
				me = n
			}
		}
		senao se (n < me){
			me = n
		}
		c = c + 1
	}
		escreva("\n", ma, "\n", me, " ")
	
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 226; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */