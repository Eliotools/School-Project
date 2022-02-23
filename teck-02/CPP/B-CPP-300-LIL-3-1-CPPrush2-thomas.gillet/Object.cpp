/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPrush2-thomas.gillet
** File description:
** Object
*/

#include "Object.hpp"
#include <string.h>

Object::Object(std::string title) : _title(title)
{
    
}

Object::Object()
{
}

Object::~Object()
{
}

void Object::setTitle(std::string title)
{
    _title = title;
}

std::string Object::getTitle() const
{
    //std::cout << "Last one two" << std::endl;
    if (_title.empty())
        std::cout << "Empty" << std::endl;
    //std::cout << "ADRESSE TITLE" << &_title << std::endl;
    return(_title);
}

std::ostream &operator<<(std::ostream &str, Object &Obj)
{
    str << Obj.getTitle();
    return str;
}
