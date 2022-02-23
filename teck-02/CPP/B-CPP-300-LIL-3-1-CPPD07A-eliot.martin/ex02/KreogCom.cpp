/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD07A-eliot.martin
** File description:
** KreoCom
*/

#include "KreogCom.hpp"
#include <iostream>
#include <string>

KreogCom::KreogCom(int x, int y, int serial)
{
    this->m_serial = serial;
    this->next = NULL;
    this->x = x;
    this->y = y;
    std::cout <<"KreogCom "<<this->m_serial<<" initialized" << std::endl;
}

KreogCom::~KreogCom()
{
}

void KreogCom::addCom(int x, int y, int serial)
{   
    KreogCom *other = new KreogCom(x, y, serial);

    other->next = this->next;
    this->next = other;
}

void KreogCom::locateSquad()
{
    if (this->next == NULL) {
        this->ping();
        return;
    }
    KreogCom *tmp = this->next;
    while (tmp != NULL) {
        tmp->ping();
        tmp = tmp->next;
    }
    this->ping();
}

void KreogCom::ping()
{
    std::cout << "KreogCom " << this->m_serial << " currently at "<< this->x <<" "<< this->y << std::endl;
}

void KreogCom::removeCom()
{
    if (this->next == NULL)
        return;
    std::cout << "KreogCom "<<this->next->m_serial<< " shutting down" << std::endl;    
    this->next = this->next->next;
}

KreogCom *KreogCom::getCom()
{
    return(this->next);
}