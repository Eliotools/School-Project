/*
** EPITECH PROJECT, 2021
** B-CPP-501-LIL-5-1-rtype-thomas.gillet
** File description:
** powerupsystem
*/

#ifndef POWERUPSYSTEM_HPP_
#define POWERUPSYSTEM_HPP_

#include "ecs.hpp"
#include "components.hpp"

class PowerupSystem : public System
{
    public:
        PowerupSystem() {
            _spawns = true;
            _spawntime = rand() % 10 + 5;
            if (!_texturepowerup.loadFromFile("resources/belette.png")) {
		        exit (84);
            }
        }
        void update(float delta);
    private:
        float _totaltime;
        sf::Texture _texturepowerup;
        bool _spawns;
        int _spawntime;
};

#endif /* !POWERUPSYSTEM_HPP_ */
