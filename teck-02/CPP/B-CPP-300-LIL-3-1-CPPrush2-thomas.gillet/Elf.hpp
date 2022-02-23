/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPrush2-thomas.gillet
** File description:
** Elf
*/

#ifndef ELF_HPP_
#define ELF_HPP_
#include "ConveyorBelt.hpp"
#include "Table.hpp"
#include "Object.hpp"
#include "Box.hpp"
#include "GiftPaper.hpp"
#include "Toy.hpp"
#include "IElf.hpp"

class Elf
{
    public:
        Elf();
        ~Elf();
        ConveyorBelt *getRigth() const;
        ConveyorBelt *getLeft() const;
        Toy *getToy();
        Box *getBox();
        GiftPaper *getPaper();
        Table *getTable() const;
        virtual void wrapMeThat(Toy *toy, Box *box, GiftPaper *paper);

        void setRigth(ConveyorBelt *rigth);
        void setLeft(ConveyorBelt *left);
        void setTable(Table *table);

    protected:
        ConveyorBelt *_right;
        ConveyorBelt *_left;
        Table *_table;
        Object *_gift;
};

#endif /* !ELF_HPP_ */