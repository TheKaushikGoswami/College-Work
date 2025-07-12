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
      title: 'Flutter Demo',
      debugShowCheckedModeBanner: false,
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
    return Scaffold(
      appBar: AppBar(
        // TRY THIS: Try changing the color here to a specific color (to
        // Colors.amber, perhaps?) and trigger a hot reload to see the AppBar
        // change color while the other colors stay the same.
        backgroundColor: Theme.of(context).colorScheme.inversePrimary,
        // Here we take the value from the MyHomePage object that was created by
        // the App.build method, and use it to set our appbar title.
        title: Text('Flutter Container'),
      ),
      body: Container(
          width: 500,
          color: Colors.purpleAccent,
          child: Center(
            child: Column(
                mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                crossAxisAlignment: CrossAxisAlignment.stretch,
                children: [
                    Row(
                      mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                      children: [
                        Text('R1', style: TextStyle(fontSize: 25),),
                        Text('R2', style: TextStyle(fontSize: 25),),
                        Text('R3', style: TextStyle(fontSize: 25),),
                        Text('R4', style: TextStyle(fontSize: 25),),
                        Text('R5', style: TextStyle(fontSize: 25),),
                        ElevatedButton(onPressed: (){
                          print("WOwwwwwwwwww");
                        }, 
                        child: Text("Click Me!!!!!!"))
                      ],
                    ),
                    Text("Hello!", style: TextStyle(
                      color: Colors.amber,
                      fontSize: 40,
                      fontWeight: FontWeight.w500,
                      backgroundColor: Colors.black)
                  ),
                  TextButton(
                    child: Text('Click Here!'),
                    onPressed: (){
                      print("Hello Boy!");
                    },
                    onLongPress: (){
                      print("Stop Holding Me!");
                    },
                  ),
                  ElevatedButton(
                    onPressed: (){
                      print("Elevated Button Click");
                    },
                    child: Text('Elevated Button')
                  ),
                  OutlinedButton(
                    onPressed: (){
                      print("Outline Button");
                  },
                  child: Text("Outline Button")
                  ),
                  SizedBox(
                      height: 200,
                      width: 200,
                      child: Image.asset('assets/images/sanyojm_logo.jpeg'),
                  )
                ]
            ),
          ),
        ),
      // This trailing comma makes auto-formatting nicer for build methods.
    );
  }
}
