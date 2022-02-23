/*
** EPITECH PROJECT, 2021
** B-OOP-400-LIL-4-1-tekspice-thomas.gillet [WSL: Ubuntu]
** File description:
** chipset
*/

#ifndef CHIPSET_HPP_
#define CHIPSET_HPP_
#include "IComponent.hpp"
#include <list>
#include <vector>
#include <iterator>
#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <memory>

class Component : public nts::IComponent
{
    public :
        Component();
        ~Component();
        void createMap(std::string file, std::string gate);
        std::vector<int> createIntVector(int one, int two);
        void simulate();
        void dump();
        pinData *getPin(int i);
        std::map<int, pinData> getMap();
        pinData createStruc(nts::Tristate states, std::vector<int> in, int out, std::string name, int places);
        void addInMap(pinData struc);
        void printList(std::vector<int> const &list);
        void printMap(bool hint);
        void setState(pinData *pin, nts::Tristate new_state);
        int getState(pinData *pin);
        int getStateSim(pinData *pin);
        pinData *getPinByName(std::string name);
        nts::Tristate intToTristate(int i);
        void displayAll();
        void mouvState();
        int getNbPin();
        void setStateSim(pinData *pin, nts::Tristate stat);
        void makeItWork();

        // nts::Tristate compute(std::size_t pin)
        //void setLink (std::size_t pin, nts::IComponent & other, std::size_t otherPin);
        //int getNthPin(int n);
        std::map<int, pinData> _pins;
};
#endif /* !CHIPSET_HPP_ */
