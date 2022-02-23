/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPrush2-thomas.gillet
** File description:
** Table
*/

#ifndef TABLE_HPP_
#define TABLE_HPP_
#include "Object.hpp"
#include "ITable.hpp"
#include "Box.hpp"
#include "GiftPaper.hpp"
#include "Toy.hpp"

class Table {
    public:
        Table();
        ~Table();
        std::string *look();
        virtual Object *take(int index);
        virtual void put(Object *obj);
        ITable *createTable();

        void createTableRand();
        void setstring();
        int getIndex(Object::Type type);

        Toy *getToy(int index, Object::Toy_Type type);
        GiftPaper *getPaper(int index);
        Box *getBox(int index);



    protected:
        Object *_object[10];
        std::string _s[11];
        int _index;
    private:
};

#endif /* !TABLE_HPP_ */
