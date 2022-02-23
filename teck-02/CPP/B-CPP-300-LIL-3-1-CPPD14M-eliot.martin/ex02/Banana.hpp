/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD14M-eliot.martin
** File description:
** Banana
*/

#ifndef BANANA_HPP_
#define BANANA_HPP_
#include "Fruit.hpp"

class Banana : public Fruit{
    public:
        Banana();
        ~Banana();
        virtual int getVitamins() const;
        virtual std::string getName() const;

    protected:
    private:
};

#endif /* !BANANA_HPP_ */
