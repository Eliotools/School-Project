/*
** EPITECH PROJECT, 2021
** B-OOP-400-LIL-4-1-tekspice-thomas.gillet [WSL: Ubuntu]
** File description:
** main
*/

#include "Chipset.hpp"
#include "IComponent.hpp"
#include "And_4081.hpp"
#include "Or_4071.hpp"
#include "Error.hpp"
#include "Parser.hpp"
#include <iostream>
#include <vector>
#include <memory>
#include <cstdio>
#include <fstream>
#include <cassert>
#include <functional>

//Class Parser
void inputToValue(std::string cmd, Component *gate)
{
    std::string input = cmd.substr(0, cmd.find("="));
    int value = std::stoi(cmd.substr(cmd.find("=")+1, std::string::npos));
    pinData *in = gate->getPinByName(input);
    if (in == nullptr)
        //ERROR NULLPTR
        return;
    gate->setState(in, gate->intToTristate(value));
}

std::string giveMyGate(std::string file)
{
    int my_switch = 0;
    std::string tmp;
    std::string tmp_2;
    std::string tmp_3;
    std::ifstream myfile (file);
    std::string gate;
    while (getline (myfile, tmp)) {
        if(!tmp.compare(".links:"))
            return ("error");
        if(!tmp.compare(".chipsets:")) {
            my_switch = 1;
            continue;
        }
        if (my_switch == 1)
        {
            tmp_2 = tmp.substr(tmp.find(' ')+1);
            tmp_3 = tmp.substr(0, tmp.find(' '));
            if (tmp_3 != "input" && tmp_3 != "output")
                return tmp;
        }
    }
    return ("error");
}

And_4081 *create4081(std::string file, std::string name)
{
    return (new And_4081(file, name));
}

Or_4071 *create4071(std::string file, std::string name)
{
    return (new Or_4071(file, name));
}

Component *createComponent(std::string file, std::string name)
{
    std::string CompName = name.substr(0, name.find(' '));
    name = name.substr(name.find(' ')+1);
    if (CompName == "4081")
        return create4081(file, name);
    else if (CompName == "4071")
        return create4071(file, name);
    else
        throw ParseError("Unknow compoment");
}

int main (int ac, char **av)
{
    if (ac != 2)
        return 84;
    int tick = 0;
    std::string cmd;
    std::string gateName;
    Component* gate;
    try{
        Parser parser(av[1]);
    } catch(const std::exception& e) {
        std::cerr << "Error Parse : \033[1;31m" << e.what() << std::endl;
        return 84;
    }

    try {
        gateName = giveMyGate(av[1]);
        gate = createComponent(av[1], gateName);
        if (gateName == "error")
            throw ParseError("No name find");
    } catch(const std::exception& e) {
        std::cerr << "Error Parse : \033[1;31m" << e.what() << std::endl;
        return 84;
    }
    
    std::cout << ">";
    while (std::getline(std::cin, cmd)) {
        if (cmd == "exit")
            break;
        if (cmd == "simulate") {
            ++tick;
            gate->simulate();
        }
        if (cmd == "display") {
            std::cout << "tick: " << tick << std::endl;
            gate->displayAll();
        }
        if (cmd == "dump")
            gate->dump();
        if (cmd.find("=") != std::string::npos)
            inputToValue(cmd, gate);
        std::cout << ">";
    }
    return 0;
}