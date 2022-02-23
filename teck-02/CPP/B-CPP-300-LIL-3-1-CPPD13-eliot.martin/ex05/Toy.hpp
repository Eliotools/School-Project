/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD13-eliot.martin
** File description:
** Toy
*/

#ifndef TOY_HPP_
#define TOY_HPP_
#include "Picture.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

class Toy {
    public:
        class Error {
            public:
                Error();
                ~Error();
                std::string what() const;
                std::string where() const;
                enum ErrorType {UNKNOW, PICTURE, SPEAK};
                ErrorType type;
                void setType(ErrorType new_type);
        };
        enum ToyType{BASIC_TOY, ALIEN, BUZZ, WOODY};
        Toy();
        Toy(const Toy &toy);
        Toy(ToyType type, std::string name, const std::string &file);
        ~Toy();
        ToyType getType() const;
        std::string getName() const;
        void setName(std::string name);
        bool setAscii(const std::string &file);
        std::string getAscii() const;
        Toy &operator=(const Toy &pic);     
        void operator<<(std::string std);
        virtual void speak(const std::string str);
        virtual bool speak_es(std::string str);
        Toy::Error getLastError() const;
        Error error;

    protected:
    private:
        Toy::ToyType _type;
        std::string _name;
        Picture *_pic;
};

std::ostream &operator<<(std::ostream &str, Toy &toy);

#endif /* !TOY_HPP_ */
