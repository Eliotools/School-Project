/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD09-eliot.martin
** File description:
** Character
*/

#include "Character.hpp"
#include <iostream>
Character::Character(const std::string &name, int level)
{
    this->_name = new std::string(name);
    this->_class = new std::string("Character");
    this->_race = new std::string("Humain");
    this->_level = level;
    this->_power = 100;
    this->_strength = 5;
    this->_stamina = 5;
    this->_intelligence = 5;
    this->_spirit = 5;
    this->_agitily = 5;
    this->_pv = 100;
    this->Range = Character::CLOSE;
    std::cout << this->getName() << " Created" << std::endl;
}

Character::~Character()
{
    delete this->_name;
    delete this->_class;
    delete this->_race;
}

int Character::getLvl() const
{
    return(this->_level);
}

int Character::getPv() const
{
    return(this->_pv);
}

int Character::getPower() const
{
    return(this->_power);
}

int Character::getStrength() const
{
    return(this->_strength);
}

int Character::getStamina() const
{
    return(this->_stamina);
}

int Character::getIntelligence() const
{
    return(this->_intelligence);
}

int Character::getSpirit() const
{
    return(this->_spirit);
}

int Character::getAgility() const
{
    return(this->_agitily);
}

const std::string &Character::getName() const
{
    return(*this->_name);
}

const std::string &Character::getClass() const
{
    return(*this->_class);
}

const std::string &Character::getRace() const
{
    return(*this->_race);
}

Character::AttackRange Character::getRange() const
{
    return(this->Range);
}

void Character::setRange(AttackRange Range)
{
    this->Range = Range;
}

int Character::CloseAttack()
{
    if (this->_power < 10) {
        std::cout << this->getName() << " out of power" <<std::endl;
        return 0;
    }
    if (this->Range == Character::RANGE)
        return 0;
    this->_power -= 10;
    std::cout << this->getName() << " strikes with a wooden stick" <<std::endl;
    return (10+this->_strength);
}

void Character::Heal()
{
    this->_pv += 50;
    std::cout << this->getName() << " takes a potion" <<std::endl;
    if (this->_pv > 100)
        this->_pv = 100;
}

int Character::RangeAttack()
{
    if (this->_power < 10) {
        std::cout << this->getName() << " out of power" <<std::endl;
        return 0;
    }
    this->_power -= 10;
    std::cout << this->getName() << " tosses a stone" <<std::endl;
    return (5+this->_strength);
}

void Character::RestorePower()
{
    this->_power += 100;
    std::cout << this->getName() << " eats" <<std::endl;
    if (this->_power > 100)
        this->_power = 100;
}

void Character::TakeDamage(int damage)
{
    this->_pv -= damage;
    if (this->_pv <= 0) {
        std::cout << this->getName() << " out of combat" <<std::endl;
        return;
    }
    std::cout << this->getName() << " takes " << damage << " damage" <<std::endl;
}

void Character::setRace(std::string race)
{
    this->_race = new std::string(race);
}
/*
void Character::PrintAll()
{
    std::cout << "Name :\t\t\t" << getName() << "\t\033[35m*\033[0m" << std::endl;
    std::cout << "Class :\t\t\t" << getClass() << "\t\t\033[35m*\033[0m" << std::endl;
    std::cout << "Race :\t\t\t" << getRace() << "\t\t\033[35m*\033[0m" << std::endl;
    std::cout << "Pv :\t\t\t" << getPv() << "\t\t\033[35m*\033[0m" << std::endl;
    std::cout << "Energy :\t\t" << getPower() << "\t\t\033[35m*\033[0m" << std::endl;
    std::cout << "Level :\t\t\t" << getLvl() << "\t\t\033[35m*\033[0m" << std::endl;
    std::cout << "Strength :\t\t" << getStrength() << "\t\t\033[35m*\033[0m" << std::endl;
    std::cout << "Stamina :\t\t" << getStamina() << "\t\t\033[35m*\033[0m" << std::endl;
    std::cout << "Intelligence :\t\t" << getIntelligence() << "\t\t\033[35m*\033[0m" << std::endl;
    std::cout << "Spirit :\t\t" << getSpirit() << "\t\t\033[35m*\033[0m" << std::endl;
    std::cout << "Agility :\t\t" << getAgility() << "\t\t\033[35m*\033[0m" << std::endl;
    std::cout << "Range :\t\t\t" << getRange() << "\t\t\033[35m*\033[0m" << std::endl;
}
*/