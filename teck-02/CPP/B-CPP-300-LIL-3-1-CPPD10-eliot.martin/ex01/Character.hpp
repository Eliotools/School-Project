/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD10-eliot.martin
** File description:
** Character
*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_
#include "AWeapon.hpp"
#include "AEnemy.hpp"

class Character
{
    public:
        Character(const std::string &name);
        ~Character();
        void recoverAP();
        void equip(AWeapon *weapon);
        void attack(AEnemy *enemy);
        std::string getName() const;
        int getAP() const;
        std::string get_w_name() const;
        bool have_w() const;

    protected :
        std::string _name;
        int _AP;
        AWeapon *_weapon;
};
std::ostream &operator<<(std::ostream &str, const Character &Cha);

#endif /* !CHARACTER_HPP_ */
