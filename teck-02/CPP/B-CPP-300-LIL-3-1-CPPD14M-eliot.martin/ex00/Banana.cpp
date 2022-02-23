/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD14M-eliot.martin
** File description:
** Banana
*/

#include "Banana.hpp"

Banana::Banana() : Fruit("banana", 5)
{
}

Banana::~Banana()
{
}

int Banana::getVitamins() const
{
    return(_vitamins);
}

std::string Banana::getName() const
{
    return(_Name);
}