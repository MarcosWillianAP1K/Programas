import 'package:flutter/material.dart';

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
                        iconSize: 80.0,
                        onPressed: () {
                          Navigator.push(
                            context,
                            MaterialPageRoute(
                                builder: (context) => const passar_pagina()),
                          );
                        },
                        icon: const Icon(Icons.circle),
                        color: const Color.fromARGB(255, 0, 89, 255),
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

class passar_pagina extends StatelessWidget {
  const passar_pagina({super.key});

  @override
  Widget build(BuildContext context) {
    return const MaterialApp(
      home: outra_tela(),
    );
  }
}

class outra_tela extends StatefulWidget {
  const outra_tela({super.key});

  @override
  _OutraTelaState createState() => _OutraTelaState();
}

class _OutraTelaState extends State<outra_tela> {
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
          child: IconButton(
            iconSize: 80.0,
            onPressed: () {
              Navigator.pop(context);
            },
            icon: const Icon(Icons.circle),
            color: const Color.fromARGB(255, 0, 89, 255),
          ),
        ),
      ),
    );
  }
}
