/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD13-eliot.martin
** File description:
** Picture
*/

#include "Picture.hpp"

Picture::Picture() : _data("")
{
}

Picture::Picture(const std::string &file)
{
    getPictureFromFile(file);
}

Picture::~Picture()
{
}

Picture::Picture(const Picture &pic)
{
    _data = pic._data;
}

bool Picture::getPictureFromFile(const std::string &file)
{
    std::ifstream f(file);
    std::ostringstream _new;
    if (f) {
        _new << f.rdbuf();
        _data = _new.str();
        return (true);
    }
    _data = "ERROR";
    return (false);
}

Picture &Picture::operator=(const Picture &pic)
{
    _data = pic._data;
    return (*this);
}