nome = input("Digite seu nome: ")
sobrenome = input('Sobrenome: ')
idade = int(input("Idade: "))
ano_de_nascimento = int(input("ano de nascimento: "))
maior_de_idade = idade >= 18
altura = float(input("Altura em metros: "))

print('\nNome:', nome, "\nSobrenome:", sobrenome, "\nIdade:", idade, "\nAno de nascimento:", ano_de_nascimento, "\nE de maior?:", maior_de_idade, "\nAltura:", altura, end="\n\n")

