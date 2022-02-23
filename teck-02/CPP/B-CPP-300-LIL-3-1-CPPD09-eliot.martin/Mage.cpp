/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD09-eliot.martin
** File description:
** Mage
*/

#include "Mage.hpp"

Mage::Mage(const std::string &name, int level) : Character(name, level)
{
    this->_class = new std::string("Mage");
    this->_race = new std::string("Gnome");
    this->_strength = 6;
    this->_stamina = 6;
    this->_intelligence = 12;
    this->_spirit = 11;
    this->_agitily = 7;
    std::cout << this->getName() << " teleported" << std::endl;
}

Mage::~Mage()
{
}

int Mage::CloseAttack()
{
    if (this->_power < 10) {
        std::cout << this->getName() << " out of power" <<std::endl;
        return 0;
    }
    if (this->Range == Character::RANGE)
        return 0;
    this->_power -= 10;
    std::cout << this->getName() << " blink" <<std::endl;
    this->Range = Character::RANGE;
    return (0);
}

int Mage::RangeAttack()
{
    if (this->_power < 25) {
        std::cout << this->getName() << " out of power" <<std::endl;
        return 0;
    }
    this->_power -= 25;
    std::cout << this->getName() << " launches a fire ball" <<std::endl;
    return (20 + this->_spirit);
}

void Mage::RestorePower()
{
    this->_power += 50 + this->_intelligence;
    std::cout << this->getName() << " takes a mana potion" <<std::endl;
    if (this->_power > 100)
        this->_power = 100;
}