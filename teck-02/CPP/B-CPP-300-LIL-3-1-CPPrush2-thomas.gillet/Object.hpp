/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPrush2-thomas.gillet
** File description:
** Object
*/

#ifndef OBJECT_HPP_
#define OBJECT_HPP_
#include <string>
#include <iostream>

class Object {
    public:
        enum Type {TOY, BOX, GIFT_PAPER};
        enum Toy_Type {TEDDY, PONY};
        
        Object(std::string title);
        Object();
        ~Object();
        std::string getTitle() const;
        void setTitle(std::string title);
        Type _type;
        Toy_Type _toyType;
        std::string _title;

    protected:
    private:
};

std::ostream &operator<<(std::ostream &str, Object &Obj);
Object **MyUnitTests();
Object *MyUnitTests(Object **Array);
#endif /* !OBJECT_HPP_ */
