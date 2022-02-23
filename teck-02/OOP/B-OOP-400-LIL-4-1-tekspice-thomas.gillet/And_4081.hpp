/*
** EPITECH PROJECT, 2021
** B-OOP-400-LIL-4-1-tekspice-thomas.gillet [WSL: Ubuntu]
** File description:
** And_4081
*/

#ifndef AND_4081_HPP_
#define AND_4081_HPP_
#include "Chipset.hpp"
#include "IComponent.hpp"

class And_4081 : public Component
{
    public :
        And_4081(std::string name, std::string gate);
        void makeItWork();
        void createBaseMap();
};


#endif /* !AND_4081_HPP_ */
