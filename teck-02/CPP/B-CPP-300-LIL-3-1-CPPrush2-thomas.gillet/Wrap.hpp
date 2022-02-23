/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPrush2-thomas.gillet
** File description:
** Wrap
*/

#ifndef WRAP_HPP_
#define WRAP_HPP_
#include "Object.hpp"

class Wrap : public Object
{
    public:
        Wrap(std::string title);
        ~Wrap();
        Object *getObject() const;
        void openMe();
        void closeMe();
        bool getIsopen();
        void isTaken();
        void operator=(Wrap &wrap);

    protected:
        Object *_object;
        bool _isopen;
    private:
};
#endif /* !WRAP_HPP_ */
