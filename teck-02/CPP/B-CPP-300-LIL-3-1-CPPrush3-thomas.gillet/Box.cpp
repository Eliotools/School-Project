/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPrush3-thomas.gillet
** File description:
** Box
*/

#include "Box.hpp"

Box::Box(int height, int width, int start_y, int start_x, const std::string id) : _height(height), _width(width), _start_y(start_y), _start_x(start_x), _identifier(id)
{
}

Box::~Box()
{
}

WINDOW *Box::create_box()
{
    WINDOW *tmp;

    tmp = newwin(_height, _width, _start_y, _start_x);
    box(tmp, 0, 0);
    wrefresh(tmp);
    return tmp;
}

std::string Box::getId()
{
    return _identifier;
}

int Box::getHeight()
{
    return _height;
}

int Box::getWidth()
{
    return _width;
}

int Box::getY()
{
    return _start_y;
}

int Box::getX()
{
    return _start_x;
}