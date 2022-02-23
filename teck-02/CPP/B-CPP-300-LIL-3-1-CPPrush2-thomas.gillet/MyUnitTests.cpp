/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPrush2-thomas->gillet
** File description:
** MyUnitTests
*/

#include "LittlePony.hpp"
#include "Teddy.hpp"
#include "GiftPaper.hpp"
#include "Box.hpp"
#include <string>
#include <iostream>

Object **MyUnitTests()
{
    Object **Array = new Object*[2];

    Array[0] = new LittlePony("happy pony");
    Array[1] = new Teddy("cuddles");

    //     std::cout << "OK!" << std::endl;
    // else
    //     std::cout << "KO!" << std::endl;
    //     std::cout << "OK!" << std::endl;
    // else
    //     std::cout << "KO!" << std::endl;
    
    return Array;
}

Object *MyUnitTests(Object **Array)
{
    GiftPaper *paper = (GiftPaper*)Array[2];
    Box *box = (Box*)Array[1];
    Teddy *teddy = (Teddy*)Array[0];

    box->openMe();
    box->wrapMeThat(teddy);
    box->closeMe();
    paper->wrapMeThat(box);
    return (paper);
}