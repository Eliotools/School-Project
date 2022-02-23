/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD09-eliot.martin
** File description:
** Paladin
*/

#ifndef Paladin_HPP_
#define Paladin_HPP_
#include "Character.hpp"
#include "Priest.hpp"
#include "Warrior.hpp"

class Paladin : public Priest, public Warrior{
    public:
        explicit Paladin(const std::string &name, int level);
        ~Paladin();
        using Warrior::CloseAttack;
        using Warrior::RestorePower;
        using Priest::RangeAttack;
        using Priest::Heal;
        int intercept();
    protected:
    private:
        

};

#endif /* !Paladin_HPP_ */
