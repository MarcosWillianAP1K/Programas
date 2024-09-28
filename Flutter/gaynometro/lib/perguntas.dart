import 'package:flutter/material.dart';

class Perguntas extends StatefulWidget {
  @override
  State<Perguntas> createState() {
    return _PerguntasState();
  }
}

class _PerguntasState extends State<Perguntas> {
  final _perguntaSelecionada = [
    "Escolha uma bebida",
    "Escolha um filme",
    "Escolha um livro"
  ];

  final _respostas = [
    ['Cerveja', 'Vinho', 'Refrigerante'],
    ['Ação', 'Comédia', 'Terror'],
    ['Romance', 'Ficção', 'Aventura']
  ];

  final _bool = [
    [false, true, false],
    [false, true, false],
    [true, false, false]
  ];

  int _contador_de_viado = 0, _contador_de_pergunta = 0;

  void _incrementar(int resposta) {
    if (_bool[_contador_de_pergunta][resposta]) {
      setState(() {
        _contador_de_viado++;
      });
    }
  }

  void _proximaPergunta(int n) {
    setState(() {
      if (_contador_de_pergunta < 2) {
        _incrementar(n);
        _contador_de_pergunta++;
      } else {
        Navigator.push(
          context,
          MaterialPageRoute(
            builder: (context) => Resultado(_contador_de_viado, _resetar),
          ),
        );
      }
    });
  }

  void _resetar() {
    setState(() {
      _contador_de_viado = 0;
      _contador_de_pergunta = 0;
    });
  }

  @override
  Widget build(BuildContext context) {
    return Center(
      child: Column(
        mainAxisAlignment: MainAxisAlignment.center,
        children: <Widget>[
          Text(
            _perguntaSelecionada[_contador_de_pergunta],
            textScaler: const TextScaler.linear(2.0),
          ),
          SizedBox(height: 10),
          ElevatedButton(
              onPressed: () => _proximaPergunta(0),
              child: Text(_respostas[_contador_de_pergunta][0])),
          SizedBox(height: 10),
          ElevatedButton(
              onPressed: () => _proximaPergunta(1),
              child: Text(_respostas[_contador_de_pergunta][1])),
          SizedBox(height: 10),
          ElevatedButton(
              onPressed: () => _proximaPergunta(2),
              child: Text(_respostas[_contador_de_pergunta][2])),
        ],
      ),
    );
  }
}

class Resultado extends StatelessWidget {
  int cont;
  Function _resetar;

  Resultado(this.cont, this._resetar);

  static const Re = ["HETORO TOP", "BIXA", "BAITOLÃO"];

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          title: const Text('Medidor de gayzisse'),
          centerTitle: true,
          backgroundColor: Colors.blue,
        ),
        body: Center(
          child: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            children: <Widget>[
              Text(Re[cont]),
              SizedBox(height: 10),
              ElevatedButton(
                  onPressed: () {
                    _resetar();
                    Navigator.pop(context);
                  },
                  child: Text("Recomeçar"))
            ],
          ),
        ),
      ),
    );
  }
}
