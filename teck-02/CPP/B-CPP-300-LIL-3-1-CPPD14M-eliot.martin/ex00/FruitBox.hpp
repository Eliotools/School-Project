/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD14M-eliot.martin
** File description:
** FruitBox
*/

#ifndef FRUITBOX_HPP_
#define FRUITBOX_HPP_
#include "Fruit.hpp"
#include "FruitNode.hpp"

class FruitBox {
    public:
        FruitBox(int size);
        ~FruitBox();
        int nbFruits();
        bool putFruit(Fruit *f);
        void seeBox();
        Fruit *pickFruit();
        FruitNode *head();

    protected:
    private:        
        FruitNode *_first;
        FruitNode *_tmp;
        int _size;
};

#endif /* !FRUITBOX_HPP_ */
