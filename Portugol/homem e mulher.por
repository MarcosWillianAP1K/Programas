programa
{
	
	funcao inicio()
	{
		inteiro h, m
		caracter sexo

		h = 0
		m = 0
		
		faca{
			
			escreva("h-homem\nm-mulher\n@-sair\n")
			leia(sexo)

			se(sexo == 'h'){
				h = h + 1
				sexo = 'k'
			}
			senao se (sexo == 'm'){
				m = m + 1
				sexo = 'k'
			}
			senao se(sexo == '@'){
				escreva("homem: ", h, "\nmulher: ", m)
			}
			senao{
				sexo = 'k'
			}
			
		}enquanto(sexo == 'k')
		
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 206; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */