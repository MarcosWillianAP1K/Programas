nome = input("Digite seu nome: ")
idade = input("Digite sua idade: ")

if not nome or not idade:
    print("\n\nVocê não digitou o nome ou idade animal KKKKK")

else:
    print(f"\n\nseu nome é {nome}")
    print(f"seu nome invertido é {nome[::-1]}")
    print("seu nome contem espaços?: ", ' ' in nome)
    print("a primeira letra do seu nome é ", nome[0])
    print("a ultima letra do seu nome é", nome[-1])
    print(f"idade {idade}", end="\n\n")
    