/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD08-eliot.martin
** File description:
** Droid
*/

#include "Droid.hpp"
#include <iostream>
#include <string>

Droid::Droid(Droid &old) : Id(old.Id), Energy(old.Energy), Attack(old.Attack), Toughness(old.Toughness), Status(old.Status)
{
    std::cout <<"Droid '" << this->Id << "' Activated, Memory Dumped" << std::endl;
}

Droid::Droid(): Id(""), Energy(50), Attack(25), Toughness(15)
{
    this->Status = new std::string ("Standing by");
    std::cout <<"Droid '" << this->Id << "' Activated" << std::endl;
}

Droid::Droid(std::string s_nb) : Id(s_nb), Energy(50), Attack(25), Toughness(15)
{
    this->Status = new std::string ("Standing by");
    std::cout <<"Droid '" << this->Id << "' Activated" << std::endl;
}

Droid::~Droid()
{
    std::cout <<"Droid '" << this->Id << "' Destroyed" << std::endl;
}

std::string Droid::getId() const
{
    return(this->Id);
}

size_t Droid::getEnergy() const
{
    return(this->Energy);
}

size_t Droid::getAttack() const
{
    return(this->Attack);
}

size_t Droid::getToughness() const
{
    return(this->Toughness);
}

std::string *Droid::getStatus() const
{
    return(this->Status);
}

void Droid::setStatus(std::string *n_status)
{
    this->Status = (n_status);
}

void Droid::setId(std::string n_Id)
{
    this->Id = n_Id;
}

void Droid::setEnergy(size_t n_Energy)
{
    this->Energy = n_Energy;
}

bool Droid::operator==(Droid &fs) const
{
    if (fs.Energy == this->Energy && *fs.Status == *this->Status && fs.Id == this->Id)
        return true;
    return false;
}

bool Droid::operator!=(Droid &fs) const
{
    if (fs.Energy == this->Energy && *fs.Status == *this->Status && fs.Id == this->Id)
        return false;
    return true;
}

void Droid::operator<<(size_t &batterie)
{
    size_t use = 100 - this->Energy;

    if (batterie >= use) {
        batterie -= use;
        this->Energy += use;
    }
    else {
        this->Energy += batterie;
        batterie = 0;
    }
}

std::ostream &operator<<(std::ostream &str, Droid &D)
{
    str << "Droid '" << D.getId() << "', " << *D.getStatus() << ", " << D.getEnergy(); 
    return (str);
}

void Droid::operator=(Droid &d1)
{
    setId(d1.Id);
    setStatus(d1.Status);
    setEnergy(d1.Energy);
}
