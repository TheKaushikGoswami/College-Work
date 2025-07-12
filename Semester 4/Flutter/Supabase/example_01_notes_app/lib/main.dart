import 'package:flutter/material.dart';
import 'package:supabase_flutter/supabase_flutter.dart';

void main() async{
  WidgetsFlutterBinding.ensureInitialized();

  await Supabase.initialize(
    url: 'https://lrrzpixyyyuniicumwrz.supabase.co',
    anonKey: 'eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJzdXBhYmFzZSIsInJlZiI6ImxycnpwaXh5eXl1bmlpY3Vtd3J6Iiwicm9sZSI6ImFub24iLCJpYXQiOjE3NDQwODQ1NzIsImV4cCI6MjA1OTY2MDU3Mn0.MyK0Nb09i1PhAQciknhdjmmbqVDPbWFwSfZ70lUMzRI',
  );

  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      title: 'Flutter Demo',
      home: MyHomePage(),
    );
  }
}

class MyHomePage extends StatefulWidget {
  const MyHomePage({super.key});

  @override
  State<MyHomePage> createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {
  final _notesStream =
      Supabase.instance.client.from('notes').stream(primaryKey: ['id']);
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text("My Notes"),
      ),
      body: StreamBuilder<List<Map<String, dynamic>>>(
        stream: _notesStream,
        builder: (context, snapshot) {
          if (!snapshot.hasData) {
            return const Center(child: CircularProgressIndicator());
          }
          final notes = snapshot.data!;

          return ListView.builder(
              itemCount: notes.length,
              itemBuilder: (context, index) {
                return ListTile(
                  title: Text(notes[index]['body']),
                );
              },
          );
        },
      ),
      floatingActionButton: FloatingActionButton(
          onPressed: (){
            showDialog(context: context, builder: ((context) {
              return SimpleDialog(
                  title: const Text('Add a Note'),
                  contentPadding: const EdgeInsets.symmetric(horizontal: 40),
                  children: [
                    TextFormField(
                      onFieldSubmitted: (value) async {
                        await Supabase.instance.client.from('notes').insert({
                          'body': value
                        });
                      },
                    )
                  ],
              );
            }),
            );
          },
          child: const Icon(Icons.add)
      ),
    );
  }
}
