/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPrush2-thomas.gillet
** File description:
** Teddy
*/

#include "Teddy.hpp"

Teddy::Teddy(std::string title): Toy(title)
{
    _toyType = Object::TEDDY;
}

Teddy::~Teddy()
{
}

void Teddy::isTaken()
{
    std::cout << "gra hu" << std::endl;
}