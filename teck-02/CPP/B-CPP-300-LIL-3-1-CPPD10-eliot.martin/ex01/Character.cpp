/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD10-eliot.martin
** File description:
** Character
*/

#include "Character.hpp"

Character::Character(const std::string &name) : _name(name), _AP(40)
{
}

Character::~Character()
{
}

void Character::recoverAP()
{
    this->_AP += 10;
    if (this->_AP > 40)
        this->_AP = 40;
}

void Character::equip(AWeapon *weapon)
{
    this->_weapon = weapon;
}

void Character::attack(AEnemy *enemy)
{

    if (!have_w())
        return;
    if (getAP() < _weapon->getAPCost() || (!have_w()))
        return;
    enemy->takeDamage(this->_weapon->getDamage());
    std::cout << this->getName() << " attacks " << enemy->getType() << " with a " << _weapon->getName() << std::endl;
    this->_weapon->attack();
    this->_AP -= this->_weapon->getAPCost();
    if (enemy->getHP() <= 0) {
        enemy->~AEnemy();
    }
}

std::string Character::getName() const
{
    return(this->_name);
}

int Character::getAP() const
{
    return(this->_AP);
}

bool Character::have_w() const
{
    if (!this->_weapon)
        return (false);
    return (true);
}

std::ostream &operator<<(std::ostream &str, const Character &Cha) 
{
    if (Cha.have_w())
        str << Cha.getName() << " has " << Cha.getAP() << " AP and wields a " << Cha.get_w_name() << std::endl;
    else
        str << Cha.getName() << " has " << Cha.getAP() << " AP and is unarmed" << std::endl;
    return (str);
}
std::string Character::get_w_name() const
{
    return(this->_weapon->getName());
}