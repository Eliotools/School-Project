/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD07A-eliot.martin
** File description:
** KreoCom
*/

#ifndef KREOCOM_HPP_
#define KREOCOM_HPP_
#include <iostream>
#include <string>
class  KreogCom
{
    public:
        KreogCom(int x, int y, int serial);
        ~KreogCom();
        void addCom(int x, int y, int serial);
        void removeCom();
        KreogCom *getCom();
        void ping();
        void locateSquad();
    private:
        int m_serial;
        KreogCom *next;
        int x;
        int y;
};

#endif /* !KREOCOM_HPP_ */
