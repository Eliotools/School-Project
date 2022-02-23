/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD07M-eliot.martin
** File description:
** Federation
*/

#include <iostream>
#include "Federation.hpp"

Federation::Starfleet::Ship::Ship(int length, int width, std:: string name, short maxWarp)
{
    this->_length = length;
    this->_width = width;
    this->_name = name;
    this->_maxWarp = maxWarp;
    std::cout << "The ship USS "<< this->_name <<" has been finished." << std::endl;
    std::cout << "It is "<< this->_length <<" m in length and " << this->_width << " m in width." <<std::endl;
    std::cout << "It can go to Warp "<< this->_maxWarp <<"!" << std::endl;
}

Federation::Ship::Ship(int length, int width, std:: string name)
{
    this->_length = length;
    this->_width = width;
    this->_name = name;
    this->_maxWarp = 1;
    std::cout << "The independent ship "<< this->_name <<" just finished its construction." << std::endl;
    std::cout << "It is "<< this->_length <<" m in length and " << this->_width << " m in width." <<std::endl;
}

Federation::Ship::~Ship()
{
    
}

Federation::Starfleet::Ship::~Ship()
{
    
}

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *new_Core)
{
    this->Core = new_Core;
    std::cout << "USS " << this->_name <<": The core is set." << std::endl;
}

void Federation::Ship::setupCore(WarpSystem::Core *new_Core)
{
    this->Core = new_Core;
    std::cout << this->_name <<": The core is set." << std::endl;
}

void Federation::Starfleet::Ship::checkCore()
{
    std::string stab;
    if (this->Core->checkReactor()->isStable())
        stab = "stable";
    else
        stab = "unstable";
    std::cout << "USS " << this->_name << ": The core is " << stab << " at the time." << std::endl;
}

void Federation::Ship::checkCore()
{
    std::string stab;
    if (this->Core->checkReactor()->isStable())
        stab = "stable";
    else
        stab = "unstable";
    std::cout << this->_name << ": The core is " << stab << " at the time." << std::endl;
}