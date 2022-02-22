/*
** EPITECH PROJECT, 2021
** B-CPP-501-LIL-5-1-rtype-thomas.gillet
** File description:
** movesystem
*/

#ifndef MOVESYSTEM_HPP_
#define MOVESYSTEM_HPP_

#include "ecs.hpp"
#include "components.hpp"

class MoveSystem : public System
{
    public:
        void update(float delta);
    private:
};

#endif /* !MOVESYSTEM_HPP_ */
