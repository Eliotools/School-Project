/*
** EPITECH PROJECT, 2021
** B-OOP-400-LIL-4-1-arcade-thomas.gillet [WSL: Ubuntu]
** File description:
** ncurses
*/

#include "ncurses.hpp"
#include <ncurses.h>

/**
* \file
* \brief all function for ncurses print of game infos
*/

/**
* \brief constructor of MyNcurses
*/
MyNcurses::MyNcurses() : _input(2)
{
}

/**
* \brief deconstructor
*/
MyNcurses::~MyNcurses()
{
}

/**
* \brief Set symbol for print and init screen
*/
void MyNcurses::launch()
{
    _screen = initscr();
    timeout(50);
    rectangle = '*';
    apple = 'A';
    bullet = '^';
    _input = 2;
}

/**
* \brief strop sceen
*/
void MyNcurses::stop()
{
    endwin();
}

/**
* \brief set _input to given input
* \param[in] input -> new input
*/
void MyNcurses::settingInput(int input)
{
    _input = input;
}

/**
* \brief get input and set _input
* \return _input
*/
int MyNcurses::getInput()
{
    char input = wgetch(_screen);
    char rec = rectangle;
    if (_input >= 100)
        _input = 0;
    if (input == 's')
        _input = 1;
    if (input == 'd')
        _input = 2;
    if (input == 'q')
        _input = 3;
    if (input == 'z')
        _input = 4;
    if (input == 'a')
        _input = 5;
    if (input == ' ')
        _input = 6;
    if (input == 'i')
        _input = 100;
    if (input == 'k')
        _input = 101;
    if (input == 'j')
        _input = 102;
    if (input == 'l')
        _input = 103;


    rectangle = rec;
    return _input;
}

/**
* \brief draw snake, apple, bullet
* \param[in] xcoord -> vector of x coor d of snake
* \param[in] ycoords -> vector ycoords for snake
* \param[in] food_x -> coord x of apple
* \param[in] food_y -> coord y of apple
* \param[in] bullet_x -> coord x of bullet
* \param[in] bullet_y -> coord y of bullet
*/
void MyNcurses::drawobj(std::vector<int> xcoords, std::vector<int> ycoords, int food_x, int food_y, int bullet_x, int bullet_y)
{
    clear();
    mvprintw(bullet_y, bullet_x, "%c",bullet);
    mvprintw(food_y, food_x, "%c",apple);
    for (int d = xcoords.size() - 1; d > 0; d--)
        mvprintw(ycoords[d], xcoords[d], "%c",rectangle);
    print_map();
    refresh();
}

/**
* \brief print ext map
*/
void MyNcurses::print_map(void)
{
    for (int i = 0; i != 24; i++)
        mvprintw(i, 32, "|");
    for (int i = 0; i != 32; i++)
        mvprintw(24, i, "_");
}
// Créer le entryPoint

void __attribute__((constructor)) calledFirst(); 
void __attribute__((destructor)) calledLast(); 

/**
* \brief entryPoint 
* \return instance of IGraphic 
*/
extern "C" IGraphic *entryPoint()
{
    IGraphic *gra = new MyNcurses();
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