/*
** EPITECH PROJECT, 2021
** B-OOP-400-LIL-4-1-arcade-thomas.gillet
** File description:
** nibbler
*/

#ifndef NIBBLER_HPP_
#define NIBBLER_HPP_

#include "../igame.hpp"
#include <list>
#include <vector>

/**
* \class Nibbler
* \brief Game use IGame as Interface
*/  
class Nibbler : public IGame
{
    public:
        Nibbler(int a, int b) {
            x = a;
            y = b;
            score = 0;
            lock = false;
        }
        ~Nibbler() {}
        int getXpos() { return x; }
        int getYpos() { return y; }
        std::vector<int> getSnakeXpos() { return xcoords; }
        std::vector<int> getSnakeYpos() { return ycoords; }
        int getFoodY() { return food_y; }
        int getFoodX() { return food_x; }
        int getBulletY() { return -1; }
        int getBulletX() { return -1; }
        std::list<Nibbler> getSnake() { return snakes; }
        int checkInputs(int dir);
        void setLock();
        void relaunch();
        int getScore();

    private:
        int x;
        int y;
        std::list<Nibbler> snakes;
        std::vector<int> xcoords;
        std::vector<int> ycoords;
        int food_x;
        int food_y;
        bool lock;
        int score;
        void createSnake();
        void changeFoodCoord(int x, int y);
        int changeDir(Nibbler logic, int dir);
        int checkSnake(int dir, int xx);
};

#endif /* !NIBBLER_HPP_ */
