/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD10-eliot.martin
** File description:
** AWeapon
*/

#include "AWeapon.hpp"

AWeapon::AWeapon(const std::string &name, int apcost, int damage) : _name(name), _apcost(apcost), _damage(damage)
{
}

AWeapon::~AWeapon()
{
}

std::string AWeapon::getName() const
{
    return(this->_name);
}

int AWeapon::getAPCost() const
{
    return(this->_apcost);
}

int AWeapon::getDamage() const
{
    return(this->_damage);
}

void AWeapon::attack() const
{
    std::cout << "here" << std::endl;
}