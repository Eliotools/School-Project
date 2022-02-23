/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD10-eliot.martin
** File description:
** Peon
*/

#ifndef PEON_HPP_
#define PEON_HPP_
#include "Victim.hpp"

class Peon : public Victim {
    public:
        Peon(std::string name);
        ~Peon();
        void getPolymorphed() const;

    protected:
    private:
};

#endif /* !PEON_HPP_ */
