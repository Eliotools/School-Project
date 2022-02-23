/*
** EPITECH PROJECT, 2019
** info
** File description:
** bistromatic
*/

#include <stdio.h>
#include <unistd.h>
#include "include/my.h"

int info(char *av)
{
    if (av[0] == '-' && av[1] == 'h' && my_strlen(av) == 2) {
        my_putstr("USAGE\n");
        my_putstr("./calc base operators size_read\n");
        my_putchar('\n');
        my_putstr("DESCRIPTION\n");
        my_putstr("- base: all the symbols of the base\n");
        my_putstr("- operators: the symbols for the");
        my_putstr(" parantheses and the 5 operators\n");
        my_putstr("- size_read: number of characters to be read\n");
        return (0);
    }
    else
        return (84);
}
