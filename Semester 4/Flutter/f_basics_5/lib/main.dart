import "package:flutter/material.dart";

void main(){
  runApp(FlutterApp());
}

class FlutterApp extends StatelessWidget{
  const FlutterApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: "Flutter App",
      debugShowCheckedModeBanner: false,
      theme: ThemeData(
        primarySwatch: Colors.blue,
      ),
      home: HomeScreen(),
    );
  }
}

class HomeScreen extends StatelessWidget{
  const HomeScreen({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
        appBar: AppBar(
          title: Text("Home"),
          backgroundColor: Colors.blue.shade100,
        ),
        body: Column(
          children: [
            Expanded(
              flex: 2,
              child: Container(
                height: 100,
                color: Colors.blue,
              ),
            ),
            Expanded(
              flex: 4,
              child: Container(
                height: 100,
                color: Colors.red,
              ),
            ),
            Expanded(
              flex: 2,
              child: Container(
                height: 100,
                color: Colors.green,
              ),
            ),
            Expanded(
              child: Container(
                height: 100,
                color: Colors.orange,
              ),
            ),

          ],
        )
    );
  }
}