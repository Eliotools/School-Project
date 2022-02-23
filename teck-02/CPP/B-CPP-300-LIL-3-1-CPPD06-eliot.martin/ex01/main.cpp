/*
** EPITECH PROJECT, 2020
** main
** File description:
** Moi
*/

#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

void next(char *file)
{

}

int main() {
    std::string input;
    getline(std::cin, input);
    float i = stof(input);

    if(input.find("Fahrenheit") != std::string::npos)
        std::cout << std::fixed << std::setprecision(3) << std::setw(16) << 5.0 / 9.0 * (i - 32) << std::setw(16) << "Celsius" << std::endl;
    if(input.find("Celsius") != std::string::npos)
        std::cout << std::fixed << std::setprecision(3) << std::setw(16) << (i * 9.0 )/5.0 + 32 << std::setw(16) << "Fahrenheit" << std::endl;
    return 0;
}
