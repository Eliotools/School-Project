/*
** EPITECH PROJECT, 2021
** B-OOP-400-LIL-4-1-arcade-thomas.gillet
** File description:
** SDL2
*/


#include <SDL2/SDL.h>
#include "MySDL2.hpp"
/**
* \file
* \brief SDL2 Function
*/

/**
* \brief constructor
*/
MySDL2::MySDL2() : _input(2)
{
}

/**
* \brief deconstructor
*/
MySDL2::~MySDL2()
{
}

/**
* \brief set window and render for launch window
*/
void MySDL2::launch()
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(1024, 768, 0, &_screen, &_render);
    SDL_SetRenderDrawColor(_render, 170, 170, 170, 255);
    _input = 2;
}

/**
* \brief destroy window and quit sdl
*/
void MySDL2::stop()
{
    SDL_DestroyWindow(_screen);
    SDL_Quit();
}

/**
* \brief return _input
* \return _input
*/
int MySDL2::getInput()
{
    return _input;
}

/**
* \brief set _input to value set by key press
*/
void MySDL2::setInput()
{
    SDL_Event event;
    SDL_Keycode key;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_KEYDOWN) {
            key = event.key.keysym.sym;
            if (_input >= 100)
                _input = 0;
            if (key == SDLK_s) 
                _input = 1;
            if (key == SDLK_d)
                _input = 2;
            if (key == SDLK_q)
                _input = 3;
            if (key == SDLK_z)
                _input = 4;
            if (key == SDLK_a)
                _input = 5;
            if (key == SDLK_SPACE)
                _input = 6;
            if (key == SDLK_i)
                _input = 100;
            if (key == SDLK_k)
                _input = 101;
            if (key == SDLK_j)
                _input = 102;
            if (key == SDLK_l)
                _input = 103;
            }
        }
}

/**
* \brief set _input to given value
* \param[in] input-> new value to set
*/
void MySDL2::settingInput(int input)
{
    _input = input;
}

/**
* \brief draw snake at given coord
* \param[in] xcoords -> vector x of coord of snake]
* \param[in] ycoords -> vector of coord y of snake
*/
void MySDL2::drawSnake(std::vector<int> xcoords, std::vector<int> ycoords)
{
    SDL_Rect rect;
    rect.w = 32;
    rect.h = 32;
    for (int d = xcoords.size() - 1; d > 0; d--) {
        rect.x = xcoords[d] * 32;
        rect.y = ycoords[d] * 32;
        if (d != 1) {
            SDL_SetRenderDrawColor(_render, 255, 255, 0, 255);
            SDL_RenderFillRect(_render, &rect);
            SDL_RenderDrawRect(_render, &rect);
        } else {
            SDL_SetRenderDrawColor(_render, 255, 0, 0, 255);
            SDL_RenderFillRect(_render, &rect);
            SDL_RenderDrawRect(_render, &rect);
        }
    }
}

/**
* \brief draw apple
* \param[in] food_x -> coord x of apple
* \param[in] food_y -> coord y of apple
*/
void MySDL2::drawApple(int food_x, int food_y)
{
    SDL_Rect rect;
    rect.w = 32;
    rect.h = 32;
    rect.x = food_x * 32;
    rect.y = food_y * 32;

    SDL_SetRenderDrawColor(_render, 0, 255, 0, 255);
    SDL_RenderFillRect(_render, &rect);
    SDL_RenderDrawRect(_render, &rect);
}

/**
* \brief draw bullet
* \param[in] bullet_x -> coord x of bullet
* \param[in] bullet_y -> coord y of bullet
*/
void MySDL2::drawBullet(int bullet_x, int bullet_y)
{
    SDL_Rect rect;
    rect.w = 32;
    rect.h = 32;
    rect.x = bullet_x * 32;
    rect.y = bullet_y * 32;

    SDL_SetRenderDrawColor(_render, 0, 0, 255, 255);
    SDL_RenderFillRect(_render, &rect);
    SDL_RenderDrawRect(_render, &rect);
}

/**
* \brief call all function for draw game
* \param[in] xcoord -> vector of x coor d of snake
* \param[in] ycoords -> vector ycoords for snake
* \param[in] food_x -> coord x of apple
* \param[in] food_y -> coord y of apple
* \param[in] bullet_x -> coord x of bullet
* \param[in] bullet_y -> coord y of bullet
*/
void MySDL2::drawobj(std::vector<int> xcoords, std::vector<int> ycoords, int food_x, int food_y, int bullet_x, int bullet_y)
{
    setInput();
    SDL_RenderClear(_render);
    drawSnake(xcoords, ycoords);
    drawApple(food_x, food_y);
    drawBullet(bullet_x, bullet_y);
    SDL_SetRenderDrawColor(_render, 0, 0, 0, 255);
    SDL_RenderPresent(_render);
}


void __attribute__((constructor)) calledFirst(); 
void __attribute__((destructor)) calledLast(); 

/**
* \brief entryPoint 
* \return instance of IGraphic 
*/
extern "C" IGraphic *entryPoint()
{
    IGraphic *gra = new MySDL2();    
    return gra;
}

/**
* \brief function call during constructor
*/
void calledFirst() 
{ 
} 

/**
* \brief function call during desconstructor
*/
void calledLast() 
{ 
} 