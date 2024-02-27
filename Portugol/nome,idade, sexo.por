programa
{
	
	funcao inicio()
	{
	 caracter nome
	 logico sexo
	 inteiro idade, i

	 i = 1

	 enquanto (i < 21){

	 escreva("\ndigite nome, idade\n")
	 leia(nome, idade)
	 escreva("\nÉ masculino, verdadeiro ou falso?\n")
	 leia(sexo)

	 i = i + 1

	 se (sexo == verdadeiro e idade > 21){
	 	escreva("\n", nome," é compativel\n")
	 }
	 senao{
	 	escreva("\nNao é compativel\n")
	 }
	 }

	 escreva("\nfim de programa")


	 }
	
	
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 404; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */