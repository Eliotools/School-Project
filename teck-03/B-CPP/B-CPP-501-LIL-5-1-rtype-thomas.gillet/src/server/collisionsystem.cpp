/*
** EPITECH PROJECT, 2021
** B-CPP-501-LIL-5-1-rtype-thomas.gillet
** File description:
** collisionsystem
*/

#include "collisionsystem.hpp"

extern Engine moteur;

int CollisionSystem::update(float delta)
{
    _totaltime += delta;
    bool is_collide = false;

    this->_totaltime -= 0.0001;
    for (auto &ent : _entities) {
        for (auto &otherent : _entities) {
            if (ent != otherent) {
                if (check_collision(ent, otherent)) {
                    auto &other = moteur.getComponent<Movable>(ent);
                    auto &otherother = moteur.getComponent<Movable>(otherent);
                    if (other.typeent == TypeEnt::ENNEMY && otherother.typeent == TypeEnt::BULLET) {
                        moteur.destroyEntity(ent);
                        moteur.destroyEntity(otherent);
                        is_collide = true;
                        break;
                    }
                    else if (other.typeent == TypeEnt::ENNEMY && otherother.typeent == TypeEnt::PLAYER) {
                        std::cout << "Game Over." << std::endl;
                        return 42;
                    }
                    else if (other.typeent == TypeEnt::POWERUP && otherother.typeent == TypeEnt::PLAYER) {
                        otherother.speed = 25;
                        moteur.destroyEntity(ent);
                        is_collide = true;
                        break;
                    }
                }
            }
        }
        if (is_collide == true)
            break;
    }
    return 0;
}

bool CollisionSystem::check_collision(int currententity, int otherentity)
{
    auto currentent = moteur.getComponent<Drawable>(currententity);
    sf::RectangleShape body;
    body.setSize(currentent.size);
    body.setOrigin(currentent.size / 2.0f);
    body.setPosition(currentent.position);

    auto other = moteur.getComponent<Drawable>(otherentity);
    sf::RectangleShape otherbody;
    otherbody.setSize(other.size);
    otherbody.setOrigin(other.size / 2.0f);
    otherbody.setPosition(other.position);

    float delta_x = other.position.x - currentent.position.x;
    float delta_y = other.position.y - currentent.position.y;

    //std::cout << "entity " << currententity << "delta_x " << delta_x << " delta_y " << delta_y << std::endl;
    float intersect_x = abs(delta_x) - ((other.size.x / 2) + (currentent.size.x / 2));
    float intersect_y = abs(delta_y) - ((other.size.y / 2) + (currentent.size.y / 2));
    
    auto type = moteur.getComponent<Movable>(otherentity);
    auto type2 = moteur.getComponent<Movable>(currententity);
    if (type.typeent == TypeEnt::BULLET or type2.typeent == TypeEnt::BULLET) {
        intersect_x += 40; // 40 est la size de la balle * 2
        intersect_y -= 40;
    }
    
    //std::cout << "entity: " << currententity << " intersect_x " << intersect_x << " intersect_y " << intersect_y << std::endl;


    if (intersect_x < 0.0f && intersect_y < 0.0f) {
        //std::cout << std::endl;
        // if (intersect_x > intersect_y) {
        //     if  (delta_x > 0.0f) {
        //         std::cout << "collision 1" << std::endl;
        //     }
        //     else {
        //         std::cout << "collision 2" << std::endl;
        //     }
        // }
        // else {
        //     if  (delta_y > 0.0f) {
        //         std::cout << "collision 3" << std::endl;
        //     }
        //     else {
        //         std::cout << "collision 4" << std::endl;
        //     }
        // }
        return (true);
    }

    return (false);
}