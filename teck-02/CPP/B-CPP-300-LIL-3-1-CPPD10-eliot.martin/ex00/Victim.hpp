/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD10-eliot.martin
** File description:
** Victim
*/

#ifndef VICTIM_HPP_
#define VICTIM_HPP_
#include <string>


class Victim {
    public:
        explicit Victim(std::string name);
        ~Victim();
        std::string getName() const; 
        virtual void getPolymorphed() const;

    protected:
     std::string _name;
    private:
};
std::ostream &operator<<(std::ostream &str, Victim &Sor);

#endif /* !VICTIM_HPP_ */
