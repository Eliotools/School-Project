/*
** EPITECH PROJECT, 2021
** B-CPP-501-LIL-5-1-rtype-thomas.gillet
** File description:
** playersystem
*/

#ifndef PLAYERSYSTEM_HPP_
#define PLAYERSYSTEM_HPP_

#include "ecs.hpp"
#include "components.hpp"

class PlayerSystem : public System
{
    public:
        void update(float delta, int playerentity, int input);
    private:
};

#endif /* !PLAYERSYSTEM_HPP_ */
