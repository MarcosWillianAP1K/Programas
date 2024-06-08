void main() {
  //aritmeticos (operadores binarios/ infix)
  int a = 7, b = 3;

  print(a + b);
  print(a - b);
  print(a * b);
  print((a / b));
  print(a % b);

  print("\n\n");

  //logicos
  bool c = true, d = false;

  print(c && d);
  print(c | d);
  //OU exclusivo, apenas um pode ser verdadeiro
  print(c ^ d);
  print(c != d);
  print(c == d);
  //! inverte
  print(!(c | d));

  print(3 >= 2);
  print(3 <= 2);

  print("");

  //101 = 5
  //100 = 4
  //resultado = 100 = 4, ele compara bit por bit 0 = false, 1 = true(o mesmo para os outros logicos)
  print(5 & 4);

  print("");
  //encrementos e decrementos
  int num1 = 2, num2 = 3;

  //ele compila o numero primeiro, e depois acresenta
  //num1++;

  //ele decrementa primeiro e depois compila o numero
  // --num2;

  print(num1++ == --num2);//dara true, pois ele decrementou primeiro, e depois fez a comparação, e so depois incrementou, ai sim daria false
}
