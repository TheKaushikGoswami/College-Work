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
      body: Container(
        width: double.infinity,
        height: double.infinity,
        color: Colors.blue.shade50,
        child: Center(
          child: Container(
            width: 200,
            height: 200,
            decoration: BoxDecoration(
              color: Colors.blueGrey,
              borderRadius: BorderRadius.circular(20),
              // borderRadius: BorderRadius.only(
              //   topLeft: Radius.circular(30),
              //   bottomRight: Radius.circular(30),
              // )

              border: Border.all(
                width: 5,
                color: Colors.black,
              ),
              boxShadow: [
                BoxShadow(
                blurRadius: 55,
                color: Colors.red,
                spreadRadius: 15
                )
              ],
              // shape: BoxShape.circle
            )
          )
        )
      )
    );
  }
}