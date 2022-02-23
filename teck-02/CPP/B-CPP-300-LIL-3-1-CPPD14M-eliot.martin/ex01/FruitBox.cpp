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
    _nb_f = 0;
}

FruitBox::~FruitBox()
{
}

int FruitBox::nbFruits() const
{
    return _nb_f;
}

bool FruitBox::putFruit(Fruit *f)
{
    if (_nb_f == _size) {
        std::cerr << "box full" << std::endl;
        return false;
    }
    _tmp = _first;
    auto *node = new FruitNode();
    node->_fruit = f;
    node->next = nullptr;
    if (_first == nullptr) {
        _first = node;
        _nb_f++;
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
    _nb_f++;
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
        std::cerr << "empty bix" << std::endl;
        return nullptr;
    }
    _tmp = _first;
    _first = _first->next;
    return _tmp->_fruit;
    _nb_f--;
}

FruitNode *FruitBox::head() const
{
    if (_first == nullptr)
        return nullptr;
    return _first;
}

FruitNode *FruitBox::getNode(int nb) const
{
    if (nb == 0)
        return _first;
    return _tmp;
}

void FruitBox::settmp(FruitNode *fn)
{
    _tmp = fn;
}
