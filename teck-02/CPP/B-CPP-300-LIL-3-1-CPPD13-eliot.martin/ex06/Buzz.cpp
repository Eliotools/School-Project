/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD13-eliot.martin
** File description:
** Buzz
*/

#include "Buzz.hpp"

Buzz::Buzz(std::string name, std::string ascii) : Toy(Toy::BUZZ, name, ascii)
{
}

Buzz::~Buzz()
{
}

bool Buzz::speak(const std::string str)
{
    std::cout <<"BUZZ: "<< getName() << " \"" << str << "\"" << std::endl; 
    return true;
}

bool Buzz::speak_es(const std::string str)
{
    std::cout <<"BUZZ: "<< getName() << " senorita \"" << str << "\" senorita" << std::endl; 
    return true;
}