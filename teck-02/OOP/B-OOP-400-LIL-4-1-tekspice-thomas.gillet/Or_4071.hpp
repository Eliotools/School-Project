/*
** EPITECH PROJECT, 2021
** B-OOP-400-LIL-4-1-tekspice-thomas.gillet [WSL: Ubuntu]
** File description:
** Or_4071
*/

#ifndef OR_4071_HPP_
#define OR_4071_HPP_
#include "Chipset.hpp"
#include "IComponent.hpp"

class Or_4071 : public Component
{
    public :
        Or_4071(std::string name, std::string gate);
        void makeItWork();
        void createBaseMap();
};


#endif /* !OR_4071_HPP_ */
