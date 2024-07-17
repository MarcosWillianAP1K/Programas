import 'dart:io';

main() {
  var notas =
      stdin.readLineSync()!.split(" ").map((e) => double.parse(e)).toList();


  var notasboasFn = (double nota) => nota >= 7;

  var notasboas = notas.where(notasboasFn).toList();

  print(notas);
  print(notasboas);
}
