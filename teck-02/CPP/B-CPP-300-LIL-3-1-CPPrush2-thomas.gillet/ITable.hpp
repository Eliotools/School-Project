/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPrush2-thomas.gillet
** File description:
** ITable
*/

#ifndef ITABLE_HPP_
#define ITABLE_HPP_

#include "Object.hpp"

class ITable {
    public:
        ITable();
        virtual std::string *look() = 0;
        virtual Object *take() = 0;
        virtual void put(Object *obj) = 0;
        virtual ITable *createTable() = 0;
        ~ITable();
};

#endif /* !ITABLE_HPP_ */
