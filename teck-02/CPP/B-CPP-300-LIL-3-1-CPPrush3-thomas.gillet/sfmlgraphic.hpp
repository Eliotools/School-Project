/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPrush3-thomas.gillet
** File description:
** sfmlgraphic
*/

#ifndef SFMLGRAPHIC_HPP_
#define SFMLGRAPHIC_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "info.hpp"
#include "IMonitor.hpp"

class Graphibox : public IMonitorModule, public IMonitorDisplay
{
    public:
        Graphibox();
        ~Graphibox();
        void addBox(int y);
        std::vector<sf::RectangleShape> getBox() const;
        void my_display(sf::RenderWindow &window, info &my_info);

        void addText(std::string str, int y);
        std::vector<sf::Text> getTexts() const;

        sf::Font getFont() const;
                
    private:
        std::vector<sf::RectangleShape> _box;
        std::vector<sf::Text> _texts;

        sf::Font font;
};

#endif /* !SFMLGRAPHIC_HPP_ */
