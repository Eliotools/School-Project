/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD07A-eliot.martin
** File description:
** Parts
*/

#ifndef PARTS_HPP_
#define PARTS_HPP_
#include <string>

class Arms {
    public:
        Arms(std::string serial, bool functional);
        Arms();
        ~Arms();
        void informations();
        bool isFunctional();
        std::string serial();
    
    protected:
    private:
        std::string _serial;
        bool _functional;
};

class Legs {
    public:
        Legs(std::string serial, bool functional);
        Legs();
        ~Legs();
        void informations();
        bool isFunctional();
        std::string serial();

    protected:
    private:
        std::string _serial;
        bool _functional;
};

class Head {
    public:
        Head(std::string serial, bool functional);
        Head();
        ~Head();
        void informations();
        bool isFunctional();
        std::string serial();

    protected:
    private:
        std::string _serial;
        bool _functional;
};

#endif /* !PARTS_HPP_ */
