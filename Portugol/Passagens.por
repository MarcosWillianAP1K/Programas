programa
{
	
	funcao inicio()
	{
		inteiro regiao, ida, valor
		
		
		escreva("______MENU______\nDigite a região desejada\n")
		escreva("1-Norte\n2-Nordeste\n3-Centro Oeste\n4-Sul\n")
		leia(regiao)

		escreva("\n1-Ida\n2-Ida e Volta\n")
		leia(ida)

		valor = 0

		se(regiao == 1){
			se(ida == 1){
				valor = 500
			}
			senao{
				valor = 900
			}
			
		}
		senao se (regiao == 2){
			se(ida == 1){
				valor = 350
			}
			senao{
				valor = 650
			}
		}
		senao se(regiao == 3){
			se(ida == 1){
				valor = 350
			}
			senao{
				valor = 600
			}
		}
		senao se(regiao == 4){
			se(ida == 1){
				valor = 300
			}
			senao{
				valor = 550
			}
		}
		
		escreva("valor ficara: ", valor)
	
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 706; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */