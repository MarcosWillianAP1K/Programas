import 'dart:math';

void main() {
  int n = 100;

  print(numero_aleatorio(n));

  print(numero_aleatorio());
}

//os colchetes tranforma o parametro opcional, caso nada seja passado, ele assume o valor padrão, que eu defino
int numero_aleatorio([int maximo = 10]) {
  return Random().nextInt(maximo);
}
