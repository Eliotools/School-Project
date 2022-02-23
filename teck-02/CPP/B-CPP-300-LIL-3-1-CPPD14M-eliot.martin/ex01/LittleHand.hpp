/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD14M-eliot.martin
** File description:
** LittleHand
*/
#include "FruitNode.hpp"
#include "FruitBox.hpp"

#ifndef LITTLEHAND_HPP_
#define LITTLEHAND_HPP_

class LittleHand {
    public:
        LittleHand();
        ~LittleHand();
        static void sortFruitBox(FruitBox &unsorted, FruitBox &lemons, FruitBox &bananas, FruitBox &limes);
    protected:
    private:
};

#endif /* !LITTLEHAND_HPP_ */
