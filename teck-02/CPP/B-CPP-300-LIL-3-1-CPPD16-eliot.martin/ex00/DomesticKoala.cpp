/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD16-eliot.martin
** File description:
** DomesticKoala
*/

#include "DomesticKoala.hpp"

DomesticKoala::DomesticKoala(KoalaAction &ka)
{
    _Action = ka;
}

DomesticKoala::~DomesticKoala()
{
}

DomesticKoala::DomesticKoala(const DomesticKoala &old)
{
    _Action = old._Action;
    _v1 = old._v1;
    _v2 = old._v2;
}

DomesticKoala &DomesticKoala::operator=(const DomesticKoala &old)
{
    _Action = old._Action;
    _v1 = old._v1;
    _v2 = old._v2;
    return(*this);
}

void DomesticKoala::learnAction(unsigned char command, methodPointer_t action)
{
    _v1.push_back(command);
    _v2.push_back(action);
}

void DomesticKoala::unlearnAction(unsigned char command)
{
    int i = 0;
    for (i; i != _v1.size() && _v1[i] != command; i++);
    _v1.erase(_v1.begin() + i);
    _v2.erase(_v2.begin() + i);
}

void DomesticKoala::doAction(unsigned char command, const std::string &param)
{
    int i = 0;
    for (i; i != _v1.size() && _v1[i] != command; i++);
    if (i < _v1.size())
        (_Action.*_v2[i])(param);
}