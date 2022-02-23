/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPrush2-thomas.gillet
** File description:
** ConveyorBelt
*/

#include "ConveyorBelt.hpp"
#include "GiftPaper.hpp"
#include "Box.hpp"
#include "Object.hpp"

ConveyorBelt::ConveyorBelt() : _object(nullptr)
{
}

ConveyorBelt::~ConveyorBelt()
{
}

Object* ConveyorBelt::take()
{
    Object *remove = _object;
    _object = nullptr;
    return remove;
}

void ConveyorBelt::put(Object *obj)
{
    if (_object == nullptr)
        _object = obj;
}

Object *ConveyorBelt::getObj()
{
    return _object;
}

Wrap *ConveyorBelt::inButton()
{
    static int wraps = 0;
    if (wraps % 2 == 0) {
        std::cout << "GiftPaper is coming !" << std::endl;
        wraps++;
        return (new GiftPaper);
    }
    else {
        std::cout << "Box is coming !" << std::endl;
        wraps++;
        return (new Box);
    }
}

Wrap *ConveyorBelt::inButtonRand()
{
    static int wraps = 0;
    int rum = random() % 2;
    if (rum == 0) {
        std::cout << "GiftPaper is coming !" << std::endl;
        wraps++;
        return (new GiftPaper);
    }
    else if (rum == 1) {
        std::cout << "Box is coming !" << std::endl;
        wraps++;
        return (new Box);
    }
    return (new Box);
}

void ConveyorBelt::outButton()
{
    std::cout << "Gift sent to santa!" << std::endl;
    _object = nullptr;
}

IConveyorBelt *ConveyorBelt::createConveyorBelt()
{
    IConveyorBelt *tmp = NULL;
    return tmp;
}
