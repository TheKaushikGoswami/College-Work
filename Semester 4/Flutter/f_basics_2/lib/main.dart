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
        // This is the theme of your application.
        //
        // TRY THIS: Try running your application with "flutter run". You'll see
        // the application has a purple toolbar. Then, without quitting the app,
        // try changing the seedColor in the colorScheme below to Colors.green
        // and then invoke "hot reload" (save your changes or press the "hot
        // reload" button in a Flutter-supported IDE, or press "r" if you used
        // the command line to start the app).
        //
        // Notice that the counter didn't reset back to zero; the application
        // state is not lost during the reload. To reset the state, use hot
        // restart instead.
        //
        // This works for code too, not just values: Most code changes can be
        // tested with just a hot reload.
        colorScheme: ColorScheme.fromSeed(seedColor: Colors.deepPurple),
      ),
      home: const MyHomePage(title: 'Flutter Demo Home Page'),
    );
  }
}

class MyHomePage extends StatefulWidget {
  const MyHomePage({super.key, required this.title});

  // This widget is the home page of your application. It is stateful, meaning
  // that it has a State object (defined below) that contains fields that affect
  // how it looks.

  // This class is the configuration for the state. It holds the values (in this
  // case the title) provided by the parent (in this case the App widget) and
  // used by the build method of the State. Fields in a Widget subclass are
  // always marked "final".

  final String title;

  @override
  State<MyHomePage> createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: Colors.purpleAccent,
        title: Text("Hello World"),
      ),
      body: Center(
        child: Padding(
          padding: const EdgeInsets.all(8.0),
          child: SingleChildScrollView(
            child: Column(
              children: [
                Padding(
                  padding: const EdgeInsets.only(bottom: 10),
                  child: SingleChildScrollView(
                    scrollDirection: Axis.horizontal,
                    child: Row(
                      children: [
                        Container(
                          height: 200,
                          width: 200,
                          color: Colors.blueAccent,
                        ),
                        Container(
                          margin: EdgeInsets.only(left: 10),
                          height: 200,
                          width: 200,
                          color: Colors.green,
                        ),
                        Container(
                          margin: EdgeInsets.only(left: 10),
                          height: 200,
                          width: 200,
                          color: Colors.brown,
                        ),
                        Container(
                          margin: EdgeInsets.only(left: 10),
                          height: 200,
                          width: 200,
                          color: Colors.tealAccent,
                        ),
                        Container(
                          margin: EdgeInsets.only(left: 10),
                          height: 200,
                          width: 200,
                          color: Colors.blueAccent,
                        ),
                      ],
                    ),
                  ),
                ),
                Container(
                  height: 200,
                  margin: EdgeInsets.only(bottom: 10),
                  color: Colors.redAccent,
                ),
                Container(
                  height: 200,
                  margin: EdgeInsets.only(bottom: 10),
                  color: Colors.greenAccent,
                ),
                Container(
                  height: 200,
                  margin: EdgeInsets.only(bottom: 10),
                  color: Colors.blueAccent,
                ),
                Container(
                  height: 200,
                  margin: EdgeInsets.only(bottom: 10),
                  color: Colors.redAccent,
                ),
                Container(
                  height: 200,
                  margin: EdgeInsets.only(bottom: 10),
                  color: Colors.greenAccent,
                ),
                InkWell(
                  // Used to make any widget tap-able
                  onTap: () {
                    print("Single Tap");
                  },
                  onDoubleTap: () {
                    print("Double Tap");
                  },
                  onLongPress: () {
                    print("Long Press");
                  },
                  child: Container(
                    margin: EdgeInsets.only(bottom: 10),
                    height: 200,
                    color: Colors.amber,
                    child: Center(
                      child: InkWell(
                        onTap: () {
                          print("Text clicked!!");
                        },
                        onDoubleTap: () {
                          print("Double Tapped on Text!!");
                        },
                        child: Text(
                          "Click Me!!!",
                          style: TextStyle(
                            fontSize: 25,
                            fontWeight: FontWeight.w800,
                          ),
                        ),
                      ),
                    ),
                  ),
                ),
              ],
            ),
          ),
        ),
      ),
      // This trailing comma makes auto-formatting nicer for build methods.
    );
  }
}
