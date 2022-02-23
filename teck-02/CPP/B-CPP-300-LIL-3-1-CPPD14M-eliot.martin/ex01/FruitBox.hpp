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
        int nbFruits() const;
        bool putFruit(Fruit *f);
        void seeBox();
        Fruit *pickFruit();
        FruitNode *head() const;
        FruitNode *getNode(int nb) const;
        void settmp(FruitNode *fn);
        int 

    protected:
        FruitNode *_first;
        FruitNode *_tmp;
        int _size;
        int _nb_f;
};

#endif /* !FRUITBOX_HPP_ */
