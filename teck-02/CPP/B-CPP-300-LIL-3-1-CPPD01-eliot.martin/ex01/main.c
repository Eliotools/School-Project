/*
** EPITECH PROJECT, 2020
** main
** File description:
** Moi
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include "include/printf.h"
#include "include/phoenix.h"

int check_size(int size, int level)
{
    int pow = 1;
    int i = 0;

    while (i != level) {
        pow = pow*3;
        i++;
    }
    if (pow <= size)
        return (i);
    return (-1);
}

void next(int size, int level, int x, int y)
{
    int divider = 0;

    if (size % 3 == 0 && level > 0 && level < size){
        divider = size / 3;
        printf("%.3d %.3d %.3d\n", divider, divider + x, divider + y);
        level--;
        next(divider, level, x, y);
        next(divider, level, x, y + divider);
        next(divider, level, x, y + 2 * divider);
        next(divider, level, x + divider, y);
        next(divider, level, x + divider, y + 2 * divider);
        next(divider, level, x + 2 * divider, y);
        next(divider, level, x + 2 * divider, y + divider);
        next(divider, level, x + 2 * divider, y + 2 * divider);
    }
}

int main(int ac, char **av)
{
    if (ac != 3)
        return (84);

    int size = atoi(av[1]);
    int level = atoi(av[2]);
    int power = check_size(size, level);

    if (power == -1 || level == 0 ) {
        printf("Error arguements\n");
        return (84);
    }
    next(size, level, 0, 0);
    return (0);
}
