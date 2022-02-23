/*
** EPITECH PROJECT, 2019
** screensaver
** File description:
** Moi
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/System/Vector2.h>
#include "include/my.h"
#include "stdlib.h"
#include "struct.h"
#include <math.h>

int main (int ac, char **av)
{
    int my_len = 0;
    int number = 0;

    if (ac != 2)
        return (84);
    number = av[1][0] - '0';
    return (my_sortanim(number));
}
