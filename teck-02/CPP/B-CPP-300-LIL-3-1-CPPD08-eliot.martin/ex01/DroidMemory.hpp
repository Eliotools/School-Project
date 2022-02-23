/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD08-eliot.martin
** File description:
** DroidMemory
*/

#ifndef DROIDMEMORY_HPP_
#define DROIDMEMORY_HPP_
#include <string>
#include <iostream>
class DroidMemory {
    public:
        DroidMemory();
        ~DroidMemory();
        size_t getFingerprint();
        size_t getExp();
        void setFingerprint(size_t nb);
        void setExp(size_t nb);
        DroidMemory &operator<<(DroidMemory &D_m);
        DroidMemory &operator>>(DroidMemory &D_m);
        DroidMemory &operator+=(int nb);
        DroidMemory &operator+=(DroidMemory &D_m);
        DroidMemory *operator+(int nb);
        DroidMemory *operator+(DroidMemory &D_m);

    protected:
    private:
        size_t _Fingerprint;
        size_t _Exp;
};

std::ostream &operator<<(std::ostream &str, DroidMemory &D_m);
#endif /* !DROIDMEMORY_HPP_ */
