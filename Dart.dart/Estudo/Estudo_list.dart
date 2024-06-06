main() {
  //lista (para os intimos, vetor)
  List nomes = ["ana", 'gabriel', "teu pai"];

  print(nomes);

  //como acessar, 2 formaas
  print(nomes.elementAt(2));
  print(nomes[0]);

  //printar o tamanho da lista
  print(nomes.length);

  print("\n\n");

  //map
  Map numero_de_ap = {"marcos": 305, "walison": 305, "cleiton": 306};

  print(numero_de_ap is Map);

  //printar todo mapa, apenas valores, apenas chaves, ambos
  print(numero_de_ap);
  print(numero_de_ap.values);
  print(numero_de_ap.keys);
  print(numero_de_ap.entries);

  //para acessar o valor (a direita) n usa indices, usa a chave(a esquerda).
  print(numero_de_ap["marcos"]);
  print(numero_de_ap["cleiton"]);

  print("\n\n");

  //set
  //ele não é uma lista(vetor), ele é um conjunto, não necessariamente ordernado
  //detalhe, diferente da lista, ele não aceita repetição
  Set times = {"flamengo", "são paulo", "vasco"};

  print(times is Set);

  //tem varias funcionalidades nas funções de ponto(.)
  times.add("palmeiras");
  print(times);
  print(times.length);
  print(times.contains("flamengo"));
  print(times.first);
  print(times.last);
}
