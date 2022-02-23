/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD13-eliot.martin
** File description:
** Toy
*/

#include "Toy.hpp"

Toy::Toy()
{
    _type = Toy::BASIC_TOY;
    _name = "toy";
    _pic = new Picture();
}

Toy::Toy(Toy::ToyType type, std::string name, const std::string &file)
{
    _type = type;
    _name = name;
    _pic = new Picture(file);
}

Toy::Toy(const Toy &toy)
{
    _type = toy._type;
    _name = toy._name;
    _pic = toy._pic;
}

Toy::~Toy()
{
}

Toy::ToyType Toy::getType() const
{
    return (_type);
}

std::string Toy::getName() const
{
    return (_name);
}

void Toy::setName(std::string name)
{
    _name = name;
}

bool Toy::setAscii(const std::string &file)
{
    return (_pic->getPictureFromFile(file));
}

std::string Toy::getAscii() const
{
    return(_pic->_data);
}

Toy &Toy::operator=(const Toy &pic)
{
    _type = pic._type;
    _name = pic._name;
    _pic = pic._pic;
    return (*this);
}

void Toy::speak(const std::string str)
{
    std::cout << _name << " \"" << str << "\"" << std::endl; 
}