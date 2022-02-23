/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD07A-eliot.martin
** File description:
** Skat
*/

#include "Skat.hpp"
#include <string>
#include <ostream>
#include <iostream>

Skat::Skat(const std::string &name , int stimPaks)
{
    this->_name = name;
    this->_stimpaks = stimPaks;
}

Skat::~Skat()
{
}

int Skat::stimPaks()
{
    return(this->_stimpaks);
}

const std::string &Skat::name()
{
    return(this->_name);
}

void Skat::shareStimPaks(int number, int stock)
{
    if ((this->_stimpaks - number) < 0)
        std::cout << "Don't be greedy" << std::endl;
    else {
        std::cout << "Keep de change." << std::endl;
        stock += number;
    }
}


void Skat::addStimPaks(unsigned int number)
{
    if (number == 0)
        std::cout << "Hey boya, did you forget something?" << std::endl;
    this->_stimpaks += number;
}

void Skat::useStimPaks()
{
    if (this->_stimpaks < 1)
        std::cout << "Mediiiiiic" << std::endl;
    else {
        std::cout << "Time to kick some ass and chew bubble gum." << std::endl;
        this->_stimpaks -= 1;
    }
}

void Skat::status()
{
        std::cout << "Soldier "<<this->_name <<" reporting "<<this->_stimpaks<< " stimpaks remaining sir!" << std::endl;
}
