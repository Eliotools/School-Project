/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD10-eliot.martin
** File description:
** Sorcerer
*/

#ifndef SORCERER_HPP_
#define SORCERER_HPP_

#include "Victim.hpp"
#include <string>
#include <iostream>



class Sorcerer {
    public:
        explicit Sorcerer(std::string name, std::string title);
        ~Sorcerer();
        std::string getName();
        std::string getTitle();
        void polymorph(const Victim &victim)const;

    protected:
        std::string _name;
        std::string _title;
    private:
};
std::ostream &operator<<(std::ostream &str, Sorcerer &Sor);

#endif /* !SORCERER_HPP_ */
