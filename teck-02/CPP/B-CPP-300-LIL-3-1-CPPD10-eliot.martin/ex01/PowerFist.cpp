/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD10-eliot.martin
** File description:
** PowerFist
*/

#include "PowerFist.hpp"

PowerFist::PowerFist() : AWeapon("Power Fist", 8, 50)
{
}

PowerFist::~PowerFist()
{
}

void PowerFist::attack() const
{
    std::cout << "* pschhh ... SBAM! *" << std::endl;
}