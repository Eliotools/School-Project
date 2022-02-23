/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD16-eliot.martin
** File description:
** DomesticKoala
*/

#ifndef DOMESTICKOALA_HPP_
#define DOMESTICKOALA_HPP_
#include <vector>
#include <iostream>
#include <string>
#include "KoalaAction.hpp"

class DomesticKoala {
    public:
        DomesticKoala(KoalaAction &ka);
        ~DomesticKoala();
        DomesticKoala(const  DomesticKoala  &old);
        DomesticKoala &operator =(const  DomesticKoala &old);
        typedef void (KoalaAction::*methodPointer_t)(const std::string &);
        const std::vector <methodPointer_t > *getActions () const;
        void learnAction(unsigned char command, methodPointer_t action);
        void unlearnAction(unsigned char command);
        void doAction(unsigned char command, const std::string &param);
    protected:
    private:
        KoalaAction _Action;
        std::vector <char> _v1;
        std::vector <methodPointer_t> _v2;
};

#endif /* !DOMESTICKOALA_HPP_ */
