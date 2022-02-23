/*
** EPITECH PROJECT, 2021
** B-CPP-501-LIL-5-1-rtype-thomas.gillet
** File description:
** shootsytem
*/

#ifndef SHOOTSYTEM_HPP_
#define SHOOTSYTEM_HPP_

#include "ecs.hpp"
#include "components.hpp"

class ShootSystem : public System
{
    public:
        ShootSystem() {
            if (!_texturebullet.loadFromFile("resources/bullet.gif")) {
		        exit (84);
            }
        }
        void update(float delta, int playerentity, int input);
        int getNbBullets();
    private:
        float _totaltime;
        sf::Texture _texturebullet;
};

#endif /* !SHOOTSYTEM_HPP_ */
