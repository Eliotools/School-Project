/*
** EPITECH PROJECT, 2021
** B-OOP-400-LIL-4-1-arcade-thomas.gillet
** File description:
** sfmldraw
*/

#include "sfmldraw.hpp"

/**
* \file
* \brief Function for draw with SFML
*/

/**
* \brief constructor
*/
MySfml::MySfml() : _input(2)
{
}

/**
* \brief deconstructor
*/
MySfml::~MySfml()
{
}

/**
* \brief set screen and element to draw
*/
void MySfml::launch()
{
    screen = new sf::RenderWindow(sf::VideoMode(1024, 768), "Link igame test");
    screen->setFramerateLimit(60);
    rectangle = new sf::RectangleShape(sf::Vector2f(32, 32));
    rectangle->setFillColor(sf::Color::Blue);

    apple = new sf::CircleShape(16);
    apple->setFillColor(sf::Color(100, 250, 50));

    bullet = new sf::CircleShape(16, 3);
    bullet->setFillColor(sf::Color(55, 210, 232));
    _input = 2;
}

/**
* \brief close window
*/
void MySfml::stop()
{
    screen->close();
}

/**
* \brief set _input with correspondant key pressed
* \param[in] event -> event of key press
*/
void MySfml::setInput(sf::Event event)
{
    while (screen->pollEvent(event)) {
        if (_input >= 100)
            _input = 0;
        if (event.type == sf::Event::Closed)
            screen->close();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            _input = 1;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) )
            _input = 2;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            _input = 3;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
            _input = 4;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            _input = 5;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            _input = 6;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
            _input = 100;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
            _input = 101;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
            _input = 102;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
            _input = 103;
    }
}

/**
* \brief return _input
* \return _input
*/
int MySfml::getInput()
{
    return _input;
}

/**
* \brief draw and set position of obj of game
* \param[in] xcoord -> vector of x coor d of snake
* \param[in] ycoords -> vector ycoords for snake
* \param[in] food_x -> coord x of apple
* \param[in] food_y -> coord y of apple
* \param[in] bullet_x -> coord x of bullet
* \param[in] bullet_y -> coord y of bullet
*/
void MySfml::drawobj(std::vector<int> xcoords, std::vector<int> ycoords, int food_x, int food_y, int bullet_x, int bullet_y)
{
    sf::Event event;

    apple->setPosition(sf::Vector2f(food_x * 32, food_y * 32));
    bullet->setPosition(sf::Vector2f(bullet_x * 32, bullet_y * 32));
    this->setInput(event);
    screen->clear();
    for (int d = xcoords.size() - 1; d > 0; d--) {
        rectangle->setPosition(sf::Vector2f(xcoords[d] * 32, ycoords[d] * 32));
        if (d != 1)
            rectangle->setFillColor(sf::Color::Yellow);
        else
            rectangle->setFillColor(sf::Color::Red);
        screen->draw(*rectangle);
    }
    screen->draw(*apple);
    screen->draw(*bullet);
    screen->display();
}

/**
* \brief set _input to given input
* \param[in] input -> new input
*/
void MySfml::settingInput(int input)
{
    _input = input;
}

void __attribute__((constructor)) calledFirst(); 
void __attribute__((destructor)) calledLast(); 

/**
* \brief entryPoint 
* \return instance of IGraphic 
*/
extern "C" IGraphic *entryPoint() 
{
    IGraphic *gra = new MySfml();
    
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
void calledLastgra() 
{ 
} 