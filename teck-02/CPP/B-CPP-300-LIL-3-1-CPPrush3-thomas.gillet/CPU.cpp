/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPrush3-thomas.gillet
** File description:
** CPU
*/

#include "info.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <sys/utsname.h>
#include <boost/asio/ip/host_name.hpp>
#include <boost/algorithm/string.hpp>

CPU::CPU()
{
    reset();
}

CPU::~CPU()
{
}

void CPU::printCPU()
{
    std::cout << _model <<std::endl;
    std::cout << _nb_cores <<std::endl;
    std::cout << _frequency <<std::endl;
    std::cout << _activity <<std::endl;
}

std::string CPU::getModel()
{
    return _model;
}

std::string CPU::getFrequency()
{
    return _frequency;
}

std::string CPU::getNbcore()
{
    return _nb_cores;
}

std::string CPU::getActivity()
{
    return _activity;
}

float CPU::reset()
{
    int finded = 0;
    std::ifstream my_info("/proc/cpuinfo");
    std::string arg;
    
    while(getline(my_info, arg))
    {
        if ((finded = arg.find("model name")) != std::string::npos) {
            _model = arg.substr(arg.find(":")+2, arg.find("CPU") - 14);
        }
        if ((finded = arg.find("cpu cores")) != std::string::npos) {
            _nb_cores = arg.substr(arg.find(":")+2);
        }
        if ((finded = arg.find("model name")) != std::string::npos) {
            _frequency = arg.substr(arg.find("@")+2);
        }
        if ((finded = arg.find("cpu MHz")) != std::string::npos) {
            _activity = arg.substr(arg.find(":")+2) + "Hz";
        }
    }
    _percent = (stof(_frequency) * 100000) / stof(_activity);
    return _percent;
}