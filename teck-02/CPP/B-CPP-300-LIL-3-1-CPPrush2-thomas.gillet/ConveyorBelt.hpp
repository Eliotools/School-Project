/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPrush2-thomas.gillet
** File description:
** ConveyorBelt
*/

#ifndef CONVEYORBELT_HPP_
#define CONVEYORBELT_HPP_

#include "Object.hpp"
#include "Wrap.hpp"
#include "IConveyorBelt.hpp"

class ConveyorBelt {
    public:
        ConveyorBelt();
        ~ConveyorBelt();
        virtual Object *take();
        virtual void put(Object *obj);
        Wrap *inButton();
        Wrap *inButtonRand();
        void outButton();    
        Object *getObj();

        virtual IConveyorBelt *createConveyorBelt();
    protected:
        Object *_object;
        bool _In;
        bool _Out;
    private:
};

#endif /* !CONVEYORBELT_HPP_ */
