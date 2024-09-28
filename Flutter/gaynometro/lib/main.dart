import 'package:flutter/material.dart';
import './perguntas.dart';

void main() {
  runApp(const Inicio());
}

class Inicio extends StatelessWidget {
  const Inicio({Key? key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          title: const Text('Medidor de gayzisse'),
          centerTitle: true,
          backgroundColor: Colors.blue,
        ),
        body: Perguntas(),
      ),
    );
  }
}
