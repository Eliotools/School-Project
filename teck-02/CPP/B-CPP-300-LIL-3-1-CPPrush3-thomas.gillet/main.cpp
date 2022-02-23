/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPrush3-thomas.gillet
** File description:
** main
*/

#include <iostream>
#include "info.hpp"

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cout << "Usage:\n\t./MyGKrellm -g : For graphical mode\n\t./MyGKrellm -n : For ncurses mode" << std::endl;
        return 84;
    }
    std::string option = av[1];
    if (option == "-g")
        my_sfml();
    else if (option == "-n")
        my_ncurse();
    std::cout << "Usage:\n\t./MyGKrellm -g : For graphical mode\n\t./MyGKrellm -n : For ncurses mode" << std::endl;
	return 0;
}