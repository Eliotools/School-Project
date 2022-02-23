/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD17-eliot.martin
** File description:
** Cesar
*/

#include "Cesar.hpp"

Cesar::Cesar()
{
}

Cesar::~Cesar()
{
}

void Cesar::encryptChar(char plainchar)
{
    int nb = 1;
    if (plainchar >= 65 && plainchar <= 90)
    {
        while (nb <= _plus) {
            plainchar += 1;
            if (plainchar == 91)
                plainchar = 65;
            nb++;
        }
        _plus++;
        std::cout << plainchar;
        return;
    }
    if (plainchar >= 97 && plainchar <= 122)
        {
        while (nb <= _plus) {
            plainchar += 1;
            if (plainchar == 123)
                plainchar = 97;
            nb++;
        }
        _plus++;
        std::cout << plainchar;
        return;
    }
    _plus++;
    std::cout << plainchar;
    return;
}

void Cesar::decryptChar(char cipherchar)
{
    int nb = 1;
    if (cipherchar >= 65 && cipherchar <= 90)
    {
        while (nb <= _minus) {
            cipherchar -= 1;
            if (cipherchar == 64)
                cipherchar = 90;
            nb++;
        }
        _minus++;
        std::cout << cipherchar;
        return;
    }
    if (cipherchar >= 97 && cipherchar <= 122)
        {
        while (nb <= _minus) {
            cipherchar -= 1;
            if (cipherchar == 96)
                cipherchar = 122;
            nb++;
        }
        _minus++;
        std::cout << cipherchar;
        return;
    }
    _minus++;
    std::cout << cipherchar;
    return;
}

void Cesar::reset()
{
    _plus = 3;
    _minus = 3;
}