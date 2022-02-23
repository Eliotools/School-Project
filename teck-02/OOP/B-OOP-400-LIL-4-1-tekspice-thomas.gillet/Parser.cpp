/*
** EPITECH PROJECT, 2021
** B-OOP-400-LIL-4-1-tekspice-thomas.gillet [WSL: Ubuntu]
** File description:
** Parser
*/

#include "Parser.hpp"
#include "Error.hpp"
#include <fstream>
#include <iostream>
#include <algorithm>

Parser::Parser(std::string file) : _file(file)
{
    checkLinks();
    checkChipset();
    //checkSameName();
    checkPin();
}

Parser::~Parser()
{
}

void Parser::checkLinks()
{
    std::ifstream myfile (_file);
    std::string str((std::istreambuf_iterator<char>(myfile)),
                std::istreambuf_iterator<char>());
    if (!(str.find(".links:") != std::string::npos))
        throw ParseError("No .links:");
}

void Parser::checkChipset()
{
    std::ifstream myfile (_file);
    std::string str((std::istreambuf_iterator<char>(myfile)),
                std::istreambuf_iterator<char>());

    if (!(str.find(".chipsets:") != std::string::npos))
        throw ParseError("No .chipsets:");
}

void Parser::checkSameName()
{
    std::ifstream myfile (_file);
    std::ifstream myfile_2 (_file);
    std::string tmp;
    std::string str((std::istreambuf_iterator<char>(myfile_2)),
                std::istreambuf_iterator<char>());

    while (getline (myfile, tmp)) {
        if(tmp.rfind("#", 0) == 0 || tmp.rfind(".links:", 0) == 0
        || tmp.rfind(".chipsets:", 0) == 0)
            continue;

        if(tmp.rfind("input", 0) == 0) {
            //tmp.replace(tmp.begin(), tmp.begin() + 6, "");
            //if (std::count(str.begin(), str.end(), "in_01") == 2)
            //    std::cout << "yes";
        }

    }   

    //size_t n = std::count(s.begin(), s.end(), '_');

}

void Parser::checkPin()
{
    std::ifstream myfile (_file);
    std::string tmp;
    int passed = 0;

    while (getline (myfile, tmp)) {
        if (passed == 1 && tmp != "") {
            if ((std::count(tmp.begin(), tmp.end(), ':') > 2))
                throw ParseError("> 2: " + tmp);
            if ((std::count(tmp.begin(), tmp.end(), ':') < 2))
                throw ParseError("< 2: " + tmp);
        } if (!(tmp.compare(".links:")))
            passed = 1;
    }
}