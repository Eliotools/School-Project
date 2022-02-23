/*
** EPITECH PROJECT, 2021
** B-OOP-400-LIL-4-1-arcade-thomas.gillet
** File description:
** igraphic
*/

#ifndef IGRAPHIC_HPP_
#define IGRAPHIC_HPP_

#include <iostream>
#include <list>
#include <vector>
#include "../game/igame.hpp"

/**
* \class IGraphic
* \brief Interface for graph class
*/
class IGraphic
{
    public:
        virtual ~IGraphic() = default;
        virtual void drawobj(std::vector<int> xcoords, std::vector<int> ycoords, int food_x, int food_y, int bullet_x, int bullet_y) = 0;
        virtual int getInput() = 0;
        virtual void launch() = 0;
        virtual void stop() = 0;
        virtual void settingInput(int) = 0;
};

#endif /* !IGRAPHIC_HPP_ */
