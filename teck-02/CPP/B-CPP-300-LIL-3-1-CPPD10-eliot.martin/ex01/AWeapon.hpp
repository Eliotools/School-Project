/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD10-eliot.martin
** File description:
** AWeapon
*/

#ifndef AWEAPON_HPP_
#define AWEAPON_HPP_
#include <string>
#include <iostream>

class AWeapon {
    public:
        AWeapon(const std::string &name, int apcost, int damage);
        ~AWeapon();
        std::string getName()  const;
        int getAPCost() const;
        int getDamage() const;
        virtual void attack() const = 0;
    protected:
        std::string _name;
        int _apcost;
        int _damage;
    private:
};

#endif /* !AWEAPON_HPP_ */
