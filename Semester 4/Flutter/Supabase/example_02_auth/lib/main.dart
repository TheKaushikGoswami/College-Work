import 'package:example_02_auth/pages/login_page.dart';
import 'package:example_02_auth/pages/splash_page.dart';
import 'package:example_02_auth/pages/account_page.dart';
import 'package:flutter/material.dart';
import 'package:supabase_flutter/supabase_flutter.dart';

void main() async{
  await Supabase.initialize(
    url: 'https://lrrzpixyyyuniicumwrz.supabase.co',
    anonKey: 'eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJzdXBhYmFzZSIsInJlZiI6ImxycnpwaXh5eXl1bmlpY3Vtd3J6Iiwicm9sZSI6ImFub24iLCJpYXQiOjE3NDQwODQ1NzIsImV4cCI6MjA1OTY2MDU3Mn0.MyK0Nb09i1PhAQciknhdjmmbqVDPbWFwSfZ70lUMzRI',
  );
  runApp(const MyApp());
}

final supabase = Supabase.instance.client;

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      title: 'Flutter Demo',
      theme: ThemeData(
        colorScheme: ColorScheme.fromSeed(seedColor: Colors.deepPurple),
      ),
      initialRoute: '/',
      routes: {
        '/': (context) => SplashPage(),
        '/login': (context) => LoginPage(),
        '/account': (context) => AccountPage(),
      },
    );
  }
}
