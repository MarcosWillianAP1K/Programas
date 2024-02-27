programa
{
	
	funcao inicio()
	{
		inteiro ma, me, id, t, c
		real m

		ma = 0
		me = 0
		c = 0
		t = 0
		
		
		faca{
			escreva("digite as idades\nou sair digite -1 \n")
			leia(id)

			se(id == -1){
				m = t / c
				escreva("maior: ", ma, "\nmenor: ", me, "\nmedia: ", m)
			}
			senao se(id > ma){
				se(c == 0){
					me = id
				}
				ma = id
			}
			senao se( id < me){
				me = id
			}
			c = c + 1
			t = t + id
				
		}enquanto(id >= 0)
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 301; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */