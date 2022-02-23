/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** Elf
*/

#include "Elf.hpp"
#include "GiftPaper.hpp"
#include "Box.hpp"
#include "Object.hpp"

Elf::Elf() : _gift(nullptr)
{
}

Elf::~Elf()
{
}

void Elf::setRigth(ConveyorBelt *rigth)
{
    _right = rigth;
}

void Elf::setLeft(ConveyorBelt *left)
{
    _left = left;
}

void Elf::setTable(Table *table)
{
    _table = table;
}

ConveyorBelt *Elf::getRigth() const
{
    return _right;
}

ConveyorBelt *Elf::getLeft() const
{
    return _left;
}

Table *Elf::getTable() const
{
    return _table;
}

void Elf::wrapMeThat(Toy *toy, Box *box, GiftPaper *paper)
{
    if (box == NULL) {
        std::cerr << "Missing a box!" << std::endl;
        return ;
    }
    if (paper == NULL) {
        std::cerr << "Missing a paper!" << std::endl;
        return ;
    }
    if (toy == NULL) {
        std::cerr << "Missing a toy!" << std::endl;
        return ;
    }
    box->isTaken();
    box->openMe();
    box->wrapMeThat(toy);
    toy->isTaken(toy->_toyType);
    box->closeMe();
    paper->isTaken();
    paper->wrapMeThat(box);
    _gift = paper;
    getRigth()->put(_gift);
    getRigth()->outButton();
}

Toy *Elf::getToy()
{
    //les title ont disparu
    int index = getTable()->getIndex(Object::TOY);
    Object::Toy_Type type = getTable()->take(index)->_toyType;
    return (getTable()->getToy(index, type));
}

Box *Elf::getBox()
{
    int index = getTable()->getIndex(Object::BOX);
    return (getTable()->getBox(index));
}

GiftPaper *Elf::getPaper()
{
    int index = getTable()->getIndex(Object::GIFT_PAPER);
    return (getTable()->getPaper(index));
}
//void Elf::printGift()
//{
//    std::cout <<"Toy :" << <<std::endl;
//}/*
// elf.getLeft().take(TOY).wrapMeThat(elf.getTable(BOX))
// elf.wrapMethat(TOY, BOX, PAPER)
// open box -> toy>box -> cloose box -> box>paper*/