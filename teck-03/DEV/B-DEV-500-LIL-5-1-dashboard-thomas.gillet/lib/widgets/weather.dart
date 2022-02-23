import 'dart:convert';
import 'dart:async';

import 'package:dashboard/globals/globals.dart';
import 'package:flutter/material.dart';
import 'package:flutter/services.dart';

// Import the firebase_core plugin
import 'package:firebase_core/firebase_core.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:http/http.dart' as http;
import 'dart:js' as js;

class WeatherW extends StatefulWidget {
  final String name = "Weather";
  String configuration = "";
  String timer = "";
  WeatherW({Key? key}) : super(key: key);
  @override
  State<WeatherW> createState() => _Weather();
}

class _Weather extends State<WeatherW> {
  @override
  final _locationTextController = TextEditingController();
  final _timerTextController = TextEditingController();
  int timer = 0;

  Timer startTimeout() {
    return Timer.periodic(Duration(minutes: timer), (Timer timer) {
      getInfo();
    });
  }

  void startAll() {
    if (_timerTextController.value.text.isEmpty) {
      js.context
          .callMethod("alert", <String>["Select Timer for Weather Widget"]);
      return;
    }
    if (int.parse(_timerTextController.value.text) <= 1) {
      js.context
          .callMethod("alert", <String>["Timer need to be more than 1 minute"]);
      return;
    }
    if (_timerTextController.value.text.isEmpty) {
      js.context.callMethod(
          "alert", <String>["Select a location for Weather Widget"]);
      return;
    }
    setState(() {
      timer = int.parse(_timerTextController.value.text);
    });
    startTimeout();
    getInfo();
  }

  var infos = {};

  void getInfo() async {
    widget.configuration = _locationTextController.value.text;
    widget.configuration = _timerTextController.value.text;
    print(_locationTextController.value.text);
    var url = Uri.parse(
        'http://localhost:8080/weather/current/${_locationTextController.value.text}');

    var response = await http.get(url);
    infos = jsonDecode(response.body);
    print('Response status: ${response.statusCode}');
    print('Response status: ${response.body}');

    print('Infos => ${infos}');
    setState(() {
      infos = jsonDecode(response.body);
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
                "Weather",
                style: TextStyle(color: Colors.indigo.shade400),
              )),
          body: Column(children: [
            Container(
              margin: EdgeInsets.all(10),
              decoration: BoxDecoration(
                  borderRadius: BorderRadius.circular(10),
                  border: Border.all(color: Colors.indigo.shade200, width: 2)),
              child: Column(
                mainAxisAlignment: MainAxisAlignment.spaceAround,
                children: [
                  Padding(
                    padding: EdgeInsets.symmetric(horizontal: 20),
                    child: TextFormField(
                      style: TextStyle(color: Colors.indigo.shade400),
                      controller: _locationTextController,
                      decoration: InputDecoration(
                        border: InputBorder.none,
                        focusedBorder: InputBorder.none,
                        enabledBorder: InputBorder.none,
                        errorBorder: InputBorder.none,
                        disabledBorder: InputBorder.none,
                        isDense: true,
                        labelText: 'City',
                        labelStyle: TextStyle(color: Colors.indigo.shade400),
                      ),
                    ),
                  ),
                  Padding(
                    padding: EdgeInsets.symmetric(horizontal: 20),
                    child: TextFormField(
                        controller: _timerTextController,
                        style: TextStyle(color: Colors.indigo.shade400),
                        decoration: InputDecoration(
                          labelText: 'Time Reload in Min',
                          labelStyle: TextStyle(color: Colors.indigo.shade400),
                          border: InputBorder.none,
                          focusedBorder: InputBorder.none,
                          enabledBorder: InputBorder.none,
                          errorBorder: InputBorder.none,
                          disabledBorder: InputBorder.none,
                          isDense: true,
                        ),
                        keyboardType: TextInputType.number,
                        inputFormatters: <TextInputFormatter>[
                          FilteringTextInputFormatter.digitsOnly
                        ]),
                  ),
                  TextButton(child: Text("Load Data"), onPressed: getInfo)
                ],
              ),
            ),
            Container(
                height: MediaQuery.of(context).size.height / 2 - 135,
                child: Column(
                  mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                  children: [
                    Text(infos.isEmpty == false
                        ? "Last update: " +
                            infos['current']['last_updated'].toString()
                        : ""),
                    Text(infos.isEmpty == false
                        ? infos['location']['name']
                        : ""),
                    Text(infos.isEmpty == false
                        ? infos['location']['region'] +
                            ", " +
                            infos['location']['country']
                        : ""),
                    Text(infos.isEmpty == false
                        ? infos['current']['temp_c'].toString() + " C"
                        : ""),
                    Text(infos.isEmpty == false
                        ? "Ressenti: " +
                            infos['current']['feelslike_c'].toString() +
                            " C"
                        : ""),
                    Text(infos.isEmpty == false
                        ? infos['current']['condition']['text']
                        : ""),
                    Image.network(infos.isEmpty == false
                        ? "https:" +
                            infos['current']['condition']['icon'].toString()
                        : 'https://cdn.weatherapi.com/weather/64x64/day/113.png'),
                  ],
                ))
          ]),
        )));
  }
}
