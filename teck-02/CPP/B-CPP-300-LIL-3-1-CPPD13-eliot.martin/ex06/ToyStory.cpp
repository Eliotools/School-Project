/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD13-eliot.martin
** File description:
** ToyStory
*/

#include "ToyStory.hpp"

ToyStory::ToyStory()
{
}

ToyStory::~ToyStory()
{
}

void ToyStory::tellMeAStory(std::string file, Toy &toy1,  bool (Toy::*func1)(std::string str1), Toy &toy2, bool (Toy::*func2)(std::string str2))
{
    std::ifstream f(file);
    std::string l = toy1.getAscii();
    int count = 0;

    if (!f) {
        std::cout << "Bad Story" << std::endl;
        return;
    }
    if (l != "ERROR")
        std::cout << l << std::endl;
    l = toy2.getAscii();
    std::cout << l << std::endl;

    while (std::getline(f, l)) {
        if (l.find("picture:") != std::string::npos)
        {
            if (count % 2 == 0) {
                if (toy1.setAscii(l.substr(8)))
                    std::cout << toy1.getAscii() << std::endl;
                else { 
                    auto e = toy1.getLastError ();
                    std::cout << e.where() << ": " << e.what() << std::endl;
                    break;
                }
            }
            if (count %2 == 1) {
                if (toy2.setAscii(l.substr(8)))
                    std::cout << toy2.getAscii() << std::endl;
                else { 
                    auto e = toy2.getLastError ();
                    std::cout << e.where() << ": " << e.what() << std::endl;
                    break;
                }
            }
            continue;
        }
        if (count % 2 == 0) {
            (toy1.*func1)(l);
        }
        if (count %2 == 1) {
            (toy2.*func2)(l);
        }
        count += 1;
    }
}