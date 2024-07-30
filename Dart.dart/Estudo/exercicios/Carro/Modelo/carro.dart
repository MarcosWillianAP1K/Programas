class CARRO {
  final int velocidade_maxima;
  int velocidade_atual = 0;
  bool estaNoLimite = false;

  CARRO(this.velocidade_maxima);
}

int acelerar(CARRO carro) {
  if (carro.velocidade_atual + 5 > carro.velocidade_maxima) {
    carro.estaNoLimite = true;
    return carro.velocidade_atual = carro.velocidade_maxima;
  }

  return carro.velocidade_atual += 5;
}

int frear(CARRO carro) {
  if (carro.velocidade_atual - 5 < 0) {
    return carro.velocidade_atual = 0;
  }

  if (carro.estaNoLimite == true) {
    carro.estaNoLimite = false;
  }

  return carro.velocidade_atual -= 5;
}
