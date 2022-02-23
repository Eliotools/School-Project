/*
** EPITECH PROJECT, 2021
** B-CPP-501-LIL-5-1-rtype-thomas.gillet
** File description:
** drawsystem
*/

#include "drawsystem.hpp"

extern Engine moteur;

void DrawSystem::init()
{
    this->_window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "PI");
    this->_window.setFramerateLimit(60);
}

std::set<int> DrawSystem::update()
{
    std::string msg;
    // _totaltime += delta;
    // if (this->_totaltime > 0.001) {
    //     //std::cout << "1 second" << std::endl;
    //     this->_totaltime -= 0.001;
    //     for (auto &ent : _entities) {
    //         auto &drawable = moteur.getComponent<Drawable>(ent);
    //         auto &movable = moteur.getComponent<Movable>(ent);
    //         drawable.bulletsprite.setPosition(drawable.position);
    //         //this->_window.draw(drawable.bulletsprite);

    //         if (movable.typeent != 3) {
    //             msg = "222 " + std::to_string(movable.typeent) + " " + std::to_string((int)drawable.position.x) + " " + std::to_string((int)drawable.position.y);
    //         }
    //     }
    // }
    return _entities;
}