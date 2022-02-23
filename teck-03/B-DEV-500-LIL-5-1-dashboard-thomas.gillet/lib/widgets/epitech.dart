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

class EpitechW extends StatefulWidget {
  final String name = "Epitech";
  String configuration = "";
  String timer = "";
  EpitechW({Key? key}) : super(key: key);
  @override
  State<EpitechW> createState() => _Epitech();
}

class _Epitech extends State<EpitechW> {
  @override
  final _nameTextController = TextEditingController();

  String dropdownValue = "";
  List<dynamic> msg = [];
  List<dynamic> tmpName = [];
  List<String> gname = [];

  void getInfo() async {
    widget.configuration = _nameTextController.value.text;
    widget.timer = "2";
    var url = Uri.parse(
        'http://localhost:8080/teck/msg/${dropdownValue}&${_nameTextController.value.text}');

    var response = await http.get(url);
    print('Response status: ${response.statusCode}');
    setState(() {
      msg = jsonDecode(response.body);
    });
  }

  void getName() async {
    gname.clear();
    var url = Uri.parse(
        'http://localhost:8080/teck/title/${_nameTextController.value.text}');

    var response = await http.get(url);
    print('Response status: ${response.statusCode}');
    print('Response body: ${response.body}');

    tmpName = jsonDecode(response.body);
    setState(() {
      tmpName = jsonDecode(response.body);
      for (var i = 0; i < tmpName.length; i++) {
        gname.add(tmpName[i].toString());
      }
      if (gname.length > 0) dropdownValue = gname[0];
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
                "Epitech Messages",
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
                          controller: _nameTextController,
                          style: TextStyle(color: Colors.indigo.shade400),
                          decoration: InputDecoration(
                            border: InputBorder.none,
                            focusedBorder: InputBorder.none,
                            enabledBorder: InputBorder.none,
                            errorBorder: InputBorder.none,
                            disabledBorder: InputBorder.none,
                            isDense: true,
                            labelText: 'Autologin',
                            labelStyle:
                                TextStyle(color: Colors.indigo.shade400),
                            prefixIcon: IconButton(
                                onPressed: getInfo,
                                icon: Icon(Icons.add,
                                    size: 20, color: Colors.indigo.shade400)),
                          ),
                        ),
                      ),
                      Expanded(
                        flex: 1,
                        child: TextButton(
                            onPressed: getName, child: Text("Load Name")),
                      )
                    ],
                  ),
                  Row(
                    children: [
                      Expanded(
                        flex: 3,
                        child: Padding(
                          padding: EdgeInsets.only(left: 20),
                          child: DropdownButton<String>(
                            value: dropdownValue,
                            icon: const Icon(Icons.arrow_downward_rounded),
                            iconSize: 24,
                            style: TextStyle(color: Colors.indigo.shade400),
                            onChanged: (String? newValue) {
                              setState(() {
                                dropdownValue = newValue!;
                                //getInfo();
                              });
                            },
                            items: gname
                                .map<DropdownMenuItem<String>>((String value) {
                              return DropdownMenuItem<String>(
                                value: value,
                                child: Text(value),
                              );
                            }).toList(),
                          ),
                        ),
                      ),
                      Expanded(
                        flex: 1,
                        child: TextButton(
                            onPressed: getInfo, child: Text("Load Message")),
                      )
                    ],
                  )
                ],
              ),
            ),
            Container(
              height: MediaQuery.of(context).size.height / 2 - 190,
              child: ListView.builder(
                shrinkWrap: true,
                itemCount: msg.length,
                itemBuilder: (BuildContext context, int index) {
                  return Container(
                      child: Html(
                    data: msg[index],
                    onLinkTap: (url, _, __, ___) {
                      launch(url ?? "");
                    },
                  ));
                },
              ),
            )
          ]),
        )));
  }
}
