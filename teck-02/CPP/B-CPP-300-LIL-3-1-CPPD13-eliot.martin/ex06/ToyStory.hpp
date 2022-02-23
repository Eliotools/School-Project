/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD13-eliot.martin
** File description:
** ToyStory
*/
#include "Toy.hpp"
#ifndef TOYSTORY_HPP_
#define TOYSTORY_HPP_

class ToyStory {
    public:
        ToyStory();
        ~ToyStory();
        static void tellMeAStory(std::string file, Toy &toy1,  bool (Toy::*func1)(std::string str1), Toy &toy2, bool (Toy::*func2)(std::string str2));
};

#endif /* !TOYSTORY_HPP_ */
