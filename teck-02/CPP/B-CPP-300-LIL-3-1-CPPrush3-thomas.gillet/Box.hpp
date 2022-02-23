/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPrush3-thomas.gillet
** File description:
** Box
*/

#ifndef BOX_HPP_
#define BOX_HPP_
#include "ncurses.h"
#include <iostream>

class Box {
    public:
        Box(int height, int width, int start_y, int start_X, const std::string id);
        ~Box();
        virtual WINDOW *create_box();
        std::string getId();
        int getHeight();
        int getWidth();
        int getY();
        int getX();

    protected:
    private:
        int _height;
        int _width;
        int _start_y;
        int _start_x;
        std::string _identifier;
};

#endif /* !BOX_HPP_ */
