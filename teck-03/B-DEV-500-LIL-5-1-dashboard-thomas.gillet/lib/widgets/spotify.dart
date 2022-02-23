import 'dart:convert';

import 'package:dashboard/globals/globals.dart';
import 'package:flutter/material.dart';

// Import the firebase_core plugin
import 'package:firebase_core/firebase_core.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:url_launcher/url_launcher.dart';
import 'package:flutter_html/flutter_html.dart';
import 'package:html/dom.dart' as dom;
import 'package:http/http.dart' as http;
import 'dart:js' as js;

class SpotifyW extends StatefulWidget {
  final String name = "Spotify";
  String configuration = "";
  String timer = "";
  SpotifyW({Key? key}) : super(key: key);
  @override
  State<SpotifyW> createState() => _Spotify();
}

class _Spotify extends State<SpotifyW> {
  @override
  final _idTextController = TextEditingController();
  final _secretTextController = TextEditingController();
  String info = "Wait for login";

  void getLog() async {
    var url = Uri.parse(
        'http://localhost:8080/spotify/login/${_idTextController.value.text}&${_secretTextController.value.text}');
    print(url);
    var response = await http.get(url);
    print('Response status: ${response.statusCode}');
    print('Response body: ${response.body}');

    setState(() {
      info = jsonDecode(response.body);
    });
  }

  Widget build(BuildContext context) {
    return SizedBox(
        width: MediaQuery.of(context).size.width / 3,
        height: MediaQuery.of(context).size.height / 2 + 150,
        child: Card(
            child: Scaffold(
          appBar: AppBar(
              backgroundColor: Colors.white,
              centerTitle: true,
              title: Text(
                "Spotify Login",
                style: TextStyle(color: Colors.indigo.shade400),
              )),
          body: Column(children: [
            Container(
              margin: EdgeInsets.all(10),
              decoration: BoxDecoration(
                  borderRadius: BorderRadius.circular(10),
                  border: Border.all(color: Colors.indigo.shade200, width: 2)),
              child: Column(
                children: [
                  Row(
                    children: [
                      Expanded(
                        flex: 3,
                        child: TextFormField(
                          controller: _idTextController,
                          style: TextStyle(color: Colors.indigo.shade400),
                          decoration: InputDecoration(
                            border: InputBorder.none,
                            focusedBorder: InputBorder.none,
                            enabledBorder: InputBorder.none,
                            errorBorder: InputBorder.none,
                            disabledBorder: InputBorder.none,
                            isDense: true,
                            labelText: 'Client_Id',
                            labelStyle:
                                TextStyle(color: Colors.indigo.shade400),
                          ),
                        ),
                      ),
                      Expanded(
                          flex: 3,
                          child: TextFormField(
                              controller: _secretTextController,
                              style: TextStyle(color: Colors.indigo.shade400),
                              decoration: InputDecoration(
                                border: InputBorder.none,
                                focusedBorder: InputBorder.none,
                                enabledBorder: InputBorder.none,
                                errorBorder: InputBorder.none,
                                disabledBorder: InputBorder.none,
                                isDense: true,
                                labelText: 'Client_secret',
                                labelStyle:
                                    TextStyle(color: Colors.indigo.shade400),
                              ))),
                      Expanded(
                        flex: 1,
                        child:
                            TextButton(onPressed: getLog, child: Text("Login")),
                      )
                    ],
                  ),
                ],
              ),
            ),
            Text(info)
          ]),
        )));
  }
}
