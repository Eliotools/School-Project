/*
** EPITECH PROJECT, 2021
** B-CPP-501-LIL-5-1-rtype-thomas.gillet
** File description:
** shootsytem
*/

#include "shootsystem.hpp"

extern Engine moteur;

int ShootSystem::getNbBullets()
{
    int nb_bullets = 0;

    for (auto &ent : _entities) {
        auto &movable = moteur.getComponent<Movable>(ent);
        if (movable.typeent == TypeEnt::BULLET) {
            nb_bullets++;
        }
    }
    return (nb_bullets);
}

void ShootSystem::update(float delta, int playerentity, int input)
{
    if (_totaltime < 0.04)
        _totaltime += delta;

    auto playerposition = moteur.getComponent<Drawable>(playerentity);

    if (input == 4 and this->getNbBullets() < 4) {
        this->_totaltime -= 0.04;
        sf::Sprite bullsprite;
        bullsprite.setTexture(this->_texturebullet);
        bullsprite.setScale(20 / bullsprite.getLocalBounds().width, 20 / bullsprite.getLocalBounds().height);
        int entity = moteur.createEntity();
        moteur.addComponent(entity, Drawable {
            .position = sf::Vector2f(playerposition.position.x + playerposition.size.x, playerposition.position.y + (playerposition.size.y / 2) - 10),
            .size = sf::Vector2f(20, 20),
            .texture = this->_texturebullet,
            .bulletsprite = bullsprite
        });
        moteur.addComponent(entity, Movable {
            .speed = 42,
            .direction = "right",
            .typeent = TypeEnt::BULLET
        });
        moteur.addComponent(entity, Bullet {
            .isbullet = 0
        });

    }
    for (auto &ent : _entities) {
        auto &drawable = moteur.getComponent<Drawable>(ent);
        auto &movable = moteur.getComponent<Movable>(ent);
        if (drawable.position.x > WINDOW_WIDTH and movable.typeent == TypeEnt::BULLET) {
            moteur.destroyEntity(ent);
            break;
        }
    }
}