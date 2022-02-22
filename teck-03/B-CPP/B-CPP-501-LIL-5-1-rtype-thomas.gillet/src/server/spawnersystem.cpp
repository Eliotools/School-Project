/*
** EPITECH PROJECT, 2021
** B-CPP-501-LIL-5-1-rtype-thomas.gillet
** File description:
** spawner
*/

#include "spawnersystem.hpp"
#include <cstdlib>

extern Engine moteur;

int SpawnerSystem::getNbEnnemies()
{
    int nb_ennemies = 0;

    for (auto &ent : _entities) {
        auto &movable = moteur.getComponent<Movable>(ent);
        if (movable.typeent == TypeEnt::ENNEMY) {
            nb_ennemies++;
        }
    }
    return (nb_ennemies);
}

void SpawnerSystem::update(float delta)
{
    _totaltime += delta;

   // if (this->_totaltime > 0.05) {
        //std::cout << "1 second" << std::endl;
        this->_totaltime -= 0.05;
        if (this->getNbEnnemies() < 5) {
            int entity = moteur.createEntity();
            std::cout << "Entity is " << entity << std::endl;
            sf::Sprite enemysprite;
            enemysprite.setTexture(this->_textureenemy);
            enemysprite.setScale(100 / enemysprite.getLocalBounds().width, 100 / enemysprite.getLocalBounds().height); // LES 100 SONT LA TAILLE DU SPRITE
            moteur.addComponent(entity, Drawable {
                .position = sf::Vector2f(WINDOW_WIDTH, rand() % (WINDOW_HEIGHT - 100)),
                .size = sf::Vector2f(100, 100),
                .texture = this->_textureenemy,
                .bulletsprite = enemysprite
            });
            moteur.addComponent(entity, Movable {
                .speed = 9,
                .direction = "left",
                .typeent = TypeEnt::ENNEMY
            });
            moteur.addComponent(entity, Ennemy {
                .isennemy = 0
            });
        //}

    }
    for (auto &ent : _entities) {
        auto &drawable = moteur.getComponent<Drawable>(ent);
        auto &movable = moteur.getComponent<Movable>(ent);
        //std::cout << "entiyty => " << ent << std::endl;
        if (drawable.position.x < 0 and movable.typeent == TypeEnt::ENNEMY) {
            moteur.destroyEntity(ent);
            break;
            std::cout << "Free ennemy" << std::endl;
        }
    }
}