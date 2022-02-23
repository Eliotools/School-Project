/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD10-eliot.martin
** File description:
** Sorcerer
*/

#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string name, std::string title) : _name(name), _title(title)
{
    std::cout << this->_name << ", " << this->_title <<", is born!" << std::endl;
}

Sorcerer::~Sorcerer()
{
    std::cout << this->_name << ", " << this->_title <<", is dead. Consequences will never be the same!" << std::endl;
}

std::ostream &operator<<(std::ostream &str, Sorcerer &Sor)
{
    str << "I am " << Sor.getName() <<", " << Sor.getTitle() << ", and I like ponies!" << std::endl;
    return(str);
}

std::string Sorcerer::getName()
{
    return(this->_name);
}

std::string Sorcerer::getTitle()
{
    return(this->_title);
}

void Sorcerer::polymorph(const Victim &victim) const
{
    victim.getPolymorphed();
}