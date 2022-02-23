/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD07A-eliot.martin
** File description:
** KoalaBot
*/

#ifndef KOALABOT_HPP_
#define KOALABOT_HPP_
#include <string>
#include "Parts.hpp"

class KoalaBot {
    public:
        KoalaBot();
        ~KoalaBot();
        void informations();
        bool status();
        void setParts(Arms &Arms);
        void setParts(Legs &Legs);
        void setParts(Head &Head);
        void swipParts(Head &head);
        void swipParts(Legs &Legs);
        void swipParts(Arms &Arms);


    protected:
    private:
        std::string _serial;
        Head _H;
        Legs _L;
        Arms _A;
};

#endif /* !KOALABOT_HPP_ */
