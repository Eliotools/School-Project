/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD13-eliot.martin
** File description:
** Toy
*/

#ifndef TOY_HPP_
#define TOY_HPP_
#include <string>
#include "Picture.hpp"
#include <iostream>
#include <sstream>
#include <fstream>

class Toy {
    public:
        enum ToyType{BASIC_TOY, ALIEN, BUZZ, WOODY};
        Toy();
        Toy(ToyType type, std::string name, const std::string &file);
        ~Toy();
        ToyType getType() const;
        std::string getName() const;
        void setName(std::string name);
        bool setAscii(const std::string &file);
        std::string getAscii() const;

    protected:
    private:
        Toy::ToyType _type;
        std::string _name;
        Picture *_pic;
};

#endif /* !TOY_HPP_ */
