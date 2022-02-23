/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPrush2-thomas.gillet
** File description:
** Toy
*/

#ifndef TOY_HPP_
#define TOY_HPP_
#include "Object.hpp"

class Toy : public Object
{
    public:
        Toy(std::string title);
        Toy(std::string title, Toy_Type type);
        ~Toy();
        void isTaken(Toy_Type type);

    protected:
    private:
};

#endif /* !TOY_HPP_ */
