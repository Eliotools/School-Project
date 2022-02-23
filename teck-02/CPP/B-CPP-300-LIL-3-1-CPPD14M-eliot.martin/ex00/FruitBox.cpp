/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD14M-eliot.martin
** File description:
** FruitBox
*/

#include "FruitBox.hpp"
#include "Fruit.hpp"
#include "FruitNode.hpp"

FruitBox::FruitBox(int size)
{
    _size = size;
    _first = nullptr;
    _tmp = nullptr;
}

FruitBox::~FruitBox()
{
}

int FruitBox::nbFruits()
{
    int i = 1;
    if (_first == nullptr)
        return (0);
    _tmp = _first;
    while (_tmp->next != nullptr) {
        _tmp = _tmp->next;
        i++;
    }
    return i;
}

bool FruitBox::putFruit(Fruit *f)
{
    if (nbFruits() == _size) {
        std::cerr << "box full" << std::endl;
        return false;
    }
    _tmp = _first;
    auto *node = new FruitNode();
    node->_fruit = f;
    node->next = nullptr;
    if (_first == nullptr) {
        _first = node;
        return true;
    }
    if (_tmp->_fruit == f) {
        std::cerr << "already in" << std::endl;
        return false;
    }
    while (_tmp->next != nullptr) {
        if (_tmp->_fruit == f) {
            std::cerr << "already in" << std::endl;
            return false;
        }
        _tmp = _tmp->next;
    }
    _tmp->next = node;
    return true;
}

void FruitBox::seeBox()
{
    _tmp = _first;
    if (_first == nullptr) {
        std::cerr << "empty box" << std::endl;
        return;
    }
    std::cout << _first->_fruit->getName() << std::endl;
    while (_tmp->next != nullptr) {
        _tmp = _tmp->next;
        std::cout << _tmp->_fruit->getName() << std::endl;
    }
}

Fruit *FruitBox::pickFruit()
{
    if (nbFruits() == 0) {
        std::cerr << "empty box" << std::endl;
        return nullptr;
    }
    _tmp = _first;
    _first = _first->next;
    return _tmp->_fruit;
}

FruitNode *FruitBox::head()
{
    if (_first == nullptr)
        return nullptr;
    return _first;
}


