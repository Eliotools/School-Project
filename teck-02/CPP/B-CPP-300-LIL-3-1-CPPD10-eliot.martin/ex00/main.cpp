/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD10-eliot.martin
** File description:
** main
*/

#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"
#include <string>
#include <iostream>

int main()
{
    Sorcerer s("BillyBob", "Tueur de dragon");
    Victim v("Loic");
    Peon p("bite");
    std::cout << s << v << p;
    s.polymorph(v);
    s.polymorph(p);
    return 0;
}