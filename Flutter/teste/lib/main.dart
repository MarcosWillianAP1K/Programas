import 'package:flutter/material.dart';
import "./Uau.dart";

main() {
  runApp(const perguntaApp());
}

// ignore: camel_case_types
class perguntaApp extends StatelessWidget {
  const perguntaApp({super.key});

  @override
  Widget build(BuildContext context) {
    return const Contador();
  }
}

class Contador extends StatefulWidget {
  const Contador({super.key});

  @override
  // ignore: library_private_types_in_public_api
  _Contador_estado createState() => _Contador_estado();
}

// ignore: camel_case_types
class _Contador_estado extends State<Contador> {
  int cont = 0;

  void incrementarCont() {
    setState(() {
      cont++;
    });
  }

  void decrementarCont() {
    setState(() {
      cont--;
    });
  }

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Navigator(
        onGenerateRoute: (RouteSettings settings) {
          return MaterialPageRoute(
            builder: (BuildContext context) => Scaffold(
              appBar: AppBar(
                centerTitle: true,
                backgroundColor:
                    Colors.blue, // Set the background color to blue
                title: const Text('Ola flutter'),
              ),
              body: Center(
                  child: Column(children: [
                const Spacer(flex: 1),
                Center(
                    child: Column(
                  children: [
                    const Text("Contador", textScaler: TextScaler.linear(2.0)),
                    Text("$cont", textScaler: const TextScaler.linear(2.0))
                  ],
                )),
                const Spacer(),
                Row(
                    mainAxisAlignment: MainAxisAlignment.spaceBetween,
                    children: [
                      IconButton(
                        iconSize: 100.0,
                        icon: const Icon(Icons.remove),
                        color: const Color.fromARGB(255, 0, 0, 0),
                        onPressed: decrementarCont,
                      ),
                      // ignore: prefer_const_constructors
                      IconButton(
                        iconSize: 60.0,
                        onPressed: () {
                          Navigator.push(
                            context,
                            MaterialPageRoute(
                                builder: (context) => const outra_tela()),
                          );
                        },
                        icon: const Icon(Icons.arrow_forward),
                        color: const Color.fromARGB(255, 0, 0, 0),
                      ),
                      IconButton(
                        iconSize: 100.0,
                        icon: const Icon(Icons.add),
                        color: const Color.fromARGB(255, 0, 0, 0),
                        onPressed: incrementarCont,
                      )
                    ])
              ])),
            ),
          );
        },
      ),
    );
  }
}

// ignore: camel_case_types
class outra_tela extends StatefulWidget {
  const outra_tela({super.key});

  @override
  // ignore: library_private_types_in_public_api
  _OutraTelaState createState() => _OutraTelaState();
}

class _OutraTelaState extends State<outra_tela> {
  final List _perguntas = [
    "Qual é a sua cor favorita?",
    "Qual é o seu animal favorito?",
    "Qual é o seu time favorito?"
  ];
  int i = 0;

  // ignore: non_constant_identifier_names
  void _acresentar_i() {
    setState(() {
      if (i < _perguntas.length - 1) {
        i++;
      } else {
        i = 0;
      }
    });
  }

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          centerTitle: true,
          backgroundColor: Colors.blue, // Set the background color to blue
          title: const Text('Outra tela'),
        ),
        body: Center(
          child: Column(
            children: [
              Text(_perguntas[i], textScaler: const TextScaler.linear(2.0)),
              ElevatedButton.icon(
                onPressed: _acresentar_i,
                label: const Text(
                  "Resposta 1",
                  textScaler: TextScaler.linear(1.0),
                  selectionColor: Color.fromRGBO(0, 0, 0, 1),
                ),
              ),
              const Center(child: Uau("BAH"))
            ],
          ),
        ),
        floatingActionButton: FloatingActionButton(
          onPressed: () {
            Navigator.pop(context);
          },
          child: const Icon(Icons.arrow_back),
        ),
        // bottomNavigationBar: ,
      ),
    );
  }
  
}
