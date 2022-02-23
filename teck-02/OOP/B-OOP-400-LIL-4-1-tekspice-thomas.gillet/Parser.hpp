/*
** EPITECH PROJECT, 2021
** B-OOP-400-LIL-4-1-tekspice-thomas.gillet [WSL: Ubuntu]
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_
#include <string>

class Parser {
    public:
        Parser(std::string file);
        ~Parser();
        void checkLinks();
        void checkChipset();
        void checkSameName();
        void checkPin();

    protected:
    private:
        std::string _file;

};

#endif /* !PARSER_HPP_ */
