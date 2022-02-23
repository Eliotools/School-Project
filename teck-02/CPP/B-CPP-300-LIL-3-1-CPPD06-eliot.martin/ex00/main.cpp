/*
** EPITECH PROJECT, 2020
** main
** File description:
** Moi
*/

#include <string>
#include <iostream>
#include <fstream>

void next(char *file)
{
    std::ifstream f (file);
    if (f) {
        std::string line;
        while(std::getline(f, line))
            std::cout << line <<"\n";
    }
    else
        std::cerr << "my_cat: "<< file <<": No such file or directory\n";
}

int main(int ac, char **av)
{
    if (ac == 1) {
        std::cerr << "my_cat: Usage: ./my_cat file [...]\n";
        return(0);
    }

    for (int i = 1; av[i] != NULL; i++)
            next(av[i]);
}
