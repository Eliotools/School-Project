/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPrush2-thomas.gillet
** File description:
** Box
*/

#include "Box.hpp"

Box::Box() : Wrap("Box")
{
    _type = Object::BOX;
}

Box::~Box()
{
}

void Box::wrapMeThat(Object *obj)
{
    if (_object){
        std::cerr << "One object already in ! Santa say only ONE !!" << std::endl;
        return;
    }
    if (_isopen){
        _object = obj;
        std::cout << "tuuuut tuuut tuut" << std::endl;
    }
    else
        std::cerr << "Open box before try to put Object in ..." << std::endl;
    
}