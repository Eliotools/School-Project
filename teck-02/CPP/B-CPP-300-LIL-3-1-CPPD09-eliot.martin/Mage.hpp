/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD09-eliot.martin
** File description:
** Mage
*/

#ifndef Mage_HPP_
#define Mage_HPP_
#include "Character.hpp"

class Mage : virtual public Character{
    public:
        explicit Mage(const std::string &name, int level);
        ~Mage();
        int CloseAttack();
        int RangeAttack ();
        void RestorePower();
    protected:
    private:
        

};

#endif /* !Mage_HPP_ */
