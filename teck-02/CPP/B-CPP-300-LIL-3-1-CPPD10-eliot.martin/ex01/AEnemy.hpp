/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD10-eliot.martin
** File description:
** AEnemy
*/

#ifndef AENEMY_HPP_
#define AENEMY_HPP_
#include <string>
#include <iostream>

class  AEnemy
{
    public:
        AEnemy(int hp ,const std::string &type);
        virtual ~AEnemy();
        virtual void takeDamage(int damage);
        std::string getType() const;
        int getHP() const;
    protected :
        int _hp;
        std::string _type;
    private:
};

#endif /* !AENEMY_HPP_ */
