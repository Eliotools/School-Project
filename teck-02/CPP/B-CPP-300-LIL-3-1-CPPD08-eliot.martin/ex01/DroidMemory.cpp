/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD08-eliot.martin
** File description:
** DroidMemory
*/

#include "DroidMemory.hpp"
#include <string>
#include <iostream>

DroidMemory::DroidMemory() : _Fingerprint(random()), _Exp(0)
{
}

DroidMemory::~DroidMemory()
{
}

size_t DroidMemory::getFingerprint()
{
    return(this->_Fingerprint);
}

size_t DroidMemory::getExp()
{
    return(this->_Exp);
}

void DroidMemory::setExp(size_t nb)
{
    this->_Exp = nb;
}

void DroidMemory::setFingerprint(size_t nb)
{
    this->_Fingerprint = nb;
}

DroidMemory &DroidMemory::operator<<(DroidMemory &D_m)
{
    this->_Exp += D_m._Exp;
    this->_Fingerprint ^= D_m._Fingerprint;
    return(*this);
}

DroidMemory &DroidMemory::operator>>(DroidMemory &D_m)
{
    D_m._Exp += this->_Exp;
    D_m._Fingerprint ^= this->_Fingerprint;
    return(*this);
}

DroidMemory &DroidMemory::operator+=(int nb)
{
    this->_Exp += nb;
    this->_Fingerprint ^= nb;
    return(*this);
}

DroidMemory &DroidMemory::operator+=(DroidMemory &D_m)
{
    this->_Exp += D_m._Exp;
    return(*this);
}

DroidMemory *DroidMemory::operator+(int nb)
{
    DroidMemory *tmp = new DroidMemory;
    tmp->_Exp += nb;
    tmp->_Fingerprint ^= nb;
    return(tmp);
}

DroidMemory *DroidMemory::operator+(DroidMemory &D_m)
{
    DroidMemory *tmp = new DroidMemory;
    tmp->_Exp += D_m._Exp;
    return(tmp);
}

std::ostream &operator<<(std::ostream &str, DroidMemory &D_m)
{
    str << "DroidMemory '" << D_m.getFingerprint() << "', " << D_m.getExp() << ", "; 
    return (str);
}