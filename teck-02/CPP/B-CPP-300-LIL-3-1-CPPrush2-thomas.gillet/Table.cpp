/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPrush2-thomas.gillet
** File description:
** Table
*/

#include "Table.hpp"
#include "Teddy.hpp"
#include "LittlePony.hpp"
#include "GiftPaper.hpp"
#include "Box.hpp"
#include "Toy.hpp"
#include "ITable.hpp"
#include <iostream>
#include <string>

Table::Table()
{
    for (int i = 0; i != 9; i++)
        _object[i] = NULL;
    _index = 0;
    for (int i = 0; i < 10; i++)
        _s[i] = "";
    createTable();
}

Table::~Table()
{
}

std::string *Table::look()
{
    setstring();
    return (_s);
}

void Table::setstring()
{
    for (int i = 0; i < 10; i++){
        _s[i] = "";
    }
    for (int i = 0; i < 10; i++){
        if (_object[i] != NULL)
            _s[i] = _object[i]->getTitle();
        else
            _s[i] = "Vide";
    }
}

Object *Table::take(int index)
{
    if (index == -1) {
        std::cout << "Nothing there" << std::endl;
        return NULL;
    }
    Object *tmp = _object[index];
    _object[index] = NULL;
     
    look();
    return (tmp);
}

void Table::put(Object *obj)
{
    for (int i = 0; i < 11; i++) {
        if (_object[i] == NULL) {
            _object[i] = obj;
            return ;
        }
    }
    std::cout << "Too many items, the table collapsed..." << std::endl;
}

int Table::getIndex(Object::Type type)
{
    for (int i = 0; i < 11; i++){
        if (_object[i] != NULL)
            if (_object[i]->_type == type)
                return i;
    }
    return -1;
}

ITable *Table::createTable()
{
    ITable *tmp = NULL;

    _object[0] = new Teddy("Teddy");
    _object[1] = new LittlePony("Little Poney");
    _object[2] = new Teddy("Teddy2");
    _object[3] = new LittlePony("Little Poney2");
    _object[5] = new Teddy("Little Teddy");
    _object[5] = new Teddy("Little Teddy");
    _object[6] = new GiftPaper();
    _object[7] = new Teddy("Teddy3");
    _object[8] = new GiftPaper();
    _object[9] = new Box();

    return (tmp);
}

Toy *Table::getToy(int index, Object::Toy_Type type)
{
    if (index == -1)
        return NULL;
    Toy *toy = new Toy("teddy", type);
    _object[index] = NULL;
    return toy;
}

Box *Table::getBox(int index)
{
    if (index == -1)
        return NULL;
    Box *box = new Box;
    _object[index] = NULL;   
    return box;
}

GiftPaper *Table::getPaper(int index)
{
    if (index == -1)
        return NULL;
    GiftPaper *paper = new GiftPaper;
    _object[index] = NULL;
    return (paper);
}   

void Table::createTableRand()
{
    int rum = 0;
    for (int i = 0; i < 10; i++){
        rum = random() % 4;
        if (rum == 0)
            _object[i] = new Teddy("Teddy");
        else if (rum == 1)
            _object[i] = new LittlePony("Little Poney");
        else if (rum == 2)
            _object[i] = new Box();
        else
            _object[i] = new GiftPaper();
    }
}