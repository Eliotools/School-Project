/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD14M-eliot.martin
** File description:
** Lemon
*/

#ifndef LEMON_HPP_
#define LEMON_HPP_
#include "Fruit.hpp"

class Lemon : public Fruit{
    public:
        Lemon();
        ~Lemon();
        virtual int getVitamins() const;
        virtual std::string getName() const;

    protected:
    private:
};

#endif /* !LEMON_HPP_ */
