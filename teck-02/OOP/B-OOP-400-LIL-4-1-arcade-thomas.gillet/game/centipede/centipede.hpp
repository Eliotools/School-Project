/*
** EPITECH PROJECT, 2021
** B-OOP-400-LIL-4-1-arcade-thomas.gillet
** File description:
** centipede
*/

#ifndef CENTIPEDE_HPP_
#define CENTIPEDE_HPP_

#include "../igame.hpp"
#include <list>
#include <vector>
#include <iostream>

/**
* \class Centipede
* \brief Centipede class for game Centipede use IGame for Interface
*/
class Centipede : public IGame
{
    public:
        Centipede(int a, int b) {
            x = a;
            y = b;
            wall = 1;
            food_x = 3;
            food_y = 20;
            bullet_x = -1;
            bullet_y = -1;
            hit_counter = 0;
            lock = false;
        }
        ~Centipede() {}
        int getXpos() { return x; }
        int getYpos() { return y; }
        std::vector<int> getSnakeXpos() { return xcoords; }
        std::vector<int> getSnakeYpos() { return ycoords; }

        int getFoodY() { return food_y; }
        int getFoodX() { return food_x; }

        int getBulletY() { return bullet_y; }
        int getBulletX() { return bullet_x; }
        
        std::list<Centipede> getSnake() { return snakes; }
        int checkInputs(int dir);
        void setLock();
        void relaunch();
        int getScore();

    private:
        int x;
        int y;
        std::list<Centipede> snakes;
        std::vector<int> xcoords;
        std::vector<int> ycoords;
        int food_x;
        int food_y;
        bool lock;
        int wall;
        int bullet_x;
        int bullet_y;
        int hit_counter;
        void createCentipede();
        int changeDir(Centipede logic, int dir);
        void hitWall();
        void checkCollision(int xx);
};

class Bullet
{
    public:
        Bullet();
        ~Bullet();
    private:
        int _x;
        int _y;
        
};

#endif /* !CENTIPEDE_HPP_ */
