/*
** EPITECH PROJECT, 2021
** B-CPP-501-LIL-5-1-rtype-thomas.gillet
** File description:
** collisionsystem
*/

#ifndef COLLISIONSYSTEM_HPP_
#define COLLISIONSYSTEM_HPP_

#include "ecs.hpp"
#include "components.hpp"

class CollisionSystem : public System
{
    public:
        int update(float delta);
        bool check_collision(int currententity, int otherentity);
    private:
        float _totaltime;
};

#endif /* !COLLISIONSYSTEM_HPP_ */
