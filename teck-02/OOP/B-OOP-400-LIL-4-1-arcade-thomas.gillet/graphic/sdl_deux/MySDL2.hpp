/*
** EPITECH PROJECT, 2021
** B-OOP-400-LIL-4-1-arcade-thomas.gillet
** File description:
** SDL2
*/

#ifndef SDL2_HPP_
#define SDL2_HPP_
#include <SDL2/SDL.h>
#include <cstdlib>
#include <vector>
#include "../igraphic.hpp"

/**
* \class MySDL2
* \brief SDL2 function for draw game and handle input
*/
class MySDL2 : public IGraphic 
{
    public:
        MySDL2();
        ~MySDL2();
        void init();
        void stop();
        void launch();

        int getInput();
        void setInput();
        void settingInput(int input);
        void drawSnake(std::vector<int> xcoords, std::vector<int> ycoords);
        void drawApple(int, int);
        void drawBullet(int, int);

        void drawobj(std::vector<int> xcoords, std::vector<int> ycoords, int food_x, int food_y, int bullet_x, int bullet_y);

    protected:
    private:
        int _input;
        SDL_Event *_event;
        SDL_Window *_screen;
        SDL_Renderer *_render;
};

#endif /* !MySDL2_HPP_ */
