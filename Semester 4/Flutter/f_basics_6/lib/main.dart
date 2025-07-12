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
            Container(
              color: Colors.blueGrey,
              child: Padding(
                // padding: const EdgeInsets.all(8.0),
                padding: EdgeInsets.only(left: 12, top: 20, bottom: 0),
                child: Text('Hello World', style: TextStyle(fontSize: 25),)
              ),
            ),
            Container(
              // margin: EdgeInsets.all(11),
              margin: EdgeInsets.only(left: 12, top: 20),
              color: Colors.grey,
              child: Text('Hello World', style: TextStyle(fontSize: 25),)
            )
          ],
        )
    );
  }
}