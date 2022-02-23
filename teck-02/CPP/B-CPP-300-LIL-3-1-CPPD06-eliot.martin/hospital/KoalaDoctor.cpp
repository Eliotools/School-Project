/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD06-eliot.martin
** File description:
** KoalaDoctor
*/

#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "KoalaNurse.hpp"
#include "SickKoala.hpp"
#include "KoalaDoctor.hpp"

KoalaDoctor::KoalaDoctor(std::string new_name) : name(new_name)
{
    std::cout << "Dr." << name << ": I'm Dr." << name << "! How do you kreog?" << std::endl;
}

KoalaDoctor::~KoalaDoctor()
{
    if (work)
        std::cout << "Doctor " << name << ": Time to go home to my eucalyptus forest!" << std::endl; 
}

void KoalaDoctor::timeCheck(void)
{
    if (!work) {
        work = true;
        std::cout << "Doctor " << name <<": Time to get to work!" <<std::endl;
    }
}

std::string KoalaDoctor::getName(void)
{
    return(name);
}

void KoalaDoctor::diagnose(SickKoala *patient)
{
    timeCheck();
    std::string p_name = patient->getName();
    std::cout << "Dr." << name << ": So what's goerking you Mr." << p_name << "?" << std::endl;
    patient->poke();
    p_name = p_name + ".report";
    std::ofstream outfile (p_name);
    const char *array[5] = {"Mars","Kinder","Crunch", "Maroilles", "Eucalyptus leaf"};
    outfile << array[random() % 5] << std::endl;
}