programa
{
	
	funcao inicio()
	{
	real n1, n2, n3, n4, M, m

	escreva("escreva as notas respectivamente\n")
	leia(n1, n2, n3, n4)
	
	m = 4
	M = (n1 + n2 + n3 + n4) / m

	se (M >= 7) { 
		escreva("Aprovado")
		}
	senao
	se (M >=4 e M <7) { 
		escreva("Reprovado")
		}
		senao 
		escreva("Prova Final")
		
		
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 172; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */