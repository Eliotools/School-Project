/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD13-eliot.martin
** File description:
** Woody
*/

#include "Woody.hpp"

Woody::Woody(std::string name, std::string ascii) : Toy(Toy::WOODY, name, ascii)
{
}

Woody::~Woody()
{
}

void Woody::speak(const std::string str)
{
    std::cout <<"WOODY: "<< getName() << " \"" << str << "\"" << std::endl; 
}