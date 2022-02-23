/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPrush2-thomas.gillet
** File description:
** LittlePony
*/

#ifndef LITTLEPONY_HPP_
#define LITTLEPONY_HPP_
#include "Toy.hpp"

class LittlePony  : public Toy{
    public:
        LittlePony(std::string title);
        ~LittlePony();
        void isTaken();

    protected:
    private:
};

#endif /* !LITTLEPONY_HPP_ */
