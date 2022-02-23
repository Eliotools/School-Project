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


class Droid {
    public:
        Droid();
        explicit Droid(std::string s_nb);
        explicit Droid(Droid &old);
        ~Droid();
        std::string getId() const;
        size_t getEnergy() const;
        size_t getToughness() const;
        size_t getAttack() const;
        std::string *getStatus() const;
        void setStatus(std::string *n_status);
        void setId(std::string n_Id);
        void setEnergy (size_t n_Energy);
        bool operator==(Droid &fs) const;
        bool operator!=(Droid &fs) const;
        void operator<<(size_t &batterie);
        void operator=(Droid &d1);

    protected:
    private:
    std::string Id;
    size_t Energy;
    const size_t Attack;
    const size_t Toughness;
    std::string *Status;
};

std::ostream &operator<<(std::ostream &str, const Droid &D);

#endif /* !DROID_HPP_ */