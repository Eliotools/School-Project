/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD09-eliot.martin
** File description:
** Paladin
*/

#include "Paladin.hpp"

Paladin::Paladin(const std::string &name, int level) : Character(name, level), Warrior(name, level), Priest(name, level), Mage(name, level)
{
    this->_class = new std::string("Paladin");
    this->_race = new std::string("Humain");
    this-> _Weapon = "hammer";
    this->_strength = 6;
    this->_stamina = 6;
    this->_intelligence = 12;
    this->_spirit = 11;
    this->_agitily = 7;
    std::cout <<"he light falls on " << this->getName() << std::endl;
}

Paladin::~Paladin()
{
}

int Paladin::intercept()
{
    std::cout << "here";
    if (this->_power < 10) {
        std::cout << this->getName() << " out of power" <<std::endl;
        return 0;
    }
    if (this->Range == Character::CLOSE)
        return 0;
    this->_power -= 10;
    this->Range = Character::CLOSE;
    std::cout << this->getName() << " intercept" <<std::endl;
    return (0);
}