/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPrush2-thomas.gillet
** File description:
** Toy
*/

#include "Toy.hpp"

Toy::Toy(std::string title) : Object(title)
{
    _type = Object::TOY;
}

Toy::Toy(std::string title, Toy_Type type)
{
    _title = title;
    _type = Object::TOY;
    _toyType = type;
}

Toy::~Toy()
{
}

void Toy::isTaken(Toy_Type type)
{
    if (type == Toy::TEDDY)
        std::cout << "gra hu" << std::endl;
    else
        std::cout << "yo man" << std::endl;
    
}
