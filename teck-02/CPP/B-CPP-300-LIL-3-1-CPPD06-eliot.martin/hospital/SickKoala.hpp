/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD06-eliot.martin
** File description:
** SickKoala
*/

#ifndef SICKKOALA_HPP_
#define SICKKOALA_HPP_

class SickKoala {
    public:
        SickKoala(std::string new_name);
        ~SickKoala();

        void poke(void);
        void overDrive(std::string str);
        bool takeDrug(std::string drug);
        std::string getName(void);
    private:
        std::string name;
};

#endif /* !SICKKOALA_HPP_ */
