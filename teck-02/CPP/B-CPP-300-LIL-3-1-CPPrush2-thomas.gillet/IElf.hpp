/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPrush2-thomas.gillet
** File description:
** IElf
*/

#ifndef IELF_HPP_
#define IELF_HPP_
#include "Object.hpp"
#include "Table.hpp"
#include "ConveyorBelt.hpp"

class IElf {
    public:
        IElf();
        ~IElf();
        virtual void wrapMeThat(Object *obj) = 0;
        virtual ConveyorBelt *getRigth() const = 0;
        virtual ConveyorBelt *getLeft() const = 0;
        virtual Table getTable() const = 0;
        virtual void wrapMeThat(Toy *toy, Box *box, GiftPaper *paper) = 0;

        virtual void setRigth(ConveyorBelt *rigth) = 0;
        virtual void setLeft(ConveyorBelt *left) = 0;
        virtual void setTable(Table table) = 0;

    protected:
    private:
};

#endif /* !IELF_HPP_ */
