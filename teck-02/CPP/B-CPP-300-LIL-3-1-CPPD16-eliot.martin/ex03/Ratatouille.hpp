/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD16-eliot.martin
** File description:
** Ratatouille
*/

#ifndef RATATOUILLE_HPP_
#define RATATOUILLE_HPP_
#include <string>
#include <sstream>
#include <iostream>
class Ratatouille {
    public:
        Ratatouille();
        ~Ratatouille();
        Ratatouille(Ratatouille const &other);
        Ratatouille &operator =(const Ratatouille &rhs);
        Ratatouille &addVegetable(unsigned char);
        Ratatouille &addCondiment(unsigned int);
        Ratatouille &addSpice(double);
        Ratatouille &addSauce(const std::string &);
        std::string kooc();

    protected:
    private:
        std::ostringstream _str;
};

#endif /* !RATATOUILLE_HPP_ */
