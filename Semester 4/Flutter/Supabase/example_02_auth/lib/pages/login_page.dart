import 'dart:async';
import 'package:example_02_auth/main.dart';
import 'package:flutter/material.dart';
import 'package:supabase_flutter/supabase_flutter.dart';

class LoginPage extends StatefulWidget {
  const LoginPage({super.key});

  @override
  State<LoginPage> createState() => _LoginPageState();
}

class _LoginPageState extends State<LoginPage> {
  final _emailController = TextEditingController();
  late final StreamSubscription<AuthState> _authSubscription;

  @override
  void initState(){
    super.initState();
    _authSubscription = supabase.auth.onAuthStateChange.listen((event) {
      final session = event.session;
      if(session != null){
        Navigator.of(context).pushReplacementNamed('/account');
      }
    });
  }

  @override
  void dispose() {
    _emailController.dispose();
    _authSubscription.cancel();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: const Text('Login')),
      body: ListView(
        padding: EdgeInsets.all(12),
        children: [
          TextFormField(
            controller: _emailController,
            decoration: InputDecoration(
              label: Text('Email'),
              hintText: 'Enter your email',
            ),
          ),
          SizedBox(height: 12,),
          ElevatedButton(onPressed: () async {
            try{
              await supabase.auth.signInWithOtp(email: _emailController.text.trim(),
              emailRedirectTo: 'io.supabase.flutterquickstart://login-callback/');
              if(mounted){
                ScaffoldMessenger.of(context).showSnackBar(SnackBar(content: Text('Check your inbox!')));
              }
            }catch(e){
              if(mounted){
                ScaffoldMessenger.of(context).showSnackBar(SnackBar(content: Text(e.toString()), backgroundColor: Theme.of(context).colorScheme.error,));
              }
            }
          }, child: Text('Login'),),
        ],
      ),
    );
  }
}
