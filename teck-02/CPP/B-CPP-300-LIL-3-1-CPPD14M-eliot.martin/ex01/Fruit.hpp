/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD14M-eliot.martin
** File description:
** Fruit
*/

#ifndef FRUIT_HPP_
#define FRUIT_HPP_
#include <string>
#include <iostream>



class Fruit {
    public:
        Fruit(std::string name, int vitamins);
        virtual ~Fruit();
        virtual int getVitamins() const = 0;
        virtual std::string getName() const = 0;

    protected:
        std::string _Name;
        int _vitamins;
    private:
};

#endif /* !FRUIT_HPP_ */
