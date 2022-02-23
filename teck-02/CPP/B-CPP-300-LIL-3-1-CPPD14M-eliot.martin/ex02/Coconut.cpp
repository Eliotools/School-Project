/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD14M-eliot.martin
** File description:
** Coconut
*/

#include "Coconut.hpp"
#include "Fruit.hpp"


Coconut::Coconut() : Fruit("coconut", 15)
{
}

Coconut::~Coconut()
{
}

int Coconut::getVitamins() const
{
    return(_vitamins);
}

std::string Coconut::getName() const
{
    return(_Name);
}