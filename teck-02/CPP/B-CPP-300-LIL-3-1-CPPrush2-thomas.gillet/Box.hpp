/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPrush2-thomas.gillet
** File description:
** Box
*/

#ifndef BOX_HPP_
#define BOX_HPP_
#include "Wrap.hpp"
#include "Object.hpp"

class Box : public Wrap
{
    public:
        Box();
        Box(Object *obj);
        ~Box();
        void wrapMeThat(Object *obj);

    protected:
    private:
};

#endif /* !BOX_HPP_ */
