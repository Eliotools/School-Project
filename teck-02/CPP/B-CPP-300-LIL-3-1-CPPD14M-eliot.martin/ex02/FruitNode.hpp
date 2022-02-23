/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD14M-eliot.martin
** File description:
** FruitNode
*/

#ifndef FRUITNODE_HPP_
#define FRUITNODE_HPP_
#include "Fruit.hpp"

typedef struct FruitNode_s{
    Fruit *_fruit;
    struct FruitNode_s *next;
}FruitNode;

#endif /* !FRUITNODE_HPP_ */
