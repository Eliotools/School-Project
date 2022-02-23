/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPrush3-thomas.gillet
** File description:
** sfmlgraphic
*/

#include "sfmlgraphic.hpp"
#include <unistd.h>

Graphibox::Graphibox() : IMonitorModule(), IMonitorDisplay()
{
    if (!font.loadFromFile("Raleway-Regular.ttf"))
        std::cerr << "Cannot find font" << std::endl;
}

Graphibox::~Graphibox()
{

}

void Graphibox::addBox(int y)
{
    sf::Color grey(204, 210, 215);
    sf::Color blue(129, 184, 239);
    sf::Color red(222, 82, 82);
    sf::RectangleShape shape(sf::Vector2f(350, 50));
    if (y == 370) {
        shape.setFillColor(red);
    }
    else if (y >= 440) {
        shape.setFillColor(blue);
    }
    else
        shape.setFillColor(grey);
    shape.setPosition(20, y);

    this->_box.push_back(shape);
}

std::vector<sf::RectangleShape> Graphibox::getBox() const
{
    return this->_box;
}

void Graphibox::my_display(sf::RenderWindow &window, info &my_info)
{
    float act;
    std::string acty;
    // Draw boxes
    for (int i(0); i < _box.size(); i++)
        window.draw(_box[i]);
    
    // Draw texts
    my_info.setDate();
    _texts[4].setString(my_info.getDate());

    act = ((stof(my_info.getCpu().getFrequency()) * 100000) / my_info.getCpu().reset()) / 1000;
    acty = std::to_string(act) + "GHz";
    //sleep(0.3);
    _texts[9].setString("Activity :\n" + acty);

    for (int j(0); j < _texts.size(); j++)
        window.draw(_texts[j]);

    sf::Text percent;
    percent.setFont(font);
    percent.setString(" - 100 % - ");
    percent.setCharacterSize(20);
    percent.setFillColor(sf::Color::Magenta);
    percent.setPosition(540, 605);
    window.draw(percent);
    sf::Text percent2 = percent;
    percent2.setString(" - 50 % - ");
    percent2.setPosition(540, 295);
    window.draw(percent2);
    sf::Text percent3 = percent;
    percent3.setString(" - 0 % - ");
    percent3.setPosition(540, 5);
    window.draw(percent3);
}

void Graphibox::addText(std::string str, int y)
{
    info my_info;

    sf::Text text;
    text.setFont(font);
    if (str == my_info.getUsername())
        text.setString("Username :\n" + my_info.getUsername());
    else if (str == my_info.getHostname())
        text.setString("Hostname :\n" + my_info.getHostname());
    else if (str == my_info.getSysname())
        text.setString("Sysname :\n" + my_info.getSysname());
    else if (str == my_info.getKernelver())
        text.setString("Kernel Version :\n" + my_info.getKernelver());
    else if (str == my_info.getDate())
        text.setString(my_info.getDate());
    else
        text.setString(str);

    text.setCharacterSize(18);
    text.setFillColor(sf::Color::Black);
    text.setPosition(25, y);
    _texts.push_back(text);    
}

std::vector<sf::Text> Graphibox::getTexts() const
{
    return _texts;
}

sf::Font Graphibox::getFont() const
{
    return font;
}