/*
** EPITECH PROJECT, 2021
** B-OOP-400-LIL-4-1-arcade-thomas.gillet
** File description:
** sfmldraw
*/

#ifndef SFMLDRAW_HPP_
#define SFMLDRAW_HPP_

#include "../igraphic.hpp"
#include <SFML/Graphics.hpp> 

/**
* \class MySfml
* \brief SFML function for draw game use IGraphic interface
*/
class MySfml : public IGraphic
{
    public:
        MySfml();
        ~MySfml();
        void init();
        void stop();
        void launch();

        int getInput();
        void setInput(sf::Event event);
        void settingInput(int input);

        void drawobj(std::vector<int> xcoords, std::vector<int> ycoords, int food_x, int food_y, int bullet_x, int bullet_y);
    private:
        int _input;
        sf::RenderWindow *screen;
        sf::RectangleShape *rectangle;
        sf::CircleShape *apple;
        sf::CircleShape *bullet;

        

// change la couleur de la forme pour du vert
        
};

#endif /* !SFMLDRAW_HPP_ */
