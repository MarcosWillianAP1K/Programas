class Carro {
  String nome, marca, cor;

  Carro([this.nome = "sem nome", this.marca = "sem marca", this.cor = ""]);

  String printar() {
    return "Nome: $nome\nMarca: $marca\nCor: $cor\n";
  }
}

main() {
  List<Carro> carros = [];

  carros.add(Carro("Fusca", "Volkswagen", "Azul"));
  carros.add(Carro("Gol", "Volkswagen", "Preto"));
  carros.add(Carro("Uno", "Fiat", "Vermelho"));
  carros.add(Carro());

  // print(carros[0].nome);

  for (var n in carros) {
    //  print("Nome: ${n.nome}\nMarca: ${n.marca}\nCor: ${n.cor}\n");
    print("Informação\n${n.printar()}");
  }
}
