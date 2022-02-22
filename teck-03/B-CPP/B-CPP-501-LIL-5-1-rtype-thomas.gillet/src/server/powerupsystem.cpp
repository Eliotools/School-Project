/*
** EPITECH PROJECT, 2021
** B-CPP-501-LIL-5-1-rtype-thomas.gillet
** File description:
** powerupsystem
*/

#include "powerupsystem.hpp"

extern Engine moteur;

void PowerupSystem::update(float delta)
{
    _totaltime += delta;

    if (this->_totaltime > 0.05 && _spawns) {
        _spawns = false;
        //std::cout << "1 second" << std::endl;
        //this->_totaltime -= 5;
        int entity = moteur.createEntity();
        sf::Sprite enemysprite;
        enemysprite.setTexture(this->_texturepowerup);
        enemysprite.setScale(50 / enemysprite.getLocalBounds().width, 50 / enemysprite.getLocalBounds().height); // LES 100 SONT LA TAILLE DU SPRITE
        moteur.addComponent(entity, Drawable {
            .position = sf::Vector2f(WINDOW_WIDTH, rand() % (WINDOW_HEIGHT - 50)),
            .size = sf::Vector2f(50, 50),
            .texture = this->_texturepowerup,
            .bulletsprite = enemysprite
        });
        moteur.addComponent(entity, Movable {
            .speed = 3,
            .direction = "left",
            .typeent = TypeEnt::POWERUP
        });
        moteur.addComponent(entity, Powerup {
            .ispowerup = 0
        });
    }
}