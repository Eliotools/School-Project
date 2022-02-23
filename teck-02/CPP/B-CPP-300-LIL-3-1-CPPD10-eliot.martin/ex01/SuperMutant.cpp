/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD10-eliot.martin
** File description:
** SuperMutant
*/

#include "SuperMutant.hpp"

SuperMutant::SuperMutant() : AEnemy(170, "Super Mutant")
{
    std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::~SuperMutant()
{
    std::cout << "Aaargh..." << std::endl;
}

void SuperMutant::takeDamage(int damage)
{
    this->_hp = this->_hp + 3 - damage;
}