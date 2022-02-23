/*
** EPITECH PROJECT, 2021
** B-CPP-501-LIL-5-1-rtype-thomas.gillet
** File description:
** backgroundsystem
*/

#ifndef BACKGROUNDSYSTEM_HPP_
#define BACKGROUNDSYSTEM_HPP_

#include "ecs.hpp"
#include "components.hpp"

class BackgroundSystem : public System
{
    public:
        void update(int backgroundentity);
    private:
};

#endif /* !BACKGROUNDSYSTEM_HPP_ */
