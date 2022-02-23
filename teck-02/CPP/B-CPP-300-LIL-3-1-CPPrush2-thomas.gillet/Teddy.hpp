/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPrush2-thomas.gillet
** File description:
** Teddy
*/

#ifndef TEDDY_HPP_
#define TEDDY_HPP_
#include "Toy.hpp"

class Teddy : public Toy {
    public:
        Teddy(std::string title);
        ~Teddy();
        void isTaken();

    protected:
    private:
};

#endif /* !TEDDY_HPP_ */
