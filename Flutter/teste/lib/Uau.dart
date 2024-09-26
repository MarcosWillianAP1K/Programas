import 'package:flutter/material.dart';

class Uau extends StatelessWidget {
  final String texto;

  const Uau(this.texto, {super.key});

  @override
  Widget build(BuildContext context) {
    return Container(
      color: Colors.red,
      child: Text(texto, textScaler: const TextScaler.linear(2.0)),
    );
  }
}
