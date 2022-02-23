/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPrush2-thomas.gillet
** File description:
** Wrap
*/

#include "Wrap.hpp"

Wrap::Wrap(std::string title) : Object(title)
{
    _object = NULL ;
    _isopen = false;
}

Wrap::~Wrap()
{
}

void Wrap::isTaken()
{
    std::cout << "whistles while working" << std::endl;
}

Object *Wrap::getObject() const
{
    if (_object)
        return _object;
    return NULL;
}

void Wrap::openMe()
{
    if (_isopen == false)
        _isopen = true;
    else
        std::cerr << "Wrap already open ! Close it before open it" << std::endl;
}

void Wrap::closeMe()
{
    if (_isopen == true)
        _isopen = false;
    else
        std::cerr << "Wrap already close ! Open it before close it" << std::endl;
}

bool Wrap::getIsopen()
{
    return _isopen;
}

void Wrap::operator=(Wrap &wrap)
{
    _isopen = wrap._isopen;
}