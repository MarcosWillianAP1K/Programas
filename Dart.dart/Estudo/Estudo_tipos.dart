import 'dart:io';

main() {
  //constante
  const a = 2, b = 3;

  var teste2 = "A soma é: ";

  //o print sem o \n no final
  stdout.write(teste2 + (a + b).toString() + "\n");

  //final, não ser mais modificado, o read é o scanf basicamente
  final teclado = stdin.readLineSync()!;

  print("Voce digitou: " + teclado.toString());

  //absoluto
  double abs = -3.14.abs();

  print(abs);

  //convertor de string para outro tipo
  var converter = int.parse("21");

  print(converter);

  //dynamic, pode mudar os tipos das variaveis
  dynamic tipo = 2;

  tipo = "eu gostum";

  print(tipo);
}
