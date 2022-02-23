/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD07A-eliot.martin
** File description:
** Parts
*/

#include <iostream>
#include <string>
#include "Parts.hpp"

Arms::Arms(std::string serial, bool functional)
{
    this->_serial = serial;
    this->_functional = functional;
}

Arms::Arms(): _functional(true), _serial("A-01")
{
}

Arms::~Arms()
{
}

void Arms::informations()
{
    std::cout << "\t[Parts] Arms " << this->_serial;
    if (this->_functional)
        std::cout << " status : OK" << std::endl;
    else
        std::cout << " status : KO" << std::endl;
}

bool Arms::isFunctional()
{
    return(this->_functional);
}

std::string Arms::serial()
{
    return(this->_serial);
}

Legs::Legs(std::string serial, bool functional)
{
    this->_serial = serial;
    this->_functional = functional;
}

Legs::Legs(): _functional(true), _serial("A-01")
{
}

Legs::~Legs()
{
}

void Legs::informations()
{
    std::cout << "\t[Parts] Legs " << this->_serial;
    if (this->_functional)
        std::cout << " status : OK" << std::endl;
    else
        std::cout << " status : KO" << std::endl;
}


bool Legs::isFunctional()
{
    return(this->_functional);
}

std::string Legs::serial()
{
    return(this->_serial);
}

Head::Head(std::string serial, bool functional)
{
    this->_serial = serial;
    this->_functional = functional;
}

Head::Head(): _functional(true), _serial("A-01")
{
}

Head::~Head()
{
}

void Head::informations()
{
    std::cout << "\t[Parts] Head " << this->_serial;
    if (this->_functional)
        std::cout << " status : OK" << std::endl;
    else
        std::cout << " status : KO" << std::endl;
}

bool Head::isFunctional()
{
    return(this->_functional);
}

std::string Head::serial()
{
    return(this->_serial);
}
