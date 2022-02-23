/*
** EPITECH PROJECT, 2021
** B-CPP-501-LIL-5-1-rtype-thomas.gillet
** File description:
** backgroundsystem
*/

#include "backgroundsystem.hpp"

extern Engine moteur;

void BackgroundSystem::update(int backgroundentity)
{
    auto &background = moteur.getComponent<Drawable>(backgroundentity);
    float half_size = background.size.x / 2;

    if (background.position.x <= -half_size) {
        background.position.x += half_size;
    }
}