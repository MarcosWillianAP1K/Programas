import 'dart:io';

main() {
  //for normal
  for (int i = 0; i < 5; i++) {
    print("olaaa");
  }

  print('\n');

  List lista = [1, 2, 3, 4, 5];
  //dois jeitos de pecorrer a lista

  //metodo convencional
  for (int i = 0; i < lista.length; i++) {
    print(lista[i]);
  }
  print("");

  //for in
  //metodo mais otimizado
  for (var listaaux in lista) {
    print(listaaux);
  }

  print("");

  //para matriz
  var matriz = [
    [1, 2],
    [3, 4],
    [5, 6]
  ];

  for (var mataux1 in matriz) {
    for (var mataux2 in mataux1) {
      stdout.write("$mataux2 ");
    }
    print("");
  }

  for (var valor = "#"; valor != "######"; valor += "#") {
    print(valor);
  }
}
