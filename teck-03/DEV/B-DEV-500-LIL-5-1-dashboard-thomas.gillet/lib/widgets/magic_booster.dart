import 'dart:convert';

import 'package:flutter/material.dart';

// Import the firebase_core plugin
import 'package:firebase_core/firebase_core.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:http/http.dart' as http;
import 'dart:js' as js;

class BoosterW extends StatefulWidget {
  final String name = "Booster";
  final String timer = "No-Timer";
  final String configuration = "No-Config";
  const BoosterW({Key? key}) : super(key: key);
  @override
  State<BoosterW> createState() => _Booster();
}

class _Booster extends State<BoosterW> {
  @override
  final _nameTextController = TextEditingController();
  String dropdownValue = 'Red';
  List<dynamic> cards = [];
  List<dynamic> tmp = [];

  Future<List<dynamic>> getInfo() async {
    var url = Uri.parse(
        'http://localhost:8080/magic/set/${_nameTextController.value.text}');

    var response = await http.get(url);
    cards = jsonDecode(response.body);
    print('Response status: ${response.statusCode}');
    cards.forEach((element) {
      print('Card => ${element['name']}');
    });
    setState(() {
      cards = jsonDecode(response.body);
    });
    return jsonDecode(response.body);
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
                "Magic Booster Generator",
                style: TextStyle(color: Colors.indigo.shade400),
              )),
          body: Column(children: [
            Container(
              margin: EdgeInsets.all(10),
              decoration: BoxDecoration(
                  borderRadius: BorderRadius.circular(10),
                  border: Border.all(color: Colors.indigo.shade200, width: 2)),
              child: Row(
                children: [
                  Expanded(
                    flex: 3,
                    child: TextFormField(
                      style: TextStyle(color: Colors.indigo.shade400),
                      controller: _nameTextController,
                      decoration: InputDecoration(
                        border: InputBorder.none,
                        focusedBorder: InputBorder.none,
                        enabledBorder: InputBorder.none,
                        errorBorder: InputBorder.none,
                        disabledBorder: InputBorder.none,
                        isDense: true,
                        labelText: 'Generate Magic\'s Booster',
                        labelStyle: TextStyle(color: Colors.indigo.shade400),
                        prefixIcon: IconButton(
                            onPressed: getInfo,
                            icon: Icon(Icons.add,
                                size: 20, color: Colors.indigo.shade400)),
                      ),
                    ),
                  ),
                ],
              ),
            ),
            Container(
              margin: EdgeInsets.all(12),
              height: MediaQuery.of(context).size.height / 2 - 135,
              child: ListView.builder(
                shrinkWrap: true,
                itemCount: cards.length,
                itemBuilder: (BuildContext context, int index) {
                  return Container(child: Text(cards[index]['name']));
                },
              ),
            )
          ]),
        )));
  }
}
