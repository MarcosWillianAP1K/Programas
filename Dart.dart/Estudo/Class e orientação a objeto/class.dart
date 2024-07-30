import 'dart:math';

main() {
  Celular c1 = Celular("Samsung", "Galaxy S10", 3000.00);

  print(c1.marca);
  print(c1.modelo);
  print(c1.preco);
  print(c1.teste);
  print(c1.toString());
  print(c1.Media(c1.preco));

  //no mesmo arquivo ainda  é possivel acessar o atributo privado, porem em outros arquivos não
  //acessando a variavel
  print(c1._numero_de_serie);

  //acessando o get, assim não é possivel alterar o valor da variavel	privada
  print(c1.numero_de_serie);
}

//class é um molde para criar objetos, ou pra quem sabe C, e um struct mais desenvolvido
class Celular {
  //publicos
  String marca;
  String modelo;
  double preco;
  String teste = "teste";

  //privados começa com _
  String _numero_de_serie = "123456789";

  String get numero_de_serie {
    return _numero_de_serie;
  }
  //ou String get numero_de_serie => _numero_de_serie;

  Celular(this.marca, this.modelo, this.preco);

  String toString() {
    return "Marca: $marca, Modelo: $modelo, Preço: $preco";
  }

  double Media(double preco) {
    return preco / 2;
  }
}
