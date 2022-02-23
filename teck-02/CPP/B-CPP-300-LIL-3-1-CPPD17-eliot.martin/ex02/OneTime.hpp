/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD17-eliot.martin
** File description:
** OneTime
*/

#ifndef ONETIME_HPP_
#define ONETIME_HPP_
#include "IEncryptionMethod.hpp"
#include <iostream>

class OneTime : public IEncryptionMethod{
    public:
        OneTime(const std::string &key);
        ~OneTime();
        void reset();
        void encryptChar(char plainchar);
        void decryptChar(char cipherchar);

    protected:
    private:
        unsigned int _ptr;
        std::string _key;
};

#endif /* !ONETIME_HPP_ */
