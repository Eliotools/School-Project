/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD10-eliot.martin
** File description:
** PlasmaRifle
*/

#ifndef PLASMARIFLE_HPP_
#define PLASMARIFLE_HPP_
#include <string>
#include <iostream>
#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon{
    public:
        PlasmaRifle();
        ~PlasmaRifle();
        void attack() const;
    protected:
    private:
};

#endif /* !PLASMARIFLE_HPP_ */
