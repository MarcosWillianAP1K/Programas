programa
{
	
	funcao inicio()
	{
	real d1, d2, d3, v, vd, vp

	d1 = 0.15
	d2 = 0.1
	d3 = 0.05

	escreva("Digite o valor da compra: ")
	leia(v)

	se (v > 500){
		vd = v * d1
		vp = v - vd
	}
	senao
	se (v >= 200 e v < 500){
		vd = v * d2
		vp = v - vd
	}
	senao
	vd = v * d3
	vp = v - vd

	escreva("\nvalor inicial: ", v,"\nvalor do desconto: ", vd,"\nvalor total: ", vp)
	
	
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 305; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */