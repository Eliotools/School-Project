/*
** EPITECH PROJECT, 2021
** B-CPP-501-LIL-5-1-rtype-thomas.gillet
** File description:
** components
*/

#ifndef COMPONENTS_HPP_
#define COMPONENTS_HPP_

#include <SFML/Graphics.hpp>
#include <string>

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

enum TypeEnt {
        PLAYER,
        ENNEMY,
        BULLET,
        BACKGROUND,
        POWERUP
};

struct Drawable {
    sf::Vector2f position;
    sf::Vector2f size;
    sf::Texture texture;
    sf::Sprite bulletsprite;
    int id;
};

struct Bullet {
    int isbullet;
};

struct Ennemy {
    int isennemy;
};

struct Powerup {
    int ispowerup;
};

struct Player {
    int isplayer;
};

struct Movable {
    float speed;
    std::string direction;
    TypeEnt typeent;
};

#endif /* !COMPONENTS_HPP_ */
