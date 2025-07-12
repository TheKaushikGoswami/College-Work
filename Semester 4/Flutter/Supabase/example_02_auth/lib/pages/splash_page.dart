import 'package:example_02_auth/main.dart';
import 'package:flutter/material.dart';


class SplashPage extends StatefulWidget{
  const SplashPage({super.key});

  @override
  State<SplashPage> createState() => _SplashPageState();
}

class _SplashPageState extends State<SplashPage> {
  @override void initState() {
    // TODO: implement initState
    super.initState();
    _redirect();
  }

  Future<void> _redirect() async{
    await Future.delayed(Duration.zero);
    final session = supabase.auth.currentSession;

    if(!mounted) return;

    if(session != null){
      Navigator.of(context).pushReplacementNamed('/account');
    }else{
      Navigator.of(context).pushReplacementNamed('/login');
    }
  }

  @override
  Widget build(BuildContext context){
    return const Scaffold(
      body: Center(
        child: CircularProgressIndicator(),
      )
    );
  }
}