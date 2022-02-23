/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD13-eliot.martin
** File description:
** Woody
*/

#ifndef WOODY_HPP_
#define WOODY_HPP_
#include "Toy.hpp"

class Woody : public Toy {
    public:
        Woody(std::string name, std::string ascii = "woody.txt");
        ~Woody();
        void speak(const std::string str);

    protected:
    private:
};

#endif /* !WOODY_HPP_ */
