/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD07M-eliot.martin
** File description:
** Borg
*/

#include <iostream>
#include "Borg.hpp"
#include "Federation.hpp"

Borg::Ship::Ship()
{
    this->_side = 300;
    this->_maxWarp = 9;
    std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl << "Your biological characteristics and technologies will be assimilated." << std::endl << "Resistance is futile." << std::endl;
}

Borg::Ship::~Ship()
{
}

Federation::Starfleet::Ensign::Ensign(std::string name)
{
    this->_name = name;
    std::cout << "Ensign " << this->_name << ", awaiting orders." << std::endl;
}

Federation::Starfleet::Ensign::~Ensign()
{
    
}

void Borg::Ship::setupCore(WarpSystem::Core *new_Core)
{
    this->Core = new_Core;
}

Federation::Starfleet::Captain::Captain(std::string name)
{
    this->_name = name;
}

Federation::Starfleet::Captain::~Captain()
{
    
}

int Federation::Starfleet::Captain::getAge()
{
    return(this->_age);
}

std::string Federation::Starfleet::Captain::getName()
{
    return(this->_name);
}

void Federation::Starfleet::Captain::setAge(int new_age)
{
    this->_age = new_age;
}

void Borg::Ship::checkCore()
{
    std::string stab;
    if (this->Core->checkReactor()->isStable())
        std::cout << "Everything is in order." << std::endl;
    else
        std::cout << "Critical failure imminent." << std::endl;
}

void Federation::Starfleet::Ship::promote(Federation::Starfleet::Captain *captain)
{
    this->Captain = captain;
    std::cout << this->Captain->getName() << ": I'm glad to be the captain of the USS " << this->_name << "." << std::endl;
}