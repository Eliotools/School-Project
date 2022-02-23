/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD10-eliot.martin
** File description:
** PowerFist
*/

#ifndef POWERFIST_HPP_
#define POWERFIST_HPP_
#include <string>
#include <iostream>
#include "AWeapon.hpp"


class PowerFist : public AWeapon{
    public:
        PowerFist();
        ~PowerFist();
        void attack() const;

    protected:
    private:
};

#endif /* !POWERFIST_HPP_ */
