/*
** EPITECH PROJECT, 2021
** B-CPP-501-LIL-5-1-rtype-thomas.gillet
** File description:
** playersystem
*/

#include "playersystem.hpp"

extern Engine moteur;

void PlayerSystem::update(float delta, int playerentity, int input)
{
    auto speed = moteur.getComponent<Movable>(playerentity);
    auto &drawable = moteur.getComponent<Drawable>(playerentity);

    switch (input)
    {
    case 0: //LEFT
        drawable.position.x -= speed.speed;
        break;
    case 1: //RIGHT
        drawable.position.x += speed.speed;
        break;
    case 2: //UP
        drawable.position.y -= speed.speed;
        break;
    case 3: //DOWN
        drawable.position.y += speed.speed;
        break;
    default:
        break;
    }

    //std::cout << "Player move => X: " << drawable.position.x << " Y: " << drawable.position.y << std::endl;
}