/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPrush3-thomas.gillet
** File description:
** RAM
*/

#include "info.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <sys/utsname.h>
#include <boost/asio/ip/host_name.hpp>
#include <boost/algorithm/string.hpp>

RAM::RAM()
{
    reset();
}

RAM::~RAM()
{

}

void RAM::printRAM()
{
    std::cout << _total <<std::endl;
    std::cout << _free <<std::endl;
    std::cout << _percent <<std::endl;
}

float RAM::getTotal()
{
    return _total;
}

float RAM::getFree()
{
    return _free;
}

float RAM::getPercent()
{
    return _percent;
}

float RAM::reset()
{
    int finded = 0;
    std::ifstream my_info("/proc/meminfo");
    std::string arg;
    while(getline(my_info, arg))
    {
        //std::cout << arg << std::endl;
        if ((finded = arg.find("MemTotal:")) != std::string::npos) {
            arg = arg.substr(arg.find(":")+2, arg.length()-13);
            boost::erase_all(arg, " ");
            _total = stoi(arg);

        }
        if ((finded = arg.find("MemFree:")) != std::string::npos) {
            arg = arg.substr(arg.find(":")+2, arg.length()-11);
            boost::erase_all(arg, " ");
            _free = stoi(arg);
        }
    }
    _percent = (100 * _free) / _total;
    //std::cout << "percent : " << _percent << std::endl;
    return _percent;
}