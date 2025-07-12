import 'package:example_02_auth/main.dart';
import 'package:flutter/material.dart';

class AccountPage extends StatefulWidget {
  const AccountPage({super.key});

  @override
  State<AccountPage> createState() => _AccountPageState();
}

class _AccountPageState extends State<AccountPage> {
  final _usernameController = TextEditingController();
  final _websiteController = TextEditingController();

  @override
  void dispose() {
    // TODO: implement dispose
    _usernameController.dispose();
    _websiteController.dispose();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    // TODO: implement build
    return Scaffold(
      appBar: AppBar(title: Text('Account')),
      body: ListView(
        padding: EdgeInsets.all(20),
        children: [
          TextFormField(
            controller: _usernameController,
            decoration: InputDecoration(
              label: Text('Username')
            ),
          ),
          SizedBox(height: 12,),
          TextFormField(
            controller: _websiteController,
            decoration: InputDecoration(
              label: Text('Website')
            ),
          ),
          SizedBox(height: 12,),
          ElevatedButton(
            onPressed: () async {
              final username = _usernameController.text.trim();
              final website = _websiteController.text.trim();

              await supabase.from('profiles').update(
                  {
                    'username': username,
                    'website': website
                  }
              ).eq('id', supabase.auth.currentUser!.id);
            },
            child: Text('Save'),
          )
        ],
      )
    );
  }
}