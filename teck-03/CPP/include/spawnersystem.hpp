/*
** EPITECH PROJECT, 2021
** B-CPP-501-LIL-5-1-rtype-thomas.gillet
** File description:
** spawner
*/

#ifndef SPAWNER_HPP_
#define SPAWNER_HPP_

#include "ecs.hpp"
#include "components.hpp"

class SpawnerSystem : public System
{
    public:
        SpawnerSystem() {
            if (!_textureenemy.loadFromFile("resources/bydos.gif")) {
		        exit (84);
            }
        }
        void update(float delta);
        int getNbEnnemies();
    private:
        float _totaltime;
        sf::Texture _textureenemy;
};

#endif /* !SPAWNER_HPP_ */
