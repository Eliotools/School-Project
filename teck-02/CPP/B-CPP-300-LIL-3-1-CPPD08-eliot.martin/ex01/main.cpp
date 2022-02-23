/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD08-eliot.martin
** File description:
** main
*/

#include "DroidMemory.hpp"
#include "Droid.hpp"
#include <iostream>
#include <string>

int main()
{
    DroidMemory  mem1;
    DroidMemory  mem2;
    mem1 + 42;
    //mem1 = mem1 + 42;
    mem1 << mem1 += 42;
    mem1 >> mem2;
    std::cout  << mem1  << std::endl;
    DroidMemory  mem3;
    mem3  << mem1 << mem1;
    mem3  >> mem1 >> mem1;
    mem3  << mem1;
    std::cout  << mem3  << std::endl;
    std::cout  << mem1  << std::endl;
    return 0;
}