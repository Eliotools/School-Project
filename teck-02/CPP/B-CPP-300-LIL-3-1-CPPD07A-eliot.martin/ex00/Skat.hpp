/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD07A-eliot.martin
** File description:
** Skat
*/

#include <string>

#ifndef SKAT_HPP_
#define SKAT_HPP_

class  Skat
{
    public:
        Skat(const std::string &name , int  stimPaks);
        ~Skat();

        int stimPaks();
        const std:: string &name();
        void shareStimPaks(int  number, int stock);
        void addStimPaks(unsigned  int  number);
        void useStimPaks ();
        void status ();
    private:
        int _stimpaks;
        std::string _name;
};

#endif /* !SKAT_HPP_ */
