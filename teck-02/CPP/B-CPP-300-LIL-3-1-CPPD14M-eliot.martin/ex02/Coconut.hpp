/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD14M-eliot.martin
** File description:
** Coconut
*/

#ifndef COCONUT_HPP_
#define COCONUT_HPP_
#include "Fruit.hpp"

class Coconut : public Fruit{
    public:
        Coconut();
        ~Coconut();
        virtual int getVitamins() const;
        virtual std::string getName() const;

    protected:
    private:
};
#endif /* !COCONUT_HPP_ */
