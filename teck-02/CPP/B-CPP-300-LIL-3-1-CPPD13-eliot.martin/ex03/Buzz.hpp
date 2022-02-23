/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD13-eliot.martin
** File description:
** Buzz
*/

#ifndef BUZZ_HPP_
#define BUZZ_HPP_
#include "Toy.hpp"

class Buzz : public Toy{
    public:
        Buzz(std::string name, std::string ascii = "buzz.txt");
        ~Buzz();
        void speak(const std::string str);

    protected:
    private:
};

#endif /* !BUZZ_HPP_ */
