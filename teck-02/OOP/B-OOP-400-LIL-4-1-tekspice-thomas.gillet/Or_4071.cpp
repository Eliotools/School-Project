/*
** EPITECH PROJECT, 2021
** B-OOP-400-LIL-4-1-tekspice-thomas.gillet [WSL: Ubuntu]
** File description:
** Or_4071
*/

#include "Or_4071.hpp"
#include "IComponent.hpp"

Or_4071::Or_4071(std::string file, std::string gate)
{
    std::cerr << "4071 created" << std::endl;
    createBaseMap();
    createMap(file, gate);
}

void Or_4071::createBaseMap()
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

void Or_4071::makeItWork()
{
    pinData *out;
    int i = 1;

    std::cout << "DEBUG 4071" << std::endl;

    for (auto pair = _pins.cbegin(); pair != _pins.cend(); ++pair, ++i) {
        if ((*pair).second.place == 1) {
            out = &_pins[i];
            if (getState(getPin(out->pin_in[0])) == nts::TRUE || getState(getPin(out->pin_in[1])) == nts::TRUE) {
                std::cout << "SE" << std::endl;
                out->state = nts::TRUE;
            }
            else if (getState(getPin(out->pin_in[0])) == nts::UNDEFINED || getState(getPin(out->pin_in[1])) == nts::UNDEFINED)
                out->state = nts::UNDEFINED;
            else    
                out->state = nts::FALSE;
        }
    }
}