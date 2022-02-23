/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD14M-eliot.martin
** File description:
** LittleHand
*/
#include "FruitNode.hpp"
#include "FruitBox.hpp"
#include "Coconut.hpp"

#ifndef LITTLEHAND_HPP_
#define LITTLEHAND_HPP_

class LittleHand {
    public:
        LittleHand();
        ~LittleHand();
        static void sortFruitBox(FruitBox &unsorted, FruitBox &lemons, FruitBox &bananas, FruitBox &limes);
        static FruitBox *const *organizeCoconut(Coconut  const * const *coconuts);
    protected:
    private:
};

#endif /* !LITTLEHAND_HPP_ */
