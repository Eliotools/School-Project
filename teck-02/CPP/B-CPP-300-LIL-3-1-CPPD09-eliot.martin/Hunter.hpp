/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD09-eliot.martin
** File description:
** Hunter
*/

#ifndef Hunter_HPP_
#define Hunter_HPP_
#include "Character.hpp"
#include "Warrior.hpp"

class Hunter : public Warrior {
    public:
        explicit Hunter(const std::string &name, int level);
        ~Hunter();
        using Warrior::CloseAttack;
        int RangeAttack ();
        void RestorePower();
    protected:
    private:
        

};

#endif /* !Hunter_HPP_ */
