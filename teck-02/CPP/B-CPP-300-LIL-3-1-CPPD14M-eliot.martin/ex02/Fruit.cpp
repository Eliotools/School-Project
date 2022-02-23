/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD14M-eliot.martin
** File description:
** Fruit
*/

#include "Fruit.hpp"

Fruit::Fruit(std::string name, int vitamins) : _Name(name), _vitamins(vitamins)
{
}

Fruit::~Fruit()
{
}

int Fruit::getVitamins() const
{
    return(_vitamins);
}

std::string Fruit::getName() const
{
    return(_Name);
}