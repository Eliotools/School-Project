/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD10-eliot.martin
** File description:
** Victim
*/

#include "Victim.hpp"
#include <string>
#include <iostream>

Victim::Victim(std::string name) : _name(name)
{
    std::cout << "Some random victim called " << this->_name << " just popped!" << std::endl;
}

Victim::~Victim()
{
    std::cout << "Victim " << this->_name << " just died for no apparent reason!" << std::endl;
}

std::ostream &operator<<(std::ostream &str, Victim &Vic)
{
    str << "I'm " << Vic.getName() << " and I like otters!" << std::endl;
    return(str);
}

std::string Victim::getName() const
{
    return(this->_name);
}


void Victim::getPolymorphed()const
{
    std::cout << this->getName() <<" has been turned into a cute little sheep!" << std::endl;
}