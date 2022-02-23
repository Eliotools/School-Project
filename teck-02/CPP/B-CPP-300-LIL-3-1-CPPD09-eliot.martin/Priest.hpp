/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD09-eliot.martin
** File description:
** Priest
*/

#ifndef Priest_HPP_
#define Priest_HPP_
#include "Character.hpp"
#include "Mage.hpp"

class Priest : virtual public Mage{
    public:
        explicit Priest(const std::string &name, int level);
        ~Priest();
        int CloseAttack();
        int RangeAttack ();
        void RestorePower();
        void Heal();
    protected:
    private:
};

#endif /* !Priest_HPP_ */
