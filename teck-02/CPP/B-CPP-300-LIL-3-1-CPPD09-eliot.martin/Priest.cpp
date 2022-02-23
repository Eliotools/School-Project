/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD09-eliot.martin
** File description:
** Priest
*/

#include "Priest.hpp"

Priest::Priest(const std::string &name, int level) : Character(name, level), Mage(name, level)
{
    this->_class = new std::string("Priest");
    this->_race = new std::string("Orc");
    this->_strength = 4;
    this->_stamina = 4;
    this->_intelligence = 42;
    this->_spirit = 21;
    this->_agitily = 2;
    std::cout << this->getName() << " enters in the order" << std::endl;
}

Priest::~Priest()
{
}

int Priest::CloseAttack()
{
    if (this->_power < 10) {
        std::cout << this->getName() << " out of power" <<std::endl;
        return 0;
    }
    if (this->Range == Character::RANGE)
        return 0;
    this->_power -= 10;
    std::cout << this->getName() << " uses a spirit explosion" <<std::endl;
    this->Range = Character::RANGE;
    return (10+this->_spirit);
}

int Priest::RangeAttack()
{
    if (this->_power < 25) {
        std::cout << this->getName() << " out of power" <<std::endl;
        return 0;
    }
    this->_power -= 25;
    std::cout << this->getName() << " launches a fire ball" <<std::endl;
    return (20 + this->_spirit);
}

void Priest::Heal()
{
    if(this->_power < 10) {
        std::cout << this->getName() << " out of power" <<std::endl;
        return;
    }
    this->_pv += 70;
    std::cout << this->getName() << " casts a little heal spell" <<std::endl;
    if (this->_pv > 100)
        this->_pv = 100;
}

void Priest::RestorePower()
{
    this->_power += (50 + this->_intelligence);
    std::cout << this->getName() << " takes a mana potion" <<std::endl;
    if (this->_power > 100)
        this->_power = 100;
}