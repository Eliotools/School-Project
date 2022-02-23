/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD16-eliot.martin
** File description:
** Ratatouille
*/

#include "Ratatouille.hpp"

Ratatouille::Ratatouille()
{
}

Ratatouille::~Ratatouille()
{
}

Ratatouille::Ratatouille(Ratatouille const &other)
{
    _str << other._str.str();
}

Ratatouille &Ratatouille::operator=(const Ratatouille &rhs)
{
    _str.str("");
    return (*this);
}

Ratatouille &Ratatouille::addCondiment(unsigned int ingr)
{
    _str << ingr;
    return (*this);
}

Ratatouille &Ratatouille::addVegetable(unsigned char ingr)
{   
    _str << ingr;
    return (*this);
}

Ratatouille &Ratatouille::addSpice(double ingr)
{
    _str << ingr;
    return (*this);
}

Ratatouille &Ratatouille::addSauce(const std::string &ingr)
{
    _str << ingr;
    return (*this);
}

std::string Ratatouille::kooc()
{
    return _str.str();
}