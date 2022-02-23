/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD09-eliot.martin
** File description:
** Warrior
*/

#include "Warrior.hpp"

Warrior::Warrior(const std::string &name, int level) : Character(name, level)
{
    this->_class = new std::string("Warrior");
    this->_race = new std::string("Dwarf");
    this-> _Weapon = "hammer";
    this->_strength = 12;
    this->_stamina = 12;
    this->_intelligence = 6;
    this->_spirit = 5;
    this->_agitily = 7;
    std::cout << "I'm " <<this->getName() << " KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG" << std::endl;
}

Warrior::~Warrior()
{
}

int Warrior::CloseAttack()
{
    if (this->_power < 30) {
        std::cout << this->getName() << " out of power" <<std::endl;
        return 0;
    }
    if (this->Range == Character::RANGE || this->_Weapon != "hammer")
        return 0;
    this->_power -= 30;
    std::cout << this->getName() << " strikes with his hammer" <<std::endl;
    return (20+this->_strength);
}

int Warrior::RangeAttack()
{
    if (this->_power < 10) {
        std::cout << this->getName() << " out of power" <<std::endl;
        return 0;
    }
    if (this->Range == Character::CLOSE)
        return 0;
    this->_power -= 10;
    this->Range = Character::CLOSE;
    std::cout << this->getName() << " intercepts" <<std::endl;
    return (0);
}

void Warrior::TakeDamage(int damage)
{
    this->_pv -= damage;
    if (this->_pv <= 0) {
        std::cout << this->getName() << " out of combat" <<std::endl;
        return;
    }
    std::cout << this->getName() << " takes " << damage << " damage" <<std::endl;
}

void Warrior::setWeapon(const std::string weapon)
{
    this->_Weapon = weapon;
}

std::string Warrior::getWeapon(void)
{
    return(this->_Weapon);
}