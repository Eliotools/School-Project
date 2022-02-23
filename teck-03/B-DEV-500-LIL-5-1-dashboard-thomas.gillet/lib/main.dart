import 'dart:convert';

import 'package:flutter/material.dart';

// Import the firebase_core plugin
import 'package:firebase_core/firebase_core.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:google_sign_in/google_sign_in.dart';
import 'package:flutter_signin_button/flutter_signin_button.dart';
import 'package:http/http.dart' as http;
import 'dart:js' as js;
import 'package:cloud_firestore/cloud_firestore.dart';

// Widgets
import '../widgets/magic_cards.dart';
import '../widgets/magic_booster.dart';
import '../widgets/magic_booster.dart';
import '../widgets/config.dart';

// Globals
import '../globals/globals.dart' as globals;

Future<void> main() async {
  WidgetsFlutterBinding.ensureInitialized();
  FirebaseApp defaultApp = await Firebase.initializeApp(
      options: const FirebaseOptions(
          apiKey: "AIzaSyChEwm_awp3KxOTbg-HnwPLNK7Ua5Kf_RI",
          authDomain: "dashboard-310bb.firebaseapp.com",
          projectId: "dashboard-310bb",
          storageBucket: "dashboard-310bb.appspot.com",
          messagingSenderId: "855329204966",
          appId: "1:855329204966:web:fb280aeee06be9cd0d2927"));

  runApp(SignUpApp());
}

class SignUpApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      routes: {
        '/': (context) => SignUpScreen(),
        '/welcome': (context) => WelcomeScreen(),
        '/dashboard': (context) => DashboardW(),
      },
    );
  }
}

class SignUpScreen extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.grey[200],
      body: Center(
        child: SizedBox(
          width: 400,
          child: Card(
            child: SignUpForm(),
          ),
        ),
      ),
    );
  }
}

class SignUpForm extends StatefulWidget {
  @override
  _SignUpFormState createState() => _SignUpFormState();
}

class _SignUpFormState extends State<SignUpForm> {
  FirebaseAuth auth = FirebaseAuth.instance;
  final _emailTextController = TextEditingController();
  final _passwordTextController = TextEditingController();
  bool _passwordVisible = false;

  double _formProgress = 0;

  @override
  // final Future<FirebaseApp> _initialization = Firebase.initializeApp();

  @override
  Future<UserCredential> signInWithGoogle() async {
    // Trigger the authentication flow
    GoogleAuthProvider googleProvider = GoogleAuthProvider();

    googleProvider
        .addScope('https://www.googleapis.com/auth/contacts.readonly');
    googleProvider.setCustomParameters({'login_hint': 'user@example.com'});

    // Once signed in, return the UserCredential
    return await FirebaseAuth.instance.signInWithPopup(googleProvider);
  }

  void googleConnection() async {
    print(signInWithGoogle().then((value) {
      Navigator.of(context).pushNamed("/dashboard");
    }));
  }

  void Register() async {
    if (RegExp(
            r"^[a-zA-Z0-9.a-zA-Z0-9.!#$%&'*+-/=?^_`{|}~]+@[a-zA-Z0-9]+\.[a-zA-Z]+")
        .hasMatch(_emailTextController.value.text)) {
      try {
        UserCredential userCredential = await FirebaseAuth.instance
            .createUserWithEmailAndPassword(
                email: _emailTextController.value.text,
                password: _passwordTextController.value.text);
        Navigator.of(context).pushNamed('/dashboard');
      } on FirebaseAuthException catch (e) {
        if (e.code == 'weak-password') {
          print('The password provided is too weak.');
          js.context.callMethod(
              "alert", <String>["The password provided is too weak."]);
        } else if (e.code == 'email-already-in-use') {
          print('The account already exists for that email.');
          js.context.callMethod(
              "alert", <String>["The account already exists for that email."]);
        }
      } catch (e) {
        print(e);
      }
    } else {
      print("Need a valid Email");
      js.context.callMethod("alert", <String>["Need a valide Email."]);
    }
  }

  void SignIn() async {
    if (RegExp(
            r"^[a-zA-Z0-9.a-zA-Z0-9.!#$%&'*+-/=?^_`{|}~]+@[a-zA-Z0-9]+\.[a-zA-Z]+")
        .hasMatch(_emailTextController.value.text)) {
      try {
        UserCredential userCredential = await FirebaseAuth.instance
            .signInWithEmailAndPassword(
                email: _emailTextController.value.text,
                password: _passwordTextController.value.text);
        Navigator.of(context).pushNamed('/dashboard');
      } on FirebaseAuthException catch (e) {
        if (e.code == 'user-not-found') {
          print('No user found for that email.');
          js.context
              .callMethod("alert", <String>["No user found for that email."]);
        } else if (e.code == 'wrong-password') {
          print('Wrong password provided for that user.');
          js.context.callMethod(
              "alert", <String>["Wrong password provided for that user."]);
        }
      }
    } else {
      print("Need a valid Email");
      js.context.callMethod("alert", <String>["Need a valide Email."]);
    }
  }

  void _showWelcomeScreen() {
    Navigator.of(context).pushNamed('/welcome');
  }

  void _updateFormProgress() {
    var progress = 0.0;
    final controllers = [
      _emailTextController,
      _passwordTextController,
    ];

    for (final controller in controllers) {
      if (controller.value.text.isNotEmpty) {
        progress += 1 / controllers.length;
      }
    }

    setState(() {
      _formProgress = progress;
    });
  }

  Widget build(BuildContext context) {
    return Form(
      onChanged: _updateFormProgress,
      child: Column(
        mainAxisSize: MainAxisSize.min,
        children: [
          LinearProgressIndicator(
              value: _formProgress,
              backgroundColor: Colors.indigo.shade200,
              color: Colors.indigo.shade400),
          Padding(padding: EdgeInsets.all(8.0)),
          Text('Dashboard',
              style: TextStyle(color: Colors.indigo.shade400, fontSize: 20)),
          Padding(
            padding: EdgeInsets.all(8.0),
            child: TextFormField(
              style: TextStyle(color: Colors.indigo.shade400),
              controller: _emailTextController,
              decoration: InputDecoration(
                  hintText: 'Email',
                  border: OutlineInputBorder(
                      borderSide: BorderSide(color: Colors.indigo.shade200)),
                  focusedBorder: OutlineInputBorder(
                      borderSide: BorderSide(color: Colors.indigo.shade400))),
            ),
          ),
          Padding(
            padding: EdgeInsets.all(8.0),
            child: TextFormField(
              obscureText: !_passwordVisible,
              style: TextStyle(color: Colors.indigo.shade400),
              controller: _passwordTextController,
              decoration: InputDecoration(
                  suffixIcon: IconButton(
                    icon: Icon(
                      _passwordVisible
                          ? Icons.visibility
                          : Icons.visibility_off,
                      color: Colors.indigo.shade400,
                      size: 18,
                    ),
                    onPressed: () {
                      setState(() {
                        _passwordVisible = !_passwordVisible;
                      });
                    },
                  ),
                  hintText: 'Password',
                  border: OutlineInputBorder(
                      borderSide: BorderSide(color: Colors.indigo.shade200)),
                  focusedBorder: OutlineInputBorder(
                      borderSide: BorderSide(color: Colors.indigo.shade400))),
            ),
          ),
          Center(
            child: SignInButton(
              Buttons.Google,
              onPressed: googleConnection,
            ),
          ),
          Center(
            child: Row(
                mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                children: [
                  Container(
                    padding: EdgeInsets.only(top: 10, bottom: 10),
                    child: OutlinedButton.icon(
                      icon: Icon(Icons.app_registration_rounded, size: 12),
                      style: ButtonStyle(
                        foregroundColor: MaterialStateProperty.resolveWith(
                            (Set<MaterialState> states) {
                          return states.contains(MaterialState.disabled)
                              ? null
                              : Colors.white;
                        }),
                        backgroundColor: MaterialStateProperty.resolveWith(
                            (Set<MaterialState> states) {
                          return states.contains(MaterialState.disabled)
                              ? null
                              : Colors.indigo.shade400;
                        }),
                      ),
                      onPressed: _formProgress == 1 ? Register : null,
                      label: Text('Sign up'),
                    ),
                  ),
                  Container(
                    padding: EdgeInsets.only(top: 10, bottom: 10),
                    child: OutlinedButton.icon(
                      icon: Icon(Icons.subdirectory_arrow_right_outlined,
                          size: 12),
                      style: ButtonStyle(
                        foregroundColor: MaterialStateProperty.resolveWith(
                            (Set<MaterialState> states) {
                          return states.contains(MaterialState.disabled)
                              ? null
                              : Colors.white;
                        }),
                        backgroundColor: MaterialStateProperty.resolveWith(
                            (Set<MaterialState> states) {
                          return states.contains(MaterialState.disabled)
                              ? null
                              : Colors.indigo.shade400;
                        }),
                      ),
                      onPressed: _formProgress == 1 ? SignIn : null,
                      label: Text('Sign In'),
                    ),
                  )
                ]),
          )
        ],
      ),
    );
  }
}

class WelcomeScreen extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Center(
        child: TextButton(
          onPressed: () {
            Navigator.of(context).pushNamed("/dashboard");
          },
          child: Text('Load dashboard'),
        ),
      ),
    );
  }
}

class DashboardW extends StatefulWidget {
  const DashboardW({Key? key}) : super(key: key);

  @override
  State<DashboardW> createState() => _Dashboard();
}

class _Dashboard extends State<DashboardW> {
  @override
  bool _update = false;
  CollectionReference users =
      FirebaseFirestore.instance.collection('utilisateurs');

  dynamic getMarker() async {
    print("STP");
    DocumentSnapshot doc = await users.doc("tOyQIrdu1exQoPEfwRFC").get();
    print(doc.data());
  }

  void saveAndSignOut() {
    List<dynamic> toSave = [];
    for (var i = 0; i < globals.widgets.length; i++) {
      var obj = {
        'name': globals.widgets[i].name,
        "configuration": globals.widgets[i].configuration,
        "timer": globals.widgets[i].timer
      };
      toSave.add(obj);
    }
    print(toSave);
  }

  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.grey[200],
      appBar: AppBar(
          backgroundColor: Colors.indigo.shade400,
          centerTitle: true,
          title: const Text("Dashboard"),
          leading: IconButton(
              onPressed: saveAndSignOut,
              icon: Icon(Icons.power_settings_new_outlined, size: 22))),
      body: Stack(
        children: [
          GridView.count(
            crossAxisCount: 3,
            mainAxisSpacing: 1,
            crossAxisSpacing: 1,
            padding: EdgeInsets.zero,
            children: [
              Stack(
                children: [
                  globals.widgets[0],
                  Container(
                    padding: EdgeInsets.all(10.0),
                    child: CircleAvatar(
                        radius: 20,
                        backgroundColor: Colors.indigo.shade400,
                        child: IconButton(
                          tooltip: "Config",
                          onPressed: () => setState(() {
                            globals.widgets[0] = ConfigW(id: 0);
                          }),
                          icon: const Icon(Icons.settings_rounded,
                              color: Colors.white),
                        )),
                  ),
                ],
              ),
              Stack(
                children: [
                  globals.widgets[1],
                  Container(
                    padding: EdgeInsets.all(10.0),
                    child: CircleAvatar(
                        radius: 20,
                        backgroundColor: Colors.indigo.shade400,
                        child: IconButton(
                          tooltip: "Config",
                          onPressed: () => setState(() {
                            globals.widgets[1] = ConfigW(id: 1);
                          }),
                          icon: const Icon(Icons.settings_rounded,
                              color: Colors.white),
                        )),
                  )
                ],
              ),
              Stack(
                children: [
                  globals.widgets[2],
                  Container(
                    padding: EdgeInsets.all(10.0),
                    child: CircleAvatar(
                        radius: 20,
                        backgroundColor: Colors.indigo.shade400,
                        child: IconButton(
                          tooltip: "Config",
                          onPressed: () => setState(() {
                            globals.widgets[2] = ConfigW(id: 2);
                          }),
                          icon: const Icon(Icons.settings_rounded,
                              color: Colors.white),
                        )),
                  )
                ],
              ),
              Stack(
                children: [
                  globals.widgets[3],
                  Container(
                    padding: EdgeInsets.all(10.0),
                    child: CircleAvatar(
                        radius: 20,
                        backgroundColor: Colors.indigo.shade400,
                        child: IconButton(
                          tooltip: "Config",
                          onPressed: () => setState(() {
                            globals.widgets[3] = ConfigW(id: 3);
                          }),
                          icon: const Icon(Icons.settings_rounded,
                              color: Colors.white),
                        )),
                  )
                ],
              ),
              Stack(
                children: [
                  globals.widgets[4],
                  Container(
                    padding: EdgeInsets.all(10.0),
                    child: CircleAvatar(
                        radius: 20,
                        backgroundColor: Colors.indigo.shade400,
                        child: IconButton(
                          tooltip: "Config",
                          onPressed: () => setState(() {
                            globals.widgets[4] = ConfigW(id: 4);
                          }),
                          icon: const Icon(Icons.settings_rounded,
                              color: Colors.white),
                        )),
                  )
                ],
              ),
              Stack(
                children: [
                  globals.widgets[5],
                  Container(
                    padding: EdgeInsets.all(10.0),
                    child: CircleAvatar(
                        radius: 20,
                        backgroundColor: Colors.indigo.shade400,
                        child: IconButton(
                          tooltip: "Config",
                          onPressed: () => setState(() {
                            globals.widgets[5] = ConfigW(id: 5);
                          }),
                          icon: const Icon(Icons.settings_rounded,
                              color: Colors.white),
                        )),
                  )
                ],
              ),
              Stack(
                children: [
                  globals.widgets[6],
                  Container(
                    padding: EdgeInsets.all(10.0),
                    child: CircleAvatar(
                        radius: 20,
                        backgroundColor: Colors.indigo.shade400,
                        child: IconButton(
                          tooltip: "Config",
                          onPressed: () => setState(() {
                            globals.widgets[6] = ConfigW(id: 6);
                          }),
                          icon: const Icon(Icons.settings_rounded,
                              color: Colors.white),
                        )),
                  )
                ],
              ),
              Stack(
                children: [
                  globals.widgets[7],
                  Container(
                    padding: EdgeInsets.all(10.0),
                    child: CircleAvatar(
                        radius: 20,
                        backgroundColor: Colors.indigo.shade400,
                        child: IconButton(
                          tooltip: "Config",
                          onPressed: () => setState(() {
                            globals.widgets[7] = ConfigW(id: 7);
                          }),
                          icon: const Icon(Icons.settings_rounded,
                              color: Colors.white),
                        )),
                  )
                ],
              ),
              Stack(
                children: [
                  globals.widgets[8],
                  Container(
                    padding: EdgeInsets.all(10.0),
                    child: CircleAvatar(
                        radius: 20,
                        backgroundColor: Colors.indigo.shade400,
                        child: IconButton(
                          tooltip: "Config",
                          onPressed: () => setState(() {
                            globals.widgets[8] = ConfigW(id: 8);
                          }),
                          icon: const Icon(Icons.settings_rounded,
                              color: Colors.white),
                        )),
                  )
                ],
              ),
            ],
          )
        ],
      ),
      floatingActionButton: FloatingActionButton(
        onPressed: () => setState(() => _update = !_update),
        tooltip: "Update Widget",
        child: const Icon(Icons.update),
      ),
    );
  }
}
