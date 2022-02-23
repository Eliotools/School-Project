/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPrush2-thomas.gillet
** File description:
** IConveyorBelt
*/

#ifndef ICONVEYORBELT_HPP_
#define ICONVEYORBELT_HPP_
#include "Wrap.hpp"
#include "Object.hpp"

class IConveyorBelt {
    public:
        virtual Object *take() = 0;
        virtual void put(Object *obj) = 0;
        virtual Wrap *inButton() = 0;
        virtual void outButton() = 0;
        virtual Object *getObj() = 0;
        virtual IConveyorBelt *createConveyorBelt() = 0;

    protected:
    private:
};


#endif /* !ICONVEYORBELT_HPP_ */
