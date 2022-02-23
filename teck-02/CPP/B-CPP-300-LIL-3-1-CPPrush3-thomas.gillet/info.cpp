/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPrush3-thomas.gillet
** File description:
** info
*/

#include "info.hpp"
#include <iostream>
#include <sys/utsname.h>
#include <boost/asio/ip/host_name.hpp>
#include <boost/algorithm/string.hpp>

info::info()
{
    struct utsname my_struct;
    int tmp = uname(&my_struct);

    if (tmp) {
        std::cerr << "error -> exit" << std::endl;
        exit(-1);
    } 
    _hostname = boost::asio::ip::host_name();
    _sys_name = my_struct.sysname;
    _kernel_ver = my_struct.release;
    setDate();
    setUsername();
    //_my_cpu = new CPU;
    //_my_ram = new RAM;
}

info::~info()
{
    //delete _my_cpu;
    //delete _my_ram;
}

void info::printAll()
{
    std::cerr << "----Printing Info----" << std::endl;
    std::cerr << "_username = " << _username << std::endl; 
    std::cerr << "_hostname = " << _hostname << std::endl; 
    std::cerr << "_sys_name = " << _sys_name << std::endl; 
    std::cerr << "_kernel_ver = " << _kernel_ver << std::endl; 
    std::cerr << "_date = " << _date << std::endl; 
    std::cerr << "CPU->_model = " << _my_cpu.getModel()<< std::endl;
    std::cerr << "CPU->_frequancy = " << _my_cpu.getFrequency()<< std::endl;
    std::cerr << "CPU->_nb_core = " << _my_cpu.getNbcore()<< std::endl;
    std::cerr << "CPU->_activity = " << _my_cpu.getActivity()<< std::endl;
    std::cerr << "RAM->_total = " << _my_ram.getTotal()<< std::endl;
    std::cerr << "RAM->_free = " << _my_ram.getFree()<< std::endl;
    std::cerr << "RAM->_percent = " << _my_ram.getPercent()<< std::endl;
}

void info::setDate()
{
    time_t now = time(0);
    _date = ctime(&now);
    boost::erase_all(_date, "\n");
}
void info::setUsername()
{
    char text[255];
    FILE *name;
    name = popen("whoami", "r");
    fgets(text, sizeof(text), name);
    _username = text;
    boost::erase_all(_username, "\n");
    
}

std::string info::getHostname()
{
    return _hostname;
}

std::string info::getSysname()
{
    return _sys_name;
}

std::string info::getUsername()
{
    return _username;
}

std::string info::getKernelver()
{
    return _kernel_ver;
}

std::string info::getDate()
{
    return _date;
}

int info::getLongest()
{
    int size = _hostname.size();
    if (size < _username.size())
        size = _username.size();
    if (size < _sys_name.size())
        size = _sys_name.size();
    if (size < _kernel_ver.size())
        size = _kernel_ver.size();
    if (size < _date.size())
        size = _date.size();
    
    return size;
}