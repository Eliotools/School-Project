/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD14M-eliot.martin
** File description:
** LittleHand
*/

#include "LittleHand.hpp"

LittleHand::LittleHand()
{
}

LittleHand::~LittleHand()
{
}

void LittleHand::sortFruitBox(FruitBox &unsorted, FruitBox &lemons, FruitBox &bananas, FruitBox &limes)
{
    std::string name;
    if (unsorted.getNode(0) == nullptr) {
        std::cerr << "no fruit here" << std::endl;
        return;
    }
    unsorted.settmp(unsorted.getNode(0));
    while (unsorted.getNode(1) != nullptr) {
        name = unsorted.getNode(1)->_fruit->getName();
        if (name == "lime") {
            std::cerr << "lime" << std::endl;
            if (limes.putFruit(unsorted.getNode(1)->_fruit))
                unsorted.pickFruit();
        } if (name == "lemon") {
            std::cerr << "lemon" << std::endl;
            if (lemons.putFruit(unsorted.getNode(1)->_fruit))
                unsorted.pickFruit();
        } if (name == "banana") {
            std::cerr << "banana" << std::endl;
            if (bananas.putFruit(unsorted.getNode(1)->_fruit))
                unsorted.pickFruit();
        }
        unsorted.settmp(unsorted.getNode(1)->next);
    }
}

FruitBox *const *LittleHand::organizeCoconut(Coconut const * const *coconut)
{
    int i = 0;
    int mod = 0;
    int nb = 0;
    while (coconut[i] != nullptr)
        i++;
    mod = i%6;
    nb = i/6;
    std::cout << "nb = " << nb <<std::endl;
    std::cout << "mod = " << mod <<std::endl;
    if (mod == 0)
        FruitBox *const *array[nb+1];
    if (mod == 1)
        FruitBox *const *array[nb+2];
    for (int j = 0; j != nb; j++)
    {
        
    }
    return nullptr;
}