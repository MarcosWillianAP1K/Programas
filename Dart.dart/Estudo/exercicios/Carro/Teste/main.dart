import 'dart:io';
import '../Modelo/carro.dart';

main() {
  CARRO carro = CARRO(200);

  int menu = 0;

  print("1 - Acelerar\n2 - Frear\n3 - Sair\n");

  do {
    menu = int.parse(stdin.readLineSync()!);

    switch (menu) {
      case 1:
        print("Acelerando...");
        print("Velocidade atual: ${acelerar(carro)}\n");

        if (carro.estaNoLimite == true) {
          print("Você está no limite de velocidade\n");
        }
        break;

      case 2:
        print("Freando...");
        print("Velocidade atual: ${frear(carro)}\n");
        break;

      case 3:
        print("Saindo...");
        break;

      default:
        print("Opção inválida\n");
        break;
    }
  } while (menu != 3);
}
