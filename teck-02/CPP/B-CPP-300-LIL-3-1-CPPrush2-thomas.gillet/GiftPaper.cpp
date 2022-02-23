/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPrush2-thomas.gillet
** File description:
** GiftPaper
*/

#include "GiftPaper.hpp"

GiftPaper::GiftPaper() : Wrap("Gift Paper")
{
    _type = Object::GIFT_PAPER;
}

GiftPaper::~GiftPaper()
{
}

void GiftPaper::wrapMeThat(Object *obj)
{
    std::cout << "tuuuut tuuut tuut" << std::endl;
    if (_object){
        std::cerr << "One object already in ! Santa say only ONE !!" << std::endl;
        return;
    }
    _object = obj;
}

// void GiftPaper::wrapMeThat(Wrap *wrap)
// {
//     std::cout << "tuuuut tuuut tuut" << std::endl;
//     if (_wrap){
//         std::cerr << "One object already in ! Santa say only ONE !!" << std::endl;
//         return;
//     }
//     _wrap = wrap;
// }