/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD10-eliot.martin
** File description:
** AEnemy
*/

#include "AEnemy.hpp"
#include <string>
#include <iostream>

AEnemy::AEnemy(int hp ,const std::string &type) : _hp(hp), _type(type)
{
}

AEnemy::~AEnemy()
{
}

void AEnemy::takeDamage(int damage)
{
    this->_hp -= damage;
}

std::string AEnemy::getType() const
{
    return(this->_type);
}

int AEnemy::getHP() const
{
    return(this->_hp);
}