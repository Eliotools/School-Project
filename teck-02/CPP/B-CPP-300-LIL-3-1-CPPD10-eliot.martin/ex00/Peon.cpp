/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD10-eliot.martin
** File description:
** Peon
*/

#include "Peon.hpp"
#include <string>
#include <iostream>

Peon::Peon(std::string name) : Victim(name)
{
    std::cout << "Zog zog." << std::endl;
}

Peon::~Peon()
{
    std::cout << "Bleuark..." << std::endl;
}

void Peon::getPolymorphed()const
{
    std::cout << this->getName() <<" has been turned into a pink pony!" << std::endl;
}