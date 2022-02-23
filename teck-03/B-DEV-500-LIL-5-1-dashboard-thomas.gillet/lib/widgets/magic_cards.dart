import 'dart:convert';

import 'package:flutter/material.dart';

// Import the firebase_core plugin
import 'package:firebase_core/firebase_core.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:http/http.dart' as http;
import 'dart:js' as js;

class CardsW extends StatefulWidget {
  final String name = "Card";
  final String timer = "No-Timer";
  final String configuration = "No-Config";
  const CardsW({Key? key}) : super(key: key);
  @override
  State<CardsW> createState() => _Cards();
}

class _Cards extends State<CardsW> {
  @override
  final _nameTextController = TextEditingController();
  String dropdownValue = 'Red';
  List<dynamic> cards = [];
  List<dynamic> tmp = [];
  bool _load = false;

  Future<List<dynamic>> getInfo() async {
    _load = true;
    var url = Uri.parse(
        'http://localhost:8080/magic/cards/name=${_nameTextController.value.text}&colors=${dropdownValue}');

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
                resizeToAvoidBottomInset: true,
                appBar: AppBar(
                    backgroundColor: Colors.white,
                    centerTitle: true,
                    title: Text(
                      "Magic Cards",
                      style: TextStyle(color: Colors.indigo.shade400),
                    )),
                body: Column(
                  children: [
                    Container(
                      margin: EdgeInsets.all(10),
                      decoration: BoxDecoration(
                          borderRadius: BorderRadius.circular(10),
                          border: Border.all(
                              color: Colors.indigo.shade200, width: 2)),
                      child: Row(
                          mainAxisAlignment: MainAxisAlignment.spaceBetween,
                          children: [
                            Expanded(
                              flex: 4,
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
                                  labelText: 'Search Magic\'s Card',
                                  labelStyle:
                                      TextStyle(color: Colors.indigo.shade400),
                                  prefixIcon: IconButton(
                                      onPressed: getInfo,
                                      icon: Icon(Icons.search_rounded,
                                          size: 20,
                                          color: Colors.indigo.shade400)),
                                ),
                              ),
                            ),
                            Expanded(
                              flex: 1,
                              child: DropdownButton<String>(
                                style: TextStyle(
                                    color: Colors.indigo.shade400,
                                    fontSize: 20),
                                value: dropdownValue,
                                icon: Icon(Icons.arrow_downward_rounded,
                                    size: 20, color: Colors.indigo.shade200),
                                onChanged: (String? newValue) {
                                  setState(() {
                                    dropdownValue = newValue!;
                                    //getInfo();
                                  });
                                },
                                items: <String>[
                                  'Red',
                                  'Blue',
                                  'Green',
                                  'Black',
                                  'White'
                                ].map<DropdownMenuItem<String>>((String value) {
                                  return DropdownMenuItem<String>(
                                    value: value,
                                    child: Text(value),
                                  );
                                }).toList(),
                              ),
                            ),
                          ]),
                    ),
                    Container(
                      margin: EdgeInsets.all(12),
                      height: MediaQuery.of(context).size.height / 2 - 90,
                      child: ListView.builder(
                        shrinkWrap: true,
                        itemCount: cards.length,
                        itemBuilder: (BuildContext context, int index) {
                          return Container(child: Text(cards[index]['name']));
                        },
                      ),
                    )
                  ],
                ))));
  }
}
