/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD09-eliot.martin
** File description:
** Warrior
*/

#ifndef WARRIOR_HPP_
#define WARRIOR_HPP_
#include "Character.hpp"

class Warrior : virtual public Character{
    public:
        explicit Warrior(const std::string &name, int level);
        ~Warrior();
        int CloseAttack();
        int RangeAttack ();
        void TakeDamage(int damage);
        void setWeapon(const std::string);
        std::string getWeapon();
    protected:
        std::string _Weapon;
    private:
        

};

#endif /* !WARRIOR_HPP_ */
