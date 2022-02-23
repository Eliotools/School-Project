/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD17-eliot.martin
** File description:
** OneTime
*/

#include "OneTime.hpp"

OneTime::OneTime(const std::string &key)
{
    _ptr = 0;
    _key = key;
}

OneTime::~OneTime()
{
}

void OneTime::reset()
{
    _ptr = 0;
}

void OneTime::encryptChar(char plainchar)
{
    if (_ptr >= _key.size())
        _ptr = 0;
    //std::cout << _key[_ptr];
    int nb = 1;
    int _plus = 0;
    if (isupper(_key[_ptr]))
        _plus = _key[_ptr]-65;
    else
        _plus = _key[_ptr]-97;
    if (plainchar >= 65 && plainchar <= 90)
    {
        while (nb <= _plus) {
            plainchar += 1;
            if (plainchar == 91)
                plainchar = 65;
            nb++;
        }
        _ptr++;
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
        _ptr++;
        std::cout << plainchar;
        return;
    }
    _ptr++;
    std::cout << plainchar;
    return;
}

void OneTime::decryptChar(char cipherchar)
{
    if (_ptr >= _key.size())
        _ptr = 0;
    //std::cout << _key[_ptr];
    int nb = 1;
    int _minus = 0;
    if (isupper(_key[_ptr]))
        _minus = _key[_ptr]-65;
    else
        _minus = _key[_ptr]-97;
    if (cipherchar >= 65 && cipherchar <= 90)
    {
        while (nb <= _minus) {
            cipherchar -= 1;
            if (cipherchar == 64)
                cipherchar = 90;
            nb++;
        }
        _ptr++;
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
        _ptr++;
        std::cout << cipherchar;
        return;
    }
    _ptr++;
    std::cout << cipherchar;
    return;
}