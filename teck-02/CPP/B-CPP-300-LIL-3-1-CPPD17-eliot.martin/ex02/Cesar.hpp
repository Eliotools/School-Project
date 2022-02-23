/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD17-eliot.martin
** File description:
** Cesar
*/

#ifndef CESAR_HPP_
#define CESAR_HPP_
#include "IEncryptionMethod.hpp"
#include <iostream>
class Cesar : public IEncryptionMethod{
    public:
        Cesar();
        ~Cesar();
        void encryptChar(char plainchar);
        void decryptChar(char cipherchar);
        void reset();

    protected:
    private:
        unsigned int _plus;
        unsigned int _minus;
};

#endif /* !CESAR_HPP_ */
