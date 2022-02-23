/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPrush2-thomas.gillet
** File description:
** main
*/

#include "LittlePony.hpp"
#include "Teddy.hpp"
#include "GiftPaper.hpp"
#include "Box.hpp"
#include "ConveyorBelt.hpp"
#include "Table.hpp"
#include "Elf.hpp"
#include <string>
#include <iostream>

int main()
{
    std::cout << "*******************CREATING OBJECT*******************" <<std::endl;
    std::string *looky;
    Table table;
    ConveyorBelt left;
    ConveyorBelt right;
    Elf ely;
    std::cout << std::endl <<"*******************INIT TABLE*******************" <<std::endl;
    looky = table.look();
    for (int i = 0; looky[i] != ""; i++)
        std::cout << " -- " << looky[i];
    std::cout << std::endl << "*******************INIT ELF*******************" <<std::endl;
    ely.setLeft(&left);
    ely.setRigth(&right);
    ely.setTable(&table);
    std::cout << std::endl << "*******************MAKING GIFT*******************" <<std::endl;
    std::cout << "able" << std::endl << std::endl;
    ely.wrapMeThat(ely.getToy(), ely.getBox(), ely.getPaper());
    std::cout << std::endl << "*******************MAKING GIFT*******************" <<std::endl;
    std::cout << "unable" << std::endl << std::endl;
    ely.wrapMeThat(ely.getToy(), ely.getBox(), ely.getPaper());
    std::cout << std::endl <<"*******************TABLE*******************" <<std::endl;
    looky = table.look();
    for (int i = 0; looky[i] != ""; i++)
        std::cout << " -- " << looky[i];
    std::cout << std::endl <<"*******************PUSH IN BUTTON x2*******************" <<std::endl;
    std::cout << std::endl;
    ely.getTable()->put(left.inButton());
    ely.getTable()->put(left.inButton());
    std::cout << std::endl <<"*******************TABLE*******************" <<std::endl;
    looky = table.look();
    for (int i = 0; looky[i] != ""; i++)
        std::cout << " -- " << looky[i];
    std::cout << std::endl << "*******************MAKING GIFT*******************" <<std::endl;
    std::cout << "abel" << std::endl << std::endl;
    ely.wrapMeThat(ely.getToy(), ely.getBox(), ely.getPaper());
    std::cout << std::endl;
    std::cout << std::endl << "*******************COLAPSE TABLE*******************" <<std::endl;
    ely.getTable()->put(left.inButton());
    ely.getTable()->put(left.inButton());
    ely.getTable()->put(left.inButton());
    ely.getTable()->put(left.inButton());
    ely.getTable()->put(left.inButton());
    ely.getTable()->put(left.inButton());
    ely.getTable()->put(left.inButton());
    ely.getTable()->put(left.inButton());
    looky = table.look();
    for (int i = 0; looky[i] != ""; i++)
        std::cout << " -- " << looky[i];
    return 0;
}

