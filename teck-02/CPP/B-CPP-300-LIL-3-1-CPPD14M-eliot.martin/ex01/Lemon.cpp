/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD14M-eliot.martin
** File description:
** Lemon
*/

#include "Lemon.hpp"

Lemon::Lemon() : Fruit("lemon", 3)
{
}

Lemon::Lemon(std::string name, int vitamins) : Fruit(name, vitamins)
{
}

Lemon::~Lemon()
{
}

int Lemon::getVitamins() const
{
    return(_vitamins);
}

std::string Lemon::getName() const
{
    return(_Name);
}