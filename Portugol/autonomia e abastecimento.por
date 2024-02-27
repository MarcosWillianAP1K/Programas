programa
{
	
	funcao inicio()
	{
		real km1, km2, com1, com2, comf, comx, auto, L, L1
		inteiro abas
		
		escreva("AUTONOMIA", "\nE", "\nQUANTAS ABASTECIDAS DEVERA DAR?")

		escreva("\n\nDistancia percorrida em Km: ")
		leia(km1)

		escreva("\nDistancia que deseja percorrer: ")
		leia(km2)

		escreva("\nQuantidade inicial de combustivel: ")
		leia(com1)

		escreva("\nQuantidade atual de combustivel: ")
		leia(com2)

		escreva("\nQuantida maxima do tanque de combustivel: ")
		leia(comx)

		comf = com1 - com2

		auto = km1 / comf

		escreva("\n\nA autonomia é: ", auto, "Km/L")
		
		L = km2 / auto
		L1 = L - com1

		abas = L1 / comx

		se (abas == 0){
			escreva("\nNão sera necessario abastecer")
		}
		senao {
			escreva("\nSera necessario ", abas)
		

		se (abas == 1) {
			escreva(" abastecida")
		}
		senao {
			escreva(" abastecidas")
		}
		}
		
		
		
		}

		

	
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 737; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */