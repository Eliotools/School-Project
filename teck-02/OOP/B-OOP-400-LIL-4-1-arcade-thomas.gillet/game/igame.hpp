/*
** EPITECH PROJECT, 2021
** B-OOP-400-LIL-4-1-arcade-thomas.gillet
** File description:
** igame
*/

/**
* \class IGame
* \brief Interface for game
*/

#ifndef IGAME_HPP_
#define IGAME_HPP_

#include <vector>
/**
* \class IGame
* \brief Interface for Game
*/
class IGame
{
    public:
        virtual ~IGame() = default;
        virtual int checkInputs(int dir) = 0;
        virtual int getXpos() = 0;
        virtual int getYpos() = 0;
        virtual std::vector<int> getSnakeXpos() = 0;
        virtual std::vector<int> getSnakeYpos() = 0;
        virtual int getFoodY() = 0;
        virtual int getFoodX() = 0;
        virtual int getBulletX() = 0;
        virtual int getBulletY() = 0;
        virtual void setLock() = 0;
        virtual void relaunch() = 0;
        virtual int getScore() = 0;
};

#endif /* !IGAME_HPP_ */
