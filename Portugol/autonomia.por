programa
{
	
	funcao inicio()
	{
		inteiro distancia
		real inicial, final, atual, comsumo
		
		escreva("CALCULADORA DE COMSUMO DE LITRO POR KM")
		escreva("\n\nDistancia percorrida em KM ")
		leia(distancia)

		escreva("\ntanque inicial ")
		leia(inicial)
		escreva("\ntanque final ")
		leia(final)

		atual = inicial - final
		comsumo = distancia / atual

		escreva("este automovel tem autonomia de ", comsumo, " Km por litro")
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 423; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */