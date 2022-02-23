/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD06-eliot.martin
** File description:
** KoalaNurse
*/
#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "KoalaNurse.hpp"
#include "SickKoala.hpp"

KoalaNurse::KoalaNurse(int new_id) : id(new_id)
{
    work = false;
}

KoalaNurse::~KoalaNurse()
{
    std::cout << "Nurse " << id << ": Finally some rest!" << std::endl;
    if (work)
        std::cout << "Nurse " << id << ": Time to go home to my eucalyptus forest!" << std::endl; 
}

int KoalaNurse::getId(void)
{
    return(id);
}

void KoalaNurse::timeCheck(void)
{
    if (!work) {
        work = true;
        std::cout << "Nurse " << id <<": Time to get to work!" <<std::endl;
    }
}

void KoalaNurse::giveDrug(std::string drug, SickKoala *patient)
{
    this->timeCheck();
    patient->takeDrug(drug);
}

std::string KoalaNurse::readReport(std::string filename)
{
    this->timeCheck();
    std::ifstream f (filename);
    std::string report;
    std::string patient_name;
    std::string returned;
    std::stringstream tmp(filename);
    if (f) {
        std::getline(f, report);
        std::getline(tmp, patient_name, '.');
        std::cout << "Nurse " << id  <<": Kreog! Mr." << patient_name  << " needs a " << report << "!" << std::endl;
    }
    else
        return(returned);

    return(report);
}