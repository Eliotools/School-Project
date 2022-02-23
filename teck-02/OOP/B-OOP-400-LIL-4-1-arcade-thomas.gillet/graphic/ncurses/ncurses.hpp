/*
** EPITECH PROJECT, 2021
** B-OOP-400-LIL-4-1-arcade-thomas.gillet [WSL: Ubuntu]
** File description:
** ncurses
*/

#ifndef NCURSES_HPP_
#define NCURSES_HPP_

#include "../igraphic.hpp"
#include <ncurses.h>

/**
* \class MyNcurses
* \brief fucntion for draw game in ncurses use IGraphic interface
*/
class MyNcurses : public IGraphic
{
    public:
        MyNcurses();
        ~MyNcurses();
        void init();
        void stop();
        void launch();
        int getInput();
        void print_map();
        void settingInput(int input);
        void drawobj(std::vector<int> xcoords, std::vector<int> ycoords, int food_x, int food_y, int bullet_x, int bullet_y);
    private:
        int _input;
        char rectangle;
        char apple;
        char bullet;
        WINDOW *_screen;
};

#endif /* !NCURSES_HPP_ */
