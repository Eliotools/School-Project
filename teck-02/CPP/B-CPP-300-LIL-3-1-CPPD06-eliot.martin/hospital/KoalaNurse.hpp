/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD06-eliot.martin
** File description:
** KoalaNurse
*/

#ifndef KOALANURSE_HPP_
#define KOALANURSE_HPP_
#include "SickKoala.hpp"

class KoalaNurse {
    public:
        KoalaNurse(int new_id);
        ~KoalaNurse();

        void giveDrug(std::string drug, SickKoala *patient);
        std::string readReport(std::string filename);
        void timeCheck(void);
        int getId(void);
    protected:
    private:
        int id;
        bool work;
};

#endif /* !KOALANURSE_HPP_ */
