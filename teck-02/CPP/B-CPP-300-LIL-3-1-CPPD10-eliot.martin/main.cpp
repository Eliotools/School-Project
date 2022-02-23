/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD10-eliot.martin
** File description:
** main
*/

#include "AWeapon.hpp"
#include "AEnemy.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "Character.hpp"
#include <string>
#include <iostream>

int main()
{
    const auto preda = new Character("Predator");
    const auto prey = new RadScorpion;

    std::cout << *preda;

    AWeapon *pr(new PlasmaRifle());
    AWeapon *pf(new PowerFist());
    
    preda->equip(pr);
    std::cout << *preda;
    preda->equip(pf);

    preda->attack(prey);
    std::cout << *preda;
    preda->equip(pr);
    std::cout << *preda;
    preda->attack(prey);
    std::cout << *preda;
    preda->attack(prey);
    std::cout << *preda;
    return 0;
}