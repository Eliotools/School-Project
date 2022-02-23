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
    bool bo = _pic->getPictureFromFile(file);
    if (!bo)
        error.setType(Toy::Error::PICTURE);
    return bo;
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

bool Toy::speak(std::string str)
{
    std::cout << _name << " \"" << str << "\"" << std::endl; 
    return true;
}

std::ostream &operator<<(std::ostream &str, Toy &toy)
{
    str << toy.getName() << std::endl;
    str << toy.getAscii() << std::endl;
    return str;
}

void Toy::operator<<(std::string std)
{
    _pic->_data = std;
}

bool Toy::speak_es(std::string str)
{
    str = "";
    error.setType(Toy::Error::SPEAK);
    return false;
}

Toy::Error::Error() : type(Error::UNKNOW)
{
}

Toy::Error::~Error()
{
}

Toy::Error Toy::getLastError() const
{
    return error;
}

void Toy::Error::setType(ErrorType new_type)
{
    type = new_type;
}

std::string Toy::Error::what() const
{
    if (type == PICTURE)
        return ("bad new illustration");
    if (type == SPEAK)
        return ("wrong mode");
    return ("");
}

std::string Toy::Error::where() const
{

  if (type == PICTURE)
    return "setAscii";
  if (type == SPEAK)
    return "speak_es";
  else
    return "";
}
