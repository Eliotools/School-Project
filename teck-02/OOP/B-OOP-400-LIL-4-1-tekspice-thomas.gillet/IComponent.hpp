/*
** EPITECH PROJECT, 2021
** B-OOP-400-LIL-4-1-tekspice-thomas.gillet [WSL: Ubuntu]
** File description:
** mano
*/

#ifndef MANO_HPP_
#define MANO_HPP_
#include <iostream>
#include <map>
#include <vector>
#include <string>

namespace nts
{
    enum Tristate {
    UNDEFINED = (-true),
    TRUE = true,
    FALSE = false
    };

    class IComponent
    {
        public :
            virtual ~IComponent() = default ;
            virtual void makeItWork() = 0;
            //virtual void simulate(std::size_t tick) = 0;
            //virtual nts::Tristate compute(std::size_t pin) = 0;
            //virtual void setLink (std::size_t pin, nts::IComponent & other, std::size_t otherPin) = 0;
            //virtual void dump() const = 0;
    };
}

struct pinData {
    std::string name;
    nts::Tristate state;
    nts::Tristate stateSim;
    std::vector<int> pin_in;
    int pin_out;
    int place;
};

#endif /* !MANO_HPP_ */
