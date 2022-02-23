/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD07A-eliot.martin
** File description:
** KoalaBot
*/

#include "KoalaBot.hpp"
#include <iostream>
#include <string>

KoalaBot::KoalaBot(): _serial("Bob-01")
{
}

KoalaBot::~KoalaBot()
{
}

void KoalaBot::informations()
{
    std::cout << "[KoalaBot] " << this->_serial << std::endl;
    this->_A.informations();
    this->_L.informations();
    this->_H.informations();
}

bool KoalaBot::status()
{
    if (this->_A.isFunctional() && this->_H.isFunctional() && this->_L.isFunctional())
        return true;
    return false;
}

void KoalaBot::setParts(Head &head)
{
    this->_H = head;
}

void KoalaBot::setParts(Legs &Legs)
{
    this->_L = Legs;
}

void KoalaBot::setParts(Arms &Arms)
{
    this->_A = Arms;
}

void KoalaBot::swipParts(Head &head)
{
    this->setParts(head);
}

void KoalaBot::swipParts(Legs &Legs)
{
    this->setParts(Legs);
}

void KoalaBot::swipParts(Arms &Arms)
{
    this->setParts(Arms);
}