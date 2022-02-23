/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPrush3-thomas.gillet
** File description:
** IMonitor
*/

#ifndef IMONITOR_HPP_
#define IMONITOR_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <ncurses.h>
#include "Box.hpp"
#include "info.hpp"

class IMonitorModule {
    public:
        IMonitorModule() {}
        ~IMonitorModule() {}
        virtual void addBox(int y) {}
        virtual void addText(std::string str, int y) {}
        virtual std::vector<sf::RectangleShape> getBox() const { std::vector<sf::RectangleShape> v; return v;}
        virtual std::vector<sf::Text> getTexts() const { std::vector<sf::Text> v; return v; }

        virtual void createPrincipalBox(WINDOW *win){}
        virtual WINDOW *create_box(){ WINDOW *w; return w; }
        virtual std::vector<Box> getBoxes() { std::vector<Box> v; return v; }
        virtual Box createBox(){ Box b(0, 1, 2, 3, "Bob"); return b; }
        virtual void createPrincipalBoxes(){}


    protected:
    private:
};

class IMonitorDisplay {
    public:
        IMonitorDisplay() {}
        ~IMonitorDisplay() {}

        virtual void my_display(sf::RenderWindow &window, info my_info) {}
        
        virtual void writeInfo(info my_info) {}
        virtual void writeDate(info my_info) {}
    protected:
    private:
};

#endif /* !IMONITOR_HPP_ */
