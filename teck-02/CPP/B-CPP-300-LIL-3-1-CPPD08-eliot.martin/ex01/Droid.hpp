/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD08-eliot.martin
** File description:
** Droid
*/

#ifndef DROID_HPP_
#define DROID_HPP_
#include <string>
#include <iostream>
#include "DroidMemory.hpp"

class Droid {
    public:
        Droid(std::string s_nb);
        Droid(Droid &old);
        ~Droid();
        std::string getId() const;
        size_t getEnergy() const;
        size_t getToughness() const;
        size_t getAttack() const;
        std::string *getStatus() const;
        void setBattleData(DroidMemory *D_m);
        DroidMemory *getBattleData() const;
        void setStatus(std::string *n_status);
        void setId(std::string n_Id);
        void setEnergy(const size_t n_Energy);
        bool operator==(Droid const &fs) const;
        bool operator!=(Droid const &fs) const;
        void operator<<(size_t &batterie);
        void operator=(Droid &d1gic);

    protected:
    private:
    std::string Id;
    size_t Energy;
    const size_t Attack;
    const size_t Toughness;
    std::string *Status;
    DroidMemory *BattleData;
};

std::ostream &operator<<(std::ostream &str, const Droid &D);
#endif /* !DROID_HPP_ */