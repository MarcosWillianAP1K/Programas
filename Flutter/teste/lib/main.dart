import 'package:flutter/material.dart';

main() {
  runApp(const perguntaApp());
}

// ignore: camel_case_types
class perguntaApp extends StatelessWidget {
  const perguntaApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          centerTitle: true,
          backgroundColor: Colors.blue, // Set the background color to blue
          title: const Text("Ola flutter"),
        ),
        body: const Center(
          child: Text("Ola mundo"),
        ),
      ),
    );
  }
}
