import 'dart:convert';

import 'package:dashboard/widgets/astro.dart';
import 'package:dashboard/widgets/epitech.dart';
import 'package:dashboard/widgets/magic_booster.dart';
import 'package:dashboard/widgets/magic_cards.dart';
import 'package:dashboard/widgets/spotify.dart';
import 'package:dashboard/widgets/weather.dart';
import 'package:dashboard/widgets/cryp.dart';
import 'package:flutter/material.dart';

// Import the firebase_core plugin
import 'package:firebase_core/firebase_core.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:http/http.dart' as http;
import 'dart:js' as js;

// Globals
import '../globals/globals.dart' as globals;

class ConfigW extends StatefulWidget {
  @required
  final int id;
  final String name = "Config";
  final String configuration = "No-Config";
  final String timer = "No-Timer";
  const ConfigW({Key? key, required this.id}) : super(key: key);
  @override
  State<ConfigW> createState() => _Config();
  int getId() {
    return id;
  }
}

class _Config extends State<ConfigW> {
  int pos = 0;
  String name = "Config";

  dynamic getWidget(dynamic widget_s) {
    setState(() {
      globals.widgets[widget.id] = widget_s;
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
                    "Config",
                    style: TextStyle(color: Colors.indigo.shade400),
                  ),
                ),
                body: Center(
                  child: Column(
                      mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                      children: [
                        OutlinedButton(
                            onPressed: () {
                              getWidget(CardsW());
                            },
                            child: Text("Magic:Cards")),
                        OutlinedButton(
                            onPressed: () {
                              getWidget(SpotifyW());
                            },
                            child: Text("Spotify")),
                        OutlinedButton(
                            onPressed: () {
                              getWidget(BoosterW());
                            },
                            child: Text("Magic:Booster")),
                        OutlinedButton(
                            onPressed: () {
                              getWidget(WeatherW());
                            },
                            child: Text("Weather:Current")),
                        OutlinedButton(
                            onPressed: () {
                              getWidget(AstroW());
                            },
                            child: Text("Weather:Astro")),
                        OutlinedButton(
                            onPressed: () {
                              getWidget(EpitechW());
                            },
                            child: Text("Epitech:Messages")),
                        OutlinedButton(
                            onPressed: () {
                              getWidget(CrypW());
                            },
                            child: Text("Crypto")),
                      ]),
                ))));
  }
}
