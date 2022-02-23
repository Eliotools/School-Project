/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPrush2-thomas.gillet
** File description:
** LittlePony
*/

#include "LittlePony.hpp"

LittlePony::LittlePony(std::string title) : Toy(title)
{
    _toyType = Object::PONY;
}

LittlePony::~LittlePony()
{
}

void LittlePony::isTaken()
{
    std::cout << "yo man" << std::endl;
}