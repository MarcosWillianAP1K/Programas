programa
{
	
	funcao inicio()
	{
	inteiro H1, H2, M1, M2, P1, P2

	 escreva("Digite a idade de 2 homens e 2 mulheres respectivamente\n")
	 leia(H1, H2, M1, M2)

	 P1 = 0
	 P2 = 0

	se((H1 > H2 e M1 > M2) ou (H1 < H2 e M1 < M2)){
		P1 = H1 + M2
		P2 = H2 + M1
	}
	senao se(H1 > H2 e M1 < M2){
		P1 = H1 + M1
		P2 = H2 + M2
	}
	  

	 escreva("\nSoma: ", P1," ", P2)
	 
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 332; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */