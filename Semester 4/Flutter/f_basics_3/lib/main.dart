import 'package:flutter/material.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      title: 'Flutter Demo',
      theme: ThemeData(
        colorScheme: ColorScheme.fromSeed(seedColor: Colors.deepPurple),
      ),
      home: const MyHomePage(title: 'Flutter Demo Home Page'),
    );
  }
}

class MyHomePage extends StatefulWidget {
  const MyHomePage({super.key, required this.title});

  final String title;

  @override
  State<MyHomePage> createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {
  @override
  Widget build(BuildContext context) {
    var names = [
      "Kaushik",
      "Ankur", 
      "Yuvraj",
      "Humanshu",
      "Abhishek",
      "Sahil",
      "Praveen",
      "Rahul",
    ];

    return Scaffold(
      appBar: AppBar(backgroundColor: Colors.teal, title: Text("Hello")),

      // ListView Builder
      // body: ListView.builder(
      //   itemBuilder: (context, index) {
      //     return Center(
      //       child: Text(
      //         names[index],
      //         style: TextStyle(fontWeight: FontWeight.w500, fontSize: 24),
      //       ),
      //     );
      //   },
      //   itemCount: names.length,
      //   itemExtent: 100,

      // ListView Separated
      body: ListView.separated(
        itemBuilder: (context, index) {
          return Center(
            child: Text(
              names[index],
              style: TextStyle(fontWeight: FontWeight.w500, fontSize: 24),
            ),
          );
        },
        itemCount: names.length,
        separatorBuilder: (context, index) {
          return Divider(color: Colors.black, thickness: 2, height: 80);
        },

        // Basic List View
        // body: ListView(
        //   scrollDirection: Axis.vertical,
        //   // reverse: true,
        //   children: [
        //     Padding(
        //       padding: const EdgeInsets.all(8.0),
        //       child: Text(
        //         "One",
        //         style: TextStyle(fontSize: 25, fontWeight: FontWeight.w600),
        //       ),
        //     ),
        //     Padding(
        //       padding: const EdgeInsets.all(8.0),
        //       child: Text(
        //         "Two",
        //         style: TextStyle(fontSize: 25, fontWeight: FontWeight.w600),
        //       ),
        //     ),
        //     Padding(
        //       padding: const EdgeInsets.all(8.0),
        //       child: Text(
        //         "Three",
        //         style: TextStyle(fontSize: 25, fontWeight: FontWeight.w600),
        //       ),
        //     ),
        //     Padding(
        //       padding: const EdgeInsets.all(8.0),
        //       child: Text(
        //         "Four",
        //         style: TextStyle(fontSize: 25, fontWeight: FontWeight.w600),
        //       ),
        //     ),
        //     Padding(
        //       padding: const EdgeInsets.all(8.0),
        //       child: Text(
        //         "Five",
        //         style: TextStyle(fontSize: 25, fontWeight: FontWeight.w600),
        //       ),
        //     ),
        //     Padding(
        //       padding: const EdgeInsets.all(8.0),
        //       child: Text(
        //         "Six",
        //         style: TextStyle(fontSize: 25, fontWeight: FontWeight.w600),
        //       ),
        //     ),
        //   ],
        // ),
        // This trailing comma makes auto-formatting nicer for build methods.
      ),
    );
  }
}
