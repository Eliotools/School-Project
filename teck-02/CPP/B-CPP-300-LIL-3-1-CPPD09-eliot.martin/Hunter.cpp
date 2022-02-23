/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD09-eliot.martin
** File description:
** Hunter
*/

#include "Hunter.hpp"

Hunter::Hunter(const std::string &name, int level) : Character(name, level), Warrior(name, level)
{
    this->_class = new std::string("Hunter");
    this->_race = new std::string("Elf");
    this-> _Weapon = "sword";
    this->_strength = 9;
    this->_stamina = 9;
    this->_intelligence = 5;
    this->_spirit = 6;
    this->_agitily = 25;
    std::cout << this->getName() << " is born from a tree" << std::endl;
}

Hunter::~Hunter()
{
}

int Hunter::RangeAttack()
{
    if (this->_power < 25) {
        std::cout << this->getName() << " out of power" <<std::endl;
        return 0;
    }
    this->_power -= 25;
    std::cout << this->getName() << " uses his bow" <<std::endl;
    return (20 + this->_agitily);
}

void Hunter::RestorePower()
{
    this->_power += 100;
    std::cout << this->getName() << " meditates" <<std::endl;
    if (this->_power > 100)
        this->_power = 100;
}
