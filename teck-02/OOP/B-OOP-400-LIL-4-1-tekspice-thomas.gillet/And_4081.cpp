/*
** EPITECH PROJECT, 2021
** B-OOP-400-LIL-4-1-tekspice-thomas.gillet [WSL: Ubuntu]
** File description:
** And_4081
*/

#include "And_4081.hpp"
#include "IComponent.hpp"

And_4081::And_4081(std::string file, std::string gate)
{
    std::cerr << "4081 created" << std::endl;
    createBaseMap();
    createMap(file, gate);
}

void And_4081::createBaseMap()
{
    addInMap(createStruc(nts::UNDEFINED, createIntVector(0, 0), 3, "default", 0));
    addInMap(createStruc(nts::UNDEFINED, createIntVector(0, 0), 3, "default", 0));
    addInMap(createStruc(nts::UNDEFINED, createIntVector(1, 2), 0, "default", 1));
    addInMap(createStruc(nts::UNDEFINED, createIntVector(5, 6), 0, "default", 1));
    addInMap(createStruc(nts::UNDEFINED, createIntVector(0, 0), 4, "default", 0));
    addInMap(createStruc(nts::UNDEFINED, createIntVector(0, 0), 4, "default", 0));
    addInMap(createStruc(nts::UNDEFINED, createIntVector(0, 0), 0, "default", 0));
    addInMap(createStruc(nts::UNDEFINED, createIntVector(0, 0), 10, "default", 0));
    addInMap(createStruc(nts::UNDEFINED, createIntVector(0, 0), 10, "default", 0));
    addInMap(createStruc(nts::UNDEFINED, createIntVector(8, 9), 0, "default", 1));
    addInMap(createStruc(nts::UNDEFINED, createIntVector(12, 13), 0, "default", 1));
    addInMap(createStruc(nts::UNDEFINED, createIntVector(0, 0), 10, "default", 0));
    addInMap(createStruc(nts::UNDEFINED, createIntVector(0, 0), 10, "default", 0));
    addInMap(createStruc(nts::UNDEFINED, createIntVector(0, 0), 0, "default", 0));
}

void And_4081::makeItWork()
{
    pinData *out;
    int i = 1;

    std::cout << "DEBUG 4081" << std::endl;

    for (auto pair = _pins.cbegin(); pair != _pins.cend(); ++pair, ++i) {
        if ((*pair).second.place == 1) {
            out = &_pins[i];
            if (getState(getPin(out->pin_in[0])) == nts::TRUE && getState(getPin(out->pin_in[1])) == nts::TRUE)
                out->state = nts::TRUE;
            else if (getState(getPin(out->pin_in[0])) == nts::UNDEFINED || getState(getPin(out->pin_in[1])) == nts::UNDEFINED)
                out->state = nts::UNDEFINED;
            else    
                out->state = nts::FALSE;
        }
    }
}