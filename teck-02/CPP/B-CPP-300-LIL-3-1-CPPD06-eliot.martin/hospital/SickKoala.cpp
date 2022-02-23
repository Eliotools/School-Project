/*
** EPITECH PROJECT, 2020
** main
** File description:
** Moi
*/

#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "SickKoala.hpp"

SickKoala::SickKoala(std::string new_name) : name(new_name)
{
}

SickKoala::~SickKoala()
{
    std::cout << "Mr."<< name <<": Kreooogg!! I'm cuuuured!" << std::endl;
}

std::string SickKoala::getName(void)
{
    return(name);
}


void SickKoala::poke(void)
{
    std::cout <<"Mr."<< name <<": Gooeeeeerrk!!" << std::endl;
}

bool SickKoala::takeDrug(std::string drug)
{
    if (drug == "Mars") {
        std::cout <<"Mr." << name << ": Mars, and it kreogs!" << std::endl;
        return(true);
    }
    if (drug == "Kinder") {
        std::cout <<"Mr." << name << ": There is a toy inside!" << std::endl;
        return(true);
    }
    std::cout <<"Mr." << name << ": Goerkreog!" << std::endl;
    return(false);
}

void SickKoala::overDrive(std::string str)
{
    int i  = 1;
    while(str.find("Kreog!") != std::string::npos)
    {
        i = str.find("Kreog!"); 
        str.replace(i, 6, "1337!");
    }
    std::cout << "Mr." << name << ": "<< str << std::endl;

}
