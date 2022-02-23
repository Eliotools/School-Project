/*
** EPITECH PROJECT, 2021
** B-CPP-501-LIL-5-1-rtype-thomas.gillet
** File description:
** movesystem
*/

#include "movesystem.hpp"

extern Engine moteur;

void MoveSystem::update(float delta)
{
    for (auto &ent : _entities) {
        auto &movable = moteur.getComponent<Movable>(ent);
        auto &drawable = moteur.getComponent<Drawable>(ent);
        if (movable.direction == "right")
            drawable.position.x += movable.speed;
        if (movable.direction == "down")
            drawable.position.y += movable.speed;
        if (movable.direction == "left")
            drawable.position.x -= movable.speed;
        if (movable.direction == "up")
            drawable.position.y -= movable.speed;
    }
}