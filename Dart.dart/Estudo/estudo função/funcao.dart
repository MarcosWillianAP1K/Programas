void main() {
  int a = 2, b = 3, soma;

  soma = soma_ab(a, b);

  print(soma);

  print(somaaa(a, b));
}

//passando como parametro especifico, bem parecido com C
int soma_ab(int a, int b) {
  return a + b;
}

//passando parametro dinamico
dynamic somaaa(dynamic a, b) {
  return a + b;
}
