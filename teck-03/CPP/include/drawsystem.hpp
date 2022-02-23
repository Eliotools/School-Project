/*
** EPITECH PROJECT, 2021
** B-CPP-501-LIL-5-1-rtype-thomas.gillet
** File description:
** drawsystem
*/


#ifndef DRAWSYSTEM_HPP_
#define DRAWSYSTEM_HPP_ 1

#include "ecs.hpp"
#include "components.hpp"

class DrawSystem : public System
{
    public:
        void init();
        std::set<int> update();
        sf::RenderWindow  _window;
    private:
        float _totaltime;
};

#endif /* !DRAWSYSTEM_HPP_ */
